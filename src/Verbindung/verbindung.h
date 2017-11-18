#ifndef VERBINDUNG_H
#define VERBINDUNG_H
#include "../Einstellungen/einstellungen.h"
#include <boost/asio.hpp>
#include <vector>

//Lädt alle Relevanten Daten für Verbindungen und baut die Verbindungen auf
class Verbindung{
private:
    std::vector<struct seriellStruct> seriellStVec;
    std::string onlineDatenquelle;
public:
    Verbindung(Einstellungen const &a);
    std::vector<seriellStruct> ladeSerielleVerbindung() const;
    std::string ladeOnlineDatenquelle() const;
    boost::asio::serial_port starteSerielleVerbindung(int Verbindungsnummer) const;
    int anzahlSerielleVerbindungen() const;
};

#endif // VERBINDUNG_H
