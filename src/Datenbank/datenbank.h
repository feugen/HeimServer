#ifndef DATENBANK_H
#define DATENBANK_H
#include "src/Einstellungen/einstellungen.h"
#include "src/Wetter/arduino.h"
#include "src/Verbindung/validierung.h"
#include <sqlite3.h>

struct arduinoWetterJASONDaten
{
    std::string a;
};

class Datenbank{
private:
    dbStruct datenbankdaten;
    sqlite3 *db_sqlite3 = nullptr;
    int datenbankVerbindungAufbauen();
    bool datenbankVerbindungOffen();
    void arduinoWetterDatenInSQLiteEinfuegen(std::string &a);
    arduinoWetterJASONDaten& arduinoWetterJASONParser(std::string &a);
public:
    Datenbank(Einstellungen &a);
    bool datenbankVerbindungPruefen();
    void datenbankVerbindungPruefenUndGgfAufbauen(Datenbank &dat);
    void datenbankVereinen();
    void arduinoWetterDatenInDbImportieren(Arduino &arduinoWetterInstanz);
};

#endif // DATENBANK_H
