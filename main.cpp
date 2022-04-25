
#include <iostream>
#include "Dualshock4.h"
#include "CarDriver.h"

using namespace std;

int main() {

    Dualshock4 joystick;
    CarDriver carDriver;

    while (true) {
        joystick.readState();
        for (int i = 0; i < 20; i++)
            cout << "\n";
        if (joystick.getKeyUp() == true) {
            carDriver.gas();
        } else if (joystick.getKeyDown()) {
            carDriver.reverse();
        } else if (joystick.getKeyLeft()) {
            carDriver.turnLeft();
        } else if (joystick.getKeyRight()) {
            carDriver.turnRight();
        }
        cout << "key UP: " << joystick.getKeyUp() << endl;
        cout << "key DOWN: " << joystick.getKeyDown() << endl;
        cout << "key LEFT: " << joystick.getKeyLeft() << endl;
        cout << "key RIGHT: " << joystick.getKeyRight() << endl;
    }
    return 0;
}