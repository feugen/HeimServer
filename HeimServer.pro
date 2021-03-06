TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

LIBS += -L/usr/lib/x86_64-linux-gnu -lboost_system -lsqlite3

SOURCES += \
    src/Datenbank/datenbank.cpp \
    src/Datenbank/statistik.cpp \
    src/Einstellungen/einstellungen.cpp \
    src/Einstellungen/logging.cpp \
    src/Verbindung/verbindung.cpp \
    src/Verbindung/tcpip.cpp \
    src/Verbindung/seriell.cpp \
    src/Verbindung/validierung.cpp \
    src/Wetter/arduino.cpp \
    src/Wetter/openweather.cpp \
    src/Ueberwachung/ueberwachung.cpp \
    src/Ueberwachung/alarm.cpp \
    src/Ueberwachung/anwesenheit.cpp \
    src/Ueberwachung/bewegungsmelder.cpp \
    src/Ueberwachung/video.cpp \
    heimserver.cpp \
    src/Wetter/dwd.cpp


HEADERS += \
    src/Datenbank/datenbank.h \
    src/Datenbank/statistik.h \
    src/Einstellungen/einstellungen.h \
    src/Einstellungen/logging.h \
    src/Verbindung/verbindung.h \
    src/Verbindung/tcpip.h \
    src/Verbindung/seriell.h \
    src/Verbindung/validierung.h \
    src/Wetter/arduino.h \
    src/Wetter/openweather.h \
    src/Ueberwachung/ueberwachung.h \
    src/Ueberwachung/alarm.h \
    src/Ueberwachung/anwesenheit.h \
    src/Ueberwachung/bewegungsmelder.h \
    src/Ueberwachung/video.h \
    ext/json/json.hpp \
    src/Wetter/dwd.h
