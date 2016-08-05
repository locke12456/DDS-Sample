/*
 *                         OpenSplice DDS
 *
 *   This software and documentation are Copyright 2006 to 2015 PrismTech
 *   Limited and its licensees. All rights reserved. See file:
 *
 *                     $OSPL_HOME/LICENSE
 *
 *   for full copyright notice and license terms.
 *
 */

#ifndef NW_COMPPLUGIN_H
#define NW_COMPPLUGIN_H

typedef unsigned long (*nw_cp_maxfn)(unsigned long);
typedef unsigned long (*nw_cp_compfn)(void *, unsigned long, const void *, unsigned long, void *);
typedef unsigned long (*nw_cp_uncompfn)(void *, unsigned long, const void *, unsigned long);
typedef void (*nw_cp_exitfn)(void *);

typedef struct
{
   nw_cp_maxfn maxfn;
   nw_cp_compfn compfn;
   nw_cp_uncompfn uncompfn;
   nw_cp_exitfn exitfn;
   void *parameter;
} nw_compressor;

typedef void (*nw_cp_initfn)(nw_compressor *, const char *);

#endif /* NW_COMPPLUGIN_H */

