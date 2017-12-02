#include "datenbank.h"

Datenbank::Datenbank(Einstellungen& a){
    datenbankdaten = a.datenbankLaden();
}

Datenbank::~Datenbank(){
    datenbankVerbindungSchliessen();
}

bool Datenbank::datenbankVerbindungSQLiteOeffnen(){

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
            return false;
        }
        return false;
    }
    return true;
}

bool Datenbank::datenbankVerbindungSQLiteIstOffen(){

    if(db_sqlite3 != nullptr){
        return true;
    }
    else{
        return false;
    }
}

bool Datenbank::datenbankVerbindungSQLiteSchliessen(){
    return sqlite3_close_v2(db_sqlite3);
}

bool Datenbank::datenbankVerbindungMariaDBOeffnen(){
    //Zutun
    return false;
}

bool Datenbank::datenbankVerbindungMariaDBIstOffen(){
    //Zutun
    return false;
}

bool Datenbank::datenbankVerbindungMariaDBSchliessen(){
    //Zutun
    return false;
}

bool Datenbank::datenbankVerbindungOeffnen(Datenbank &dat){
    if(!datenbankVerbindungIstOffen()){
        try{
            if(datenbankdaten.datenbankName.compare("SQLite") == 0){
                dat.datenbankVerbindungSQLiteOeffnen();
            }
            else if(datenbankdaten.datenbankName.compare("MariaDB") == 0){
                dat.datenbankVerbindungMariaDBIstOffen();
            }
        }
        catch(std::string &str){
            //Wegschreiben, evtl Log
            std::cout << str << std::endl;
        }
        if(dat.datenbankVerbindungSQLiteIstOffen()){
            return true;
        }
        else{
            return false;
        }
    }
    return false;
}

bool Datenbank::datenbankVerbindungIstOffen(){
    if(datenbankdaten.datenbankName.compare("SQLite") == 0){
        return datenbankVerbindungSQLiteIstOffen();
    }
    else if (datenbankdaten.datenbankName.compare("MariaDB") == 0){
        return datenbankVerbindungMariaDBIstOffen();
    }
    return false;
}

bool Datenbank::datenbankVerbindungSchliessen(){
    if(datenbankdaten.datenbankName.compare("SQLite") == 0){
        return datenbankVerbindungSQLiteSchliessen();
    }
    else if (datenbankdaten.datenbankName.compare("MariaDB") == 0){
        return datenbankVerbindungMariaDBSchliessen();
    }
    return false;
}

void Datenbank::datenbankVereinen(){
    //Zutun
}

void Datenbank::arduinoWetterDatenInSQLiteImportieren(std::string &a){

    struct arduinoWetterJASONDaten ArduinoJasonCache = arduinoWetterJASONParser(a);
    const char * sqlQuerry = "insert into t_ArduinoWetter(Luftfeuchte,Luftdruck,Photostrom,Temp_am2303,Temp_bmp180,Zeitstempel) Values(?,?,?,?,?,?)";
    static sqlite3_stmt *sql_vorbereitet;
    auto zeit = std::chrono::system_clock::now();
    auto zeitstempel = std::chrono::system_clock::to_time_t(zeit);

    int resultat = sqlite3_prepare_v2(db_sqlite3, sqlQuerry, -1, &sql_vorbereitet, nullptr);
    if(resultat != SQLITE_OK){
        //In Log Datei ausgeben z.B. so: //NSLog(@"Prepare-error #%i: %s", result, sqlite3_errmsg(_database));
        std::cout << "Fehler" << std::endl;
    }

    sqlite3_bind_double(sql_vorbereitet,1,ArduinoJasonCache.Luftfeuchte);
    sqlite3_bind_double(sql_vorbereitet,2,ArduinoJasonCache.Luftdruck);
    sqlite3_bind_int(sql_vorbereitet,3,ArduinoJasonCache.Photostrom);
    sqlite3_bind_double(sql_vorbereitet,4,ArduinoJasonCache.Temperatur.Temp_am2303);
    sqlite3_bind_double(sql_vorbereitet,5,ArduinoJasonCache.Temperatur.Temp_bmp180);
    sqlite3_bind_int(sql_vorbereitet,6,zeitstempel);

    resultat = sqlite3_step(sql_vorbereitet);
    if (resultat != SQLITE_DONE){
        //In Log Datei ausgeben z.B. so: //NSLog(@"Prepare-error #%i: %s", result, sqlite3_errmsg(_database));
        std::cout << "Fehler2" << std::endl;
    }

    sqlite3_finalize(sql_vorbereitet);
}

void Datenbank::arduinoWetterDatenInMariaDBImportieren(std::string &a){
    //zutun
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

void Datenbank::arduinoWetterDatenInDbImportieren(Arduino &arduinoWetterInstanz){
    std::string arduinoString;
    while(true){
        arduinoString = arduinoWetterInstanz.arduinoAuslesen();
        if (Validierung::jsonValidiert(arduinoString).at(arduinoString)){
            if(datenbankVerbindungIstOffen()){
                if((datenbankdaten.datenbankName.compare("SQLite") == 0)){
                    //SQL Querry mit Daten ausführen
                    arduinoWetterDatenInSQLiteImportieren(arduinoString);
                }
                else if((datenbankdaten.datenbankName.compare("MariaDB" )== 0)){
                    arduinoWetterDatenInMariaDBImportieren(arduinoString);
                }
            }
            //Fürs Debugging (vorläufig, später entfernen)
            std::cout << arduinoString << std::endl;
            //Prüfe Verbindung ob sie noch besteht, wenn nicht so break
            if(!datenbankVerbindungIstOffen()){
                //Log einfügen
                break;
            }
        }
    }
}
