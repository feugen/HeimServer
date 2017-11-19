#ifndef ARDUINO_H
#define ARDUINO_H
#include "src/Verbindung/serielllesen.h"

class Arduino: public Seriell{
private:

public:
    Arduino(boost::asio::serial_port &SerielleVerbindung);
};

#endif // ARDUINO_H
