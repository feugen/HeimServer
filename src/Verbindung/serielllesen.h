#ifndef SERIELLLESEN_H
#define SERIELLLESEN_H
#include <boost/asio.hpp>
#include <map>
#include "ext/json/json.hpp"


class SeriellLesen{
private:
    boost::asio::serial_port *serVer;
public:
    SeriellLesen(boost::asio::serial_port &a);
    boost::asio::serial_port* ladeVerbindung();
    std::string arduinoAuslesen();
};

#endif // SERIELLLESEN_H
