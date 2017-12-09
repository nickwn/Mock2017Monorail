#ifndef ArmUp_H
#define ArmUp_H

#include "../CommandBase.h"

class ArmUp : public CommandBase {
public:
	ArmUp();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // ArmUp_H
