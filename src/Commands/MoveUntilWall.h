#ifndef MoveUntilWall_H
#define MoveUntilWall_H

#include "../CommandBase.h"

class MoveUntilWall : public CommandBase {
private:
	double targetDistance;
	double leftDistance;
	double rightDistance;
	double angle;
public:
	MoveUntilWall(double _distance);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // MoveUntilWall_H
