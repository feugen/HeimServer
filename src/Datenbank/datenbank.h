#ifndef DATENBANK_H
#define DATENBANK_H
#include "src/Einstellungen/einstellungen.h"
#include "src/Wetter/arduino.h"
#include "src/Verbindung/validierung.h"
#include <sqlite3.h>
#include "ext/json/json.hpp"
#include <chrono>


//ArduinoWetter Jason Struktur
struct arduinoWetterJASONDaten{
    double Luftfeuchte;
    double Luftdruck;
    int Photostrom;
    struct Temp{
        double Temp_am2303;
        double Temp_bmp180;
    }Temperatur;
};

class Datenbank{
private:
    dbStruct datenbankdaten;
    sqlite3 *db_sqlite3 = nullptr;
    bool datenbankVerbindungSQLiteOeffnen(); //erledigt
    bool datenbankVerbindungSQLiteIstOffen(); //erledigt
    bool datenbankVerbindungSQLiteSchliessen(); //erledigt

    bool datenbankVerbindungMariaDBOeffnen(); //Zutun
    bool datenbankVerbindungMariaDBIstOffen();  //Zutun
    bool datenbankVerbindungMariaDBSchliessen(); //Zutun

    void arduinoWetterDatenInSQLiteImportieren(std::string &a); //Zutun
    void arduinoWetterDatenInMariaDBImportieren(std::string &a); //Zutun
    arduinoWetterJASONDaten arduinoWetterJASONParser(std::string &ArduinoJasonString); //erledigt
public:
    Datenbank(Einstellungen &a);
    virtual ~Datenbank();
    bool datenbankVerbindungOeffnen(Datenbank &dat); //erledigt
    bool datenbankVerbindungIstOffen(); //erledigt
    bool datenbankVerbindungSchliessen(); //erledigt

    void datenbankVereinen(); //Zutun
    void arduinoWetterDatenInDbImportieren(Arduino &arduinoWetterInstanz); //erledigt
};

#endif // DATENBANK_H
