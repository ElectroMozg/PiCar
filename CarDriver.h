//
// Created by Alex on 4/14/2022.
//

#ifndef MAIN_CARDRIVER_H
#define MAIN_CARDRIVER_H


class CarDriver {
private:
    int pinGas;
    int pinReverse;
    int pinTurnLeft;
    int pinTurnRight;
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
