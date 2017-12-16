#ifndef NicksGyroTurn_H
#define NicksGyroTurn_H

#include "../CommandBase.h"
#include "WPILib.h"

class NicksGyroTurn : public CommandBase {
public:
	NicksGyroTurn(double setAngle, double Kp = 3, double Ki = 0.7, double Kd =
			0.8);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
private:
	double _setAngle;
	WVPIDController* _pid;
};

#endif  // NicksGyroTurn_H
