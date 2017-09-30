#include "../dynamic_libs/os_functions.h"
#include "../dynamic_libs/socket_functions.h"
#include "tcpgecko_net.h"
#include "assertions.h"

s32 TCPGeckoNet::recvwait(s32 sock, void *buffer, s32 len) {
	s32 ret;
	while (len > 0) {
		ret = recv(sock, buffer, len, 0);
		if(ret < 0) return ret;
		len -= ret;
		buffer =  (void *)(((char *) buffer) + ret);
	}
	return 0;
}

u8 TCPGeckoNet::recvbyte(s32 sock) {
	unsigned char buffer[1];
	s32 ret;

	ret = recvwait(sock, buffer, 1);
	if (ret < 0) return ret;
	return buffer[0];
}

s32 TCPGeckoNet::checkbyte(s32 sock) {
	unsigned char buffer[1];
	s32 ret;

	ret = recv(sock, buffer, 1, MSG_DONTWAIT);
	if (ret < 0) return ret;
	if (ret == 0) return -1;
	return buffer[0];
}

s32 TCPGeckoNet::sendwait(s32 sock, const void *buffer, s32 len) {
	s32 ret;
	while (len > 0) {
		ret = send(sock, buffer, len, 0);
		if(ret < 0) return ret;
		len -= ret;
		buffer =  (void *)(((char *) buffer) + ret);
	}
	return 0;
}

s32 TCPGeckoNet::sendbyte(s32 sock, unsigned char byte) {
	unsigned char buffer[1];
	buffer[0] = byte;
	return sendwait(sock, buffer, 1);
}

u32 TCPGeckoNet::receiveString(int clientfd, unsigned char *stringBuffer, unsigned int bufferSize) {
	// Receive the string length
	unsigned char lengthBuffer[4] = {0};
	int ret = TCPGeckoNet::recvwait(clientfd, lengthBuffer, sizeof(int));
	ASSERT_FUNCTION_SUCCEEDED(ret, "recvwait (string length)")
	unsigned int stringLength = ((unsigned int *) lengthBuffer)[0];

	if (stringLength <= bufferSize) {
		// Receive the actual string
		ret = TCPGeckoNet::recvwait(clientfd, stringBuffer, stringLength);
		ASSERT_FUNCTION_SUCCEEDED(ret, "recvwait (string)")
	} else {
		OSFatal("String buffer size exceeded");
	}

	return stringLength;
}
