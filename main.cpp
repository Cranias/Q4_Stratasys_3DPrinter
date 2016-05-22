#include "cartridge.h"
#include "eeprom.h"
#include "crypto.h"
#include "gui.h"

int main()
{
    Crypto crypto;
    Eeprom eeprom;
    Cartridge cartridge(&eeprom);
    GUI gui;
    gui.print("Hello World!");

    return 0;
}

