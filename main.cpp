#include "cartridge.h"
#include "eeprom.h"
#include "crypto.h"
#include "gui.h"

#include <cryptopp/des.h>
#include <cryptopp/modes.h>
#include <iostream>

using namespace CryptoPP;

void DES_Process(const char *keyString, byte *block, size_t length, CryptoPP::CipherDir direction);

int main()
{
    Crypto crypto;
    Eeprom eeprom;
    Cartridge cartridge(&eeprom);
    GUI gui;
    gui.print("Hello World!");

//D50000015A031023
    const char *key = "";

    FILE *fileptr;
    byte buffer[512] = {0};
    long filelen;

    fileptr = fopen("/home/cranias/Desktop/eeprom_encrypted.bin", "rb");  // Open the file in binary mode
    fseek(fileptr, 0, SEEK_END);          // Jump to the end of the file
    filelen = ftell(fileptr);             // Get the current byte offset in the file
    rewind(fileptr);                      // Jump back to the beginning of the file

    fread(buffer, filelen, 1, fileptr); // Read in the entire file
    fclose(fileptr); // Close the file
    printf("original text:\n");
    for(int i = 0; i < filelen; i++)
    {
        printf("%02x ", buffer[i]);
    }

    printf("\n");

//       DES_Process(key, block, 16, CryptoPP::ENCRYPTION);

//       printf("Encrypt: %s\n", block);

    DES_Process(key, buffer, sizeof(buffer), CryptoPP::DECRYPTION);

    printf("Decrypt:\n");
    for(int i = 0; i < filelen; i++)
    {
        printf("%02x ", buffer[i]);
    }
    fileptr = fopen("/home/cranias/Desktop/eeprom_decrypted.bin", "wb");  // Open the file in binary mode
    fwrite(buffer, sizeof(char), sizeof(buffer), fileptr);
    fclose(fileptr);

    return 0;
}

void DES_Process(const char *keyString, byte *block, size_t length, CryptoPP::CipherDir direction){
    using namespace CryptoPP;

//    byte key[DES_EDE2::KEYLENGTH] = {0xD5, 0x00, 0x00, 0x01, 0x5A, 0x03, 0x10, 0x23};
    byte key[DES_EDE2::KEYLENGTH] = {0x23, 0x10, 0x03, 0x5A, 0x01, 0x00, 0x00, 0xD5};
//    memcpy(key, keyString, DES_EDE2::KEYLENGTH);
    BlockTransformation *t = NULL;

    if(direction == ENCRYPTION)
        t = new DES_EDE2_Encryption(key, DES_EDE2::KEYLENGTH);
    else
        t = new DES_EDE2_Decryption(key, DES_EDE2::KEYLENGTH);

    int steps = length / t->BlockSize();
    for(int i=0; i<steps; i++){
        int offset = i * t->BlockSize();
        t->ProcessBlock(block + offset);
    }

    delete t;
}
