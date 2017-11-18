#include "verbindung.h"

Verbindung::Verbindung(Einstellungen const &a){
    onlineDatenquelle = a.onlineDatenquelleLaden();
    seriellStVec = a.serielleVerbindungLaden();
}

std::vector<struct seriellStruct> Verbindung::ladeSerielleVerbindung() const{
    return seriellStVec;
}

std::string Verbindung::ladeOnlineDatenquelle() const{
    return onlineDatenquelle;
}

boost::asio::serial_port Verbindung::starteSerielleVerbindung(int Verbindungsnummer) const{

    boost::asio::io_service io;
    boost::asio::serial_port port(io);

    port.open(seriellStVec[Verbindungsnummer].seriellPfad);
    port.set_option(boost::asio::serial_port_base::baud_rate(seriellStVec[Verbindungsnummer].seriellPort));

    return port;
}

int Verbindung::anzahlSerielleVerbindungen() const{
    return seriellStVec.size();
}
