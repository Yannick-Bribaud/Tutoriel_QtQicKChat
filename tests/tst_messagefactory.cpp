#include <QtTest>
#include "MessageFactory.h"
#include "Message.h"

class MessageFactoryTest : public QObject
{
    Q_OBJECT

public:
    MessageFactoryTest();
    ~MessageFactoryTest();

private slots:
    void test_creeMessage();

};


MessageFactoryTest::MessageFactoryTest(){}

MessageFactoryTest::~MessageFactoryTest(){}

void MessageFactoryTest::test_creeMessage(){

    QString données("{\n    \"message\": \"Bonjour !\",\n    \"uuid\": \"{9542229c-d70b-4bf6-b479-546969b5eb57}\"\n}\n");
    Message msg = MessageFactory::creeMessage(données.toUtf8());
    QCOMPARE(msg.getMessage(), "Bonjour !");
    QCOMPARE(msg.getEmetteur(), "{9542229c-d70b-4bf6-b479-546969b5eb57}");
}
#include "tst_messagefactory.moc"
