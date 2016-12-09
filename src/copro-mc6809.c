/*
 * 6809 Co Pro Emulation
 *
 * (c) 2016 David Banks
 */
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include "tube-defs.h"
#include "tube.h"
#include "tube-ula.h"
#include "startup.h"

#include "copro-mc6809.h"

#ifdef USE_HD6309
#include "mc6809/hd6309.h"
#else
#include "mc6809/mc6809.h"
#endif

struct MC6809 *mc6809;

static int overlay_rom = 0;

static unsigned char *copro_mc6809_ram;

// http://mdfs.net/Software/Tube/6809/Client09.bin
// MD5sum = 853e3aea82287c0a3626e9fd727366cd  C
unsigned char copro_mc6809_rom[0x800] = {
  0xf8, 0x2c, 0xf8, 0x71, 0xff, 0xe0, 0xf8, 0xe0, 0xf8, 0xf4, 0xff, 0xee,
  0xf8, 0xe9, 0xff, 0xe7, 0xf8, 0xe6, 0xf8, 0xdf, 0x20, 0x5b, 0x0d, 0x36,
  0x38, 0x30, 0x39, 0x20, 0x54, 0x55, 0x42, 0x45, 0x20, 0x36, 0x34, 0x4b,
  0x20, 0x31, 0x2e, 0x30, 0x30, 0x20, 0x0d, 0x00, 0x1a, 0x50, 0x10, 0xce,
  0xf8, 0x00, 0x1f, 0x41, 0xec, 0x84, 0xed, 0x81, 0x8c, 0xfe, 0xc0, 0x26,
  0x03, 0x8e, 0xfe, 0xf0, 0x8c, 0xff, 0x8c, 0x26, 0x03, 0x8e, 0xff, 0x94,
  0x8c, 0x00, 0x00, 0x26, 0xe7, 0xb6, 0xfe, 0xe0, 0x1a, 0x50, 0x10, 0xce,
  0xff, 0x28, 0x8d, 0x68, 0xbe, 0xff, 0x90, 0xbf, 0xff, 0x8e, 0x1c, 0x00,
  0x8e, 0xf8, 0x16, 0xbd, 0xf9, 0x33, 0xbd, 0xff, 0xe7, 0x4f, 0xbd, 0xff,
  0xee, 0x4f, 0xbd, 0xfa, 0x30, 0x10, 0xce, 0xff, 0x28, 0x8d, 0x49, 0x10,
  0xfe, 0xff, 0x8a, 0x8e, 0xff, 0xb9, 0xbf, 0xff, 0x90, 0x1c, 0x00, 0x8e,
  0xf8, 0x96, 0xbd, 0xf9, 0x33, 0xbd, 0xff, 0xf1, 0x25, 0x14, 0x8e, 0xff,
  0x28, 0xbd, 0xff, 0xf7, 0x20, 0xed, 0x36, 0x38, 0x30, 0x39, 0x3e, 0x2a,
  0x00, 0xff, 0x28, 0x57, 0x20, 0xff, 0x86, 0x7e, 0xbd, 0xff, 0xf4, 0x3f,
  0x11, 0x45, 0x73, 0x63, 0x61, 0x70, 0x65, 0x00, 0x10, 0xfe, 0xff, 0x8a,
  0xbd, 0xff, 0xe7, 0xa6, 0x80, 0x8d, 0x78, 0xbd, 0xff, 0xe7, 0x20, 0xc3,
  0xcc, 0x00, 0x00, 0xfd, 0xff, 0x88, 0xcc, 0xf8, 0x00, 0xfd, 0xff, 0x8a,
  0xcc, 0xf8, 0xb0, 0xfd, 0xff, 0xfa, 0xcc, 0xfe, 0x22, 0xfd, 0xfe, 0xfa,
  0x8e, 0xff, 0xfa, 0x10, 0x8e, 0xff, 0x80, 0x39, 0xbd, 0xff, 0xe0, 0x7e,
  0xff, 0xee, 0xbd, 0xff, 0xe7, 0xa6, 0x80, 0x81, 0x04, 0x27, 0xf0, 0xbd,
  0xff, 0xee, 0x20, 0xf5, 0x34, 0x32, 0x86, 0x80, 0x8e, 0xff, 0xff, 0x1f,
  0x12, 0xbd, 0xff, 0xf4, 0x8c, 0x00, 0x00, 0x35, 0xb2, 0x34, 0x06, 0x1f,
  0x10, 0x8d, 0x06, 0x1f, 0x98, 0x8d, 0x02, 0x35, 0x86, 0x34, 0x02, 0x44,
  0x44, 0x44, 0x44, 0x8d, 0x06, 0xa6, 0xe4, 0x8d, 0x02, 0x35, 0x82, 0x84,
  0x0f, 0x81, 0x0a, 0x25, 0x02, 0x8b, 0x07, 0x8b, 0x30, 0x7e, 0xff, 0xee,
  0x35, 0x10, 0x8d, 0x03, 0x34, 0x10, 0x39, 0xa6, 0x80, 0x27, 0xfb, 0xbd,
  0xff, 0xe3, 0x20, 0xf7, 0x10, 0x8e, 0x00, 0x00, 0xa6, 0x80, 0x81, 0x30,
  0x25, 0x2b, 0x81, 0x3a, 0x25, 0x0a, 0x84, 0xdf, 0x80, 0x07, 0x25, 0x21,
  0x81, 0x40, 0x24, 0x1d, 0x84, 0x0f, 0x1e, 0x02, 0x58, 0x49, 0x58, 0x49,
  0x58, 0x49, 0x58, 0x49, 0x1e, 0x12, 0x1e, 0x01, 0x1e, 0x89, 0x3a, 0x1e,
  0x12, 0x20, 0xd5, 0xa6, 0x80, 0x81, 0x20, 0x27, 0xfa, 0x30, 0x1f, 0x81,
  0x21, 0x39, 0x34, 0x7c, 0x11, 0x8c, 0xf8, 0x00, 0x24, 0x08, 0x10, 0xff,
  0xf9, 0x8a, 0x10, 0xce, 0xff, 0x28, 0x8d, 0x0f, 0x10, 0xce, 0x00, 0x00,
  0x35, 0xfc, 0x48, 0x45, 0x4c, 0x50, 0x80, 0x47, 0x4f, 0x81, 0x00, 0x8d,
  0xd2, 0xa6, 0x80, 0x81, 0x2a, 0x27, 0xf8, 0x30, 0x1f, 0x34, 0x10, 0xa6,
  0x80, 0x81, 0x21, 0x24, 0xfa, 0x30, 0x1f, 0x8d, 0xbe, 0xbf, 0xff, 0x86,
  0x10, 0x8e, 0xf9, 0x8e, 0xae, 0xe4, 0xa6, 0x84, 0x81, 0x41, 0x25, 0x68,
  0xa6, 0x80, 0x84, 0xdf, 0xa1, 0xa0, 0x27, 0xf8, 0xa6, 0xa2, 0x2b, 0x16,
  0xa6, 0x1f, 0x81, 0x2e, 0x27, 0x0a, 0xa6, 0xa0, 0x2a, 0xfc, 0xa6, 0xa4,
  0x26, 0xde, 0x20, 0x4c, 0xa6, 0xa0, 0x2a, 0xfc, 0x20, 0x06, 0xe6, 0x82,
  0xc1, 0x21, 0x24, 0x40, 0x81, 0x80, 0x27, 0x2d, 0x8d, 0x81, 0x10, 0xbe,
  0xff, 0x90, 0x81, 0x0d, 0x27, 0x18, 0x81, 0x3b, 0x27, 0x12, 0xbd, 0xff,
  0xa1, 0x24, 0x29, 0xbd, 0xf9, 0x6b, 0x81, 0x3b, 0x27, 0x06, 0x81, 0x0d,
  0x26, 0x1e, 0x30, 0x1f, 0x30, 0x01, 0xbf, 0xff, 0x86, 0x35, 0x10, 0x1f,
  0x21, 0x1a, 0x01, 0x20, 0x23, 0xbd, 0xf9, 0x6b, 0x25, 0x04, 0x81, 0x2e,
  0x26, 0x06, 0x8e, 0xf8, 0x16, 0xbd, 0xf9, 0x33, 0x35, 0x10, 0x86, 0x02,
  0xbd, 0xfc, 0xde, 0xbd, 0xfc, 0xa2, 0x1a, 0x01, 0xbd, 0xfa, 0xb4, 0x2a,
  0x51, 0xbe, 0xff, 0x8e, 0x34, 0x01, 0x1f, 0x12, 0xe6, 0x07, 0x3a, 0xce,
  0xfa, 0x93, 0xc6, 0x04, 0xa6, 0x80, 0xa1, 0xc2, 0x26, 0x3d, 0x5a, 0x26,
  0xf7, 0xa6, 0x26, 0x48, 0x2a, 0x41, 0x84, 0x1e, 0x81, 0x06, 0x26, 0x3b,
  0x30, 0x1c, 0xbf, 0xff, 0x82, 0xfe, 0xff, 0x90, 0xbe, 0xff, 0x8a, 0x35,
  0x02, 0x34, 0x50, 0x10, 0x8c, 0x80, 0x00, 0x25, 0x04, 0x10, 0xbf, 0xff,
  0x8a, 0x10, 0xbf, 0xff, 0x90, 0x46, 0xbe, 0xff, 0x86, 0x86, 0x01, 0xad,
  0xa4, 0x35, 0x60, 0x10, 0xbf, 0xff, 0x8a, 0xff, 0xff, 0x90, 0x39, 0xbe,
  0xff, 0x86, 0x4f, 0x35, 0x01, 0x6e, 0xa4, 0x29, 0x43, 0x28, 0x00, 0x35,
  0x01, 0x10, 0x24, 0x05, 0x20, 0xbd, 0xf8, 0xcc, 0x3f, 0xf9, 0x4e, 0x6f,
  0x74, 0x20, 0x36, 0x38, 0x30, 0x39, 0x20, 0x63, 0x6f, 0x64, 0x65, 0x00,
  0x4f, 0xbd, 0xfc, 0xde, 0x8d, 0x02, 0x8b, 0x80, 0xb6, 0xfe, 0xe2, 0x2a,
  0xfb, 0xb6, 0xfe, 0xe3, 0x39, 0x34, 0x06, 0x4d, 0x2b, 0x23, 0x86, 0x04,
  0xbd, 0xfc, 0xde, 0x1f, 0x10, 0xbd, 0xfc, 0xdc, 0x35, 0x06, 0x34, 0x06,
  0xbd, 0xfc, 0xde, 0x8d, 0xdf, 0x1f, 0x89, 0x4f, 0x1f, 0x01, 0x35, 0x86,
  0x8e, 0xf8, 0x16, 0xbf, 0xff, 0x86, 0x7e, 0xfa, 0x2e, 0x81, 0x82, 0x27,
  0x39, 0x81, 0x83, 0x27, 0x37, 0x81, 0x84, 0x27, 0x33, 0x86, 0x06, 0xbd,
  0xfc, 0xde, 0x1f, 0x10, 0xbd, 0xfc, 0xdc, 0xbd, 0xfc, 0xda, 0x35, 0x06,
  0xbd, 0xfc, 0xde, 0x81, 0x9d, 0x27, 0xb5, 0x81, 0x8e, 0x27, 0xd1, 0x34,
  0x06, 0x8d, 0xa5, 0x8b, 0x80, 0x34, 0x01, 0x8d, 0x9f, 0x1f, 0x89, 0x4f,
  0x1f, 0x02, 0x8d, 0x98, 0x1e, 0x89, 0x1f, 0x01, 0x35, 0x87, 0x86, 0x85,
  0x48, 0x8e, 0xff, 0x82, 0xec, 0x84, 0x1f, 0x01, 0x1f, 0x89, 0x4f, 0x1f,
  0x02, 0x35, 0x86, 0x4d, 0x27, 0x5c, 0x34, 0x26, 0x34, 0x10, 0x1f, 0x89,
  0x86, 0x08, 0xbd, 0xfc, 0xde, 0xbd, 0xfc, 0xdc, 0x5d, 0x2a, 0x04, 0xa6,
  0x84, 0x20, 0x0c, 0x86, 0x10, 0xc1, 0x15, 0x24, 0x06, 0x8e, 0xfb, 0xc1,
  0x3a, 0xa6, 0x84, 0x35, 0x10, 0xbd, 0xfc, 0xde, 0x1f, 0x02, 0x1e, 0x89,
  0x4f, 0x1e, 0x02, 0x4a, 0x2b, 0x03, 0xbd, 0xfc, 0xab, 0x34, 0x10, 0x5d,
  0x2a, 0x04, 0xa6, 0x01, 0x20, 0x0c, 0x86, 0x10, 0xc1, 0x15, 0x24, 0x06,
  0x8e, 0xfb, 0xd5, 0x3a, 0xa6, 0x84, 0x35, 0x10, 0xbd, 0xfc, 0xde, 0x1f,
  0x02, 0x1e, 0x89, 0x4f, 0x1e, 0x02, 0x4a, 0x2b, 0x03, 0xbd, 0xfc, 0xbb,
  0x35, 0xa6, 0x86, 0x0a, 0xbd, 0xfc, 0xde, 0x30, 0x02, 0x10, 0x8e, 0x00,
  0x03, 0xbd, 0xfc, 0xab, 0x30, 0x1e, 0x86, 0x07, 0xbd, 0xfc, 0xde, 0x4f,
  0xbd, 0xfc, 0xde, 0xbd, 0xfa, 0xb4, 0x8b, 0x80, 0x25, 0x0f, 0xae, 0x84,
  0xbd, 0xfa, 0xb4, 0xa7, 0x80, 0x31, 0x21, 0x81, 0x0d, 0x26, 0xf5, 0x31,
  0x3f, 0x39, 0x00, 0x05, 0x00, 0x05, 0x04, 0x05, 0x08, 0x0e, 0x04, 0x01,
  0x01, 0x05, 0x00, 0x10, 0x20, 0x10, 0x0d, 0x00, 0x04, 0x80, 0x05, 0x00,
  0x05, 0x00, 0x05, 0x00, 0x00, 0x00, 0x05, 0x09, 0x05, 0x00, 0x08, 0x19,
  0x00, 0x01, 0x0d, 0x80, 0x04, 0x80, 0x34, 0x26, 0x86, 0x0c, 0xbd, 0xfc,
  0xde, 0xbd, 0xfc, 0xda, 0x10, 0x8e, 0x00, 0x04, 0xbd, 0xfc, 0xab, 0x35,
  0x06, 0xbd, 0xfc, 0xde, 0xbd, 0xfa, 0xb4, 0x34, 0x02, 0x10, 0x8e, 0x00,
  0x04, 0xbd, 0xfc, 0xbb, 0x35, 0xa2, 0x34, 0x04, 0x86, 0x0e, 0xbd, 0xfc,
  0xde, 0xbd, 0xfc, 0xda, 0x35, 0x04, 0x7e, 0xfa, 0xb0, 0x34, 0x06, 0x86,
  0x10, 0xbd, 0xfc, 0xde, 0xbd, 0xfc, 0xda, 0x35, 0x06, 0x34, 0x06, 0xbd,
  0xfc, 0xde, 0xbd, 0xfa, 0xb4, 0x35, 0x86, 0x34, 0x06, 0x86, 0x12, 0xbd,
  0xfc, 0xde, 0x35, 0x06, 0xbd, 0xfc, 0xde, 0x4d, 0x27, 0x06, 0xbd, 0xfc,
  0xa2, 0x7e, 0xfa, 0xb4, 0x34, 0x04, 0xbd, 0xfc, 0xda, 0xbd, 0xfa, 0xb4,
  0x4f, 0x35, 0x84, 0x34, 0x32, 0x86, 0x14, 0xbd, 0xfc, 0xde, 0x30, 0x02,
  0x10, 0x8e, 0x00, 0x10, 0xbd, 0xfc, 0xab, 0x30, 0x1e, 0xae, 0x84, 0xbd,
  0xfc, 0xa2, 0x35, 0x02, 0xbd, 0xfc, 0xde, 0xbd, 0xfa, 0xb4, 0x35, 0x10,
  0x34, 0x02, 0x30, 0x02, 0x10, 0x8e, 0x00, 0x10, 0xbd, 0xfc, 0xbb, 0x30,
  0x1e, 0x35, 0xa2, 0x34, 0x22, 0x86, 0x16, 0xbd, 0xfc, 0xde, 0x10, 0x8e,
  0x00, 0x0d, 0xbd, 0xfc, 0xab, 0x35, 0x02, 0xbd, 0xfc, 0xde, 0x10, 0x8e,
  0x00, 0x0d, 0xbd, 0xfc, 0xbb, 0x35, 0x20, 0x7e, 0xfa, 0xb0, 0xa6, 0x80,
  0x8d, 0x38, 0x81, 0x0d, 0x26, 0xf8, 0x39, 0x34, 0x04, 0x1f, 0x20, 0x3a,
  0x35, 0x04, 0xa6, 0x82, 0x8d, 0x28, 0x31, 0x3f, 0x26, 0xf8, 0x39, 0x34,
  0x04, 0x1f, 0x20, 0x3a, 0x35, 0x04, 0xbd, 0xfa, 0xb4, 0xa7, 0x82, 0x31,
  0x3f, 0x26, 0xf7, 0x39, 0x34, 0x02, 0xb6, 0xfe, 0xe0, 0x48, 0x2a, 0xfa,
  0x35, 0x02, 0xb7, 0xfe, 0xe1, 0x39, 0x1f, 0x20, 0x1f, 0x98, 0x34, 0x02,
  0xb6, 0xfe, 0xe2, 0x48, 0x2a, 0xfa, 0x35, 0x02, 0xb7, 0xfe, 0xe3, 0x39,
  0x34, 0x02, 0xb6, 0xfe, 0xe6, 0x2b, 0x51, 0xb6, 0xfe, 0xe0, 0x2b, 0x06,
  0x35, 0x02, 0x6e, 0x9f, 0xff, 0xb1, 0xb6, 0xfe, 0xe1, 0x2b, 0x1b, 0x35,
  0x02, 0x34, 0x76, 0x8d, 0x1c, 0x1f, 0x89, 0x4f, 0x1f, 0x02, 0x8d, 0x15,
  0x1f, 0x89, 0x4f, 0x1f, 0x01, 0x8d, 0x0e, 0xad, 0x9f, 0xff, 0xfc, 0x35,
  0x76, 0x3b, 0x48, 0xb7, 0xff, 0x80, 0x35, 0x02, 0x3b, 0xb6, 0xfe, 0xe6,
  0x2b, 0x02, 0x8d, 0x12, 0xb6, 0xfe, 0xe0, 0x2a, 0xf4, 0xb6, 0xfe, 0xe1,
  0x39, 0xb6, 0xfe, 0xe6, 0x2a, 0xfb, 0xb6, 0xfe, 0xe7, 0x39, 0x1c, 0x7f,
  0x34, 0x01, 0x34, 0x02, 0x35, 0x02, 0x34, 0x16, 0xb6, 0xfe, 0xe7, 0x2a,
  0x22, 0x10, 0xce, 0xff, 0x80, 0x8e, 0xff, 0x00, 0xbd, 0xfa, 0xb4, 0x86,
  0x3f, 0xa7, 0x80, 0xbd, 0xfa, 0xb4, 0xa7, 0x80, 0xbd, 0xfa, 0xb4, 0xa7,
  0x80, 0x26, 0xf9, 0x8e, 0xff, 0x01, 0x34, 0x10, 0x7e, 0xff, 0xbc, 0x34,
  0x02, 0x8d, 0xc2, 0x35, 0x02, 0x81, 0x05, 0x26, 0x06, 0x7f, 0xff, 0x94,
  0x35, 0x16, 0x3b, 0x34, 0x02, 0x8d, 0xb2, 0xb7, 0xff, 0x8c, 0x8d, 0xad,
  0xb7, 0xff, 0x8d, 0x8d, 0xa8, 0xb7, 0xff, 0x8e, 0x8d, 0xa3, 0xb7, 0xff,
  0x8f, 0x8d, 0x9e, 0x86, 0xff, 0xb7, 0xff, 0x94, 0x1c, 0xbf, 0xbe, 0xff,
  0x8e, 0xa6, 0xe0, 0x27, 0x6c, 0x81, 0x02, 0x25, 0x5b, 0x27, 0x49, 0x81,
  0x04, 0x25, 0x35, 0x27, 0x6e, 0x5f, 0x81, 0x07, 0x25, 0x11, 0x26, 0x67,
  0xb6, 0xfe, 0xe4, 0x2a, 0xfb, 0xb6, 0xfe, 0xe5, 0xa7, 0x85, 0x5c, 0x26,
  0xf3, 0x20, 0x17, 0xb6, 0xfe, 0xe4, 0x48, 0x2a, 0xfa, 0xa6, 0x85, 0xb7,
  0xfe, 0xe5, 0x5c, 0x26, 0xf2, 0xb6, 0xfe, 0xe4, 0x48, 0x2a, 0xfa, 0xb7,
  0xfe, 0xe5, 0x30, 0x89, 0x01, 0x00, 0x20, 0x38, 0x13, 0xb6, 0xfe, 0xe5,
  0xf6, 0xfe, 0xe5, 0xed, 0x81, 0xb6, 0xff, 0x94, 0x26, 0xf2, 0x20, 0x28,
  0x13, 0xec, 0x81, 0xb7, 0xfe, 0xe5, 0xf7, 0xfe, 0xe5, 0xb6, 0xff, 0x94,
  0x26, 0xf2, 0x20, 0x18, 0x13, 0xb6, 0xfe, 0xe5, 0xa7, 0x80, 0xb6, 0xff,
  0x94, 0x26, 0xf5, 0x20, 0x0b, 0x13, 0xa6, 0x80, 0xb7, 0xfe, 0xe5, 0xb6,
  0xff, 0x94, 0x26, 0xf5, 0xbf, 0xff, 0x8e, 0x35, 0x16, 0x3b, 0x32, 0x6a,
  0x35, 0x10, 0xbf, 0xff, 0x82, 0x1c, 0x00, 0x6e, 0x9f, 0xff, 0xfa, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xfe, 0x21, 0xfe, 0x21, 0xfe, 0x21, 0xfc, 0xec, 0xfe, 0x21, 0xfe, 0x22,
  0xfe, 0x21, 0xf8, 0x2c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0xf8, 0x16, 0xf8, 0xb0, 0xf8, 0x16, 0x00, 0x00, 0xf8, 0x00,
  0x00, 0x00, 0x00, 0x00, 0xff, 0xb9, 0xff, 0x00, 0x00, 0x7e, 0xfa, 0x86,
  0x7e, 0xf8, 0x2c, 0x7e, 0xfa, 0x86, 0x7e, 0xfa, 0x86, 0x7e, 0xf9, 0x3c,
  0x7e, 0xfa, 0x86, 0x7e, 0xf8, 0x71, 0x7e, 0xf9, 0x11, 0x7e, 0xf9, 0x05,
  0x7e, 0xfe, 0x21, 0x7e, 0xf9, 0x2c, 0x7e, 0xfa, 0x86, 0x7e, 0xf8, 0x71,
  0x7e, 0xfe, 0x24, 0x7e, 0xf8, 0xd2, 0x7e, 0xfa, 0x86, 0x7e, 0xf9, 0x33,
  0x7e, 0xfa, 0x86, 0x7e, 0xfa, 0x86, 0x7e, 0xfc, 0x33, 0x7e, 0xfc, 0x83,
  0x7e, 0xfc, 0x1d, 0x7e, 0xfc, 0x0e, 0x7e, 0xfb, 0xea, 0x7e, 0xfc, 0x53,
  0x7e, 0xfa, 0xac, 0x81, 0x0d, 0x26, 0x07, 0x86, 0x0a, 0xbd, 0xff, 0xee,
  0x86, 0x0d, 0x7e, 0xfc, 0xcc, 0x7e, 0xfb, 0x33, 0x7e, 0xfa, 0xbd, 0x7e,
  0xf9, 0x76, 0xf8, 0xb0, 0xfa, 0x86, 0xf8, 0x2c
};

static int debug = 0;

static void copro_mc6809_mem_cycle(void *sptr, _Bool rnw, uint16_t addr) {
   if (rnw) {
      // read cycle
      if ((addr & 0xFFF0) == 0xFEE0) {
         overlay_rom = 0;
         mc6809->D = tube_parasite_read(addr & 7);
      } else if (overlay_rom) {
         mc6809->D = copro_mc6809_rom[addr & 0x7ff];
      } else {
         mc6809->D = copro_mc6809_ram[addr & 0xffff];
      }
      if (debug) {
         printf("Rd %04x=%02x\r\n", addr, mc6809->D);
      }
   } else {
      // write cycle
      if ((addr & 0xFFF0) == 0xFEE0) {
         overlay_rom = 0;
         tube_parasite_write(addr & 7, mc6809->D);
      } else {
         copro_mc6809_ram[addr & 0xffff] = mc6809->D;
      }
      if (debug) {
         printf("Wr %04x=%02x\r\n", addr, mc6809->D);
      }
   }
}

static void copro_mc6809_poweron_reset() {
   // Initialize memory pointer to zero (the start of the 2MB of memory shared with the 6502)
   copro_mc6809_ram = (unsigned char *) 0;
   // Wipe memory
   memset(copro_mc6809_ram, 0, 0x10000);
}

static void copro_mc6809_reset() {
  // Log ARM performance counters
  tube_log_performance_counters();

  // Re-instate the Tube ROM on reset
  overlay_rom = 1;

  // Reset the processor
  mc6809->reset(mc6809);

  // Wait for rst become inactive before continuing to execute
  tube_wait_for_rst_release();

  // Reset ARM performance counters
  tube_reset_performance_counters();
}

void copro_mc6809_emulator()
{

#ifdef USE_HD6309
   mc6809 = hd6309_new();
#else
   mc6809 = mc6809_new();
#endif

	mc6809->mem_cycle = DELEGATE_AS2(void, bool, uint16, copro_mc6809_mem_cycle, (void *)0);

   static unsigned int last_rst = 0;

   // Remember the current copro so we can exit if it changes
   int last_copro = copro;

   copro_mc6809_poweron_reset(); 
   copro_mc6809_reset();
  
   while (1)
   {
      // Execute emulator for one instruction
      mc6809->run(mc6809);

      MC6809_IRQ_SET(mc6809, 0);
      if (is_mailbox_non_empty()) {
         unsigned int tube_mailbox_copy = read_mailbox();
         unsigned int intr = tube_io_handler(tube_mailbox_copy);
         unsigned int nmi = intr & 2;
         unsigned int rst = intr & 4;
         // Reset the processor on active edge of rst
         if (rst && !last_rst) {
            // Exit if the copro has changed
            if (copro != last_copro) {
               break;
            }
            copro_mc6809_reset();
         }
         // NMI is edge sensitive, so only check after mailbox activity
         if (nmi) {
            overlay_rom = 1;
            MC6809_IRQ_SET(mc6809, 1);
         }

         last_rst = rst;
      }
      // IRQ is level sensitive, so check between every instruction
      MC6809_FIRQ_SET(mc6809, tube_irq & 1);
   }
}
