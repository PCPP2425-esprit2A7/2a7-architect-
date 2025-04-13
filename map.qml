import QtQuick 2.15
import QtQuick.Window 2.15
import QtLocation 5.15
import QtPositioning 5.15

Rectangle {
    id: root
    width: 800
    height: 600
    color: "lightgray"

    signal mapClicked(double latitude, double longitude)

    Plugin {
        id: mapPlugin
        name: "osm"
        PluginParameter {
            name: "osm.mapping.custom.host"
            value: "https://tile.openstreetmap.org/"
        }
        PluginParameter {
            name: "osm.mapping.providersrepository.disabled"
            value: "true"
        }
        PluginParameter {
            name: "osm.mapping.highdpi_tiles"
            value: true
        }
        PluginParameter {
            name: "osm.useragent"
            value: "Your Application Name"
        }

        Component.onCompleted: {
            console.log("Supported map types:", mapPlugin.supportedMapTypes);
            console.log("Plugin available:", mapPlugin.availableServiceProviders);
        }
    }

    Map {
        id: map
        anchors.fill: parent
        plugin: mapPlugin
        center: QtPositioning.coordinate(46.2276, 2.2137) // Start in France
        zoomLevel: 8
        focus: true

        MouseArea {
            id: panArea
            anchors.fill: parent
            property point lastMousePos
            acceptedButtons: Qt.LeftButton

            onPressed: lastMousePos = Qt.point(mouse.x, mouse.y)

            onPositionChanged: {
                if (pressedButtons & Qt.LeftButton) {
                    var dx = mouse.x - lastMousePos.x
                    var dy = mouse.y - lastMousePos.y
                    lastMousePos = Qt.point(mouse.x, mouse.y)

                    // Calculate new center
                    var centerPixel = Qt.point(width/2 - dx, height/2 - dy)
                    map.center = map.toCoordinate(centerPixel)
                }
            }
        }

        // Right-click to select location
        MouseArea {
            anchors.fill: parent
            acceptedButtons: Qt.RightButton
            onClicked: function(mouse) {
                var coord = map.toCoordinate(Qt.point(mouse.x, mouse.y))
                console.log("Clicked at:", coord.latitude, coord.longitude)
                mapClicked(coord.latitude, coord.longitude)
            }
        }

        // Mouse wheel zoom
        MouseArea {
            anchors.fill: parent
            acceptedButtons: Qt.NoButton
            onWheel: {
                var zoomBefore = map.zoomLevel
                var newZoom = wheel.angleDelta.y > 0 ?
                    Math.min(zoomBefore + 0.5, map.maximumZoomLevel) :
                    Math.max(zoomBefore - 0.5, map.minimumZoomLevel)

                map.zoomLevel = newZoom
            }
        }

        MapItemView {
            model: ListModel {
                id: markersModel
                // Markers will be populated from C++
            }

            delegate: MapQuickItem {
                coordinate: QtPositioning.coordinate(model.lat, model.lon)
                sourceItem: Rectangle {
                    width: 40
                    height: 40
                    radius: 20
                    color: "red"
                    border.width: 2
                    border.color: "white"

                    Text {
                        text: model.title
                        anchors.top: parent.bottom
                        anchors.horizontalCenter: parent.horizontalCenter
                        font.pixelSize: 14
                        font.bold: true
                        color: "black"
                        style: Text.Outline
                        styleColor: "white"
                    }
                }
            }
        }
    }

    // Zoom Controls
    Column {
        anchors.right: parent.right
        anchors.top: parent.top
        anchors.margins: 10
        spacing: 5

        // Zoom In
        Rectangle {
            width: 40
            height: 40
            color: "white"
            radius: 5
            border.width: 1
            Text {
                text: "+"
                anchors.centerIn: parent
                font.pixelSize: 20
            }
            MouseArea {
                anchors.fill: parent
                onClicked: map.zoomLevel = Math.min(map.zoomLevel + 1, 20)
            }
        }

        // Zoom Out
        Rectangle {
            width: 40
            height: 40
            color: "white"
            radius: 5
            border.width: 1
            Text {
                text: "-"
                anchors.centerIn: parent
                font.pixelSize: 20
            }
            MouseArea {
                anchors.fill: parent
                onClicked: map.zoomLevel = Math.max(map.zoomLevel - 1, 1)
            }
        }
    }

    // Status Display
    Text {
        anchors.bottom: parent.bottom
        anchors.left: parent.left
        anchors.margins: 10
        text: "Lat: " + map.center.latitude.toFixed(4) +
              " | Lon: " + map.center.longitude.toFixed(4) +
              " | Zoom: " + map.zoomLevel.toFixed(1)
        font.pixelSize: 12
        color: "black"
        style: Text.Outline
        styleColor: "white"
    }

    // Function to handle adding markers dynamically
    function addMarkers(newMarkers) {
        markersModel.clear();
        for (var i = 0; i < newMarkers.length; i++) {
            var marker = newMarkers[i];
            if (marker.lat && marker.lon) {
                markersModel.append({
                    lat: marker.lat,
                    lon: marker.lon,
                    title: marker.title || "Untitled"
                });
            }
        }

        if (markersModel.count > 0) {
            map.center = QtPositioning.coordinate(markersModel.get(0).lat, markersModel.get(0).lon);
            map.zoomLevel = 8;
        }
    }
}
