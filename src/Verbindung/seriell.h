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
    std::string arduinoAuslesen();
};

#endif // SERIELLLESEN_H