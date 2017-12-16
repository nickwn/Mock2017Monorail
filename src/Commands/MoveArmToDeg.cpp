#include "MoveArmToDeg.h"

MoveArmToDeg::MoveArmToDeg(double deg) :
		_deg(deg)
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(arm);
}

// Called just before this Command runs the first time
void MoveArmToDeg::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void MoveArmToDeg::Execute() {
	arm->SetPosition(_deg);
}

// Make this return true when this Command no longer needs to run execute()
bool MoveArmToDeg::IsFinished() {
	return fabs(arm->EncoderPosition() - _deg) < 10; // or just true
}

// Called once after isFinished returns true
void MoveArmToDeg::End() {
	arm->End();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void MoveArmToDeg::Interrupted() {

}
