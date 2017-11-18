#include <iostream>
#include "src/Einstellungen/einstellungen.h"
#include "src/Verbindung/verbindung.h"
#include "src/Verbindung/bluetooth.h"
#include "ext/json/json.hpp"
#include <fstream>

using namespace std;
const std::string versionsnummer = "0.0.1";

int main()
{
    Einstellungen einstellungen;
    Verbindung verbindungsdaten(einstellungen);

    //Mit Anzahl der seriellen Verbindungen, kann man Threads starten.
    std::cout << verbindungsdaten.anzahlSerielleVerbindungen();

    //boost::asio::serial_port *serVerbindung[];
    //*serVerbindung[0] = verbindungsdaten.starteSerielleVerbindung();

    return 0;
}
