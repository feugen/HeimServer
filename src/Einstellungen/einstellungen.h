#ifndef EINSTELLUNGEN_H
#define EINSTELLUNGEN_H
#include <iostream>

class Einstellungen{
private:
    std::string jsonPfad = "/home/efischer/Dokumente/Programmierung/Projekte/C++/HeimServer/HeimServer/einstellungen.json";
    //Datenbankeinstellungen
    std::string datenbankName;
    std::string datenbankPfad;
    std::string datenbankHost;
    std::string datenbankPort;
    //Serieller Port
    std::string serielPfad;
    std::string serielNeueZeile;
    signed int serielPort;
    //Log Einstellungen
    bool loging;
public:
    Einstellungen();
    void parsejson();
};

#endif // EINSTELLUNGEN_H
