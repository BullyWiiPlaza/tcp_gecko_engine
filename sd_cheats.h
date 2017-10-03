#ifndef TCPGECKO_SD_CHEATS_H
#define TCPGECKO_SD_CHEATS_H

#include <gctypes.h>

class SDCheats{
    friend class TCPGecko;
private:
    static bool applySDCheats(const char * filePath);

    static int LoadFileToMem(const char *filepath, u8 **inbuffer, u32 *size);
};

#endif
