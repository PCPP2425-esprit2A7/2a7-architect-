#ifndef DASHBORD_H
#define DASHBORD_H
#include <QJsonArray>
#include <QDialog>
#include <QTimer>
namespace Ui {
class dashbord;
}

class dashbord : public QDialog
{
    Q_OBJECT

public:
    explicit dashbord(QWidget *parent = nullptr);
    ~dashbord();
    void sauvegarderNotifications();
    void chargerNotifications();
public slots:
    void ajouterNotification(const QString& message);
    void showNewFormationsNotification();
private:
    Ui::dashbord *ui;
    QString fichierNotifications = "notifications.json"; // Fichier de sauvegarde
    int m_unsavedCount;
    QList<QPair<QString, QString>> m_notificationCache; // Cache en mémoire
    QTimer m_saveTimer; // Pour sauvegarde différée
signals:
    void returnRequested();
};

#endif // DASHBORD_H
