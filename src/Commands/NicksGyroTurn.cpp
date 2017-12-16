#include "NicksGyroTurn.h"
#include <cmath>

NicksGyroTurn::NicksGyroTurn(double setAngle, double Kp, double Ki, double Kd) :
		_setAngle(setAngle), _pid(
				new WVPIDController(Kp, Ki, Kd, _setAngle, true))
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(driveTrain);
}

// Called just before this Command runs the first time
void NicksGyroTurn::Initialize()
{
	driveTrain->GyroReset();
}

// Called repeatedly when this Command is scheduled to run
void NicksGyroTurn::Execute()
{
	double val = _pid.Tick(driveTrain->GyroAngle());
	val = WVPIDController::Map(std::fabs(val), 0, std::fabs(_setAngle), 0, 1);
	val = WVPIDController::Limit(val, 1);
	int dir = std::fabs(_setAngle) / _setAngle;
	double spd = (1 - val) * dir;
	driveTrain->tankDrive(spd, -spd);
}

// Make this return true when this Command no longer needs to run execute()
bool NicksGyroTurn::IsFinished()
{
	return std::fabs(_setAngle - driveTrain->GyroAngle()) < 3;
}

// Called once after isFinished returns true
void NicksGyroTurn::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void NicksGyroTurn::Interrupted()
{

}
