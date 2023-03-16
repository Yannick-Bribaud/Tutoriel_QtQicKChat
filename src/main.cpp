#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QTranslator>
#include "ControleurReseau.h"
#include "Message.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    //On expose la classe C++ Message comme Type QML
    qmlRegisterType<Message>("net.alefbet", 1, 0, "Message");

    //On instancie le contrôleur réseau
    //Et on l'expose comme Type QML en Singleton
    ControleurReseau controleurReseau;
    qmlRegisterSingletonInstance("net.alefbet", 1, 0, "ControleurReseau", &controleurReseau);

    QQmlApplicationEngine engine;
    const QUrl url(u"qrc:/src/App.qml"_qs);
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
