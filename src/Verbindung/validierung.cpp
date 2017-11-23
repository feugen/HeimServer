#include "validierung.h"

Validierung::Validierung(){

}

std::map<std::string, bool> Validierung::jsonValidiert(const std::string &a){
    std::map<std::string, bool> ergebnis;
    //Zutun prüfen ob Json valide ist, und setze auf true oder false.
    ergebnis.insert(std::pair<std::string, bool>(a, true));
    return ergebnis;
}
