// RobotBuilder Version: 1.5
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#include "DriveSBDFeet.h"

DriveSBDFeet::DriveSBDFeet() {
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
	Requires(Robot::driveTrain);

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES


	SmartDashboard::PutNumber(DISTANCE_TO_TRAVEL_IN_FEET_DASHBOARD_KEY, FEET_DEFAULT);

}

// Called just before this Command runs the first time
void DriveSBDFeet::Initialize() {
	// here there needs to be a SetOut(ft) command...
	this -> SetTimeout(10);
	Robot::driveTrain -> DriveSDBFeet();
}

// Called repeatedly when this Command is scheduled to run
void DriveSBDFeet::Execute() {
	// took out the feet command that
	Robot::driveTrain ->PutEncoderValuesToDashboard();
	

}

// Make this return true when this Command no longer needs to run execute()
bool DriveSBDFeet::IsFinished() {
	//return false;

	return Robot::driveTrain->AtDestination() || this -> IsTimedOut();

}

// Called once after isFinished returns true
void DriveSBDFeet::End() {
	Robot::driveTrain->DisablePIDControllers();
		Robot::driveTrain -> drive(0,0,0);
	
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriveSBDFeet::Interrupted() {
	End();
}
