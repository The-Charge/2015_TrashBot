// RobotBuilder Version: 1.5
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.



#include "AutonOneTote.h"
#include "LiftXTicks.h"
#include "../Subsystems/Lift.h"
#include "DriveXFeet.h"
#include "ParallelArmsOut.h"
#include "ParallelArmsIn.h"
#include "DelayCommand.h"


AutonOneTote::AutonOneTote() {
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

	// grabbing one tote and moving it to auto zone and move away




	AddSequential (new ParallelArmsIn());

	AddSequential (new DelayCommand(1));

	AddSequential(new LiftXTicks(Lift:: TOTE_TWO_ENGAGE_TICKS,Lift::SPEED_UP));

	AddSequential (new DriveXFeet(-9.5, .3));

	AddSequential(new LiftXTicks(Lift:: TOTE_ONE_ENGAGE_TICKS,Lift::SPEED_DOWN));

	AddSequential (new ParallelArmsOut());


	// may want to add this to all command groups so it is ovbious we are not touching totes;

	AddSequential (new DriveXFeet(-.5, .3)); // to clear away from bin

	AddSequential (new LiftXTicks(Lift::TOTE_TWO_ENGAGE_TICKS, Lift::SPEED_UP));

}
