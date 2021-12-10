#-------------------------------------------------
#
# Project created by QtCreator 2018-10-26T21:45:23
#
#-------------------------------------------------

QT       += core gui sql
QT       += network
QT       += core gui charts
QT       += printsupport
QT       += core gui multimedia multimediawidgets
QT       +=svg
QT       += core gui  serialport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Atelier_Connexion
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
    arduino.cpp \
    caisse.cpp \
    client.cpp \
    dumessengerconnectiondialog.cpp \
    employers.cpp \
    fournisseur.cpp \
    historique_nourhene.cpp \
    historique_wajdi.cpp \
        main.cpp \
        mainwindow.cpp \
    connection.cpp \
    notification.cpp \
    notification_nourhene.cpp \
    notification_samar.cpp \
    produit.cpp \
    qrcode.cpp \
    reservation.cpp \
    service.cpp \
    smtp.cpp

HEADERS += \
    arduino.h \
    caisse.h \
    client.h \
    dumessengerconnectiondialog.h \
    employers.h \
    fournisseur.h \
    historique_nourhene.h \
    historique_wajdi.h \
        mainwindow.h \
    connection.h \
    notification.h \
    notification_nourhene.h \
    notification_samar.h \
    produit.h \
    qrcode.h \
    reservation.h \
    service.h \
    smtp.h

FORMS += \
        dumessengerconnectiondialog.ui \
        mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    historique

RESOURCES += \
    img.qrc \
    sound.qrc \
    traduction.qrc
