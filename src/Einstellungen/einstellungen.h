#ifndef EINSTELLUNGEN_H
#define EINSTELLUNGEN_H
#include <iostream>

class Einstellungen{
private:
    std::string jsonPfad = "/home/efischer/Dokumente/Programmierung/Projekte/C++/HeimServer/HeimServer/einstellungen.json";
    std::string datenbankname;
    std::string datenbankpfad;
    std::string datenbankhost;
    std::string datenbankport;
    bool loging;
public:
    Einstellungen();
    void parsejson();
};

#endif // EINSTELLUNGEN_H
