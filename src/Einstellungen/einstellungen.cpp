#include "einstellungen.h"
#include <iostream>
#include "ext/json/json.hpp"
#include <fstream>

Einstellungen::Einstellungen(){
}

void Einstellungen::einstellungenLaden(){
    parsejson();
}

dbStruct Einstellungen::datenbankLaden() const{
    return db;
}

serielStruct Einstellungen::serielVerbindungLaden() const{
    return seriel;
}

std::string Einstellungen::onlineDatenquelleLaden() const{
    return onlineDatenquelle;
}

bool Einstellungen::logingLaden() const{
    return loging;
}

void Einstellungen::parsejson(){

    nlohmann::json jsonToken;
    std::ifstream einstellungen(jsonPfad);

    einstellungen >> jsonToken;

    for (nlohmann::json::iterator it = jsonToken.begin(); it != jsonToken.end(); ++it) {
        std::cout << it.key();
        if(it.key() == "Datenbank"){
            nlohmann::json jsonobject = *it;
            for(nlohmann::json::iterator it_o = jsonobject.begin(); it_o != jsonobject.end(); ++it_o){
                if(it_o.key()=="Name"){
                    db.datenbankName = *it_o;
                }
                else if(it_o.key()=="Pfad"){
                    db.datenbankPfad = *it_o;
                }
                else if(it_o.key()=="Host"){
                    db.datenbankHost = *it_o;
                }
                else if(it_o.key()=="Port"){
                    db.datenbankPort = *it_o;
                }
            }
        }
        if(it.key() == "Seriel"){
            nlohmann::json jsonobject = *it;
            for(nlohmann::json::iterator it_o = jsonobject.begin(); it_o != jsonobject.end(); ++it_o){
                if(it_o.key() == "Pfad"){
                    seriel.serielPfad = *it_o;
                }
                else if(it_o.key() == "Baud"){
                    seriel.serielPort = *it_o;
                }
                else if(it_o.key() == "NeueZeile"){
                    seriel.serielNeueZeile = *it_o;
                }
            }
        }
        if(it.key() == "Onlinequelle"){
            onlineDatenquelle = *it;
        }
        if(it.key() == "Loging"){
            loging = *it;
        }
    }
}
