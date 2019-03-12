#-------------------------------------------------
#
# Project created by QtCreator 2019-03-12T16:31:16
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ThefirstApp
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui

#Add INCLUDE Path outside project folder
INCLUDEPATH += \
            ../Dialog

#solve error: undefined reference
LIBS += \
        /home/rk42/Qt_Workspace/QtLearning/FoundationOfQtDevelopmentBook/build-FoundationOfQtDevelopmentBook-Desktop_Qt_5_7_0_GCC_64bit-Debug/Dialog/dialog.o \
        /home/rk42/Qt_Workspace/QtLearning/FoundationOfQtDevelopmentBook/build-FoundationOfQtDevelopmentBook-Desktop_Qt_5_7_0_GCC_64bit-Debug/Dialog/moc_dialog.o \
