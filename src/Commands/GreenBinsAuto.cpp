#include "GreenBinsAuto.h"
#include "StrafeXFeet.h"
#include "TurnNDegrees.h"
#include "DriveXFeet.h"

GreenBinsAuto::GreenBinsAuto() {
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

	//First bin
	/*
	 for (int x = 0; x < 3; x++)
	 {
	 AddSequential(new StrafeXFeet(2));
	 AddSequential(new StrafeXFeet(-.5));
	 AddSequential(new TurnNDegrees(90));
	 AddSequential(new DriveXFeet(3));
	 AddSequential(new DriveXFeet(-5));

	 if(x < 2)
	 {
	 AddSequential(new TurnNDegrees(-90));
	 AddSequential(new DriveXFeet(6.41666));
	 }
	 }
	 */

	AddSequential(new StrafeXFeet(2));
	AddSequential(new StrafeXFeet(-.5));
	AddSequential(new TurnNDegrees(90));
	AddSequential(new DriveXFeet(4, .7));
	AddSequential(new DriveXFeet(-5, .7));

	AddSequential(new TurnNDegrees(-90));
	AddSequential(new DriveXFeet(6.41666, .9));

}
