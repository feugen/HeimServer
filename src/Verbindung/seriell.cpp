#include "src/Verbindung/seriell.h"

Seriell::Seriell(boost::asio::serial_port &a){
    serVer = &a;
}

boost::asio::serial_port *Seriell::ladeVerbindung(){
    return serVer;
}



