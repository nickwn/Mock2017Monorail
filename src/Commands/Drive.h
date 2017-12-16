#ifndef Drive_H
#define Drive_H

#include "../CommandBase.h"

class Drive : public CommandBase {
private:
	double left, right;
public:
	Drive(double _left, double _right);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // Drive_H
