#include "MoveUntilWall.h"

MoveUntilWall::MoveUntilWall(int _distance) :distanceToTravel(_distance),
						leftDistance(999), rightDistance(999),
						leftEncoder(0), rightEncoder(0){
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(driveTrain);
}

// Called just before this Command runs the first time
void MoveUntilWall::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void MoveUntilWall::Execute() {
	driveTrain->tankDrive(1, 1);
	//driveTrain->tankDrive(1 - leftEncoder + rightEncoder, 1 - rightEncoder + leftEncoder)
	leftDistance = driveTrain->leftUltra();
	rightDistance = driveTrain->rightUltra();
	leftEncoder = driveTrain->leftEncoder();
	rightEncoder = driveTrain->rightEncoder();
}

// Make this return true when this Command no longer needs to run execute()
bool MoveUntilWall::IsFinished() {
	return distanceToTravel - leftDistance < fabs(0.05);// or distanceToTravel - leftDistance < fabs(0.05);
}

// Called once after isFinished returns true
void MoveUntilWall::End() {
	driveTrain->Stop();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void MoveUntilWall::Interrupted() {
	driveTrain->Stop();
}
