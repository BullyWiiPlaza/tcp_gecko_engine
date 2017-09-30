#include "../dynamic_libs/os_functions.h"
#include "address.h"

int AddressUtils::validateAddressRange(int starting_address, int ending_address) {
	return __OSValidateAddressSpaceRange(1, (void *) starting_address, ending_address - starting_address + 1);
}

/*bool AddressUtils::isValidDataAddress(int address) {
	return OSIsAddressValid((const void *) address)
		   && address >= 0x10000000
		   && address < 0x50000000;
}*/

int AddressUtils::roundUpToAligned(int number) {
	return (number + 3) & ~0x03;
}
