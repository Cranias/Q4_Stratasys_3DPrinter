#ifndef CARTRIDGE_H
#define CARTRIDGE_H

#include <string>
class Eeprom;

class Cartridge
{
public:
    Cartridge(Eeprom *eepr);
    bool program_data();
    bool read_data();
    void set_data(std::string mat, float qty);
    bool isEepromRead();
private:
    std::string material;
    float initial_quantity;
    float current_quantity;
    long serial_number;
    bool eeprom_read;
    Eeprom *eeprom;
};

#endif // CARTRIDGE_H
