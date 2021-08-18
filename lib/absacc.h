/*--------------------------------------------------------------------------
ABSACC.H

Direct access to 8051, extended 8051 and NXP 8051MX memory areas.
Copyright (c) 1988-2010 Keil Elektronik GmbH and ARM Germany GmbH
All rights reserved.
--------------------------------------------------------------------------*/

#ifndef __ABSACC_H__
#define __ABSACC_H__

#define CBYTE ((unsigned char volatile code  *) 0)
#define DBYTE ((unsigned char volatile data  *) 0)
#if !defined (__CX2__)
#define PBYTE ((unsigned char volatile __pdata *) 0)
#endif
#define XBYTE ((unsigned char volatile __xdata *) 0)

#define CWORD ((unsigned int volatile code  *) 0)
#define DWORD ((unsigned int volatile data  *) 0)
#if !defined (__CX2__)
#define PWORD ((unsigned int volatile __pdata *) 0)
#endif
#define XWORD ((unsigned int volatile __xdata *) 0)


#if defined (__CX51__) || defined (__CX2__)
#define FVAR(object, addr)   (*((object volatile far *) (addr)))
#define FARRAY(object, base) ((object volatile far *) (base))
#define FCVAR(object, addr)   (*((object const far *) (addr)))
#define FCARRAY(object, base) ((object const far *) (base))
#else
#define FVAR(object, addr)    (*((object volatile far *) ((addr)+0x10000L)))
#define FCVAR(object, addr)   (*((object const far *) ((addr)+0x810000L)))
#define FARRAY(object, base)  ((object volatile far *) ((base)+0x10000L))
#define FCARRAY(object, base) ((object const far *) ((base)+0x810000L))
#endif

#if defined (__CX2__)
#define HBYTE ((unsigned char volatile huge *)  0)
#define HWORD ((unsigned int volatile huge *)  0)
#define HVAR(object, addr)   (*((object volatile huge *) (addr)))
#define HARRAY(object, base) ((object volatile huge *) (base))
#endif

#define CVAR(object, addr)   (*((object volatile code *) (addr)))
#define CARRAY(object, base) ((object volatile code *) (base))
#define DVAR(object, addr)   (*((object volatile data *) (addr)))
#define DARRAY(object, base) ((object volatile data *) (base))
#define XVAR(object, addr)   (*((object volatile xdata *) (addr)))
#define XARRAY(object, base) ((object volatile xdata *) (base))

#endif
