#include "AutonOneToteCounterClockwise.h"
#include "LiftXTicks.h"
#include "../Subsystems/Lift.h"
#include "DriveXFeet.h"
#include "ParallelArmsOut.h"
#include "ParallelArmsIn.h"
#include "DelayCommand.h"
#include "TurnNDegrees.h"

AutonOneToteCounterClockwise::AutonOneToteCounterClockwise()
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
	AddSequential (new ParallelArmsIn());

		AddSequential (new DelayCommand(1));

		AddSequential(new LiftXTicks(Lift:: TOTE_TWO_ENGAGE_TICKS,Lift::SPEED_UP));

		AddSequential (new DriveXFeet(-7.5, .3));

		AddSequential (new TurnNDegrees(-90, .3, 10));

		AddSequential (new DriveXFeet(1, .3));

		AddSequential(new LiftXTicks(Lift:: TOTE_ONE_ENGAGE_TICKS,Lift::SPEED_DOWN));

		AddSequential (new ParallelArmsOut());


		// may want to add this to all command groups so it is ovbious we are not touching totes;

		AddSequential (new DriveXFeet(-1, .3));  // to clear away from bin

		AddParallel (new LiftXTicks(Lift::GO_OVER_BIN_TICKS, Lift::SPEED_UP));
}
