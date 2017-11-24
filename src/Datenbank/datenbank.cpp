#include "datenbank.h"

Datenbank::Datenbank(Einstellungen& a){
    datenbankdaten = a.datenbankLaden();
}

int Datenbank::datenbankVerbindungAufbauen()
{
    if(datenbankdaten.datenbankName.compare("SQLite") == 0 && !datenbankVerbindungOffen()){

        int db = sqlite3_open(datenbankdaten.datenbankPfad.c_str(), &db_sqlite3);
        if(db){
            return 0;
        }
        else{
            db_sqlite3 = nullptr;
            return 1;
        }
    }
    else if (datenbankdaten.datenbankName.compare("MariaDB") == 0 && !datenbankVerbindungOffen()){
        //Zutun
        return 1;
    }
    return 1;
}

bool Datenbank::datenbankVerbindungOffen()
{
    if(datenbankdaten.datenbankName.compare("SQLite") == 0){
        if(db_sqlite3 != nullptr){
            return true;
        }
        else{
            return false;
        }
    }
    else if (datenbankdaten.datenbankName.compare("MariaDB") == 0){
        //Zutun
        return false;
    }
    return false;
}

void Datenbank::datenbankVereinen(){
    //Zutun
}
