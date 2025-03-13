# Nom du projet
TARGET = Gclient

# Type de projet (application Qt)
QT += core gui widgets sql printsupport

# Fichiers sources
SOURCES += main.cpp \
           clientmanager.cpp \
           connexion.cpp \
           gclinet.cpp \
           modifc.cpp \
           supp.cpp

# Fichiers d'en-tête
HEADERS += gclinet.h \
    clientmanager.h \
    connexion.h \
    modifc.h \
    supp.h

# Fichiers d'interface utilisateur (UI)
FORMS += gclinet.ui \
    modifc.ui \
    supp.ui

# Fichiers de ressources
RESOURCES += img.qrc
