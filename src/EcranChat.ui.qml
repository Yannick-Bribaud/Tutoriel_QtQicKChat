import QtQuick 6.2
import QtQuick.Controls 6.2
import net.alefbet 1.0

Rectangle {
    width: 400
    height: 800

    property alias saisie: saisie
    property alias echangesModel: echangesModel
    property alias echangeDelegate: echangeDelegate

    ListModel {
        id: echangesModel
    }

    Rectangle {
        id: echanges
        anchors {

            top: parent.top
            bottom: rect_saisie.top
            bottomMargin: width / 50
            left: parent.left
            right: parent.right
        }

        color: "#303342"

        ListView {
            id: listeEchanges
            anchors.fill: parent

            model: echangesModel
            delegate: echangeDelegate
            spacing: 10

            Component {
                id: echangeDelegate

                Rectangle {
                    id: wrapper
                    width: listeEchanges.width
                    height: txt.paintedHeight * 2
                    radius: 10

                    color: emetteur === "local" ? "#c7cffc" : "#c7fcd6"

                    Text {
                        id: txt
                        anchors.fill: parent
                        anchors.leftMargin: 10
                        anchors.rightMargin: 10
                        text: texte
                        verticalAlignment: Qt.AlignVCenter
                        horizontalAlignment: emetteur === "local" ? Qt.AlignRight : Qt.AlignLeft
                        wrapMode: TextEdit.WordWrap
                        font.pixelSize: 20
                    }

                }
            }

        }
    }

    Rectangle {
        id: rect_saisie

        border {
            color: "black"
            width: 4
        }
        anchors {
            bottom: parent.bottom
            left: parent.left
            right: parent.right
            margins: width / 50
        }
        radius: height / 5
        height: parent.height / 10

        ScrollView {
            anchors.fill: parent
            TextArea {
                id: saisie
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                font.pointSize: rect_saisie.height * 0.3
                text: ""
                padding: 10
                cursorVisible: true
                wrapMode: TextEdit.WordWrap
            }
        }
    }

}
