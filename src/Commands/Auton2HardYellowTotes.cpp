#include "Auton2HardYellowTotes.h"
#include "LeftArmOut.h"
#include "RightArmOut.h"
#include "StrafeXFeet.h"
#include "LiftXTicks.h"
#include "RightArmIn.h"
#include "LeftArmIn.h"
#include "DriveXFeet.h"
#include "Auton3ToteStack.h"

#include "ParallelArmsIn.h"
#include "ParallelArmsOut.h"

Auton2HardYellowTotes::Auton2HardYellowTotes()
{
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

	// Grab Bin1
	AddSequential (new ParallelArmsIn());
	AddSequential (new LiftXTicks(4000, .75));
	AddSequential (new StrafeXFeet(5.4125));
	AddSequential (new LiftXTicks(2000, -.75));
	AddSequential (new ParallelArmsOut());

	// Grab Bin2
	AddSequential (new LiftXTicks(1000, -.75));
	AddSequential (new ParallelArmsIn());
	AddSequential (new LiftXTicks(4000, .75));
	AddSequential (new StrafeXFeet(5.4125));
	AddSequential (new LiftXTicks(2000, -.75));
	AddSequential (new ParallelArmsOut());

	//Moving to AutoZone
	AddSequential(new DriveXFeet(-4, .5));
	AddSequential(new ParallelArmsOut());
	// this should move the two bins where the outer right part of the tote is above the landmark
	// if strafe to the right a small distance, bins will be on the landmark.
	// can place the two totes ontop of the other tote places by another team.


}
