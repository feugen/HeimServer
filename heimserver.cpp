#include <iostream>
#include "src/Einstellungen/einstellungen.h"
#include "src/Verbindung/verbindung.h"
#include "src/Verbindung/serielllesen.h"
#include "src/Wetter/arduino.h"
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
        Arduino arduinoInstanz(SerielleVerbindung);

        while(true){
            std::cout << arduinoInstanz.arduinoAuslesen() << std::endl;
        }
    }
    return 0;
}
