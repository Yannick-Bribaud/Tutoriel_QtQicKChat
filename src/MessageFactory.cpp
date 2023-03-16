#include "MessageFactory.h"
#include "Message.h"
#include "JsonHelper.h"

Message MessageFactory::creeMessage(const QByteArray& données) {
    //Cette fonction crée une nouvelle instance de la classe Message
    //à partir de données brutes
    QString msg = JsonHelper::extraitMessage(données);
    QString emetteur = JsonHelper::extraitUUid(données);

    return Message{msg, emetteur};
}
