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

    //On instancie le traducteur
    QTranslator translator;
    //On récupère la langue courante du système
    QString langue = QLocale::system().name().split("_")[0];
    qDebug() << "chargement de la langue" << langue;

    //On charge le fichier de langue correspondant à la langue du système
    if(!translator.load(QString(":/%1.qm").arg(langue))) {
        qWarning() << "Les traductions n'ont pas été chargées";

    }else{
        //On installe les nouvelles traductions
        app.installTranslator(&translator);
    }
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
