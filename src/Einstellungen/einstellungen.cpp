#include "einstellungen.h"
#include <iostream>
#include "ext/json/json.hpp"
#include <fstream>

Einstellungen::Einstellungen(){
    parsejson();
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
                    datenbankname = *it_o;
                }
                else if(it_o.key()=="Pfad"){
                    datenbankpfad = *it_o;
                }
                else if(it_o.key()=="Host"){
                    datenbankhost = *it_o;
                }
                else if(it_o.key()=="Port"){
                    datenbankport = *it_o;
                }
            }
        }
        if(it.key() == "Seriel"){
            nlohmann::json jsonobject = *it;
            for(nlohmann::json::iterator it_o = jsonobject.begin(); it_o != jsonobject.end(); ++it_o){
                if(it_o.key() == "Pfad"){
                    serielPfad = *it_o;
                }
                else if(it_o.key() == "Baud"){
                    serielPort = *it_o;
                }
                else if(it_o.key() == "NeueZeile"){
                    serielNeueZeile = *it_o;
                }
            }
        }
        if(it.key() == "Loging"){
            loging = *it;
        }
    }
}
