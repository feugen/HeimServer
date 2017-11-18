#ifndef EINSTELLUNGEN_H
#define EINSTELLUNGEN_H
#include <iostream>
#include <vector>

//Serielle Verbindung
struct seriellStruct{
    std::string seriellPfad;
    std::string seriellNeueZeile;
    signed int seriellPort;
};

//Datenbankeinstellungen
struct dbStruct{
    std::string datenbankName;
    std::string datenbankPfad;
    std::string datenbankHost;
    std::string datenbankPort;
};

class Einstellungen{
private:
    std::string jsonPfad = "/home/efischer/Dokumente/Programmierung/Projekte/C++/HeimServer/HeimServer/einstellungen.json";
    struct dbStruct db;
    std::vector<struct seriellStruct> seriellStVec;
    std::string onlineDatenquelle;
    bool loging;
    void parseJson();
public:
    Einstellungen();
    void einstellungenLaden();
    dbStruct datenbankLaden() const;
    std::vector<struct seriellStruct> serielleVerbindungLaden() const;
    std::string onlineDatenquelleLaden() const;
    bool logingLaden() const;
};

#endif // EINSTELLUNGEN_H
