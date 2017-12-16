#include "Arm.h"
#include "../RobotMap.h"
#include "Commands/MoveArm.h"
#include "OI.h"

Arm::Arm() : Subsystem("Arm"), armMotor(new CANTalon(ARMMOTOR)), encoder(new Encoder(0, 1)) {
	encoder->Reset();
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

double Arm::EncoderPosition() {
	return encoder->GetDistance();
}
