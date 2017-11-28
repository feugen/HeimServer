#ifndef DATENBANK_H
#define DATENBANK_H
#include "src/Einstellungen/einstellungen.h"
#include "src/Wetter/arduino.h"
#include "src/Verbindung/validierung.h"
#include <sqlite3.h>
#include "ext/json/json.hpp"


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
    int datenbankVerbindungAufbauen();
    bool datenbankVerbindungOffen();
    void arduinoWetterDatenInSQLiteEinfuegen(std::string &a);
    arduinoWetterJASONDaten arduinoWetterJASONParser(std::string &ArduinoJasonString);
public:
    Datenbank(Einstellungen &a);
    bool datenbankVerbindungPruefen();
    void datenbankVerbindungPruefenUndGgfAufbauen(Datenbank &dat);
    void datenbankVereinen();
    void arduinoWetterDatenInDbImportieren(Arduino &arduinoWetterInstanz);
};

#endif // DATENBANK_H
