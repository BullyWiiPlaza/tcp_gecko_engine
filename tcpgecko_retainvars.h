#ifndef TCPGECKO_RETAINS_VARS_H_
#define TCPGECKO_RETAINS_VARS_H_
#include <gctypes.h>

// The dynamically allocated buffer size for the image copy
#define IMAGE_BUFFER_SIZE 100

// The time the producer and consumer wait while there is nothing to do
#define WAITING_TIME_MILLISECONDS 1

// Flag for telling the hook whether to dump a screen shot
extern bool tcpg_shouldTakeScreenShot;

// Indication for the consumer how many bytes are there to read in total
extern u32 tcpg_totalImageSize;

// Indication for the consumer how many bytes are left to read
extern u32 tcpg_remainingImageSize;

// Indication for the consumer how many bytes can be read from the buffer at once
extern s32 tcpg_bufferedImageSize;

// The actual image data buffer for the consumer to consume
extern void * tcpg_bufferedImageData;

#endif // TCPGECKO_RETAINS_VARS_H_
