#ifndef TCPGECKO_DISASSEMBLER_H
#define TCPGECKO_DISASSEMBLER_H

class TCPGeckoDisassembler{
    friend class TCPGecko;
private:
    static void formatDisassembled(char *format, ...);
};

#endif
