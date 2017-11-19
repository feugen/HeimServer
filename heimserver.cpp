#include <iostream>
#include "src/Einstellungen/einstellungen.h"
#include "src/Verbindung/verbindung.h"
#include "src/Verbindung/serielllesen.h"
#include "ext/json/json.hpp"
#include <fstream>
#include <boost/asio.hpp>

using namespace std;
const std::string versionsnummer = "0.0.1";

int main()
{
    Einstellungen einstellungen;
    Verbindung verbindungsdaten(einstellungen);

    if (verbindungsdaten.anzahlSerielleVerbindungen() > 0){

        boost::asio::serial_port SerielleVerbindung = verbindungsdaten.starteSerielleVerbindung(0);
        SeriellLesen serLesenInstanz(SerielleVerbindung);

        char c;

        std::string res;
        bool anfang_gefunden = false;
        while (true) {
            boost::asio::read(*serLesenInstanz.ladeVerbindung(), boost::asio::buffer(&c,1));
            if (c == '{' || anfang_gefunden){
                anfang_gefunden = true;
                res+=c;
                if (res.back() == '}'){
                    break;
                }
            }
        }

        std::cout<< res << std::endl;
    }
    return 0;
}
