# Nom du projet
TARGET = Gclient

# Type de projet (application Qt)
QT += core gui widgets sql printsupport charts network


# Fichiers sources
SOURCES += main.cpp \
           clientmanager.cpp \
           connexion.cpp \
           gclinet.cpp

# Fichiers d'en-tête
HEADERS += gclinet.h \
    clientmanager.h \
    connexion.h

# Fichiers d'interface utilisateur (UI)
FORMS += gclinet.ui

# Fichiers de ressources
RESOURCES += img.qrc
