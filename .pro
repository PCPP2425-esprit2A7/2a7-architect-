# Nom du projet
TARGET = 000

# Type de projet (application Qt)
QT += core gui widgets sql printsupport charts


# Fichiers sources
SOURCES += main.cpp \
           NotificationService.cpp \
           dashbord.cpp \
           formation.cpp \
           mainwindow.cpp \
           connexion.cpp \
           modifier.cpp \
           supp.cpp


# Fichiers d'en-tête
HEADERS += mainwindow.h \
    NotificationService.h \
    connexion.h \
    dashbord.h \
    formation.h \
    modifier.h \
    supp.h

# Fichiers d'interface utilisateur (UI)
FORMS += mainwindow.ui \
    dashbord.ui \
    modifier.ui \
    supp.ui

# Fichiers de ressources
RESOURCES += img.qrc
