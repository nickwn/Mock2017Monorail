#ifndef OI_H
#define OI_H
#include "WPILib.h"

class OI {
private:
	Joystick* leftStick;
	Joystick* rightStick;
<<<<<<< HEAD
	Joystick* ArmStick;
=======
	Button* gyroTurn;
	Button* drive;
>>>>>>> 519c26f6f774607e08e3c5b87fd1f8dc16898650
public:
	OI();
	Joystick* getLeft();
	Joystick* getRight();
	Joystick* gitArm();
};

#endif  // OI_H
