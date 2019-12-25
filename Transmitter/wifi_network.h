#ifndef WIFI_NETWORK_H
#define WIFI_NETWORK_H

#include "user_config.h"

#define AP_SSID "Shinu BSNL"
#define AP_PASSWORD "987654321"

struct espconn esp;
esp_tcp tcp;

void conf_wifi();
void wifi_event_handler_callback(System_Event_t *event);

#endif