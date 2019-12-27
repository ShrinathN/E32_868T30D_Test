#include "E32_868T30D.h"

const U8 E32_868T30D_default_configuration[6] = { 0xc2, 0x00, 0x00, 0x1a, 0x17, 0x44};

struct _E32_868T30D_Message_ E32_868T30D_Message;

/*
 * Function to set mode
 *
 * This function is used to set mode. It is written for clarity, I understand bit shifting
 * @param (U8)mode to set the E32 chip to
*/
void E32_ModeSet(U8 mode)
{
	switch(mode)
	{
		case E32_MODE_NORMAL:
			E32_M0_PIN_LOW;
			break;
		case E32_MODE_SLEEP:
			E32_M0_PIN_HIGH;
			break;
	}
}