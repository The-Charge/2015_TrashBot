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
#include "Commands/AutonomousCommand.h"
#include "Commands/BrakeOff.h"
#include "Commands/BrakeOn.h"
#include "Commands/Drive.h"
#include "Commands/Drive2Feet.h"
#include "Commands/DriveXFeet.h"
#include "Commands/ResetEncoders.h"


    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES

OI::OI() {
	// Process operator interface input here.
        // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS

	joystick1 = new Joystick(0);
	
	drive2FeetButton = new JoystickButton(joystick1, 11);
	drive2FeetButton->WhenPressed(new Drive2Feet());
	resetEncodersButton = new JoystickButton(joystick1, 8);
	resetEncodersButton->WhenPressed(new ResetEncoders());
     

        // SmartDashboard Buttons
	SmartDashboard::PutData("Autonomous Command", new AutonomousCommand());

	SmartDashboard::PutData("Drive", new Drive());

	SmartDashboard::PutData("ResetEncoders", new ResetEncoders());

	SmartDashboard::PutData("Drive2Feet", new Drive2Feet());

	SmartDashboard::PutData("BrakeOn", new BrakeOn());

	SmartDashboard::PutData("BrakeOff", new BrakeOff());

	SmartDashboard::PutData("DriveXFeet", new DriveXFeet());


    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
}

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=FUNCTIONS

Joystick* OI::getJoystick1() {
	return joystick1;
}


    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=FUNCTIONS
