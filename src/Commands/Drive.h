#ifndef Drive_H
#define Drive_H

#include "../CommandBase.h"

class Drive : public CommandBase {
private:
	double left, right, time;
public:
	Drive(double _left, double _right, double _time);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // Drive_H
