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

void Datenbank::arduinoWetterDatenInSQLiteEinfuegen(std::string &a){
    struct arduinoWetterJASONDaten JasonCache = arduinoWetterJASONParser(a);
    //Zutun
}

arduinoWetterJASONDaten Datenbank::arduinoWetterJASONParser(std::string &ArduinoJasonString){

    arduinoWetterJASONDaten wetterStruc;
    nlohmann::json j = nlohmann::json::parse(ArduinoJasonString);

    for(nlohmann::json::iterator j_iter = j.begin(); j_iter != j.end(); ++j_iter){

        std::string jsonKey = j_iter.key();
        if(jsonKey.compare("Luftfeuchte") == 0){
            wetterStruc.Luftfeuchte = *j_iter;
        }
        if(jsonKey.compare("Luftdruck") == 0){
            wetterStruc.Luftdruck = *j_iter;
        }
        if(jsonKey.compare("Photostrom") == 0){
            wetterStruc.Photostrom = *j_iter;
        }
        if(jsonKey.compare("Temperatur") == 0){
            nlohmann::json j2 = *j_iter;
            for(nlohmann::json::iterator j_iter2 = j2.begin(); j_iter2 != j2.end(); ++j_iter2 ){
                jsonKey = j_iter2.key();
                if(jsonKey.compare("Temp_am2303")){
                    wetterStruc.Temperatur.Temp_am2303 = *j_iter2;
                }
                if(jsonKey.compare("Temp_bmp180")){
                    wetterStruc.Temperatur.Temp_bmp180 = *j_iter2;
                }
            }
        }
    }
    return wetterStruc;
}

void Datenbank::datenbankVereinen(){
    //Zutun
}

void Datenbank::arduinoWetterDatenInDbImportieren(Arduino &arduinoWetterInstanz){
    std::string arduinoString;
    while(true){
        arduinoString = arduinoWetterInstanz.arduinoAuslesen();
        if (Validierung::jsonValidiert(arduinoString).at(arduinoString)){
            if(datenbankVerbindungPruefen()){
                if((datenbankdaten.datenbankName.compare("SQLite") == 0)){
                    //SQL Querry mit Daten ausführen
                    //arduinoWetterDatenInSQLiteEinfuegen(arduinoString);
                }
                else if((datenbankdaten.datenbankName.compare("MariaDB" )== 0)){

                }
            }
            std::cout << arduinoString << std::endl;
            //Zutun Füge die Daten in die Arduino Wetterdatenbank ein.
            arduinoWetterDatenInSQLiteEinfuegen(arduinoString);
            //Prüfe Verbindung ob sie noch besteht, wenn nicht so break, oder neue Verbindung aufbauen oder kombiniert
        }
    }
}
