#include "cartridge.h"
#include "eeprom.h"

Cartridge::Cartridge(Eeprom *eepr)
{
    eeprom = eepr;
}

bool Cartridge::program_data()
{

}

bool Cartridge::read_data()
{
    eeprom->read(std::to_string(serial_number));
}

void Cartridge::set_data(std::string mat, float qty)
{
    material = mat;
    current_quantity = qty;
}

bool Cartridge::isEepromRead()
{
    return eeprom_read;
}
