#include "dweet.h"
#include "wifi_network.h"
#include "E32_868T30D.h"

struct espconn esp_update, esp;
ip_addr_t ipaddr, ip_update;
esp_tcp tcp_update;
char payload_buffer[50];

//external
extern os_timer_t dweet_timer;
extern struct _E32_868T30D_Message_ E32_868T30D_Message;

/*
 * Function called every 5 seconds in order to check for new settings
 *
 * Called by the timer, this function basically looks up the hostname of dweet.io, and then proceeds to connect to it, and get the data regarding the E32 settings
 * @param (void*)arg none
*/
void ICACHE_FLASH_ATTR dweet_entry(void * arg)
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
void ICACHE_FLASH_ATTR dweet_dns_found_callback(const char *name, ip_addr_t *ipaddr, void *callback_arg)
{
	if(ipaddr != NULL)
	{
		// os_printf("Got Ip address"IPSTR, IP2STR(ipaddr->addr));
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
void ICACHE_FLASH_ATTR dweet_connect_callback(void * arg)
{
	struct espconn * esp_temp = (struct espconn *)arg;
	uint8 *buffer = (uint8 *)os_zalloc(200);
	// os_printf("Sending request");
	os_sprintf(buffer, "GET %s HTTP/1.1\r\nHost: %s\r\nUser-Agent: wget\r\nConnection: close\r\n\r\n", SUBDIR, HOSTNAME);
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
void ICACHE_FLASH_ATTR dweet_receive_callback(void *arg, char *pdata, unsigned short len)
{
	// os_printf("Data received! %d\n%s\n", len,pdata);
	char * json_string_ptr = os_strstr(pdata, "{\"d0\"");
	unsigned short length_of_json_string = os_strlen(json_string_ptr) - 4;
	int jt = 0;
	char tempmem[7], tempmem_counter = 0;

	struct jsonparse_state * jps = (struct jsonparse_state *)os_zalloc(sizeof(struct jsonparse_state));
	jsonparse_setup(jps, json_string_ptr, length_of_json_string);

	while(jt = jsonparse_next(jps))
	{
		switch(jt)
		{
			case JSON_TYPE_NUMBER:
				tempmem[tempmem_counter++] = jsonparse_get_value_as_int(jps);
				break;
			case JSON_TYPE_STRING:
				jsonparse_copy_value(jps, payload_buffer, jsonparse_get_len(jps) + 1);
				os_printf("Payload->%s\n", payload_buffer);
				break;
			default:
				break;
		}
		if(jt == -2)
			break;
	}

	// for(tempmem_counter = 0; tempmem_counter < 7; tempmem_counter++)
	// {
		// os_printf("%d -> %d\n", tempmem_counter, tempmem[tempmem_counter]);
	// }

	os_free(jps);
}