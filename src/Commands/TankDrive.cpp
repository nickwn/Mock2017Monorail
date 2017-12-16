#include "TankDrive.h"

TankDrive::TankDrive() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(driveTrain);
}

// Called just before this Command runs the first time
void TankDrive::Initialize() {
	driveTrain->GyroReset();
}

// Called repeatedly when this Command is scheduled to run
void TankDrive::Execute() {
	double leftVal = -oi->getLeft()->GetY();
	double rightVal = -oi->getRight()->GetY();
	driveTrain->tankDrive(leftVal, rightVal);
	std::cout << "LeftUltrasonic: " << driveTrain->leftUltra() << std::endl;
	std::cout << "RightUltrasonic: " << driveTrain->rightUltra() << std::endl;
	std::cout << "GyroAngle: " << driveTrain->GyroAngle() << std::endl;
	std::cout << "GyroRate: " << driveTrain->GyroRate() << std::endl;
}

// Make this return true when this Command no longer needs to run execute()
bool TankDrive::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void TankDrive::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void TankDrive::Interrupted() {

}
