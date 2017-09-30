#ifndef TCPGECKO_NETWORK_H_
#define TCPGECKO_NETWORK_H_
class TCPGeckoNet{
    friend class TCPGecko;
    private:
        static s32 recvwait(s32 sock, void *buffer, s32 len);
        static u8 recvbyte(s32 sock);
        static s32 checkbyte(s32 sock);
        static s32 sendwait(s32 sock, const void *buffer, s32 len);
        static s32 sendbyte(s32 sock, unsigned char byte);
        static u32 receiveString(int clientfd, unsigned char *stringBuffer, unsigned int bufferSize);
};
#endif
