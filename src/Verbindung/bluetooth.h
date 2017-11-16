#ifndef BLUETOOTH_H
#define BLUETOOTH_H
#include "verbindung.h"
#include <boost/asio.hpp>

class Bluetooth{
private:
    //Wie in Einstellungen.h
    struct serielverbindung{
        //Serieller Port
        std::string serielPfad;
        std::string serielNeueZeile;
        signed int serielPort;
    }seriel;
public:
    Bluetooth(Verbindung const &a);
    void verbindungAufbauen() const;
};

#endif // BLUETOOTH_H
