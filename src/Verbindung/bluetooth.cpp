#include "bluetooth.h"


Bluetooth::Bluetooth(const Verbindung &a){
    struct serielStruct verbindungsdaten = a.ladeSerielverbindung();
}

void Bluetooth::verbindungAufbauen() const{
    //seriel.serielPfad;
    //seriel.serielPort;
    //seriel.serielNeueZeile;
}
