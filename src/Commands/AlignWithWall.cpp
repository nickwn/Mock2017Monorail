#include "AlignWithWall.h"

AlignWithWall::AlignWithWall() : leftDistance(0), rightDistance(999){
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(driveTrain);
}

// Called just before this Command runs the first time
void AlignWithWall::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void AlignWithWall::Execute() {
	double leftDistance = driveTrain->leftUltra();
	double rightDistance = driveTrain->rightUltra();
	if (leftDistance < rightDistance) {
		driveTrain->tankDrive(-0.1, 0.1);
	}
	else {
		driveTrain->tankDrive(0.1, -0.1);
	}
}

// Make this return true when this Command no longer needs to run execute()
bool AlignWithWall::IsFinished() {
	return leftDistance - rightDistance < fabs(0.05);
}

// Called once after isFinished returns true
void AlignWithWall::End() {
	driveTrain->Stop();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AlignWithWall::Interrupted() {
	driveTrain->Stop();
}
