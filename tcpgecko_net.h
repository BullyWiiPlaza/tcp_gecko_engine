#ifndef TCPGECKO_NETWORK_H_
#define TCPGECKO_NETWORK_H_
    int tcpg_recvwait(int sock, void *buffer, int len);
    int tcpg_recvwaitlen(int sock, void *buffer, int len);
    int tcpg_recvbyte(int sock);
    int tcpg_sendwait(int sock, const void *buffer, int len);
    int tcpg_sendbyte(int sock, unsigned char byte);
#endif
