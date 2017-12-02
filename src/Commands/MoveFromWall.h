#ifndef MoveFromWall_H
#define MoveFromWall_H

#include "../CommandBase.h"

class MoveFromWall : public CommandBase {
private:
	double targetDistance;
	double leftDistance;
	double rightDistance;
	double leftEncoder;
	double rightEncoder;
public:
	MoveFromWall(double _distance);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // MoveFromWall_H
