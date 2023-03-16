#ifndef CONTROLEURRESEAU_H
#define CONTROLEURRESEAU_H

#include <QObject>
#include <QUdpSocket>
#include <QNetworkInterface>
#include <QUuid>
#include "JsonHelper.h"
#include "Message.h"

class ControleurReseau : public QObject
{
    Q_OBJECT

public:
    explicit ControleurReseau(QObject *parent = nullptr);

public slots:
    void demarre();
    void envoieMessage(const QString& message);

signals:
    void message(Message* message);
    void erreur(const QString& erreur);

private:
    inline bool isLocal(const QByteArray& msg) const {
        return JsonHelper::extraitUUid(msg) == uuid_.toString();
    }

private:
    QUdpSocket *socket_ = nullptr;
    QUuid uuid_;
};

#endif // CONTROLEURRESEAU_H
