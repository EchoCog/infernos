#ifndef LIB9_H
#define LIB9_H

#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <setjmp.h>
#include <unistd.h>

/* Basic Plan 9 types */
#define nil ((void*)0)
typedef unsigned short ushort;
typedef unsigned char uchar;
typedef unsigned long ulong;
typedef unsigned int uint;
typedef signed char schar;
typedef long long vlong;
typedef unsigned long long uvlong;
typedef uint Rune;

/* UTF/Rune constants */
enum {
	UTFmax = 4,                /* maximum bytes per rune */
	Runesync = 0x80,          /* cannot represent part of a UTF sequence (<) */
	Runeself = 0x80,          /* rune and UTF sequences are the same (<) */
	Runeerror = 0xFFFD,       /* decoding error in UTF */
	Runemax = 0x10FFFF,       /* 21-bit rune */
	Runemask = 0x1FFFFF,      /* bits used by runes (see grep) */
};

/* Utility macros */
#define nelem(x) (sizeof(x)/sizeof((x)[0]))

/* Function prototypes - using extern to reference from kern.h or other libraries */
extern int chartorune(Rune*, char*);
extern char* utfrune(char*, long);

/* Plan 9 style exits function - map to standard exit */
#define exits(s) exit((s) ? 1 : 0)

#endif // LIB9_H