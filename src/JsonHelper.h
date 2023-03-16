#ifndef JSONHELPER_H
#define JSONHELPER_H

#include <QJsonDocument>
#include <QJsonObject>
#include <QString>

class Message;

class JsonHelper {
public:
    static QString extraitJson(const QByteArray& msg, const QString& clé);
    static QString extraitUUid(const QByteArray& msg);
    static QString extraitMessage(const QByteArray& msg);
    static QString formatteMessage(const Message& message);

private:
    JsonHelper() {}
};

#endif // JSONHELPER_H
