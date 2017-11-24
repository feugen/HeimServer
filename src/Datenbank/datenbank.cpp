#include "datenbank.h"

Datenbank::Datenbank(Einstellungen& a){
    datenbankdaten = a.datenbankLaden();
}

void Datenbank::datenbankBeschreiben()
{
    if(datenbankdaten.datenbankName.compare("SQLite") == 0){
        sqlite3 *db_sqlite3;
        int db = sqlite3_open(datenbankdaten.datenbankPfad.c_str(), &db_sqlite3);
        if(db){
            //Zutun
        }

    }
    else if (datenbankdaten.datenbankName.compare("MariaDB") == 0){

    }
}

void Datenbank::datenbankVereinen(){

}
