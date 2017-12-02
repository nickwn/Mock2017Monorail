#include "DriveTrain.h"
#include "../RobotMap.h"
#include "Commands/TankDrive.h"

DriveTrain::DriveTrain() : Subsystem("DriveTrain"), leftMotor(new CANTalon(LEFTMOTOR)), rightMotor(new CANTalon(RIGHTMOTOR)),
							leftUltrasonic(new Ultrasonic(LEFT_ULTRA_TRIGGER, LEFT_ULTRA_ECHO)),
							rightUltrasonic(new Ultrasonic(RIGHT_ULTRA_TRIGGER, RIGHT_ULTRA_ECHO)){
	leftUltrasonic->SetAutomaticMode(true);
}

void DriveTrain::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
	SetDefaultCommand(new TankDrive);
}

double DriveTrain::leftUltra() {
	int distanceCount = 10;
	double distances[10];
	double distance;
	for (int i = 0; i < distanceCount; i++) {
		distances[i] = leftUltrasonic->GetRangeInches();
	}
	distance = 0;
	for (int i = 0; i < distanceCount; i++) {
		distance += distances[i];
		distance /= 10;
	}
	return distance;
}

double DriveTrain::rightUltra() {
	int distanceCount = 10;
	double distances[10];
	double distance;
	for (int i = 0; i < distanceCount; i++) {
	distances[i] = rightUltrasonic->GetRangeInches();
	}
	distance = 0;
	for (int i = 0; i < distanceCount; i++) {
		distance += distances[i];
		distance /= 10;
	}
	return distance;
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

void DriveTrain::EnablePID() {
	leftMotor->Enable();
	rightMotor->Enable();
}

void DriveTrain::setPID(double p, double i, double d) {
	leftMotor->SetPID(p, i, d);
	rightMotor->SetPID(p, i, d);
}

void DriveTrain::setSetpoint(double setpoint) {
	leftMotor->SetSetpoint(setpoint);
	rightMotor->SetSetpoint(setpoint);
}
// Put methods for controlling this subsystem
// here. Call these from Commands.
