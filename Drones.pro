#-------------------------------------------------
#
# Project created by QtCreator 2016-06-24T09:26:30
#
#-------------------------------------------------

QT       += core \
                  gui \
                  charts \
                  sql \

!MobileBuild {4
QT += \
    printsupport \
}

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Drones
TEMPLATE = app

SOURCES += main.cpp\
        mainwindow.cpp \
    LogDisplay/LogWidget.cpp \
    LogDisplay/Callout.cpp \
    QuadApplication.cpp \
    LogDisplay/chartView.cpp \
    LogDisplay/LogAnalysis.cpp


HEADERS  += mainwindow.h \
    LogDisplay/basic_types.h \
    LogDisplay/messages.h \
    LogDisplay/sdfiles.h \
    LogDisplay/LogAnalysis.h \
    LogDisplay/chartView.h \
    LogDisplay/LogWidget.h \
    LogDisplay/Callout.h \
    QuadApplication.h

FORMS    += mainwindow.ui \
    LogWidget.ui

UI_DIR  += E:/baseModule-12.21


