import QtQuick 6.2
import QtQuick.Controls 6.2

Rectangle {
    width: 400
    height: 800

    property alias participantsModel: participantsModel
    property var clientsConnus: []

    ListModel {
        id: participantsModel
    }

    ListView {
        id: liste
        anchors.fill: parent
        spacing: 10
        model: participantsModel

        delegate: Item {
            id: wrapper
            height: 40
            width: liste.width

            Rectangle {
                anchors.fill: wrapper
                color: type === "local" ? "#c7cffc" : "#c7fcd6"

                Text {
                    text: nom
                    padding: 10
                    anchors.fill: parent
                    width: liste.width
                    font.pixelSize: height
                    fontSizeMode: Text.HorizontalFit
                    verticalAlignment: Qt.AlignVCenter
                    horizontalAlignment: Qt.AlignLeft
                }
            }
        }
    }
}
