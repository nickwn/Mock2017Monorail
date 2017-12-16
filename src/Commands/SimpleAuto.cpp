
#include "SimpleAuto.h"

SimpleAuto::SimpleAuto()
{
	AddSequential(new MoveUntilWall(6))
}
