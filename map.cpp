#include "map.h"
#include "ui_map.h"
#include "formation.h"
#include <QQuickItem>
#include <QVBoxLayout>
#include <QDebug>

Map::Map(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    setupMap();
}

Map::~Map()
{
    delete ui;
}

void Map::setupMap() {
    mapWidget = new QQuickWidget(this);
    mapWidget->setResizeMode(QQuickWidget::SizeRootObjectToView);
    mapWidget->setSource(QUrl("qrc:/map.qml"));

    // Debug connection
    connect(mapWidget, &QQuickWidget::statusChanged, this, [this](QQuickWidget::Status status) {
        qDebug() << "Map status:" << status;
        if (status == QQuickWidget::Ready) {
            qDebug() << "Map is ready, loading formations...";
            loadFormationsToMap();
        }
    });

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(mapWidget);
    setLayout(layout);

    QObject::connect(mapWidget->rootObject(), SIGNAL(mapClicked(double, double)),
                     this, SLOT(handleMapClick(double, double)));
}

void Map::handleMapClick(double latitude, double longitude)
{
    QGeoCoordinate coord(latitude, longitude);
    emit locationSelected(coord);
    this->accept();  // Close the dialog after selection
}

void Map::loadFormationsToMap() {
    QList<QPair<QString, QGeoCoordinate>> formations = Formation::getAllCoordinates();
    QVariantList markers;

    for (const auto &[name, coord] : formations) {
        if (coord.isValid()) {
            QVariantMap marker;
            marker["lat"] = coord.latitude();
            marker["lon"] = coord.longitude();
            marker["title"] = name;
            markers.append(marker);
        }
    }

    QObject *rootObject = mapWidget->rootObject();
    if (rootObject) {
        QMetaObject::invokeMethod(rootObject, "addMarkers",
                                  Q_ARG(QVariant, QVariant::fromValue(markers)));
    } else {
        qDebug() << "Root object is null!";
    }
}

