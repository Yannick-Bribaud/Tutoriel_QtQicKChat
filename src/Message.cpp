#include "Message.h"
#include <QDebug>

Message::Message() {}
Message::~Message() { }

Message::Message(const QString& message, const QString& emetteur)
    : QQuickItem{}, message_(message), emetteur_(emetteur) { }

Message::Message(const Message& orig)
    : QQuickItem{}, message_(orig.message_), emetteur_(orig.emetteur_) { }

Message& Message::operator=(const Message& orig) {
    message_ = orig.message_;
    emetteur_ = orig.emetteur_;

    return *this;
}

QString Message::getMessage() const {
    return message_;
}

QString Message::getEmetteur() const {
    return emetteur_;
}

QDebug operator<<(QDebug debug, const Message& message)
{
    //Cette fonction permet de sérialiser l'objet message dans la log
    //à des fins de débogage
    QDebugStateSaver saver(debug);
    debug << QString("Message { message: %1, emetteur: %2").arg(message.getMessage(), message.getEmetteur());
    return debug;
}
