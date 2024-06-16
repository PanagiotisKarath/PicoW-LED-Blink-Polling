# Raspberry Pi Pico W LED Blinker Using Polling
A simple project which controls the on-board LED on the pico w using a push button. It's made using the simplest method which is polling.
## Componenets Used
* Raspberry Pi Pico W
* Breadboard
* 4-pin Push Button
* Jumper Wires

The button is connected to GPIO 15, which is physical pin number 20.
## Implementation
The processor keeps checking whether the input from GPIO 15 is 0. If it is, then it turns on the on-board LED, sleeps for half a second and then turns it off. It's worth noting that the on-board LED on the pico w is controlled by the wireless chip. As a result, this project is **not** going to work on a normal pico.
