#ifndef VALIDIERUNG_H
#define VALIDIERUNG_H
#include <map>
#include "ext/json/json.hpp"


class Validierung{
private:
    Validierung();
    Validierung(const Validierung& other);
    Validierung& operator =(const Validierung& other);
public:
    static std::map<std::string, bool> jsonValidiert(const std::string &a);
};

#endif // VALIDIERUNG_H
