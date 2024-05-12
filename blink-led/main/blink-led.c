#include <stdio.h>

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#include "esp_log.h"

#include "driver/gpio.h"

#define BLINK_LED 2

void app_main(void)
{

    // get current task name
    // NOTE: freertos operates on tasks
    char * taskName = pcTaskGetName(NULL);
    ESP_LOGI(taskName, "Hello, starting up\n");

    // reset blink pin configuration
    gpio_reset_pin(BLINK_LED);

    // set blink pin direction to output
    gpio_set_direction(BLINK_LED, GPIO_MODE_OUTPUT);

    while(1) {
        // turn on blink pin
        gpio_set_level(BLINK_LED, 1);
        ESP_LOGI("%s", "LED: ON\n");

        // wait for 1 second
        vTaskDelay(1000 / portTICK_PERIOD_MS);

        // turn off blink pin
        gpio_set_level(BLINK_LED, 0);
        ESP_LOGI("%s", "LED: OFF\n");

        // wait for 1 second
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
}
