TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    datenbank.cpp \
    mariadb.cpp \
    sqlite.cpp \
    statistik.cpp \
    einstellungen.cpp \
    logging.cpp \
    verbindung.cpp \
    bluetooth.cpp \
    nfs.cpp \
    tcpip.cpp \
    wetter.cpp \
    arduino.cpp \
    openweather.cpp \
    ueberwachung.cpp \
    alarm.cpp \
    anwesenheit.cpp \
    bewegungsmelder.cpp \
    video.cpp \
    heimserver.cpp

HEADERS += \
    datenbank.h \
    mariadb.h \
    sqlite.h \
    statistik.h \
    einstellungen.h \
    logging.h \
    verbindung.h \
    bluetooth.h \
    nfs.h \
    tcpip.h \
    wetter.h \
    arduino.h \
    openweather.h \
    ueberwachung.h \
    alarm.h \
    anwesenheit.h \
    bewegungsmelder.h \
    video.h
