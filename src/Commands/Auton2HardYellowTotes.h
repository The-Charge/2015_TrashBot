#ifndef Auton2HardYellowTotes_H
#define Auton2HardYellowTotes_H

#include "Commands/CommandGroup.h"
#include "WPILib.h"

class Auton2HardYellowTotes: public CommandGroup {
public:
	Auton2HardYellowTotes();
	const float SPEED_UP = .7;
	const float SPEED_DOWN = .4;
	const float TOTE_ONE_ENGAGE_TICKS = 0;
	//TODO: MATH FOR CONSTANT TICK VALUE BELOW
	const float TOTE_TWO_ENGAGE_TICKS = 0;
	const float TOTE_THREE_ENGAGE_TICKS = 0;
	const float GO_OVER_BIN_TICKS = 0;

};

#endif
