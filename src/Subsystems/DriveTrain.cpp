#include "DriveTrain.h"
#include "../RobotMap.h"
#include "Commands/TankDrive.h"

DriveTrain::DriveTrain() : Subsystem("DriveTrain"), leftMotor(new CANTalon(LEFTMOTOR)), rightMotor(new CANTalon(RIGHTMOTOR)),
							ultrasonicSensor(new Ultrasonic(ULTRASONIC_TRIGGER, ULTRASONIC_ECHO)) {
	ultrasonicSensor->SetAutomaticMode(true);
}

void DriveTrain::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
	SetDefaultCommand(new TankDrive);
}

double DriveTrain::getUltra() {
	return ultrasonicSensor->GetRangeInches();
}

void DriveTrain::tankDrive(double left, double right) {
	leftMotor->Set(left * MULTIPLIER);
	rightMotor->Set(right * MULTIPLIER);
}

void DriveTrain::Stop() {
	leftMotor->Set(0);
	rightMotor->Set(0);
}

double DriveTrain::leftEncoder() {
	return leftMotor->GetEncPosition();
}

double DriveTrain::rightEncoder() {
	return rightMotor->GetEncPosition();
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
