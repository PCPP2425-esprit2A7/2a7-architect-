QT       += core gui sql widgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    connexion.cpp \
    gestion_projet.cpp \
    main.cpp \
    mainwindow.cpp \
    modifier.cpp

HEADERS += \
    connexion.h \
    gestion_projet.h \
    mainwindow.h \
    modifier.h

FORMS += \
    mainwindow.ui \
    modifier.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    res.qrc \
    ress.qrc \
    form_icons.qrc

# Copier le dossier styles dans le répertoire de build
styles.path = $$OUT_PWD/styles
styles.files = styles/*
QMAKE_EXTRA_TARGETS += styles
PRE_TARGETDEPS += styles
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target styles
