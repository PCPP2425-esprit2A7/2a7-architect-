#include "dashbord.h"
#include "ui_dashbord.h"
#include <QDateTime>
#include <QJsonDocument>
#include <QFile>
#include <QDebug>
#include <QJsonArray>    // Assurez-vous que c'est présent
#include <QJsonObject>   // Nécessaire pour QJsonObject

dashbord::dashbord(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dashbord),
    fichierNotifications("notifications.json"),
    m_unsavedCount(0)
{
    ui->setupUi(this);

    // Configuration de la table
    ui->tableView->setColumnCount(2);
    ui->tableView->setHorizontalHeaderLabels({"Message", "Date/Heure"});
    ui->tableView->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Stretch);

    // Configuration du timer de sauvegarde
    m_saveTimer.setInterval(3000); // 3 secondes
    m_saveTimer.setSingleShot(true);
    connect(&m_saveTimer, &QTimer::timeout, this, &dashbord::sauvegarderNotifications);

    // Chargement initial
    chargerNotifications();

    connect(ui->anuule, &QPushButton::clicked, this, [this]() {
        if (parentWidget()) parentWidget()->show();
        this->hide();
        emit returnRequested();
    });
}

dashbord::~dashbord()
{
    if (m_unsavedCount > 0) {
        sauvegarderNotifications();
    }
    delete ui;
}

void dashbord::sauvegarderNotifications()
{
    if (m_notificationCache.isEmpty()) return;

    QJsonArray notificationsArray;

    for (const auto& notif : qAsConst(m_notificationCache)) {
        QJsonObject obj;
        obj["message"] = notif.first;
        obj["date"] = notif.second;
        notificationsArray.append(obj);
    }

    QFile file(fichierNotifications);
    if (file.open(QIODevice::WriteOnly)) {
        file.write(QJsonDocument(notificationsArray).toJson(QJsonDocument::Compact));
        file.close();
        m_unsavedCount = 0;
    } else {
        qDebug() << "Erreur de sauvegarde:" << file.errorString();
    }
}

void dashbord::chargerNotifications()
{
    QFile file(fichierNotifications);
    if (file.open(QIODevice::ReadOnly)) {
        QJsonDocument doc = QJsonDocument::fromJson(file.readAll());
        file.close();

        if (doc.isArray()) {
            ui->tableView->setUpdatesEnabled(false);
            ui->tableView->setRowCount(0);
            m_notificationCache.clear();

            const QJsonArray notificationsArray = doc.array();
            ui->tableView->setRowCount(notificationsArray.size());

            for (int i = 0; i < notificationsArray.size(); ++i) {
                const QJsonObject obj = notificationsArray[i].toObject();
                m_notificationCache.append(qMakePair(
                    obj["message"].toString(),
                    obj["date"].toString()
                    ));

                QTableWidgetItem* msgItem = new QTableWidgetItem(obj["message"].toString());
                QTableWidgetItem* dateItem = new QTableWidgetItem(obj["date"].toString());
                msgItem->setForeground(Qt::darkGreen);
                dateItem->setForeground(Qt::blue);
                ui->tableView->setItem(i, 0, msgItem);
                ui->tableView->setItem(i, 1, dateItem);
            }
            ui->tableView->setUpdatesEnabled(true);
        }
    }
}

void dashbord::ajouterNotification(const QString& message)
{
    const QString currentTime = QDateTime::currentDateTime().toString("dd/MM/yyyy hh:mm:ss");

    // Ajout au cache
    m_notificationCache.append(qMakePair(message, currentTime));

    // Ajout à l'interface
    const int row = ui->tableView->rowCount();
    ui->tableView->insertRow(row);

    QTableWidgetItem* msgItem = new QTableWidgetItem(message);
    QTableWidgetItem* dateItem = new QTableWidgetItem(currentTime);
    msgItem->setForeground(Qt::darkGreen);
    dateItem->setForeground(Qt::blue);

    ui->tableView->setItem(row, 0, msgItem);
    ui->tableView->setItem(row, 1, dateItem);
    ui->tableView->scrollToBottom();

    // Planifier la sauvegarde
    if (++m_unsavedCount >= 5) {
        m_saveTimer.start();
    }
}
