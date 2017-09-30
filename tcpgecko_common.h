#ifndef TCPGECKO_COMMON_H
#define TCPGECKO_COMMON_H

#ifdef __cplusplus
extern "C" {
#endif

#define CODE_HANDLER_INSTALL_ADDRESS 0x010F4000

#define CODE_FOLDER                 "codes"
#define CODEFILE_EXTENSION          ".gctu"

#ifndef MEM_BASE
    #define MEM_BASE                    (0x00800000)
#endif

#ifndef OS_FIRMWARE
    #define OS_FIRMWARE                 (*(volatile unsigned int*)(MEM_BASE + 0x1400 + 0x04))
#endif

#ifndef OS_SPECIFICS
    #define OS_SPECIFICS                ((OsSpecifics*)(MEM_BASE + 0x1500))
#endif

#ifdef __cplusplus
}
#endif

#endif
