#ifndef MoveArmToDeg_H
#define MoveArmToDeg_H

#include "../CommandBase.h"

class MoveArmToDeg : public CommandBase {
public:
	MoveArmToDeg(double deg);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
private:
	double _deg;
};

#endif  // MoveArmToDeg_H
