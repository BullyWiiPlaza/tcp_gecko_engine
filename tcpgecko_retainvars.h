#ifndef TCPGECKO_RETAINS_VARS_H_
#define TCPGECKO_RETAINS_VARS_H_
#include <gctypes.h>
#include "dynamic_libs/os_types.h"
#include "tcpgecko_defs.h"


class TCPGeckoRetainVars{
    friend class TCPGecko;
private:
    static void setShouldTakeScreenShot(bool value);

    static OSThread * getThreadPointer();

    static void* getThreadStackPointer();

    static u32 getThreadStackSize();

    static void setCodeHandlerInstalled(bool val);

    static screenshotBufferInfo* getScreenshotBuffer();

    static void resetThread();

    static bool isCodeHandlerInstalled();

    static void setSDCheatsEnabled(bool val);

    static bool areSDCheatsEnabled();
};
#endif // TCPGECKO_RETAINS_VARS_H_
