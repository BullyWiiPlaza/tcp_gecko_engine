#include "tcpgecko_retainvars.h"

#include <malloc.h>
#include <string.h>

screenshotBufferInfo tcpgecko_screenshotBufferInfo __attribute__((section(".data")));
bool tcpg_isCodeHandlerInstalled __attribute__((section(".data")))= false;
bool tcpg_areSDCheatsEnabled __attribute__((section(".data")))= false;

void TCPGeckoRetainVars::setShouldTakeScreenShot(bool value){
    TCPGeckoRetainVars::getScreenshotBuffer()->shouldTakeScreenShot = value;
}

screenshotBufferInfo* TCPGeckoRetainVars::getScreenshotBuffer(){
    return &tcpgecko_screenshotBufferInfo;
}

void TCPGeckoRetainVars::setCodeHandlerInstalled(bool val){
    tcpg_isCodeHandlerInstalled = val;
}

bool TCPGeckoRetainVars::isCodeHandlerInstalled(){
    return tcpg_isCodeHandlerInstalled;
}

void TCPGeckoRetainVars::setSDCheatsEnabled(bool val){
    tcpg_areSDCheatsEnabled = val;
}

bool TCPGeckoRetainVars::areSDCheatsEnabled(){
    return tcpg_areSDCheatsEnabled;
}
