# Nom du projet
TARGET = 000

# Type de projet (application Qt)
QT += core gui widgets sql printsupport


# Fichiers sources
SOURCES += main.cpp \
           formation.cpp \
           mainwindow.cpp \
           connexion.cpp \
           modifier.cpp \
           supp.cpp
          

# Fichiers d'en-tête
HEADERS += mainwindow.h \
    connexion.h \
    formation.h \
    modifier.h \
    supp.h

# Fichiers d'interface utilisateur (UI)
FORMS += mainwindow.ui \
    modifier.ui \
    supp.ui

# Fichiers de ressources
RESOURCES += img.qrc
