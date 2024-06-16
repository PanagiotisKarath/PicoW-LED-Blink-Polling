#include "pico/stdlib.h"
#include "pico/cyw43_arch.h"

#define BUTTON_PIN 15

int main(){
    stdio_init_all();
    gpio_init(BUTTON_PIN);
    gpio_set_dir(BUTTON_PIN, 0);
    gpio_pull_up(BUTTON_PIN);

    
    if (cyw43_arch_init()){
        printf("Wifi init failed.");
        return -1;
    }
    while(true){
        if (gpio_get(BUTTON_PIN) == 0){
            cyw43_arch_gpio_put(CYW43_WL_GPIO_LED_PIN, 1);
            sleep_ms(500);
            cyw43_arch_gpio_put(CYW43_WL_GPIO_LED_PIN, 0);
        }
    }

    return 0;
}