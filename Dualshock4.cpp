#include "Dualshock4.h"
#include <iostream>
#include <fcntl.h>

#include <linux/joystick.h>
#include <unistd.h>
#include <iomanip>

Dualshock4::Dualshock4() {

    int num_of_axis = 0;
    int num_of_buttons = 0;
    char name_of_joystick[80];

    if ((joystickFile = open(JOY_DEV, O_RDONLY)) < 0) {
        cerr << "Failed to open " << JOY_DEV << endl;
        return;
    }
    ioctl(joystickFile, JSIOCGAXES, &num_of_axis);
    ioctl(joystickFile, JSIOCGBUTTONS, &num_of_buttons);
    ioctl(joystickFile, JSIOCGNAME(80), &name_of_joystick);

    joy_button.resize(num_of_buttons,0);
    joy_axis.resize(num_of_axis,0);

    cout<<"Joystick: "<<name_of_joystick<<endl
        <<"  axis: "<<num_of_axis<<endl
        <<"  buttons: "<<num_of_buttons<<endl;
}

bool Dualshock4::getKeyLeft() {
    return keyLeft;
}

bool Dualshock4::getKeyRight() {
    return keyRight;
}

bool Dualshock4::getKeyUp() {
    return keyUp;
}

bool Dualshock4::getKeyDown() {
    return keyDown;
}

void Dualshock4::readState() {
    js_event js;

    read(joystickFile, &js, sizeof(js_event));

    switch (js.type & ~JS_EVENT_INIT)
    {
        case JS_EVENT_AXIS:
            if((int)js.number>=joy_axis.size())  {cerr<<"err:"<<(int)js.number<<endl; continue;}
            joy_axis[(int)js.number]= js.value;
            break;
        case JS_EVENT_BUTTON:
            if((int)js.number>=joy_button.size())  {cerr<<"err:"<<(int)js.number<<endl; continue;}
            joy_button[(int)js.number]= js.value;
            break;
    }

    cout<<"axis/10000: ";
    for(size_t i(0);i<joy_axis.size();++i)
        cout<<" "<<setw(2)<<joy_axis[i]/10000;
    cout<<endl;

    cout<<"  button: ";
    for(size_t i(0);i<joy_button.size();++i)
        cout<<" "<<(int)joy_button[i];
    cout<<endl;
}

Dualshock4::~Dualshock4() {
    close(joystickFile);
}