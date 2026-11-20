#pragma once
#include <QObject>
#include <QtQmlIntegration/qqmlintegration.h>

namespace gui::utils {

class Theme : public QObject
{
  Q_OBJECT
  QML_SINGLETON
  QML_ELEMENT

public:
    Theme(QObject *parent = nullptr)
      : QObject(parent)
    {}


    Q_INVOKABLE int spacing(double k = 1) {
      const int size = 8;
      return static_cast<int>(size * k);
    }
};

}
