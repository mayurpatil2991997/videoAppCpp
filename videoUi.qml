import QtQuick 2.15
import QtQuick.Controls 2.15
import com.company.mainwindow 1.0


ApplicationWindow  {
    title: "Video"
    color: "black"

//MainWindow {
//   id: mainwindow
//}

Row {
    anchors.top: parent.top
    anchors.topMargin: 8
    anchors.horizontalCenterOffset: 0
    anchors.horizontalCenter: parent.horizontalCenter
    spacing: 3

    Button {
        id: btnUpload
        anchors.centerIn: parent
        text: "Upload"
//        onClicked: mainwindow.on_actionOpen_triggered()
    }
    Button {
        id: btnPlay
        anchors.centerIn: parent
        text: "Play"
//        onClicked: mainwindow.on_actionPlay_triggered()
    }
    Button {
        id: btnPause
        anchors.centerIn: parent
        text: "Pause"
//        onClicked: mainwindow.on_actionPause_triggered()
    }
    Button {
        id: btnStop
        anchors.centerIn: parent
        text: "Stop"
//        onClicked: mainwindow.on_actionStop_triggered()
    }
}
}
