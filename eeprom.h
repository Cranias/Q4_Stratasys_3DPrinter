#ifndef EEPROM_H
#define EEPROM_H

#include <string>

class Eeprom
{
public:
    Eeprom();
    bool read(std::string fname);
    bool write(std::string fname);
};

#endif // EEPROM_H
