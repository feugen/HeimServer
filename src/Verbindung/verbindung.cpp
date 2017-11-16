#include "verbindung.h"

Verbindung::Verbindung(Einstellungen const &a){
    //Für TCP/IP
    onlineDatenquelle = a.onlineDatenquelleLaden();
    //Für Serielverbindung/Bluetooth
    seriel = a.serielVerbindungLaden();
}

serielStruct Verbindung::ladeSerielverbindung() const{
    return seriel;
}

std::string Verbindung::ladeOnlineDatenquelle() const{
    return onlineDatenquelle;
}
