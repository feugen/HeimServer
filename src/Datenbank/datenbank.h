#ifndef DATENBANK_H
#define DATENBANK_H
#include "src/Einstellungen/einstellungen.h"
#include <sqlite3.h>


class Datenbank{
private:
    dbStruct datenbankdaten;
public:
    Datenbank(Einstellungen &a);
    void datenbankBeschreiben();
    void datenbankVereinen();
};

#endif // DATENBANK_H
