#include "OI.h"

#include <WPILib.h>

#include "Commands/GyroTurn.h"
#include "Commands/Drive.h"
#include "Commands/MoveUntilWall.h"

OI::OI() :
		leftStick(new Joystick(0)), rightStick(new Joystick(1)), armStick(
				new Joystick(2)), armLow(new JoystickButton(armStick, 2)), armMid(
				new JoystickButton(armStick, 3)), armHigh(
				new JoystickButton(armStick, 4)), back(
				new JoystickButton(armStick, 5)), hit(
				new JoystickButton(armStick, 1))
{

	// Process operator interface input here
	armLow->WhenPressed(new MoveArm(60));
	armMid->WhenPressed(new MoveArm(90));
	armHigh->WhenPressed(new MoveArm(120));
	back->WhenPressed(new TimedDrive(-0.5, -0.5, 1));
	hit->WhenPressed(new HitPeg());
}

Joystick* OI::getLeft() {
	return leftStick;
}

Joystick* OI::getRight() {
	return rightStick;
}

Joystick* OI::getArm()
{
	return armStick;
}
