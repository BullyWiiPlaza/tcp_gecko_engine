#include "tcpgecko_retainvars.h"

#include <malloc.h>
#include <string.h>

screenshotBufferInfo tcpgecko_screenshotBufferInfo __attribute__((section(".data")));
bool tcpg_isCodeHandlerInstalled __attribute__((section(".data")))= false;
bool tcpg_areSDCheatsEnabled __attribute__((section(".data")))= false;
OSThread tcpgecko_thread __attribute__((section(".data")));
unsigned char tcpgecko_stack[TCPGECKO_THREAD_STACKSIZE] __attribute__((section(".data")));

void TCPGeckoRetainVars::resetThread(){
    memset(&tcpgecko_thread,0,sizeof(tcpgecko_thread));
    memset(&tcpgecko_stack,0,sizeof(tcpgecko_stack));
}

OSThread * TCPGeckoRetainVars::getThreadPointer(){
    return &tcpgecko_thread;
}

void* TCPGeckoRetainVars::getThreadStackPointer(){
    return &tcpgecko_stack;
}

u32 TCPGeckoRetainVars::getThreadStackSize(){
    return TCPGECKO_THREAD_STACKSIZE;
}

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
