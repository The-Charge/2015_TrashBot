#include "AutonPickingUpTwoThings.h"
#include "AutonPickingUpTwoThings.h"
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
#include "TurnNDegrees.h"
AutonPickingUpTwoThings::AutonPickingUpTwoThings()
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
	// Grabbing the bin
	AddSequential(new ParallelArmsIn()); //arms in to the bin
	AddSequential(new LiftXTicks(Lift::GO_OVER_BIN_TICKS, Lift:: SPEED_UP));//lifting the bin
	AddSequential(new StrafeXFeet(1.5));// close value, but need to strafe to the next tote
	AddSequential(new LiftXTicks(Lift::TOTE_TWO_ENGAGE_TICKS, Lift :: SPEED_DOWN));// going down to the tote might be for setting a tote on a tote not a bin on a tote
	AddSequential(new ParallelArmsOut());// setting the bin down
	//
		AddSequential(new LiftXTicks(Lift:: TOTE_ONE_ENGAGE_TICKS, Lift:: SPEED_DOWN));// going down to pick up the bottom tote
		AddSequential(new ParallelArmsIn());// grab
		AddSequential(new LiftXTicks(Lift:: TOTE_TWO_ENGAGE_TICKS, Lift:: SPEED_UP));//lift up don't know if high enough
		//Moving to AutoZone
		AddSequential(new DriveXFeet(-7.5, .5));// should end up in the middle of the zone
		AddSequential(new TurnNDegrees(90, .3, 10)); // turning 90 degrees
		AddSequential(new DriveXFeet(1,.5));// moving forward
		AddSequential(new LiftXTicks(Lift::TOTE_ONE_ENGAGE_TICKS, Lift::SPEED_DOWN)); //Lowers totes to the ground
		AddSequential(new ParallelArmsOut());// letting go of the stack
		AddSequential(new DriveXFeet(-1,.5)); // driving back
		AddSequential(new LiftXTicks(Lift::GO_OVER_BIN_TICKS, Lift:: SPEED_UP));// going all the way up (to go over a bin)

		AddSequential (new DriveXFeet(.5)); // to clear away from bin
}
