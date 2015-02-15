// RobotBuilder Version: 1.5
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#include "OI.h"

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES
#include "SmartDashboard/SmartDashboard.h"
#include "Commands/Auton2HardYellowTotes.h"
#include "Commands/Auton3TotesStack.h"
#include "Commands/AutonomousCommand.h"
#include "Commands/AutonomousStrategy2.h"
#include "Commands/AutonomousStrategyPush.h"
#include "Commands/BrakeOff.h"
#include "Commands/BrakeOn.h"
#include "Commands/Drive.h"
#include "Commands/DriveSBDFeet.h"
#include "Commands/DriveXFeet.h"
#include "Commands/GreenBinsAuto.h"
#include "Commands/LeftArmIn.h"
#include "Commands/LeftArmOut.h"
#include "Commands/LiftDownFast.h"
#include "Commands/LiftDownSlow.h"
#include "Commands/LiftUpFast.h"
#include "Commands/LiftUpSlow.h"
#include "Commands/ResetEncoders.h"
#include "Commands/RightArmIn.h"
#include "Commands/RightArmOut.h"
#include "Commands/StrafeSBDFeet.h"
#include "Commands/StrafeXFeet.h"
#include "Commands/Trashbin_Auto.h"


    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES

OI::OI() {
	// Process operator interface input here.
        // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS

	buttonBox = new Joystick(1);
	
	leftArmOutBtn = new JoystickButton(buttonBox, 4);
	leftArmOutBtn->WhenPressed(new LeftArmOut());
	rightArmOutBtn = new JoystickButton(buttonBox, 8);
	rightArmOutBtn->WhenPressed(new RightArmOut());
	rightArmInBtn = new JoystickButton(buttonBox, 7);
	rightArmInBtn->WhenPressed(new RightArmIn());
	leftArmInBtn = new JoystickButton(buttonBox, 3);
	leftArmInBtn->WhenPressed(new LeftArmIn());
	liftDownSlowBtn = new JoystickButton(buttonBox, 6);
	liftDownSlowBtn->WhileHeld(new LiftDownSlow());
	liftUpSlowBtn = new JoystickButton(buttonBox, 5);
	liftUpSlowBtn->WhileHeld(new LiftUpSlow());
	liftDownFastBtn = new JoystickButton(buttonBox, 2);
	liftDownFastBtn->WhileHeld(new LiftDownFast());
	liftUpFastBtn = new JoystickButton(buttonBox, 1);
	liftUpFastBtn->WhileHeld(new LiftUpFast());
	joystick1 = new Joystick(0);
	
	resetEncodersButton = new JoystickButton(joystick1, 8);
	resetEncodersButton->WhenPressed(new ResetEncoders());
     

        // SmartDashboard Buttons
	SmartDashboard::PutData("Autonomous Command", new AutonomousCommand());

	SmartDashboard::PutData("Drive", new Drive());

	SmartDashboard::PutData("ResetEncoders", new ResetEncoders());

	SmartDashboard::PutData("BrakeOn", new BrakeOn());

	SmartDashboard::PutData("BrakeOff", new BrakeOff());

	SmartDashboard::PutData("DriveXFeet", new DriveXFeet());

	SmartDashboard::PutData("LiftUpFast", new LiftUpFast());

	SmartDashboard::PutData("LiftDownFast", new LiftDownFast());

	SmartDashboard::PutData("LiftUpSlow", new LiftUpSlow());

	SmartDashboard::PutData("LiftDownSlow", new LiftDownSlow());

	SmartDashboard::PutData("LeftArmIn", new LeftArmIn());

	SmartDashboard::PutData("RightArmIn", new RightArmIn());

	SmartDashboard::PutData("LeftArmOut", new LeftArmOut());

	SmartDashboard::PutData("RightArmOut", new RightArmOut());

	SmartDashboard::PutData("AutonomousStrategyPush", new AutonomousStrategyPush());

	SmartDashboard::PutData("AutonomousStrategy2", new AutonomousStrategy2());

	SmartDashboard::PutData("StrafeSBDFeet", new StrafeSBDFeet());

	SmartDashboard::PutData("DriveSBDFeet", new DriveSBDFeet());

	SmartDashboard::PutData("Auton3TotesStack", new Auton3TotesStack());

	SmartDashboard::PutData("Auton2HardYellowTotes", new Auton2HardYellowTotes());

	SmartDashboard::PutData("Trashbin_Auto", new Trashbin_Auto());

	SmartDashboard::PutData("GreenBinsAuto", new GreenBinsAuto());


    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS

	SmartDashboard::PutData("Schedular", Scheduler::GetInstance());
	SmartDashboard::PutData("lift", Robot::lift);
	SmartDashboard::PutData("DriveTrain",Robot::driveTrain);
	SmartDashboard::PutData("arms",Robot::arms);
	SmartDashboard::PutData("brake",Robot::brake);
	SmartDashboard::PutData("winch",Robot::winchSystem);
	SmartDashboard::PutData("compressor",Robot::compressor1);

}

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=FUNCTIONS

Joystick* OI::getButtonBox() {
	return buttonBox;
}

Joystick* OI::getJoystick1() {
	return joystick1;
}


    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=FUNCTIONS
