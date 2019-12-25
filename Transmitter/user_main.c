#include "user_config.h"

#include "wifi_network.h"
#include "E32_868T30D.h"

#define SET_BAUD(UART_NUMBER, BAUD_RATE) uart_div_modify(UART_NUMBER, UART_CLK_FREQ / BAUD_RATE)

//private function declaration
static void setup_gpio();

/*
 * Sets up the GPIO pins
 *
 * GPIO0 <- AUX
 * GPIO2 -> M0, M1
*/
static void setup_gpio()
{
	//setting GPIO
	PIN_FUNC_SELECT(PERIPHS_IO_MUX_GPIO0_U, FUNC_GPIO0);
	PIN_FUNC_SELECT(PERIPHS_IO_MUX_GPIO2_U, FUNC_GPIO2);
	GPIO_REG_WRITE(GPIO_OUT_W1TS_ADDRESS, GPIO_REG_READ(GPIO_OUT_W1TS_ADDRESS) | (1 << 2));
	GPIO_DIS_OUTPUT(0);
}

void user_init(void)
{
	SET_BAUD(UART0, 9600);
	setup_gpio();
	conf_wifi();
}