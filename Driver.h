//
// Created by Alex on 5/5/2022.
//

#ifndef MAIN_DRIVER_H
#define MAIN_DRIVER_H


class Driver {
private:
     int pinGas;
     int pinReverse;
     int pinTurnLeft;
     int pinTurnRight;
public:
    Driver();
    void gas();

    void brake();

    void reverse();

    void turnLeft();

    void turnRight();
    ~Driver();
};


#endif //MAIN_DRIVER_H
