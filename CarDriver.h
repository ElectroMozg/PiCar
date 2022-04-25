//
// Created by Alex on 4/14/2022.
//

#ifndef MAIN_CARDRIVER_H
#define MAIN_CARDRIVER_H


class CarDriver {
private:
    const int pinGas = RPI_BPLUS_GPIO_J8_40;
    const int pinReverse = RPI_BPLUS_GPIO_J8_38;
    const int pinTurnLeft = RPI_BPLUS_GPIO_J8_37;
    const int pinTurnRight = RPI_BPLUS_GPIO_J8_36;
public:

    CarDriver();

    void gas();

    void brake();

    void reverse();

    void turnLeft();

    void turnRight();

    ~CarDriver();
};


#endif //MAIN_CARDRIVER_H
