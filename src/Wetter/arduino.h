#ifndef ARDUINO_H
#define ARDUINO_H
#include "src/Verbindung/seriell.h"

class Arduino: public Seriell{
private:

public:
    Arduino(boost::asio::serial_port &SerielleVerbindung);
    std::string arduinoAuslesen();
};

#endif // ARDUINO_H
