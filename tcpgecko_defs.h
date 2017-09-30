#pragma once

#define DATA_BUFFER_SIZE 0x5000

#define TCPGECKO_THREAD_STACKSIZE   0x6F00

// The dynamically allocated buffer size for the image copy
#define IMAGE_BUFFER_SIZE 100

// The time the producer and consumer wait while there is nothing to do
#define WAITING_TIME_MILLISECONDS 1

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
