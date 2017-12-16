#include "MoveUntilWall.h"

MoveUntilWall::MoveUntilWall(double _distance) : targetDistance(_distance),
						leftDistance(999), rightDistance(999), angle(0){
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(driveTrain);
}

// Called just before this Command runs the first time
void MoveUntilWall::Initialize() {
	/*
	driveTrain->EnablePID();
	driveTrain->setPID(1, 0, 0);
	*/
}

// Called repeatedly when this Command is scheduled to run
void MoveUntilWall::Execute() {
	leftDistance = driveTrain->leftUltra();
	rightDistance = driveTrain->rightUltra();
	angle = driveTrain->GyroAngle();
	driveTrain->arcadeDrive(1, -angle);
}

// Make this return true when this Command no longer needs to run execute()
bool MoveUntilWall::IsFinished() {
	return targetDistance - leftDistance < fabs(0.05) or targetDistance - rightDistance < fabs(0.05);
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
