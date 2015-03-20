#include "AutonStrategy1Reeper.h"
#include "DriveXFeet.h"
#include "BinRetrievalRaiseAuton.h"
#include "BinRetrievalLowerAutonm.h"
#include "DelayCommand.h"

AutonStrategy1Reeper::AutonStrategy1Reeper()
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

	AddSequential (new DriveXFeet(-3, .5) );
	AddSequential (new BinRetrievalRaiseAuton (5));
	AddSequential (new DelayCommand(1));
	AddSequential (new DriveXFeet(6, .8));
	AddSequential (new BinRetrievalLowerAutonm(4));

}
