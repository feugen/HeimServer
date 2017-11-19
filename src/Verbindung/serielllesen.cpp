#include "serielllesen.h"

SeriellLesen::SeriellLesen(boost::asio::serial_port &a){
    serVer = &a;
}

boost::asio::serial_port *SeriellLesen::ladeVerbindung()
{
    return serVer;
}

