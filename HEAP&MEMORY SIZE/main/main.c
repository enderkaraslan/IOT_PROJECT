#include <stdio.h>
#include "driver/gpio.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_log.h"
#include "esp_flash.h"
#include "esp_spi_flash.h"
#include "esp_heap_caps.h"
#include "esp_random.h"

// LED'in bağlı olduğu GPIO pini
#define LED_PIN GPIO_NUM_32


#define LED_TAG "LED_STATE"
#define TAG_FLASH_SIZE "FLASH_SIZE"
#define TAG_FUEL_LEVEL "FUEL_LEVEL"


void app_main(void)
{
    // NOTE: FLASH_SIZE
    uint32_t flash_size = 0;
    esp_flash_get_size(NULL, &flash_size);
    ESP_LOGI(TAG_FLASH_SIZE, "Flash size: %lu MB\n", flash_size / (1024*1024));


    // NOTE: Toplam ve kullanılabilir RAM
    size_t total_ram = 0;
    size_t free_ram = 0;
    total_ram = heap_caps_get_total_size(MALLOC_CAP_8BIT);
    free_ram = heap_caps_get_free_size(MALLOC_CAP_8BIT);
    ESP_LOGI(LED_TAG, "Total RAM: %u KB, Free RAM: %u KB\n", total_ram / 1024, free_ram / 1024);
    

    // GPIO pinini çıkış olarak ayarla
    gpio_set_direction(LED_PIN, GPIO_MODE_OUTPUT);

    esp_log_level_set(LED_TAG, ESP_LOG_WARN); // LOG seviyesini ayarlar
    
    uint32_t a = esp_random();
    printf("SEED: %lu\n", a);


    while (1) {
        

        // LED'i yak
        gpio_set_level(LED_PIN, 1);

        ESP_LOGI(LED_TAG, "LED_ON");
        
        vTaskDelay(1000 / portTICK_PERIOD_MS); // 1 saniye bekle

        // LED'i söndür
        gpio_set_level(LED_PIN, 0);
        
        ESP_LOGW(LED_TAG, "LED_OFF");
        
        vTaskDelay(1000 / portTICK_PERIOD_MS); // 1 saniye bekle
        int fuel_level = rand() % 101;
        ESP_LOGI(TAG_FUEL_LEVEL, "Fuel level: %d%%", fuel_level);
    }
}
