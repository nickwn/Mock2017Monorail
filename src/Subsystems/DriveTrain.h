#ifndef DriveTrain_H
#define DriveTrain_H

#include <Commands/Subsystem.h>

#include "WPILib.h"
#include "ctrlib/CANTalon.h"

class DriveTrain : public Subsystem {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	CANTalon* leftMotor;
	CANTalon* rightMotor;
	Ultrasonic* leftUltrasonic;
	Ultrasonic* rightUltrasonic;
public:
	DriveTrain();
	void InitDefaultCommand();
	double leftUltra();
	double rightUltra();
	void tankDrive(double left, double right);
	void Stop();
	double leftEncoder();
	double rightEncoder();
	void EnablePID();
	void setPID(double p, double i, double d);
	void setSetpoint(double setpoint);
};

#endif  // DriveTrain_H
