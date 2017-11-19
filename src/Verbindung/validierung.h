#ifndef VALIDIERUNG_H
#define VALIDIERUNG_H
#include <map>
#include "ext/json/json.hpp"


class Validierung{
private:
    static std::map<std::string, bool> stringmap;
public:
    Validierung();
    //Zutun Referenz auf string wird nicht akzeptiert, wieso?
    static std::map<std::string, bool> jsonValidiert(const std::string);
};

#endif // VALIDIERUNG_H
