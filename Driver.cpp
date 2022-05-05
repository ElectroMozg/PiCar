//
// Created by Alex on 5/5/2022.
//

#include "Driver.h"
#include "bcm2835.h"

Driver::Driver() {
    bcm2835_init();
    pinGas = RPI_BPLUS_GPIO_J8_08;
    pinReverse = RPI_BPLUS_GPIO_J8_16;
    pinTurnLeft = RPI_BPLUS_GPIO_J8_18;
    pinTurnRight = RPI_BPLUS_GPIO_J8_10;
    bcm2835_gpio_fsel(pinGas, BCM2835_GPIO_FSEL_OUTP);
    bcm2835_gpio_fsel(pinReverse, BCM2835_GPIO_FSEL_OUTP);
    bcm2835_gpio_fsel(pinTurnRight, BCM2835_GPIO_FSEL_OUTP);
    bcm2835_gpio_fsel(pinTurnLeft, BCM2835_GPIO_FSEL_OUTP);
}

void Driver::gas() {
    bcm2835_gpio_write(pinGas, HIGH);
    bcm2835_gpio_write(pinReverse, LOW);
}

void Driver::brake() {
    bcm2835_gpio_write(pinGas, LOW);
    bcm2835_gpio_write(pinReverse, LOW);
}

void Driver::reverse() {
    bcm2835_gpio_write(pinGas, LOW);
    bcm2835_gpio_write(pinReverse, HIGH);
}

void Driver::turnLeft() {
    bcm2835_gpio_write(pinTurnLeft, HIGH);
    bcm2835_gpio_write(pinTurnRight, LOW);
}

void Driver::turnRight() {
    bcm2835_gpio_write(pinTurnRight, HIGH);
    bcm2835_gpio_write(pinTurnLeft, LOW);
}

Driver::~Driver() {
    bcm2835_close();
}
