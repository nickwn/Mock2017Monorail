#include "OI.h"

#include <WPILib.h>

OI::OI() :leftStick(new Joystick(0)), rightStick(new Joystick(1)){
	// Process operator interface input here.
}

Joystick* OI::getLeft() {
	return leftStick;
}

Joystick* OI::getRight() {
	return rightStick;
}
