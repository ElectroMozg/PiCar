
#include <iostream>
#include "Dualshock4.h"

using namespace std;

int main() {

    Dualshock4 joystick;
    while (true) {
        joystick.readState();
        for(int i=0;i<20;i++)
            cout <<"\n";

        cout << "key UP: " << joystick.getKeyUp() << endl;
        cout << "key DOWN: " << joystick.getKeyDown() << endl;
        cout << "key LEFT: " << joystick.getKeyLeft() << endl;
        cout << "key RIGHT: " << joystick.getKeyRight() << endl;
    }
    return 0;
}