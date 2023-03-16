#ifndef MESSAGEFACTORY_H
#define MESSAGEFACTORY_H

class QByteArray;
class Message;

class MessageFactory {
public:
    static Message creeMessage(const QByteArray& données);

private:
    MessageFactory() {}
};

#endif // MESSAGEFACTORY_H
