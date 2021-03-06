#ifndef E32_868T30D_H
#define E32_868T30D_H

#include "user_config.h"

//configuration for M0, M1 and AUX pin
//please configure your pins prior to doing anything using this part of the application
#define E32_M0_PIN 2
#define E32_M0_PIN_LOW GPIO_OUTPUT_SET(E32_M0_PIN, 0)
#define E32_M0_PIN_HIGH GPIO_OUTPUT_SET(E32_M0_PIN, 1)

typedef unsigned char U8;

//ENUM DECLARATION SECTION

enum
{
	E32_HEAD_SAVE = 0xc0,
	E32_HEAD_DONT_SAVE = 0xc2
};

enum
{
	E32_UART_PARITY_BIT_8N1 = 0x0,
	E32_UART_PARITY_BIT_8O1,
	E32_UART_PARITY_BIT_8E1,
};

enum
{
	E32_UART_TTL_BAUD_RATE_1200 = 0x0,
	E32_UART_TTL_BAUD_RATE_2400,
	E32_UART_TTL_BAUD_RATE_4800,
	E32_UART_TTL_BAUD_RATE_9600,
	E32_UART_TTL_BAUD_RATE_19200,
	E32_UART_TTL_BAUD_RATE_38400,
	E32_UART_TTL_BAUD_RATE_57600,
	E32_UART_TTL_BAUD_RATE_115200
};

enum
{
	E32_AIR_DATA_RATE_0_3k = 0x0,
	E32_AIR_DATA_RATE_1_2k,
	E32_AIR_DATA_RATE_2_4k,
	E32_AIR_DATA_RATE_4_8k,
	E32_AIR_DATA_RATE_9_6k,
	E32_AIR_DATA_RATE_19_2k
};

enum
{
	E32_TRANSMISSION_POWER_30dBm,
	E32_TRANSMISSION_POWER_27dBm,
	E32_TRANSMISSION_POWER_24dBm,
	E32_TRANSMISSION_POWER_21dBm
};

enum
{
	E32_FEC_SWITCH_OFF,
	E32_FEC_SWITCH_ON
};

enum
{
	E32_WIRELESS_WAKE_UP_TIME_250ms,
	E32_WIRELESS_WAKE_UP_TIME_500ms,
	E32_WIRELESS_WAKE_UP_TIME_750ms,
	E32_WIRELESS_WAKE_UP_TIME_1000ms,
	E32_WIRELESS_WAKE_UP_TIME_1250ms,
	E32_WIRELESS_WAKE_UP_TIME_1500ms,
	E32_WIRELESS_WAKE_UP_TIME_1750ms,
	E32_WIRELESS_WAKE_UP_TIME_2000ms
};

enum
{
	E32_IO_DRIVE_TXD_AUX_PUSH_PULL_OUTPUT_RXD_PULLUP_INPUT,
	E32_IO_DRIVE_TXD_AUX_OPEN_COLL_OUTPUT_RXD_OPEN_COLLE_INPUT
};

//default message
// const U8 E32_868T30D_default_configuration[6] = {
// 	0xc2,
// 	0x00,
// 	0x00,
// 	0x1a,
// 	0x06,
// 	0xc4
// };

enum
{
	E32_MODE_NORMAL,
	E32_MODE_POWER_SAVE,
	E32_MODE_WAKE_UP,
	E32_MODE_SLEEP
};

//message structure
struct _E32_868T30D_Message_
{
	//0x0 - head
	U8 E32_HEAD;
	//0x1 - address high
	U8 E32_ADDR_HIGH;
	//0x2 - address low
	U8 E32_ADDR_LOW;
	//0x3 - speed
	U8 E32_AIR_DATA_RATE : 3;
	U8 E32_UART_TTL_BAUD_RATE : 3;
	U8 E32_UART_PARITY_BIT : 2;
	//0x4 - channel
	U8 _E32_RESERVED_ : 5;
	U8 E32_CHANNEL : 3;
	//0x5 - options
	U8 E32_TRANSMISSION_POWER : 2;
	U8 E32_FEC_SWITCH : 1;
	U8 E32_WIRELESS_WAKE_UP_TIME : 3;
	U8 E32_IO_DRIVE : 1;
	U8 E32_FIXED_TRANSMISSION_ENABLING_BIT : 1;
};

//function declaration
void E32_ModeSet(U8 mode);

#endif