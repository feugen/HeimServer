#include "arduino.h"


Arduino::Arduino(boost::asio::serial_port &SerielleVerbindung) : Seriell(SerielleVerbindung){

}

std::string Arduino::arduinoAuslesen(){
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
