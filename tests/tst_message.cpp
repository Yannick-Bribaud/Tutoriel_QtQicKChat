#include <QTest>
#include "Message.h"

class MessageTest : public QObject
{
    Q_OBJECT

public:
    MessageTest();
    ~MessageTest();

private slots:
    void test_constructeur();

};

MessageTest::MessageTest(){}

MessageTest::~MessageTest(){}

void MessageTest::test_constructeur(){
    Message msg;
    QCOMPARE(msg.getMessage(),"");
    QCOMPARE(msg.getEmetteur(),"");

    Message msg2("message","émetteur");
    QCOMPARE(msg2.getMessage(),"message");
    QCOMPARE(msg2.getEmetteur(),"émetteur");

}
#include "tst_message.moc"


