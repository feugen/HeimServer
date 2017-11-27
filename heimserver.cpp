#include <iostream>
#include "src/Einstellungen/einstellungen.h"
#include "src/Verbindung/verbindung.h"
#include "src/Verbindung/seriell.h"
#include "src/Datenbank/datenbank.h"
#include "src/Wetter/arduino.h"
#include "src/Verbindung/validierung.h"
#include "ext/json/json.hpp"
#include <fstream>
#include <boost/asio.hpp>

constexpr auto versionsnummer = "0.1.0";

void threadStarterSerielleVerbindungen(Verbindung &verbindungsdaten, Datenbank &dat, int &Verbindungsnummer){

    boost::asio::serial_port SerielleVerbindung = verbindungsdaten.starteSerielleVerbindung(Verbindungsnummer);
    SerielleVerbindung = verbindungsdaten.starteSerielleVerbindung(Verbindungsnummer);
    //Starte die Arduino Verbindung, sie braucht die generelle serielle Verbindung, diese ist immer die Nummer 0, liefert nur Wetterdaten
    std::vector<struct seriellStruct> a = verbindungsdaten.ladeSerielleVerbindung();

    //Prüfe ob es sich tatsählich um ArduinoWetter handelt.
    if (a.at(Verbindungsnummer).seriellKennung.compare("ArduinoWetter") == 0){
        Arduino arduinoWetterInstanz(SerielleVerbindung);
        //Zutun Vorsicht ob sowas mit Multithreading funktioniert.
        while(SerielleVerbindung.is_open()){
            dat.arduinoWetterDatenInDbImportieren(arduinoWetterInstanz);
        }
    }
    else if(1){
        //Standard Serielle Verbindung starten, evtl für andere Geräte auch separat anpassen, wie für Arduino Wetter.
    }
}

int main(){

    Einstellungen einstellungen;
    Verbindung verbindungsdaten(einstellungen);
    Datenbank dat(einstellungen);
    dat.datenbankVerbindungPruefenUndGgfAufbauen(dat);

    if (verbindungsdaten.anzahlSerielleVerbindungen() > 0){
        //Serielle Verbindungen in Threads starten
        for(int i = 0; i <= verbindungsdaten.anzahlSerielleVerbindungen()-1; ++i){
            threadStarterSerielleVerbindungen(verbindungsdaten, dat, i);
        }
    }
    return 0;
}
