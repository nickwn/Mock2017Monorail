#include "OI.h"

#include <WPILib.h>

#include "Commands/GyroTurn.h"
#include "Commands/Drive.h"
#include "Commands/MoveUntilWall.h"

OI::OI() :leftStick(new Joystick(0)), rightStick(new Joystick(1)), ArmStick(new Joystick(2)){
	// Process operator interface input here
}

Joystick* OI::getLeft() {
	return leftStick;
}

Joystick* OI::getRight() {
	return rightStick;
}
