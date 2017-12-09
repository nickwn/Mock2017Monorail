#include "Arm.h"
#include "../RobotMap.h"
#include "Commands/MoveArm.h"
#include "OI.h"

moveArm::moveArm() : Subsystem("Arm"), armMotor(new CANTalon(ARMMOTOR)) {

}

void moveArm::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
	SetDefaultCommand(new MoveArm());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.

void moveArm::armD(double armDistance)
{
	armMotor->Set(armDistance);
}

void moveArm::End()
{
	armMotor->Set(0);
}

