#include "Arm.h"
#include "../RobotMap.h"
#include "Commands/MoveArm.h"
#include "OI.h"

Arm::Arm() : Subsystem("Arm"), armMotor(new CANTalon(ARMMOTOR)) {

}

void Arm::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
	SetDefaultCommand(new MoveArm());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.

void Arm::armD(double armDistance)
{
	armMotor->Set(armDistance);
}

void Arm::End()
{
	armMotor->Set(0);
}

