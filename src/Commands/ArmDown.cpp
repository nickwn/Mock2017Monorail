#include "ArmDown.h"

ArmDown::ArmDown() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(arm);
}

// Called just before this Command runs the first time
void ArmDown::Initialize() {
	SetTimeout(0.5);
}

// Called repeatedly when this Command is scheduled to run
void ArmDown::Execute() {
	arm->armD(-0.2);
}

// Make this return true when this Command no longer needs to run execute()
bool ArmDown::IsFinished() {
	return IsTimedOut();
}

// Called once after isFinished returns true
void ArmDown::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ArmDown::Interrupted() {

}
