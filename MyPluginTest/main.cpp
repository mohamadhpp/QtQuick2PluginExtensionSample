#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include <QtQml/qqmlextensionplugin.h>

Q_IMPORT_QML_PLUGIN(MyPluginPlugin)

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreationFailed,
        &app, []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);
    engine.loadFromModule("MyPluginTest", "Main");

    return app.exec();
}
