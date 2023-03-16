#include "JsonHelper.h"
#include "Message.h"

QString JsonHelper::extraitJson(const QByteArray& msg, const QString& clé) {
    //On récupère les éventuelles erreurs d'interprétation dans cette variable
    QJsonParseError erreur;

    //On instancie un document JSON et on interprête les données brutes
    QJsonDocument json = QJsonDocument::fromJson(msg, &erreur);

    //S'il n'y a pas eu d'erreur d'interprétation
    if(erreur.error == QJsonParseError::NoError) {
        //On récupère la racine du document JSON
        QJsonObject jsonMsg = json.object();
        if(jsonMsg.contains(clé)) {
            //Si le document contient la clé recherchée
            //on retourne sa valeur
            return jsonMsg[clé].toString();
        } else {
            qDebug() << "La clé" << clé << "n'a pas été trouvée";
        }
    } else {
        qDebug() << "Erreur de décodage du message : " << erreur.errorString();
    }

    //Par défaut, on retourne une chaine vide
    return QString();
}

QString JsonHelper::extraitUUid(const QByteArray& msg) {
    return extraitJson(msg, "uuid");
}

QString JsonHelper::extraitMessage(const QByteArray& msg) {
    return extraitJson(msg, "message");
}

QString JsonHelper::formatteMessage(const Message& message) {
    QJsonObject jsonMsg;
    jsonMsg["uuid"] = message.getEmetteur();
    jsonMsg["message"] = message.getMessage();

    return QJsonDocument(jsonMsg).toJson();
}
