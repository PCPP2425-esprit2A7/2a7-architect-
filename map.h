#ifndef MAP_H
#define MAP_H

#include <QDialog>
#include <QQuickWidget>
#include <QGeoCoordinate>
#include "ui_map.h"

namespace Ui {
class Dialog;
}

class Map : public QDialog
{
    Q_OBJECT

public:
    explicit Map(QWidget *parent = nullptr);
    ~Map();
    void setupMap();
    void loadFormationsToMap();
    void centerOn(double lat, double lon);

signals:
    void locationSelected(const QGeoCoordinate &coord);  // New signal

private slots:
    void handleMapClick(double latitude, double longitude);  // New slot

private:
    Ui::Dialog *ui;
    QQuickWidget *mapWidget = nullptr;
};

#endif // MAP_H
