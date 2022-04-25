//
// Created by user on 4/8/2022.
//

#ifndef JOYSTICK_DUALSHOCK4_H
#define JOYSTICK_DUALSHOCK4_H

//
// Created by user on 4/8/2022.
//

#include <vector>

#define JOY_DEV "/dev/input/js0"

using namespace std;

class Dualshock4 {
private:
    int joystickFile = -1;
    bool keyLeft;
    bool keyRight;
    bool keyUp;
    bool keyDown;
    bool keyCross;
    vector<char> joy_button;
    vector<int> joy_axis;
public:
    Dualshock4();

    bool getKeyLeft();

    bool getKeyRight();

    bool getKeyUp();

    bool getKeyDown();

    bool getKeyCross();

    void readState();

    ~Dualshock4();
};

#endif //JOYSTICK_DUALSHOCK4_H
