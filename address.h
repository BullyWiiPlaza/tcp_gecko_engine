#ifndef TCPGECKO_ADDRESS_H
#define TCPGECKO_ADDRESS_H

#include <stdbool.h>
class AddressUtils{
    friend class TCPGecko;
private:
    static int validateAddressRange(int starting_address, int ending_address);

    //static bool isValidDataAddress(int address);

    static int roundUpToAligned(int number);
};

#endif
