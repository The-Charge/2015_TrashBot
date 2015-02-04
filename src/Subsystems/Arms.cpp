// RobotBuilder Version: 1.5
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.

#include "Arms.h"
#include "../RobotMap.h"
// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES
// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES

Arms::Arms() :
		Subsystem("Arms") {
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	leftArm = RobotMap::armsLeftArm;
	rightArm = RobotMap::armsRightArm;

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
}

void Arms::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND
}

void Arms::LeftArmIn() {
	leftArm->Set(DoubleSolenoid::kForward);
}

void Arms::LeftArmOut() {
	leftArm->Set(DoubleSolenoid::kReverse);
}

void Arms::LeftArmOff() {
	leftArm->Set(DoubleSolenoid::kOff);
}

void Arms::RightArmIn() {
	rightArm->Set(DoubleSolenoid::kForward);
}

void Arms::RightArmOut() {
	rightArm->Set(DoubleSolenoid::kReverse);
}

void Arms::RightArmOff() {
	rightArm->Set(DoubleSolenoid::kOff);
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
