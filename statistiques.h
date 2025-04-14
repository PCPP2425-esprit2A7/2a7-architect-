#ifndef STATISTIQUES_H
#define STATISTIQUES_H

#include <QDialog>
#include <QtCharts>
#include <QChartView>
#include <QPieSeries>
#include <QBarSet>
#include <QBarSeries>
#include <QBarCategoryAxis>
#include <QValueAxis>
#include <QSqlQuery>
#include <QGridLayout>
#include <QLabel>

namespace Ui {
class Statistiques;
}

class Statistiques : public QDialog
{
    Q_OBJECT

public:
    explicit Statistiques(QWidget *parent = nullptr);
    ~Statistiques();

private:
    Ui::Statistiques *ui;
    void setupCharts();
    void createProjectStatusChart();
    void createProjectTimelineChart();
    void createProjectCountByMonthChart();
    QMap<QString, int> getProjectStatusCount();
    QMap<QString, int> getProjectCountByMonth();
};

#endif // STATISTIQUES_H
