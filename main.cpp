
#include "Dualshock4.h"
using namespace std;

int main()
{

    Dualshock4 joystick;
    while(true)
    {
        joystick.readState();
    }
    return 0;
}