#include "dweet.h"
#include "wifi_network.h"

struct espconn esp_update, esp;
ip_addr_t ipaddr, ip_update;
esp_tcp tcp_update;
extern os_timer_t dweet_timer;
// char received_data_buffer[200];
// char received_data_buffer_pointer = 0;

/*
 * Function called every 5 seconds in order to check for new settings
 *
 * Called by the timer, this function basically looks up the hostname of dweet.io, and then proceeds to connect to it, and get the data regarding the E32 settings
 * @param (void*)arg none
*/
void dweet_entry(void * arg)
{
	espconn_gethostbyname(&esp, HOSTNAME, &ipaddr, dweet_dns_found_callback);
}

/*
 * Callback for when the DNS is found
 *
 * If the resolved IP address is not NULL or undefined, register the callback functions and connect to the dweet.io
 * @param (const char *)name is the resolved hostname
 * @param (ip_addr_t*)ipaddr is a pointer to a 4 byte long array of bytes which stores the IP address
 * @param (void*)callback_arg is a pointer to the calling espconn struct
*/
void dweet_dns_found_callback(const char *name, ip_addr_t *ipaddr, void *callback_arg)
{
	if(ipaddr != NULL)
	{
		struct espconn * esp_temp = (struct espconn *)callback_arg;
		esp_temp->state = ESPCONN_NONE;
		esp_temp->type = ESPCONN_TCP;
		esp_temp->proto.tcp = &tcp;
		esp_temp->proto.tcp->local_port = espconn_port();
		esp_temp->proto.tcp->remote_port = 80;
		os_memcpy(esp_temp->proto.tcp->remote_ip, &ipaddr->addr, 4);
		espconn_regist_connectcb(esp_temp, dweet_connect_callback);
		espconn_regist_recvcb(esp_temp, dweet_receive_callback);
		// espconn_regist_disconcb(esp_temp, dweet_disconnect_callback);
		espconn_connect(esp_temp);
	}
}

/*
 * Basically sends the HTTP request connects to dweet.io
 *
 * Requests the JSON from the dweet.io page and server
 * @param (void*)arg is a pointer to the espconn structure passed by the calling function
*/
void dweet_connect_callback(void * arg)
{
	struct espconn * esp_temp = (struct espconn *)arg;
	uint8 *buffer = (uint8 *)os_zalloc(200);
	// os_printf("Sending request");
	// os_sprintf(buffer, "GET %s HTTP/1.1\r\nHost: %s\r\nUser-Agent: wget\r\nConnection: close\r\n\r\n", SUBDIR, HOSTNAME);
	// os_printf("%s", buffer);
	espconn_send(esp_temp, buffer, os_strlen(buffer));
	os_free(buffer);
}

/*
 * Callback called when data is received
 *
 * Is called after the request is sent to dweet.io page, and JSON is received. This callback function stores all the data into a large buffer, and the data is not used until the connection is disconnected by the client server
 * @param (void*)arg is a pointer to the calling espconn structure
 * @param (char*)pdata is a pointer to the data received
 * @param (unsigned short)len length of the data received
*/
void dweet_receive_callback(void *arg, char *pdata, unsigned short len)
{

	// os_printf("Data received! %d\n%s\n", len,pdata);
}