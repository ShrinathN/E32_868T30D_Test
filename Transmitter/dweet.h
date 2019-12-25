#ifndef DWEET_H
#define DWEET_H

#include "user_config.h"

//configuration
#define HOSTNAME "dweet.io"
#define SUBDIR "/get/latest/dweet/for/E32_868T30D_Test"

//public function declaration
void dweet_entry(void * arg);
void dweet_dns_found_callback(const char *name, ip_addr_t *ipaddr, void *callback_arg);
void dweet_connect_callback(void * arg);
void dweet_receive_callback(void *arg, char *pdata, unsigned short len);

#endif