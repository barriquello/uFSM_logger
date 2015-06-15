/*
 * FreeModbus Libary: CFV1 BRTOS Port
 * Copyright (C) 2006 Christian Walter <wolti@sil.at>
 * Copyright (C) 2008 Trond Melen
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 *
 * File: $Id: port.h,v 1.1 2008/03/28 15:59:07 wolti Exp $
 */

#ifndef _PORT_H
#define _PORT_H

//#include <assert.h>
#define assert(x) while(!(x)){}

/* The include file "derivative.h" is automatically generated by Code Warrior */
#include "derivative.h"
#include "drivers.h"
#include "BRTOS.h"
#include "AppConfig.h"

#include "data_types.h"
#include "mbcrc.h"

#include "string.h"

typedef enum {
	MODBUS_PM210 = 0,
	MODBUS_TS = 1,
	MODBUS_NONE
}eMBSlaves;

/* verification code */
static union
{
    char            int8_t_incorrect[sizeof( int8_t ) == 1];
    char            uint8_t_incorrect[sizeof( uint8_t ) == 1];
    char            int16_t_incorrect[sizeof( int16_t ) == 2];
    char            uint16_t_incorrect[sizeof( uint16_t ) == 2];
    char            int32_t_incorrect[sizeof( int32_t ) == 4];
    char            uint32_t_incorrect[sizeof( uint32_t ) == 4];
};

#define	INLINE
#define PR_BEGIN_EXTERN_C       extern "C" {
#define	PR_END_EXTERN_C         }
#define	memcpy                  (void) memcpy   // gets wid of a warning in mbfuncother.c

#define SaveStatusReg()         { OSEnterCritical(); }  /* This macro saves STATUS register and disable global interrupts. */
#define RestoreStatusReg()      { OSExitCritical(); }   /* This macro restores STATUS register saved in SaveStatusReg(). */

#define ENTER_CRITICAL_SECTION( )   DisableInterrupts;
#define EXIT_CRITICAL_SECTION( )    EnableInterrupts;

typedef uint8_t                 BOOL;

#if 0
typedef unsigned char           UCHAR;
typedef char                    CHAR;
typedef uint16_t                USHORT;
typedef int16_t                 SHORT;
typedef uint32_t                ULONG;
typedef int32_t                 LONG;
#endif

#ifndef TRUE
#define TRUE                    1
#endif

#ifndef FALSE
#define FALSE                   0
#endif

/* SaveStatusReg() stores the STATUS Register here */
extern INT16U                   CPU_SR;

/* The bus clock is used for computing timer and baud rate register values */
#define BM_BUS_CLOCK			configCPU_CLOCK_HZ // Hz

void ModbusSetSlave(eMBSlaves slave_option);

#endif