#include "wifi_network.h"
#include "dweet.h"

uint8 isConnected = 0;
os_timer_t dweet_timer;

void ICACHE_FLASH_ATTR conf_wifi()
{
	struct station_config *statcon = (struct station_config *)os_zalloc(sizeof(struct station_config));
	os_strcpy(statcon->ssid, AP_SSID);
	os_strcpy(statcon->password, AP_PASSWORD);
	wifi_set_opmode_current(STATION_MODE);
	wifi_station_set_config_current(statcon);
	wifi_set_event_handler_cb(wifi_event_handler_callback);
	os_free(statcon);
}

void ICACHE_FLASH_ATTR wifi_event_handler_callback(System_Event_t *event)
{
	if(event->event == EVENT_STAMODE_GOT_IP) //this means connected and received IP
	{
		os_timer_disarm(&dweet_timer);
		os_timer_setfn(&dweet_timer, dweet_entry, NULL);
		os_timer_arm(&dweet_timer, 10000, 1);
	}
	else if(event->event == EVENT_STAMODE_DISCONNECTED) //disconnected from the AP
	{
		os_timer_disarm(&dweet_timer);
	}
}