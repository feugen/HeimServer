#ifndef EINSTELLUNGEN_H
#define EINSTELLUNGEN_H
#include <iostream>
#include <vector>
#include "ext/json/json.hpp"

//Serielle Verbindung
struct seriellStruct{
    std::string seriellKennung;
    std::string seriellPfad;
    std::string seriellNeueZeile;
    unsigned int seriellPort;
};

//Datenbankeinstellungen
struct dbStruct{
    std::string datenbankName;
    std::string datenbankPfad;
    std::string datenbankHost;
    unsigned int datenbankPort;
};

class Einstellungen{
private:
    std::string jsonPfad = "/home/efischer/Dokumente/Programmierung/Projekte/C++/HeimServer/HeimServer/einstellungen.json";
    std::string onlineDatenquelle;
    struct dbStruct db;
    std::vector<struct seriellStruct> seriellStVec;
    bool loging;
    void parseJson();
public:
    Einstellungen();
    Einstellungen(const Einstellungen &a) = delete;
    Einstellungen& operator =(const Einstellungen& a) = delete;
    void einstellungenLaden();
    dbStruct datenbankLaden() const;
    std::vector<struct seriellStruct> serielleVerbindungLaden() const;
    std::string onlineDatenquelleLaden() const;
    bool logingLaden() const;
};

#endif // EINSTELLUNGEN_H
