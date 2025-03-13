#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

    // Connect buttons to slots
    connect(ui->pushButton_2, &QPushButton::clicked, this, &MainWindow::on_addButton_clicked);
    connect(ui->pushButton_10, &QPushButton::clicked, this, &MainWindow::on_editButton_clicked);
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
    QSqlQueryModel* model = architect.read();
    ui->tableView->setModel(model);
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
