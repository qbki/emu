import QtQuick
import App

Window {
    width: 640
    height: 480
    visible: true
    title: "qbki-emu"

    CPUModel {
      id: cpu_model
    }

    CPU {
      model: cpu_model
    }
}
