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
    Einstellungen einst;
    Verbindung verbindungsdaten(einst);
    Bluetooth blue(verbindungsdaten);

    blue.verbindungAufbauen();
    return 0;
}
