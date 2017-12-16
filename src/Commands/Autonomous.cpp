#include "Autonomous.h"

Autonomous::Autonomous() : HZone("unknown"), position("A"){
	// Add Commands here:
	// e.g. AddSequential(new Command1());
	//      AddSequential(new Command2());
	// these will run in order.

	// To run multiple commands at the same time,
	// use AddParallel()
	// e.g. AddParallel(new Command1());
	//      AddSequential(new Command2());
	// Command1 and Command2 will run in parallel.

	// A command group will require all of the subsystems that each member
	// would require.
	// e.g. if Command1 requires chassis, and Command2 requires arm,
	// a CommandGroup containing them would require both the chassis and the
	// arm.
	AddSequential(new MoveUntilWall(6)); //change target distance
	if (NetworkTablesInterface::Orientation() != "V") {
		if (NetworkTablesInterface::Orientation() == "H") {
			HZone = "A";
		}
		AddSequential(new Drive(-0.5, 0.5));
		AddSequential(new AlignWithWall());
		AddSequential(new Drive(-0.5, -0.5));
		AddSequential(new Drive(0.5, -0.5));
		AddSequential(new AlignWithWall());
		if (NetworkTablesInterface::Orientation() != "V") {
			if (NetworkTablesInterface::Orientation() == "H") {
				HZone = "B";
			}
			//hit target
		} else {
			AddSequential(new GyroTurn(90, false));
			AddSequential(new Drive(0.5, 0.5));
			AddSequential(new Drive(-0.5, 0.5));
			AddSequential(new AlignWithWall());
			//hit target
		}
	} else {
		//hit target
	}
	/*
	AddSequential(new MoveUntilWall(12)); //change target distance
	if (NetworkTablesInterface::Orientation() != "s") {
		AddSequential(new MoveFromWall(42));
		if (NetworkTablesInterface:Orientation != "s") {
			AddSequential(new MoveFromWall(84));
		}
	}
	*/

}
