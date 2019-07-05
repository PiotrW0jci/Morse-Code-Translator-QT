import QtQuick 2.10
import QtQuick.Window 2.10
import QtQuick.Dialogs 1.2
import QtQuick.Controls 2.5
import QtGraphicalEffects 1.10



Window {
    visible: true
    width: 640
    height: 480
    color: "#303f9f"
    title: qsTr("Morse Code translator")
    signal submitTextField(string text)

    Rectangle
    {
                anchors.fill: parent

                gradient: Gradient{

                GradientStop {position: 0.266;color: "#330867"}
                GradientStop {position: 1.000;color: "#30cfd0"}

                //GradientStop {position: 1.000;color: Qt.rgba(1, 0, 0, 1);}

            }
}
    Text {
        id: mainText
        x: 153
        y: 53
        color: "#ffffff"
        text: qsTr("Morse Code Translator")
        font.italic: true
        font.bold: true
        font.family: "Courier"
        horizontalAlignment: Text.AlignHCenter
        font.pixelSize: 30
    }

    Text {
        id: text2
        x: 38
        y: 241
        color: "#ffffff"
        text: qsTr("or load file")
        textFormat: Text.PlainText
        font.bold: true
        font.weight: Font.Normal
        font.capitalization: Font.MixedCase
        font.pixelSize: 16
    }

    Button {
        x: 38
        y: 270
        text: "Load"
        wheelEnabled: false
        autoRepeat: false
        flat: false
        font.weight: Font.Medium
        focusPolicy: Qt.StrongFocus
        highlighted : true
        onClicked: openFileDialog.open()
    }

    Button {
        x: 38
        y: 422
        text: "Save"
        highlighted : true
        onClicked: saveFileDialog.open()

    }
    Button {
        x: 173
        y: 270
        text: "Translate"
        highlighted : true
        onClicked: submitTextField(intputText.text)
    }
    function openFile(fileUrl) {
        var request = new XMLHttpRequest();
        request.open("GET", fileUrl, false);
        request.send(null);
        return request.responseText;
    }

    function saveFile(fileUrl, text) {
        var request = new XMLHttpRequest();
        request.open("PUT", fileUrl, false);
        request.send(text);
        return request.status;
    }
    function setTextField(text){
        console.log("setTextField: " + text)
        outputText.text = text
    }

    FileDialog {
        id: openFileDialog
        title: "Please choose a file"
        folder: shortcuts.home
        nameFilters: [ "Text file (*.txt)", "All files (*)" ]
        onAccepted:  intputText.text=openFile(fileUrl);

    }


    FileDialog {
        id: saveFileDialog
        selectExisting: false
        folder: shortcuts.home
        nameFilters: ["Text files (*.txt)", "All files (*)"]
        onAccepted: saveFile(saveFileDialog.fileUrl, outputText.text)
    }

    Rectangle {
        id: rectangle
        x: 38
        y: 150
        width: 577
        height: 85
        border.color: "#3232CD"
        border.width: 1
         color: "#2F2F4F"
         ScrollView {
             anchors.fill: parent
        TextArea {
            id: intputText
            x: 0
            y: 2
            width: 577
            height: 81
            color: "white"
            text:""

        }
    }
    }



    Rectangle {
        id: rectangle1
        x: 38
        y: 316
        width: 585
        height: 86
        color: "#2F2F4F"
        border.color: "#3232CD"
        border.width: 1
        ScrollView {
            anchors.fill: parent
        TextArea {
            id: outputText
            x: 0
            y: 0
            width: 585
            height: 86
            readOnly : true
            color: "white"
            text:""
            }
        }
    }

    Text {
        id: text3
        x: 38
        y: 121
        color: "#ffffff"
        text: qsTr("Enter the text below")
        font.capitalization: Font.MixedCase
        textFormat: Text.PlainText
        font.bold: true
        font.weight: Font.Normal
        font.pixelSize: 16
    }


    }





