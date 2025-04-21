#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "loginform.h"
#include <QMessageBox>
#include <QPropertyAnimation>
#include <QSortFilterProxyModel>
#include <QVBoxLayout>
#include <QPainter>
#include <QPrinter>
#include <QTextDocument>
#include <QMessageBox>





MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    connect(ui->tri, &QComboBox::currentTextChanged, this, &MainWindow::on_tri_currentIndexChanged);


    // Connect buttons to slots
    connect(ui->addButton, &QPushButton::clicked, this, &MainWindow::on_addButton_clicked);
    connect(ui->editButton, &QPushButton::clicked, this, &MainWindow::on_editButton_clicked);
    connect(ui->pushButton_11, &QPushButton::clicked, this, &MainWindow::on_deleteButton_clicked);
    connect(ui->tableView, &QTableView::clicked, this, &MainWindow::on_tableView_clicked);

    // Load data into the table view
    refreshTable();
}

MainWindow::~MainWindow() {
    delete ui;
}

// Refresh the table view
void MainWindow::refreshTable() {
    QSqlQueryModel *model = new QSqlQueryModel(this);
    model->setQuery("SELECT * FROM ARCHITECTE");

    proxyModel = new QSortFilterProxyModel(this);
    proxyModel->setSourceModel(model);
    proxyModel->setFilterCaseSensitivity(Qt::CaseInsensitive);
    proxyModel->setFilterKeyColumn(-1); // search all columns

    ui->tableView->setModel(proxyModel);
    connect(ui->lineEditSearch, &QLineEdit::textChanged, this, [=](const QString &text) {
        proxyModel->setFilterFixedString(text);
    });


}

// Add a new architect
void MainWindow::on_addButton_clicked() {
    int id = ui->lineEdit->text().toInt();
    QString name = ui->lineEdit_2->text();
    QString email = ui->lineEdit_3->text();
    QString role = ui->lineEdit_4->text();
    QString password = ui->lineEdit_6->text();
    QString securityQuestion = ui->lineEdit_7->text();
    QString securityAnswer = ui->lineEdit_8->text();

    Architect newArchitect(id, name, email, role, password, securityQuestion, securityAnswer);
    if (newArchitect.add()) {
        QMessageBox::information(this, "Success", "Architect added successfully!");
        refreshTable(); // Refresh the table view
    } else {
        QMessageBox::critical(this, "Error", "Failed to add architect.");
    }
}
void MainWindow::on_tableView_clicked(const QModelIndex &index) {
    // Get the selected row
    int row = index.row();

    // Retrieve data from the selected row
    QModelIndex idIndex = ui->tableView->model()->index(row, 0); // ID is in column 0
    QModelIndex nameIndex = ui->tableView->model()->index(row, 1); // Name is in column 1
    QModelIndex emailIndex = ui->tableView->model()->index(row, 2); // Email is in column 2
    QModelIndex roleIndex = ui->tableView->model()->index(row, 3); // Role is in column 3
    QModelIndex passwordIndex = ui->tableView->model()->index(row, 4); // Password is in column 4
    QModelIndex securityQuestionIndex = ui->tableView->model()->index(row, 5); // Security Question is in column 5
    QModelIndex securityAnswerIndex = ui->tableView->model()->index(row, 6); // Security Answer is in column 6

    // Populate the input fields
    ui->lineEdit->setText(ui->tableView->model()->data(idIndex).toString());
    ui->lineEdit_2->setText(ui->tableView->model()->data(nameIndex).toString());
    ui->lineEdit_3->setText(ui->tableView->model()->data(emailIndex).toString());
    ui->lineEdit_4->setText(ui->tableView->model()->data(roleIndex).toString());
    ui->lineEdit_6->setText(ui->tableView->model()->data(passwordIndex).toString());
    ui->lineEdit_7->setText(ui->tableView->model()->data(securityQuestionIndex).toString());
    ui->lineEdit_8->setText(ui->tableView->model()->data(securityAnswerIndex).toString());
}
void MainWindow::on_editButton_clicked() {
    // Get the ID of the selected item
    int id = ui->lineEdit->text().toInt();

    // Get the updated data from the input fields
    QString name = ui->lineEdit_2->text();
    QString email = ui->lineEdit_3->text();
    QString role = ui->lineEdit_4->text();
    QString password = ui->lineEdit_6->text();
    QString securityQuestion = ui->lineEdit_7->text();
    QString securityAnswer = ui->lineEdit_8->text();

    // Create an Architect object with the updated data
    Architect updatedArchitect(id, name, email, role, password, securityQuestion, securityAnswer);

    // Update the database
    if (updatedArchitect.update(id)) {
        QMessageBox::information(this, "Success", "Architect updated successfully!");
        refreshTable(); // Refresh the table view
    } else {
        QMessageBox::critical(this, "Error", "Failed to update architect.");
    }
}
// Delete an architect
void MainWindow::on_deleteButton_clicked() {
    int id = ui->lineEdit->text().toInt();

    if (architect.remove(id)) {
        QMessageBox::information(this, "Success", "Architect deleted successfully!");
        refreshTable(); // Refresh the table view
    } else {
        QMessageBox::critical(this, "Error", "Failed to delete architect.");
    }
}

void MainWindow::on_btnLogout_clicked()
{
    auto reply = QMessageBox::question(this, "Déconnexion",
                                       "Êtes-vous sûr de vouloir vous déconnecter ?",
                                       QMessageBox::Yes | QMessageBox::No);
    if (reply != QMessageBox::Yes)
        return;

    // Animate fade out
    QPropertyAnimation *fadeOut = new QPropertyAnimation(this, "windowOpacity");
    fadeOut->setDuration(700);                    // duration in milliseconds
    fadeOut->setStartValue(1.0);
    fadeOut->setEndValue(0.0);
    fadeOut->setEasingCurve(QEasingCurve::InOutQuad);

    connect(fadeOut, &QPropertyAnimation::finished, this, [=]() {
        this->hide(); // or close();
        LoginForm *login = new LoginForm();
        login->show();
    });

    fadeOut->start(QAbstractAnimation::DeleteWhenStopped);
}

void MainWindow::on_pdf_clicked()
{
    QSqlQuery query("SELECT * FROM ARCHITECTE");

    QString html;
    html += "<h2 style='text-align:center;'>Liste des architectes</h2>";
    html += "<table border='1' cellspacing='0' cellpadding='5' width='100%'>";
    html += "<tr>"
            "<th>ID</th><th>Nom</th><th>Email</th><th>Rôle</th>"
            "</tr>";

    while (query.next()) {
        html += "<tr>";
        html += "<td>" + query.value("ID_ARCHITECTE").toString() + "</td>";
        html += "<td>" + query.value("NOM").toString() + "</td>";
        html += "<td>" + query.value("COURRIEL").toString() + "</td>";
        html += "<td>" + query.value("ROLE").toString() + "</td>";
        html += "</tr>";
    }

    html += "</table>";

    QTextDocument document;
    document.setHtml(html);

    QPrinter printer;
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setOutputFileName("liste_architectes.pdf");

    document.print(&printer);

    QMessageBox::information(this, "Succès", "PDF exporté sous 'liste_architectes.pdf'");
}

void MainWindow::on_tri_currentIndexChanged(const QString &text)
{
    QString queryText = "SELECT * FROM ARCHITECTE";

    if (text == "ID") {
        queryText += " ORDER BY ID_ARCHITECTE ASC";
    }
    // You can add more sort conditions here later (Nom, Courriel, etc.)

    QSqlQueryModel *model = new QSqlQueryModel(this);
    model->setQuery(queryText);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Courriel"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Rôle"));
    ui->tableView->setModel(model);
}

void MainWindow::on_darkModeBtn_clicked()
{
    darkModeEnabled = !darkModeEnabled;

    if (darkModeEnabled) {
        // Activate Dark Mode
        qApp->setStyleSheet(R"(
            QWidget {
                background-color: #121212;
                color: #eeeeee;
            }
            QLineEdit, QTextEdit, QPlainTextEdit, QTableView {
                background-color: #1e1e1e;
                color: #ffffff;
                border: 1px solid #444;
            }
            QPushButton {
                background-color: #2e2e2e;
                border: 1px solid #555;
                padding: 5px;
                border-radius: 5px;
            }
            QPushButton:hover {
                background-color: #444;
            }
        )");
        ui->darkModeBtn->setText("Light Mode ☀️");
    } else {
        // Back to Light Mode
        qApp->setStyleSheet("");
        ui->darkModeBtn->setText("Dark Mode 🌙");
    }
}










