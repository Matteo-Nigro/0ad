/* Copyright (C) 2009 Wildfire Games.
 * This file is part of 0 A.D.
 *
 * 0 A.D. is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * 0 A.D. is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with 0 A.D.  If not, see <http://www.gnu.org/licenses/>.
 */

/*
 * type definitions needed for wposix.
 */

#ifndef INCLUDED_WPOSIX_TYPES
#define INCLUDED_WPOSIX_TYPES

#include <crtdefs.h>	// intptr_t


//
// <inttypes.h>
//

typedef signed char int8_t;
typedef short int16_t;

// already defined by MinGW
#if MSC_VERSION
typedef int int32_t;
#endif

#if MSC_VERSION || ICC_VERSION || LCC_VERSION
typedef __int64 int64_t;
#else
typedef long long int64_t;
#endif

typedef unsigned char uint8_t;
typedef unsigned short uint16_t;
typedef unsigned int uint32_t;
#if MSC_VERSION || ICC_VERSION || LCC_VERSION
typedef unsigned __int64 uint64_t;
#else
typedef unsigned long long uint64_t;
#endif

// note: we used to define [u]intptr_t here (if not already done).
// however, it's not necessary with VC7 and later, and the compiler's
// definition squelches 'pointer-to-int truncation' warnings, so don't.

#define INT16_MIN -32768
#define INT16_MAX 32767
#define UINT16_MIN 0u
#define UINT16_MAX 65536u


//
// <sys/types.h>
//

typedef intptr_t ssize_t;
// prevent wxWidgets from (incompatibly) redefining it
#define HAVE_SSIZE_T

// VC9 defines off_t as long, but we need 64-bit file offsets even in
// 32-bit builds. to avoid conflicts, we have to define _OFF_T_DEFINED,
// which promises _off_t has also been defined. since that's used by
// CRT headers, we have to define it too, but must use the original
// long type to avoid breaking struct stat et al.
typedef __int64 off_t;
typedef long _off_t;
#define _OFF_T_DEFINED


//
// <limits.h>
//

// Win32 MAX_PATH is 260; our number may be a bit more efficient.
#define PATH_MAX 256u

#if OS_WIN
# ifndef SIZE_MAX // VC2005 already defines this in limits.h
#  define SIZE_MAX 0xFFFFFFFF
# endif
#else
# define SIZE_MAX 0xFFFFFFFFFFFFFFFF
#endif


#endif	// #ifndef INCLUDED_WPOSIX_TYPES
