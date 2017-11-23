#include <iostream>
#include "src/Einstellungen/einstellungen.h"
#include "src/Verbindung/verbindung.h"
#include "src/Verbindung/seriell.h"
#include "src/Wetter/arduino.h"
#include "src/Verbindung/validierung.h"
#include "ext/json/json.hpp"
#include <fstream>
#include <boost/asio.hpp>

const std::string versionsnummer = "0.0.1";

int main()
{
    Einstellungen einstellungen;
    Verbindung verbindungsdaten(einstellungen);

    if (verbindungsdaten.anzahlSerielleVerbindungen() > 0){

        boost::asio::serial_port SerielleVerbindung = verbindungsdaten.starteSerielleVerbindung(0);

        //Starte die Arduino Verbindung, sie braucht die generelle serielle Verbindung, diese ist immer die Nummer 0, liefert nur Wetterdaten
        Arduino arduinoInstanz(SerielleVerbindung);
        std::string arduinoString;
        while(true){
            arduinoString = arduinoInstanz.arduinoAuslesen();
            if (Validierung::jsonValidiert(arduinoString).at(arduinoString)){
                std::cout << arduinoString << std::endl;

                //Zutun Füge die Daten in die Arduino Wetterdatenbank ein.
                //Prüfe Verbindung ob sie noch besteht, wenn nicht so break, oder neue Verbindung aufbauen oder kombiniert
            }
        }
    }
    return 0;
}
