#ifndef VERBINDUNG_H
#define VERBINDUNG_H
#include "../Einstellungen/einstellungen.h"

//Lädt alle Relevanten Daten für Verbindungen
class Verbindung{
private:
    //Wie in Einstellungen.h
    struct serielStruct seriel;
    //Online Datenquelle, wie in Einstellungen.h
    std::string onlineDatenquelle;
public:
    Verbindung(const Einstellungen &a);
    serielStruct ladeSerielverbindung() const;
    std::string ladeOnlineDatenquelle() const;
};

#endif // VERBINDUNG_H
