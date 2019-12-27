#include "/opt/esp-open-sdk/sdk/include/airkiss.h"
#include "/opt/esp-open-sdk/sdk/include/at_custom.h"
#include "/opt/esp-open-sdk/sdk/include/c_types.h"
#include "/opt/esp-open-sdk/sdk/include/c_types.h.orig"
#include "/opt/esp-open-sdk/sdk/include/eagle_soc.h"
#include "/opt/esp-open-sdk/sdk/include/esp_sdk_ver.h"
#include "/opt/esp-open-sdk/sdk/include/espnow.h"
#include "/opt/esp-open-sdk/sdk/include/ets_sys.h"
#include "/opt/esp-open-sdk/sdk/include/gpio.h"
#include "/opt/esp-open-sdk/sdk/include/ip_addr.h"
#include "/opt/esp-open-sdk/sdk/include/mem.h"
#include "/opt/esp-open-sdk/sdk/include/mesh.h"
#include "/opt/esp-open-sdk/sdk/include/os_type.h"
#include "/opt/esp-open-sdk/sdk/include/osapi.h"
#include "/opt/esp-open-sdk/sdk/include/ping.h"
#include "/opt/esp-open-sdk/sdk/include/pwm.h"
#include "/opt/esp-open-sdk/sdk/include/queue.h"
#include "/opt/esp-open-sdk/sdk/include/simple_pair.h"
#include "/opt/esp-open-sdk/sdk/include/smartconfig.h"
#include "/opt/esp-open-sdk/sdk/include/sntp.h"
#include "/opt/esp-open-sdk/sdk/include/spi_flash.h"
#include "/opt/esp-open-sdk/sdk/include/upgrade.h"
#include "/opt/esp-open-sdk/sdk/include/user_interface.h"
#include "/opt/esp-open-sdk/sdk/include/espconn.h"
#include "/opt/esp-open-sdk/sdk/include/wpa2_enterprise.h"
#include "json/jsonparse.h"
#include "json/jsontree.h"
//Driver Headers
#include "/opt/esp-open-sdk/sdk/driver_lib/include/driver/gpio16.h"
#include "/opt/esp-open-sdk/sdk/driver_lib/include/driver/i2c_master.h"
#include "/opt/esp-open-sdk/sdk/driver_lib/include/driver/key.h"
#include "/opt/esp-open-sdk/sdk/driver_lib/include/driver/sdio_slv.h"
#include "/opt/esp-open-sdk/sdk/driver_lib/include/driver/slc_register.h"
#include "/opt/esp-open-sdk/sdk/driver_lib/include/driver/spi.h"
#include "/opt/esp-open-sdk/sdk/driver_lib/include/driver/spi_interface.h"
#include "/opt/esp-open-sdk/sdk/driver_lib/include/driver/spi_overlap.h"
#include "/opt/esp-open-sdk/sdk/driver_lib/include/driver/spi_register.h"
#include "/opt/esp-open-sdk/sdk/driver_lib/include/driver/uart.h"
#include "/opt/esp-open-sdk/sdk/driver_lib/include/driver/uart_register.h"

#define DONT_LOAD

#ifndef DONT_LOAD
	#include "/opt/esp-open-sdk/ESP8266_NONOS_SDK_V2.0.0_16_08_10/driver_lib/driver/gpio16.c"
	#include "/opt/esp-open-sdk/ESP8266_NONOS_SDK_V2.0.0_16_08_10/driver_lib/driver/hw_timer.c"
	#include "/opt/esp-open-sdk/ESP8266_NONOS_SDK_V2.0.0_16_08_10/driver_lib/driver/i2c_master.c"
	#include "/opt/esp-open-sdk/ESP8266_NONOS_SDK_V2.0.0_16_08_10/driver_lib/driver/key.c"
	#include "/opt/esp-open-sdk/ESP8266_NONOS_SDK_V2.0.0_16_08_10/driver_lib/driver/sdio_slv.c"
	#include "/opt/esp-open-sdk/ESP8266_NONOS_SDK_V2.0.0_16_08_10/driver_lib/driver/spi.c"
	#include "/opt/esp-open-sdk/ESP8266_NONOS_SDK_V2.0.0_16_08_10/driver_lib/driver/spi_interface.c"
	#include "/opt/esp-open-sdk/ESP8266_NONOS_SDK_V2.0.0_16_08_10/driver_lib/driver/spi_overlap.c"
	#include "/opt/esp-open-sdk/ESP8266_NONOS_SDK_V2.0.0_16_08_10/driver_lib/driver/uart.c"
#endif
