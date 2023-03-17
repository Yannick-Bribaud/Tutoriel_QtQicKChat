#include "tst_message.cpp"
#include "tst_messagefactory.cpp"

int main(int argc, char** argv) {
    MessageTest messageTest;
    int resultat = QTest::qExec(&messageTest, argc, argv);

    MessageFactoryTest messageFactoryTest;
    resultat &= QTest::qExec(&messageFactoryTest, argc, argv);
    return resultat;
}
