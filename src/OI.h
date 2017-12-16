#ifndef OI_H
#define OI_H
#include "WPILib.h"

class OI {
private:
	Joystick* leftStick;
	Joystick* rightStick;
	Joystick* ArmStick;
public:
	OI();
	Joystick* getLeft();
	Joystick* getRight();
	Joystick* gitArm();
};

#endif  // OI_H
