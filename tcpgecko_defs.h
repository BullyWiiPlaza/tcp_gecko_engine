#pragma once

#ifndef MEM_BASE
    #define MEM_BASE                    (0x00800000)
#endif

#ifndef OS_FIRMWARE
    #define OS_FIRMWARE                 (*(volatile unsigned int*)(MEM_BASE + 0x1400 + 0x04))
#endif

#ifndef OS_SPECIFICS
    #define OS_SPECIFICS                ((OsSpecifics*)(MEM_BASE + 0x1500))
#endif

#define _TCPGECKO_CODE_HANDLER_INSTALL_ADDRESS 0x010F4000

#define TCPGECKO_CODE_FOLDER                 "codes"
#define TCPGECKO_CODEFILE_EXTENSION          "gctu"

#define DATA_BUFFER_SIZE 0x5000

#define TCPGECKO_THREAD_STACKSIZE   0x6F00

// The dynamically allocated buffer size for the image copy
#define TCPGECKO_IMAGE_BUFFER_SIZE 100

// The time the producer and consumer wait while there is nothing to do
#define TCPGECKO_WAITING_TIME_MILLISECONDS 1

/**
 *  @brief
 */
typedef struct _screenshotBufferInfo{
// Flag for telling the hook whether to dump a screen shot
bool shouldTakeScreenShot;
// Indication for the consumer how many bytes are there to read in total
u32 totalImageSize;
// Indication for the consumer how many bytes are left to read
u32 remainingImageSize;
// Indication for the consumer how many bytes can be read from the buffer at once
s32 bufferedImageSize;
// The actual image data buffer for the consumer to consume
void * bufferedImageData;
}screenshotBufferInfo;
