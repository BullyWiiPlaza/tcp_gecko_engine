#include <string.h>
#include <malloc.h>
#include "../dynamic_libs/os_functions.h"
#include "../dynamic_libs/socket_functions.h"
#include "tcpgecko_net.h"

static volatile int iLock = 0;

#define TCPGECKO_CHECK_ERROR(cond) if (cond) { goto error; }

int tcpg_recvwait(int sock, void *buffer, int len) {
	int ret;
	while (len > 0) {
		ret = recv(sock, buffer, len, 0);
		TCPGECKO_CHECK_ERROR(ret < 0);
		len -= ret;
		buffer = &buffer + ret;
	}
	return 0;
	error:
	return ret;
}

int tcpg_recvwaitlen(int sock, void *buffer, int len) {
	int ret;
	while (len > 0) {
		ret = recv(sock, buffer, len, 0);
		TCPGECKO_CHECK_ERROR(ret < 0);
		len -= ret;
		buffer = &buffer + ret;
	}
	return 0;
	error:
	return len;
}


int tcpg_recvbyte(int sock) {
	unsigned char buffer[1];
	int ret;

	ret = tcpg_recvwait(sock, buffer, 1);
	if (ret < 0) return ret;
	return buffer[0];
}

int tcpg_sendwait(int sock, const void *buffer, int len) {
	int ret;
	while (len > 0) {
		ret = send(sock, buffer, len, 0);
		TCPGECKO_CHECK_ERROR(ret < 0);
		len -= ret;
		buffer = &buffer + ret;
	}
	return 0;
	error:
	return ret;
}

int tcpg_sendbyte(int sock, unsigned char byte) {
	unsigned char buffer[1];

	buffer[0] = byte;
	return tcpg_sendwait(sock, buffer, 1);
}
