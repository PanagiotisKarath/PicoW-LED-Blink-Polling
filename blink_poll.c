/*
* Including all the necessary libraries.
* "pico/cyw43_arch.h" is especially important, in order to control
* the on-board LED, which is connected to the CYW43 wireless chip 
* on the pico w.
*/
#include "pico/stdlib.h"
#include "pico/cyw43_arch.h"

#define BUTTON_PIN 15 //The button is connected to GPIO pin 15 (physical pin 20)

int main(){
    stdio_init_all(); //Initialize all standard I/O interfaces

    /*
    * Here the button pin is initialized as input.
    * The third line is important to understand, because it configures the button pin 
    * to the Pull-up resistor. That means that by default the input is logic level 1.
    * When the button is pressed GPIO pin 15 is connected to the ground, it reads 
    * logic level 0 and this triggers a blink
    */
    gpio_init(BUTTON_PIN);
    gpio_set_dir(BUTTON_PIN, 0);
    gpio_pull_up(BUTTON_PIN);

    /*
    * The CYW43 wireless chip is initialized
    */
    if (cyw43_arch_init()){
        printf("Wifi init failed."); //If initialization fails an error message is printed
        return -1; //Also an error code is returned
    }

    /*
    * Main part of the program. This part checks whether the button is pressed
    */
    while(true){
        if (gpio_get(BUTTON_PIN) == 0){ //If the button is pressed the GPIO pin 15 is grounded(is equal to 0)
            cyw43_arch_gpio_put(CYW43_WL_GPIO_LED_PIN, 1); //The wireless chip LED is turned on
            sleep_ms(500); //Wait for half a second
            cyw43_arch_gpio_put(CYW43_WL_GPIO_LED_PIN, 0); //The wireless chip LED is turned off
        }
    }

    return 0; //Not necessary since the program will never reach this point, but I always add return 0 in main function
}