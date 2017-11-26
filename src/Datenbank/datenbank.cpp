#include "datenbank.h"

Datenbank::Datenbank(Einstellungen& a){
    datenbankdaten = a.datenbankLaden();
}

bool Datenbank::datenbankVerbindungPruefen(){
    return datenbankVerbindungOffen();
}

void Datenbank::datenbankVerbindungPruefenUndGgfAufbauen(Datenbank &dat)
{
    if(dat.datenbankVerbindungOffen()){
        //Mach gar nichts, alles in Ordnung
    }
    else{
        try{
            dat.datenbankVerbindungAufbauen();
        }
        catch(std::string &str){
            std::cout << str << std::endl;
        }
        if(dat.datenbankVerbindungOffen()){
            //Mach gar nichts, alles in Ordnung
        }
        else{
            try{
                throw std::string("Datenbankverbindung konnte zwar aufgebaut werden, aber die Datenbank nicht geöffnet");
            }
            catch(std::string &str){
                std::cout << str << std::endl;
            }
        }
    }
}

int Datenbank::datenbankVerbindungAufbauen(){
    if(datenbankdaten.datenbankName.compare("SQLite") == 0 && !datenbankVerbindungOffen()){

        //Zutun, Pfad nicht überschreiben, sollte aus dem Homeverzeichnis abrufbar sein, später diese Zeile entfernen.
        datenbankdaten.datenbankPfad = "/home/efischer/Dokumente/Programmierung/Projekte/C++/HeimServer/HeimServer/sqlite.db";

        int db = sqlite3_open_v2(datenbankdaten.datenbankPfad.c_str(), &db_sqlite3, SQLITE_OPEN_READWRITE, NULL);
        if(db){
            //Funktion sqlite3_open_v2 liefert 14 bei fehlender Datei.
            if(db == 14){
                //SQLite Datenbank konnte nicht gefunden werden.
                sqlite3_close(db_sqlite3);
                db_sqlite3 = nullptr;
                throw std::string("SQLite Datenbank konnte nicht gefunden werden.");
                return 1;
            }
        }
        else{
            return 0;
        }
    }
    else if (datenbankdaten.datenbankName.compare("MariaDB") == 0 && !datenbankVerbindungOffen()){
        //Zutun
        return 1;
    }
    return 1;
}

bool Datenbank::datenbankVerbindungOffen(){
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
