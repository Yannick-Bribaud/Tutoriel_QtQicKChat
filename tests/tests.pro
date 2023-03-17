CONFIG += warn_on qmltestcase

TEMPLATE = app

QT += quick network testlib qmltest

DISTFILES += \
    tst_testhelper.qml

SOURCES += \
    ../src/ControleurReseau.cpp \
    ../src/JsonHelper.cpp \
    ../src/Message.cpp \
    ../src/MessageFactory.cpp \
    tst_message.cpp \
    tst_messagefactory.cpp \
    tst_suite.cpp

HEADERS += \
    ../src/ControleurReseau.h \
    ../src/JsonHelper.h \
    ../src/Message.h \
    ../src/MessageFactory.h


INCLUDEPATH += ../src
