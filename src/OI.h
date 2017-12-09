#ifndef OI_H
#define OI_H
#include "WPILib.h"

class OI {
private:
	Joystick* leftStick;
	Joystick* rightStick;
	Button* gyroTurn;
	Button* drive;
public:
	OI();
	Joystick* getLeft();
	Joystick* getRight();
};

#endif  // OI_H
