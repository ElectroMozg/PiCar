
#include <iostream>
#include "Dualshock4.h"
#include "Driver.h"

using namespace std;

int main() {

    Dualshock4 joystick;
    Driver carDriver;

    while (true) {
        joystick.readState();
        for (int i = 0; i < 20; i++)
            cout << "\n";
        carDriver.brake();
        if (joystick.getKeyUp() == true) {
            carDriver.gas();
        } else if (joystick.getKeyDown()) {
            carDriver.reverse();
        } else if (joystick.getKeyLeft()) {
            carDriver.turnLeft();
        } else if (joystick.getKeyRight()) {
            carDriver.turnRight();
        } else if (joystick.getKeyCross()){
            carDriver.brake();
        }

        cout << "key UP: " << joystick.getKeyUp() << endl;
        cout << "key DOWN: " << joystick.getKeyDown() << endl;
        cout << "key LEFT: " << joystick.getKeyLeft() << endl;
        cout << "key RIGHT: " << joystick.getKeyRight() << endl;
        cout << "key CROSS: " << joystick.getKeyCross() << endl;
    }
    return 0;
}