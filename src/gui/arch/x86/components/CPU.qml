import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import App

Item {
  required property var model;

  id: root

  component Register : RowLayout {
    property string caption;
    property var value;
    property var size: 8;

    id: rootRegister
    implicitHeight: captionId.height + valueId.height

    function reset() {
      captionId.color = "black";
      valueId.color = "black";
    }

    Text {
      id: captionId
      text: rootRegister.caption
      horizontalAlignment: Text.AlignRight
      font.family: "monospace"
      font.pointSize: 14
    }

    Text {
      id: valueId
      text: rootRegister.value.toString(16).padStart(rootRegister.size, "0")
      font.family: "monospace"
      font.pointSize: 14
    }

    onValueChanged: {
      if (inner.isTouched && rootRegister.value !== inner.savedValue) {
        valueId.color = "red";
      }
      inner.isTouched = true;
      inner.savedValue = rootRegister.value;
    }

    QtObject {
      id: inner
      property bool isTouched: false;
      property var savedValue: 0;
    }
  }

  component Flag : ColumnLayout {
    property string caption;
    property string tooltip;
    property var value;

    id: rootFlag

    Text {
      text: rootFlag.caption
      horizontalAlignment: Text.AlignRight
      font.family: "monospace"
      ToolTip.text: rootFlag.tooltip
    }

    Text {
      text: Number(rootFlag.value)
      font.family: "monospace"
    }
  }

  ColumnLayout {
    spacing: Theme.spacing(2)

    ColumnLayout {
      Register{
        id: eaxId
        caption: "EAX"
        value: root.model.eax
      }

      Register{
        caption: "EBX"
        value: root.model.ebx
      }

      Register{
        caption: "ECX"
        value: root.model.ecx
      }

      Register{
        caption: "EDX"
        value: root.model.edx
      }
    }

    ColumnLayout {
      Register{
        caption: "ESI"
        value: root.model.esi
      }

      Register{
        caption: "EDI"
        value: root.model.edi
      }

      Register{
        caption: "EBP"
        value: root.model.ebp
      }

      Register{
        caption: "ESP"
        value: root.model.esp
      }
    }

    ColumnLayout {
      Register{
        caption: "CS"
        value: root.model.cs
        size: 4
      }

      Register{
        caption: "DS"
        value: root.model.ds
        size: 4
      }

      Register{
        caption: "SS"
        value: root.model.ss
        size: 4
      }

      Register{
        caption: "ES"
        value: root.model.es
        size: 4
      }

      Register{
        caption: "FS"
        value: root.model.fs
        size: 4
      }

      Register{
        caption: "GS"
        value: root.model.gs
        size: 4
      }
    }

    Button {
      text: "Tick"
      onClicked: () => {
        eaxId.reset();
        root.model.tick();
      }
    }
  }
}

