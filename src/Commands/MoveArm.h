#ifndef MoveArm_H
#define MoveArm_H

#include "../CommandBase.h"

class MoveArm : public CommandBase {
public:
	MoveArm();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
private:
};

#endif  // MoveArm_H
