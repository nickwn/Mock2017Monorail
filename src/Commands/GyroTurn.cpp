#include "GyroTurn.h"

GyroTurn::GyroTurn(double _angle, bool _left): angle(_angle), left(_left) {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(driveTrain);
}

// Called just before this Command runs the first time
void GyroTurn::Initialize() {
	driveTrain->GyroReset();
}

// Called repeatedly when this Command is scheduled to run
void GyroTurn::Execute() {
	if (left) {
		driveTrain->tankDrive(-0.5, 0.5);
	} else {
		driveTrain->tankDrive(0.5, -0.5);
	}
}

// Make this return true when this Command no longer needs to run execute()
bool GyroTurn::IsFinished() {
	return angle - driveTrain->GyroAngle() < fabs(0.05);
}

// Called once after isFinished returns true
void GyroTurn::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void GyroTurn::Interrupted() {

}
