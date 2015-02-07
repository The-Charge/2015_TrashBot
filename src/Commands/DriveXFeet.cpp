// RobotBuilder Version: 1.5
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.

//Amanda is making changes here! <---


#include "DriveXFeet.h"

DriveXFeet::DriveXFeet(float f) {
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
	Requires(Robot::driveTrain);

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
	feet = f;
}

// Called just before this Command runs the first time
void DriveXFeet::Initialize() {
	this -> SetTimeout(10);
		Robot::driveTrain-> SetDistanceInFeet(feet);
}

// Called repeatedly when this Command is scheduled to run
void DriveXFeet::Execute() {
	Robot::driveTrain ->UpdateDashboard();
}

// Make this return true when this Command no longer needs to run execute()
bool DriveXFeet::IsFinished() {

	return Robot::driveTrain->AtDestination() || this -> IsTimedOut();
}

// Called once after isFinished returns true
void DriveXFeet::End() {
	Robot::driveTrain->DisablePIDControllers();
	Robot::driveTrain -> drive(0,0,0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriveXFeet::Interrupted() {
	End();
}
