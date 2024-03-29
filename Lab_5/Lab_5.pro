QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    csv_reader.cpp \
    csv_writer.cpp \
    employee.cpp \
    main.cpp \
    mainwindow.cpp \
    my_text_class.cpp

HEADERS += \
    csv_reader.h \
    csv_writer.h \
    employee.h \
    mainwindow.h \
    my_text_class.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
