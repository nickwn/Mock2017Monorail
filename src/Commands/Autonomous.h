#ifndef Autonomous_H
#define Autonomous_H

#include "iostream"
#include <Commands/CommandGroup.h>
#include "WPILib.h"

#include "MoveUntilWall.h"


class Autonomous : public CommandGroup {
private:
	std::string sZone = NetworkTable::GetTable("cv")->GetString("sZone", "a");
	std::string vZone = NetworkTable::GetTable("cv")->GetString("vZone", "a");
public:
	Autonomous();
};

#endif  // Autonomous_H
