#ifndef SERIELLLESEN_H
#define SERIELLLESEN_H
#include <boost/asio.hpp>
#include <map>
#include "ext/json/json.hpp"


class Seriell{
private:
    boost::asio::serial_port *serVer;
public:
    Seriell(boost::asio::serial_port &a);
    boost::asio::serial_port* ladeVerbindung();
    //Pure virtual, Definition in Arduino Klasse
    virtual std::string arduinoAuslesen()=0;
};

#endif // SERIELLLESEN_H
