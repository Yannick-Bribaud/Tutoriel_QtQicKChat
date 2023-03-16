#include "ControleurReseau.h"
#include <QNetworkDatagram>
#include "MessageFactory.h"
#include "Message.h"

#define UDP_PORT 55423

ControleurReseau::ControleurReseau(QObject *parent)
    : QObject{parent}
    , socket_(new QUdpSocket{this})
{
    //On crée un Uuid pour cet appareil, l'Uuid permettra
    //d'itentifier et de différencier les différents
    //émetteurs dans la session de chat
    uuid_ = QUuid::createUuid();
    qDebug() << "UUID = " << uuid_.toString();
}

void ControleurReseau::demarre()
{
    //On tente d'ouvrir une socket UDP
    //Le mode ShareAddress nous permet de réutiliser le même port
    //et de faire tourner plusieurs chats sur la même machine
    if(!socket_->bind(UDP_PORT, QUdpSocket::ShareAddress)) {
        qDebug() << socket_->error();
        emit erreur(tr("Ouverture socket UDP impossible"));
        return;
    }

    qDebug() << "Socket UDP ouverte";

    //On se connecte au signal de réception de données sur la socket
    connect(socket_, &QUdpSocket::readyRead, [=] {
        //Si des données sont reçues, ce slot sera exécuté
        //Les données arrivant sur la socket UDP sont des datagrammes
        QNetworkDatagram datagram;

        //Tant qu'il y a des datagrammes dans le tampon
        while(socket_->hasPendingDatagrams()) {
            //On lit le prochain datagramme
            datagram = socket_->receiveDatagram();

            //S'il est valide et non-vide
            if(datagram.isValid() && !datagram.data().isEmpty()) {
                //On vérifie si le datagramme ne provient de notre propre session de chat
                if(!isLocal(datagram.data())) {
                    qDebug() << "Réception d'un message de " << JsonHelper::extraitUUid(datagram.data()) << " : " << datagram.data();

                    //On dé-sérialise le message reçu...
                    Message msg = MessageFactory::creeMessage(datagram.data());

                    //Puis on l'affiche dans la log
                    qDebug() << msg;

                    //Et on l'envoie dans un signal pour l'affichage
                    emit message(&msg);
                }
            }
        }

    });
}

void ControleurReseau::envoieMessage(const QString &message)
{
    qDebug() << "Envoi d'un message";
    //On instancie une socket UDB
    QUdpSocket socket;
    //On écrit directement les données dans la socket
    //L'objet message est sérialisé pour être écrit sous forme
    //de chaines de caractères directement sur la socket
    socket.writeDatagram(JsonHelper::formatteMessage(Message{message, uuid_.toString()}).toUtf8(), QHostAddress::Broadcast, UDP_PORT);
}
