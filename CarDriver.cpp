//
// Created by Alex on 4/14/2022.
//

#include "CarDriver.h"
#include "bcm2835.h"

CarDriver::CarDriver() {
    const int pinGas = RPI_BPLUS_GPIO_J8_40;
    const int pinReverse = RPI_BPLUS_GPIO_J8_38;
    const int pinTurnLeft = RPI_BPLUS_GPIO_J8_37;
    const int pinTurnRight = RPI_BPLUS_GPIO_J8_36;
    bcm2835_init();
    bcm2835_gpio_fsel(pinGas, BCM2835_GPIO_FSEL_OUTP);
    bcm2835_gpio_fsel(pinReverse, BCM2835_GPIO_FSEL_OUTP);
    bcm2835_gpio_fsel(pinTurnRight, BCM2835_GPIO_FSEL_OUTP);
    bcm2835_gpio_fsel(pinTurnLeft, BCM2835_GPIO_FSEL_OUTP);

}

void CarDriver::gas() {
    bcm2835_gpio_write(pinGas, HIGH);
    bcm2835_gpio_write(pinReverse, LOW);
}

void CarDriver::brake() {
    bcm2835_gpio_write(pinGas, LOW);
    bcm2835_gpio_write(pinReverse, LOW);
}

void CarDriver::reverse() {
    bcm2835_gpio_write(pinGas, LOW);
    bcm2835_gpio_write(pinReverse, HIGH);
}

void CarDriver::turnLeft() {
    bcm2835_gpio_write(pinTurnLeft, HIGH);
    bcm2835_gpio_write(pinTurnRight, LOW);
}

void CarDriver::turnRight() {
    bcm2835_gpio_write(pinTurnRight, HIGH);
    bcm2835_gpio_write(pinTurnLeft, LOW);
}

CarDriver::~CarDriver() {
    bcm2835_close();
}