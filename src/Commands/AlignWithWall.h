#ifndef AlignWithWall_H
#define AlignWithWall_H

#include "../CommandBase.h"

class AlignWithWall : public CommandBase {
private:
	double leftDistance;
	double rightDistance;
public:
	AlignWithWall();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // AlignWithWall_H
