/**
 * This file is generated by tifstoc. Do not edit!
 * Generated from tifs for tool 'lower-rstore' (prefix='')
 */

#ifndef _LOWER_RSTORE_H
#define _LOWER_RSTORE_H

#include <atb-tool.h>

/* Prototypes for functions called from the event handler */
void rec_terminate(int conn, ATerm);
ATerm lower_rstore(int conn, ATerm);
extern ATerm lower_rstore_handler(int conn, ATerm term);
extern ATerm lower_rstore_checker(int conn, ATerm sigs);

#endif
