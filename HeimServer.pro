TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    src/Datenbank/datenbank.cpp \
    src/Datenbank/mariadb.cpp \
    src/Datenbank/sqlite.cpp \
    src/Datenbank/statistik.cpp \
    src/Einstellungen/einstellungen.cpp \
    src/Logging/logging.cpp \
    src/Verbindung/verbindung.cpp \
    src/Verbindung/bluetooth.cpp \
    src/Verbindung/nfs.cpp \
    src/Verbindung/tcpip.cpp \
    src/Wetter/wetter.cpp \
    src/Wetter/arduino.cpp \
    src/Wetter/openweather.cpp \
    src/Ueberwachung/ueberwachung.cpp \
    src/Ueberwachung/alarm.cpp \
    src/Ueberwachung/anwesenheit.cpp \
    src/Ueberwachung/bewegungsmelder.cpp \
    src/Ueberwachung/video.cpp \
    heimserver.cpp

HEADERS += \
    src/Datenbank/datenbank.h \
    src/Datenbank/mariadb.h \
    src/Datenbank/sqlite.h \
    src/Datenbank/statistik.h \
    src/Einstellungen/einstellungen.h \
    src/Logging/logging.h \
    src/Verbindung/verbindung.h \
    src/Verbindung/bluetooth.h \
    src/Verbindung/nfs.h \
    src/Verbindung/tcpip.h \
    src/Wetter/wetter.h \
    src/Wetter/arduino.h \
    src/Wetter/openweather.h \
    src/Ueberwachung/ueberwachung.h \
    src/Ueberwachung/alarm.h \
    src/Ueberwachung/anwesenheit.h \
    src/Ueberwachung/bewegungsmelder.h \
    src/Ueberwachung/video.h \
    ext/json/json.hpp
