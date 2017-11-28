#include "validierung.h"

Validierung::Validierung(){

}

std::map<std::string, bool> Validierung::jsonValidiert(const std::string &zuValidieren){

    //Zutun In seltenen Fällen gibt es immer noch Probleme beim "validieren", vielleicht geforderte
    //Zeichenlänge von 100 runtersetzen um den Fehler öfter zu provozieren.
    //Zutun wenn der Validator verfügbar ist, so mitbenutzen um zu vereinfachen und den Test
    //allgemeingültiger zu gestalten

    std::map<std::string, bool> ergebnis;
    bool status = false;
    int stringlaenge = zuValidieren.length();
    //Zählt die Anzahl der bestandenen Tests
    unsigned int zaehler = 0;

    if(stringlaenge > 100){
        ++zaehler;
    }
    if(zuValidieren.at(0) == '{'){
        ++zaehler;
    }
    if(stringlaenge >0){
        if(zuValidieren.at(stringlaenge-2) == '}'){
            ++zaehler;
        }
    }
    if (zaehler == 3){
        nlohmann::json j = nlohmann::json::parse(zuValidieren);
        for(nlohmann::json::iterator j_iter = j.begin(); j_iter != j.end(); ++j_iter){
            std::string j_iter_key = j_iter.key();
            if(j_iter_key.compare("Luftfeuchte") == 0){
                ++zaehler;
            }
            if(j_iter_key.compare("Temperatur") == 0){
                ++zaehler;
            }
            if(j_iter_key.compare("Luftdruck") == 0){
                ++zaehler;
            }
            if(j_iter_key.compare("Photostrom") == 0){
                ++zaehler;
            }
        }
    }

    //Jetzt zählen nach wieviele Tests bestanden wurden.
    if(zaehler == 7){
        status = true;
    }
    else{
        status = false;
    }
    ergebnis.insert(std::pair<std::string, bool>(zuValidieren, status));

    return ergebnis;
}
