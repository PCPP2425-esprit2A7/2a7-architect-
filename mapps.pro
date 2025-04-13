QT       += core gui sql printsupport charts quick quickwidgets location positioning

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    connexion.cpp \
    dashbord.cpp \
    formation.cpp \
    main.cpp \
    mainwindow.cpp \
    map.cpp \
    modifier.cpp \
    supp.cpp

HEADERS += \
    connexion.h \
    dashbord.h \
    formation.h \
    mainwindow.h \
    map.h \
    modifier.h \
    supp.h

FORMS += \
    dashbord.ui \
    mainwindow.ui \
    map.ui \
    modifier.ui \
    supp.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    img.qrc \
    ressources.qrc

DISTFILES += \
    map.qml
