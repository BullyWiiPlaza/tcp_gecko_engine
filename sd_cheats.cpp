#include <stdio.h> // snprintf
#include <string.h> // memcpy, memset
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <malloc.h>
#include "../utils/logger.h"
#include "../dynamic_libs/os_functions.h"
#include "tcp_gecko.h"
#include "sd_cheats.h"
#include "../kernel/syscalls.h"

#define CODE_HANDLER_ENABLED_ADDRESS 0x10014CFC
#define CODE_LIST_START_ADDRESS 0x01133000

u64 cachedTitleID;

unsigned char *kernelCopyBufferOld2[DATA_BUFFER_SIZE];

static void kernelCopyData2(unsigned char *destinationBuffer, unsigned char *sourceBuffer, unsigned int length) {
	if (length > DATA_BUFFER_SIZE) {
		OSFatal("Kernel copy buffer size exceeded");
	}

	memcpy(kernelCopyBufferOld2, sourceBuffer, length);
	SC0x25_KernelCopyData((unsigned int) OSEffectiveToPhysical(destinationBuffer),
						  (unsigned int) &kernelCopyBufferOld2,
						  length);
	DCFlushRange(destinationBuffer, (u32) length);
}

static void setCodeHandlerEnabled(bool enabled) {
	unsigned int *codeHandlerEnabled = (unsigned int *) CODE_HANDLER_ENABLED_ADDRESS;
	*codeHandlerEnabled = (unsigned int) enabled;
	log_printf("Code handler status: %i\n", enabled);
}

/*void testMount() {
	int res = IOSUHAX_Open(NULL);
	log_printf("Result: %i", res);

	if (res < 0) {//
		mount_sd_fat("sd"); // Fallback to normal OS implementation
	} else {
		fatInitDefault(); // using libfat
	}

	log_print("Unmounting...");
	fatUnmount("sd");
	fatUnmount("usb");
	log_print("Closing...");
	IOSUHAX_Close();
	log_print("DONE");
}*/


int SDCheats::LoadFileToMem(const char *filepath, u8 **inbuffer, u32 *size) {
	// Always initialize input
	*inbuffer = NULL;
	if (size)
		*size = 0;

	int iFd = open(filepath, O_RDONLY);
	if (iFd < 0)
		return -1;

	u32 filesize = lseek(iFd, 0, SEEK_END);
	lseek(iFd, 0, SEEK_SET);

	u8 *buffer = (u8 *) malloc(filesize);
	if (buffer == NULL) {
		close(iFd);
		return -2;
	}

	u32 blocksize = 0x4000;
	u32 done = 0;
	int readBytes = 0;

	while (done < filesize) {
		if (done + blocksize > filesize) {
			blocksize = filesize - done;
		}
		readBytes = read(iFd, buffer + done, blocksize);
		if (readBytes <= 0)
			break;
		done += readBytes;
	}

	close(iFd);

	if (done != filesize) {
		free(buffer);
		return -3;
	}

	*inbuffer = buffer;

	//! sign is optional input
	if (size)
		*size = filesize;

	return filesize;
}

bool SDCheats::applySDCheats(const char * filePath){
    if(filePath == NULL || *filePath == 0) return false;
    unsigned char *codes = NULL;
    u32 codesSize = 0;
    s32 result = SDCheats::LoadFileToMem((const char *) filePath, &codes, &codesSize);

    if (result < 0) {
        DEBUG_FUNCTION_LINE("LoadFileToMem() error: %i\n", result);
        setCodeHandlerEnabled(false);
        // Error, we won't write any codes
        return false;
    }

    DEBUG_FUNCTION_LINE("Copying...\n");
    kernelCopyData2((unsigned char *) CODE_LIST_START_ADDRESS, codes, (unsigned int) codesSize);
    DEBUG_FUNCTION_LINE("Copied!\n");
    setCodeHandlerEnabled(true);

    return true;
}
