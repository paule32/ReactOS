/*
 * COPYRIGHT:   See COPYING in the top level directory
 * PROJECT:     ReactOS kernel
 * FILE:        include/reactos/version.h.cmake
 * PURPOSE:     Defines the current version
 * PROGRAMMER:  David Welch (welch@mcmail.com)
 * REVISIONS:
 *  1999-11-06 (ea)
 *      Moved from include/internal in include/reactos
 *      to be used by buildno.
 *  2002-01-17 (ea)
 *      KERNEL_VERSION removed. Use
 *      reactos/buildno.h:KERNEL_VERSION_STR instead.
 */

#ifndef __VERSION_H
#define __VERSION_H

#define KERNEL_VERSION_MAJOR        0
#define KERNEL_VERSION_MINOR        4
#define KERNEL_VERSION_PATCH_LEVEL  6

#define COPYRIGHT_YEAR "2017"

/* KERNEL_VERSION_BUILD_TYPE is "SVN" or "" (for the release) */
#define KERNEL_VERSION_BUILD_TYPE   ""
/* KERNEL_VERSION_RELEASE_TYPE is "RC1", "RC2" or "" (for the final one) */
#define KERNEL_VERSION_RELEASE_TYPE ""

#endif

/* EOF */
