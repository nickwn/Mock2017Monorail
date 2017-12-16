#ifndef OI_H
#define OI_H
#include "WPILib.h"

class OI {
private:
	Joystick* leftStick;
	Joystick* rightStick;
	Joystick* armStick;
	Button* armLow;
	Button* armMid;
	Button* armHigh;
	Button* back;
	Button* hit;
public:
	OI();
	Joystick* getLeft();
	Joystick* getRight();
	Joystick* getArm();
};

#endif  // OI_H
