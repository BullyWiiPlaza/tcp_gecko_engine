#include "tcpgecko_retainvars.h"

bool tcpg_shouldTakeScreenShot __attribute__((section(".data"))) = false;
u32 tcpg_remainingImageSize __attribute__((section(".data"))) = 0;
u32 tcpg_totalImageSize __attribute__((section(".data"))) = 0;
s32 tcpg_bufferedImageSize __attribute__((section(".data"))) = 0;
void * tcpg_bufferedImageData __attribute__((section(".data"))) = NULL;
