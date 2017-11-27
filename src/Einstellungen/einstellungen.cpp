#include "einstellungen.h"
#include <iostream>
#include <fstream>

Einstellungen::Einstellungen(){
    einstellungenLaden();
}

void Einstellungen::einstellungenLaden(){
    parseJson();
}

dbStruct Einstellungen::datenbankLaden() const{
    return db;
}

std::vector<seriellStruct> Einstellungen::serielleVerbindungLaden() const{
    return seriellStVec;
}

std::string Einstellungen::onlineDatenquelleLaden() const{
    return onlineDatenquelle;
}

bool Einstellungen::logingLaden() const{
    return loging;
}

void Einstellungen::parseJson(){

    nlohmann::json jsonToken;
    std::ifstream einstellungen(jsonPfad);

    einstellungen >> jsonToken;

    for (nlohmann::json::iterator it = jsonToken.begin(); it != jsonToken.end(); ++it) {
        std::string jsonKey = it.key();
        std::string suchvorlage = "Seriel_";

        if(jsonKey.compare("Datenbank") == 0){
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
                    std::string zw = it_o.key();
                    db.datenbankPort = std::atoi(zw.c_str());
                }
            }
        }
        if(jsonKey.compare("Onlinequelle") == 0){
            onlineDatenquelle = *it;
        }
        if(jsonKey.compare("Loging") == 0){
            loging = *it;
        }
        if(jsonKey.find(suchvorlage) == 0 && (jsonKey.length() - suchvorlage.length()) == 1){
            //Bestimme die Nummer aus dem Namen
            int verbindungsnummer = std::atoi(jsonKey.substr(jsonKey.length()-1,1).c_str());
            //Füge ein Strukturelement dem Vectorarry zu, da ein Serialeintrag in Json gefunden.
            seriellStVec.push_back(seriellStruct());
            //Erzeuge einen Iterator um das Jason Sub Objekt zu durchsuchen.
            nlohmann::json jsonobject = *it;
            for(nlohmann::json::iterator it_o = jsonobject.begin(); it_o != jsonobject.end(); ++it_o){
                jsonKey = it_o.key();
                if(jsonKey.compare("Kennung") == 0){
                    seriellStVec[verbindungsnummer].seriellKennung = *it_o;
                }
                if(jsonKey.compare("Pfad") == 0){
                    seriellStVec[verbindungsnummer].seriellPfad = *it_o;
                }
                else if(jsonKey.compare("Baud") == 0){
                    seriellStVec[verbindungsnummer].seriellPort = *it_o;
                }
                else if(jsonKey.compare("NeueZeile") == 0){
                    seriellStVec[verbindungsnummer].seriellNeueZeile = *it_o;
                }
            }
        }
    }
}
