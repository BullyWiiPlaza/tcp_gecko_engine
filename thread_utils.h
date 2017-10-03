#ifndef TCPGECKO_THREAD_UTILS_H
#define TCPGECKO_THREAD_UTILS_H

class ThreadUtils{
    friend class TCPGecko;
private:
    static struct node *getAllThreads();
};
#endif
