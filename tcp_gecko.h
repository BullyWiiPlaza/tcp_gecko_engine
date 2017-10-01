#pragma once

#include <stdio.h>
#include <string.h>
#include <malloc.h>

#include "code_handler.h"
#include "sd_cheats.h"
#include "title.h"
#include "tcpgecko_retainvars.h"
#include "tcpgecko_defs.h"


class TCPGecko{
public:
    static void startTCPGecko(void);
    static void stopAndCleanupTCPGecko(void);

    static void installCodeHandler();

    static bool isRunningAllowedTitleID(){
        return TitleUtils::isRunningAllowedTitleID();
    }

    static bool shouldLoadSDCheats(){
        return SDCheats::shouldLoadSDCheats();
    }

    static bool applySDCheats(const char * basePath){
        return SDCheats::applySDCheats(basePath);
    }

    static bool areSDCheatsEnabled(){
        return TCPGeckoRetainVars::areSDCheatsEnabled();
    }

    static void setSDCheatsEnabled(bool val){
        TCPGeckoRetainVars::setSDCheatsEnabled(val);
    }

    static bool isCodeHandlerInstalled(){
        return TCPGeckoRetainVars::isCodeHandlerInstalled();
    }

    static void setCodeHandlerInstalled(bool val){
        TCPGeckoRetainVars::setCodeHandlerInstalled(val);
    }

    static void resetScreenshotBuffer(){
        free(TCPGeckoRetainVars::getScreenshotBuffer()->bufferedImageData);
        memset(TCPGeckoRetainVars::getScreenshotBuffer(),0,sizeof(screenshotBufferInfo));
    }

    static bool shouldTakeScreenShot(){
        return getScreenshotBuffer()->shouldTakeScreenShot;
    }

    static screenshotBufferInfo* getScreenshotBuffer(){
        return TCPGeckoRetainVars::getScreenshotBuffer();
    }

private:
    static int processCommands(int clientfd);
    static s32 runTCPGeckoServer(s32 argc, void *argv);
    static s32 startTCPGeckoThread(s32 argc, void *argv);
    static void reportIllegalCommandByte(int commandByte);
    static void considerInitializingFileSystem();


    static unsigned char * getCodeHandlerAddress(){
        return (unsigned char *) codeHandler;
    }

    static unsigned int getCodeHandlerLength(){
        return codeHandlerLength;
    }

    static void setShouldTakeScreenShot(bool value){
        getScreenshotBuffer()->shouldTakeScreenShot = value;
    }

    static u32 getThreadStackSize(){
        return TCPGECKO_THREAD_STACKSIZE;
    }

    //static void writeScreen(char message[100], int secondsDelay);
};
