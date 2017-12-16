#ifndef TimedDrive_H
#define TimedDrive_H

#include "../CommandBase.h"

class TimedDrive : public CommandBase {
public:
	TimedDrive(double left, double right, double timeout);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // TimedDrive_H
