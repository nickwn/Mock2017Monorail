#ifndef GyroTurn_H
#define GyroTurn_H

#include "../CommandBase.h"

class GyroTurn : public CommandBase {
private:
	double angle;
	bool left;
public:
	GyroTurn(double _angle, bool _left);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // GyroTurn_H
