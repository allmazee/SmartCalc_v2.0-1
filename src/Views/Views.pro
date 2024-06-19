QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

CONFIG += c++11
TARGET = SmartCalc_2_0

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    ../Models/calculator_model.cpp\
    ../Controllers/calculator_controller.cpp\
    ../Models/credit_model.cpp\
    ../Controllers/credit_controller.cpp\
    creditwindow.cpp \
    main.cpp \
    mainwindow.cpp \
    plotwindow.cpp \
    qcustomplot.cpp

HEADERS += \
    ../Controllers/calculator_controller.h\
    ../Models/calculator_model.h\
    ../Models/credit_model.h\
    ../Controllers/credit_controller.h\
    creditwindow.h \
    mainwindow.h \
    plotwindow.h \
    qcustomplot.h

FORMS += \
    creditwindow.ui \
    mainwindow.ui \
    plotwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
