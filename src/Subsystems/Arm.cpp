#include "Arm.h"
#include "../RobotMap.h"
#include "Commands/MoveArm.h"
#include "OI.h"

Arm::Arm() :
		Subsystem("Arm"), armMotor(new CANTalon(ARMMOTOR)), encoder(
				new AnalogInput(1)), lowerLim(new DigitalInput(1)), upperLim(
				new DigitalInput(2))
{
	encoder->SetOversampleBits(4);
	encoder->SetAverageBits(2);
}

void Arm::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
	SetDefaultCommand(new MoveArm(90));
}

// Put methods for controlling this subsystem
// here. Call these from Commands.

void Arm::SetPosition(double deg)
{
	double currPos = EncoderPosition();
	if (lowerLim->Get() && deg < currPos)
		return;
	if (upperLim->Get() && deg > currPos)
		return;

	int dir = fabs(deg - currPos) / (deg - currPos);
	armMotor->Set(0.5 * dir);

	while (fabs(deg - currPos) > 3)
		;

	armMotor->Set(0);
}

void Arm::End()
{
	armMotor->Set(0);
}

double Arm::EncoderPosition() {
	return WVPIDController::Map(encoder->GetVoltage(), 0, 5, 0, 360);
}
