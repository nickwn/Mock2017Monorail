#include "Autonomous.h"

Autonomous::Autonomous() {
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
	AddSequential(new MoveUntilWall(12)); //change target distance
<<<<<<< HEAD
	AddSequential(new Drive(-0.5, 0.5, 1)); //turn to face left wall
	AddSequential(new AlignWithWall());
	/*
	if (orientation != "v") {
=======
	//AddSequential(new Drive(-0.5, 0.5, 1)); //turn to face left wall
	//AddSequential(new AlignWithWall());
	if (NetworkTablesInterface::Orientation() != "V") {
		if (NetworkTablesInterface::Orientation() == "H") {
			HZone = "A";
		}
		AddSequential(new Drive(-0.5, 0.5, 1));
		AddSequential(new AlignWithWall());
>>>>>>> 519c26f6f774607e08e3c5b87fd1f8dc16898650
		AddSequential(new MoveFromWall(42)); //3'6" zone
		if (NetworkTablesInterface::Orientation() != "V") {
			AddSequential(new MoveFromWall(84));
			//turn
			//hit target
		} else {
			//turn
			//hit target
		}
	} else {
		//turn
		//hit target
	}
	*/
	//return to zone A
	//turn back
	/*
	AddSequential(new MoveUntilWall(12)); //change target distance
	if (orientation != "s") {
		AddSequential(new MoveFromWall(42));
		if (orientation != "s") {
			AddSequential(new MoveFromWall(84));
		}
	}
	*/

}
