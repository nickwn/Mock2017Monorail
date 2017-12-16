#include "TimedDrive.h"

TimedDrive::TimedDrive(double left, double right, double timeout)
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(driveTrain);
}

// Called just before this Command runs the first time
void TimedDrive::Initialize() {
	driveTrain->tankDrive(-0.5, -0.5);
	SetTimeout (timeout);
}

// Called repeatedly when this Command is scheduled to run
void TimedDrive::Execute() {

}

// Make this return true when this Command no longer needs to run execute()
bool TimedDrive::IsFinished() {
	return IsTimedOut();
}

// Called once after isFinished returns true
void TimedDrive::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void TimedDrive::Interrupted() {

}
