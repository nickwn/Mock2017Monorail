#include "ArmUp.h"

ArmUp::ArmUp() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(arm);
}

// Called just before this Command runs the first time
void ArmUp::Initialize() {
	SetTimeout(0.5);
}

// Called repeatedly when this Command is scheduled to run
void ArmUp::Execute() {
	arm->armD(0.2);
}

// Make this return true when this Command no longer needs to run execute()
bool ArmUp::IsFinished() {
	return IsTimedOut();
}

// Called once after isFinished returns true
void ArmUp::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ArmUp::Interrupted() {

}
