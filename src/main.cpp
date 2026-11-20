#include <print>

#include <QGuiApplication>
#include <QQmlApplicationEngine>

int main(int argc, char* argv[]) {
  qputenv("QT_QPA_PLATFORM", "xcb");
  qputenv("FONTCONFIG_PATH", "/etc/fonts");

  QGuiApplication app(argc, argv);
  QQmlApplicationEngine engine;
  const QUrl url(QStringLiteral("qrc:/qt/qml/App/src/gui/Main.qml"));

  QObject::connect(&engine,
                   &QQmlApplicationEngine::objectCreationFailed,
                   &app,
                   []() {
                     std::println("Can't create a window");
                     QCoreApplication::exit(-1);
                   },
                   Qt::QueuedConnection);

  engine.load(url);

  return app.exec();

}
