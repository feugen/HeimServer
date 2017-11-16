#ifndef EINSTELLUNGEN_H
#define EINSTELLUNGEN_H
#include <iostream>

struct serielStruct{
    std::string serielPfad;
    std::string serielNeueZeile;
    signed int serielPort;
};

struct dbStruct{
    //Datenbankeinstellungen
    std::string datenbankName;
    std::string datenbankPfad;
    std::string datenbankHost;
    std::string datenbankPort;
};

class Einstellungen{
private:
    std::string jsonPfad = "/home/efischer/Dokumente/Programmierung/Projekte/C++/HeimServer/HeimServer/einstellungen.json";
    //Datenbankeinstellungen
    struct dbStruct db;
    //Serielle Verbindung
    struct serielStruct seriel;
    //Online Datenquelle
    std::string onlineDatenquelle;
    //Log Einstellungen
    bool loging;
    //Methoden
    void parsejson();
public:
    Einstellungen();
    void einstellungenLaden();
    dbStruct datenbankLaden() const;
    serielStruct serielVerbindungLaden() const;
    std::string onlineDatenquelleLaden() const;
    bool logingLaden() const;
};

#endif // EINSTELLUNGEN_H
