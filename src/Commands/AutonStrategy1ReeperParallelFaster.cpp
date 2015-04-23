#include "AutonStrategy1ReeperParallelFaster.h"
#include "DriveXFeetReeper.h"
#include "BinRetrievalRaiseAuton.h"
#include "BinRetrievalLowerAutonm.h"
#include "DriveXFeet.h"

AutonStrategy1ReeperParallelFaster::AutonStrategy1ReeperParallelFaster()
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
	AddParallel (new DriveXFeetReeper(-.75, .25) );
		AddSequential (new BinRetrievalRaiseAuton (1.1));
		//AddSequential (new DelayCommand(1));
		AddSequential (new DriveXFeet(8, .8));

		AddParallel (new DriveXFeet(-1, .4));
		AddSequential (new BinRetrievalLowerAutonm(4));
}