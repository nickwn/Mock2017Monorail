#ifndef Autonomous_H
#define Autonomous_H

#include "iostream"
#include <Commands/CommandGroup.h>
#include "WPILib.h"

#include "MoveUntilWall.h"
#include "Drive.h"
#include "AlignWithWall.h"
#include "MoveFromWall.h"

#include "Utilities/NetworkTablesInterface.h"

class Autonomous : public CommandGroup {
private:
	std::string HZone;
public:
	Autonomous();
};

#endif  // Autonomous_H
