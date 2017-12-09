#ifndef moveArm_H
#define moveArm_H

#include <Commands/Subsystem.h>

#include "WPILib.h"
#include "ctrlib/CANTalon.h"

class Arm : public Subsystem {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	CANTalon* armMotor;

public:
	Arm();
	void InitDefaultCommand();
	void armD(double armDistance);
	void End();
};

#endif  // moveArm_H
