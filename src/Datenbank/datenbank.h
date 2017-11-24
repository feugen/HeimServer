#ifndef DATENBANK_H
#define DATENBANK_H
#include "src/Einstellungen/einstellungen.h"
#include <sqlite3.h>


class Datenbank{
private:
    dbStruct datenbankdaten;
    sqlite3 *db_sqlite3 = nullptr;
public:
    Datenbank(Einstellungen &a);
    int datenbankVerbindungAufbauen();
    bool datenbankVerbindungOffen();
    void datenbankVereinen();
};

#endif // DATENBANK_H
