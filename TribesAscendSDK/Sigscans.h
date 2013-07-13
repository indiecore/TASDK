#pragma once
#include <Psapi.h>

const byte kSigObjects[] = "\xA1\x00\x00\x00\x00\x83\x3C\xB0\x00";
const char kMaskObjects[] = "x????xxxx";

const byte kSigNames[] = "\x8B\x0D\x00\x00\x00\x00\x89\x04\xB1";
const char kMaskNames[] = "xx????xxx";

const byte kSigNatives[] = "\x89\x14\x85\x00\x00\x00\x00\x32\xC0\xC3";
const char kMaskNatives[] = "xxx????xxx";

const byte kSigCleanupStack[] = "\x55\x8B\xEC\x51\xA1\x00\x00\x00\x00\x33\xC5\x89\x45\xFC\x53\x56\x57";
const char kMaskCleanupStack[] = "xxxxx????xxxxxxxx";

const byte kSigCallFunction[] = "\x55\x8D\xAC\x24\x00\x00\x00\x00\x81\xEC\x00\x00\x00\x00\x6A\xFF\x68\x00\x00\x00\x00\x64\xA1\x00\x00\x00\x00\x50\x83\xEC\x40";
const char kMaskCallFunction[] = "xxxx????xx????xxx????xx????xxxx";

MODULEINFO GetModuleInfo( char *module_name );
uintptr_t FindPattern( void *start_address, uintptr_t file_size, const byte *pattern, const char *mask );