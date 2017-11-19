#include "seriell.h"

Seriell::Seriell(boost::asio::serial_port &a){
    serVer = &a;
}

boost::asio::serial_port *Seriell::ladeVerbindung(){
    return serVer;
}

std::string Seriell::arduinoAuslesen(){
    char c;
    std::string resultat;
    bool anfang_gefunden = false;

    while (true) {
        boost::asio::read(*ladeVerbindung(), boost::asio::buffer(&c,1));
        if (c == '{' || anfang_gefunden){
            anfang_gefunden = true;
            resultat+=c;
            if (resultat.size() > 1 && resultat.back() == '\n'){
                //Bereinige von '\n'
                resultat.pop_back();
                anfang_gefunden = false;
                break;
            }
        }
    }
    return resultat;
}