QT += quick network

SOURCES += \
        ControleurReseau.cpp \
        JsonHelper.cpp \
        Message.cpp \
        MessageFactory.cpp \
        main.cpp

resources.files = App.qml Chat.qml Participants.qml EcranChat.ui.qml EcranParticipants.ui.qml qtquickcontrols2.conf
resources.prefix = /$${TARGET}
RESOURCES += resources

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    ControleurReseau.h \
    JsonHelper.h \
    Message.h \
    MessageFactory.h

DISTFILES += \
    App.qml \
    Chat.qml \
    EcranChat.ui.qml \
    EcranParticipants.ui.qml \
    Participants.qml \
    qtquickcontrols2.conf

FORMS +=
