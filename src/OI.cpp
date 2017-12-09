#include "OI.h"

#include <WPILib.h>

#include "Commands/GyroTurn.h"
#include "Commands/Drive.h"

OI::OI() :leftStick(new Joystick(0)), rightStick(new Joystick(1)),
			gyroTurn(new JoystickButton(leftStick, 1)),
			drive(new JoystickButton(rightStick, 1)){
	// Process operator interface input here.
	gyroTurn->WhenPressed(new GyroTurn(90, false));
	drive->WhenPressed(new Drive(0.5, 0.5, 0.5));
}

Joystick* OI::getLeft() {
	return leftStick;
}

Joystick* OI::getRight() {
	return rightStick;
}
