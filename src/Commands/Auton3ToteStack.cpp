// RobotBuilder Version: 1.5
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.

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

Auton3ToteStack::Auton3ToteStack() {
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

	// 4000 indicates the level of 4 bins, 3000 indicates the level of 3 bins, 2000, etc

	//Grab Bin1

	AddSequential(new ParallelArmsIn());

	AddSequential(new LiftXTicks(Robot::lift -> GO_OVER_BIN_TICKS, Robot::lift -> SPEED_UP));
	AddSequential(new StrafeXFeet(5.4125));
	AddSequential(new LiftXTicks(Robot::lift -> TOTE_TWO_ENGAGE_TICKS,Robot::lift ->  SPEED_DOWN));

	AddSequential(new ParallelArmsOut());

	//Grab Bin2
	AddSequential(new LiftXTicks(Robot::lift -> TOTE_ONE_ENGAGE_TICKS, Robot::lift -> SPEED_DOWN));

	AddSequential(new ParallelArmsIn());

	AddSequential(new LiftXTicks(Robot::lift -> GO_OVER_BIN_TICKS, Robot::lift -> SPEED_UP));
	AddSequential(new StrafeXFeet(5.4125));
	AddSequential(new LiftXTicks(Robot::lift -> TOTE_THREE_ENGAGE_TICKS,Robot::lift ->  SPEED_DOWN));

	AddSequential(new ParallelArmsOut());

	//Grab Bin3
	AddSequential(new LiftXTicks(Robot::lift -> TOTE_ONE_ENGAGE_TICKS, Robot::lift -> SPEED_DOWN));

	AddSequential(new ParallelArmsIn());

	AddSequential(new LiftXTicks(Robot::lift -> TOTE_ONE_ENGAGE_TICKS, Robot::lift -> SPEED_UP));

	//Moving to auto zone
	AddSequential(new DriveXFeet(-8.11, .5));

	AddSequential(new ParallelArmsOut());

}
