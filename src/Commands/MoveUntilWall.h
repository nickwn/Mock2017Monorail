#ifndef MoveUntilWall_H
#define MoveUntilWall_H

#include "../CommandBase.h"

class MoveUntilWall : public CommandBase {
private:
	int distanceToTravel;
	double leftDistance;
	double rightDistance;
	double leftEncoder;
	double rightEncoder;
public:
	MoveUntilWall(int _distance);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // MoveUntilWall_H
