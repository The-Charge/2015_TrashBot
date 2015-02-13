#include "tashbin_auton.h"
#include "DriveXFeet.h"
#include "StrafeXFeet.h"
tashbin_auton::tashbin_auton()
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
	AddSequential(new StrafeXFeet(-1.7833));
	AddSequential(new DriveXFeet(-6)); // made 6 for best case senerion
	//add method for drop down of back arm
	AddSequential(new DriveXFeet(1));
	//add arm up method
	AddSequential(new StrafeXFeet(5.725));


}
