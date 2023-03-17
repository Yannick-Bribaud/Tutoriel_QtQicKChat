#ifndef MESSAGE_H
#define MESSAGE_H
#include <QQuickItem>

class Message : public QQuickItem
{
    Q_OBJECT
    Q_PROPERTY(QString message MEMBER message_)
    Q_PROPERTY(QString emetteur MEMBER emetteur_)

public:
    Message();
    ~Message();
    Message(const QString& message, const QString& emetteur);
    Message(const Message& orig);
    Message& operator=(const Message& orig);

    QString getMessage() const;
    QString getEmetteur() const;

private:
    QString message_;
    QString emetteur_;

};
Q_DECLARE_METATYPE(Message)

QDebug operator<<(QDebug debug, const Message& message);


#endif // MESSAGE_H
