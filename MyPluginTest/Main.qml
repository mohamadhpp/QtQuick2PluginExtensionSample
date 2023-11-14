import QtQuick
import QtQuick.Window

import MyPlugin

Window
{
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    MyItemControls
    {
        anchors.left: parent.left
        anchors.top: parent.top

        anchors.margins: 20

        width: 100
        height: 100
    }
}
