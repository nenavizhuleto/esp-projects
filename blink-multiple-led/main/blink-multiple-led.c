#include <stdio.h>

#include "freertos/FreeRTOS.h"

#include "esp_log.h"
#include "driver/gpio.h"


#define PROG "BLINK:"
#define RED_LED_PIN 2
#define BLUE_LED_PIN 4

#define BLINK_RATE_MS 100

#define ON 1
#define OFF 0

void app_main(void)
{

	ESP_LOGI(PROG, "starting up\n");

	// setup
	///////////////////////////////////////////////////
	gpio_reset_pin(RED_LED_PIN);
	gpio_reset_pin(BLUE_LED_PIN);

	gpio_set_direction(RED_LED_PIN, GPIO_MODE_OUTPUT);
	gpio_set_direction(BLUE_LED_PIN, GPIO_MODE_OUTPUT);

	// main loop
	///////////////////////////////////////////////////
	while(1) {
		gpio_set_level(RED_LED_PIN, ON);
		gpio_set_level(BLUE_LED_PIN, OFF);

		vTaskDelay(BLINK_RATE_MS / portTICK_PERIOD_MS);

		gpio_set_level(RED_LED_PIN, OFF);
		gpio_set_level(BLUE_LED_PIN, ON);

		vTaskDelay(BLINK_RATE_MS / portTICK_PERIOD_MS);
	}

}
