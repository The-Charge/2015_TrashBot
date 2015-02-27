// RobotBuilder Version: 1.5
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.

#include "TurnNDegrees.h"
#include "math.h"

TurnNDegrees::TurnNDegrees(float d, float s, float dt) {
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
	Requires(Robot::driveTrain);
	degrees = d;
	speed = s;
	deadturn = dt;
	// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES

	// the following SmartDashboard values are for setting up defaults

}

// Called just before this Command runs the first time
void TurnNDegrees::Initialize() {
	this->SetTimeout(10); // 10 sec safety timer
	Robot::driveTrain -> ResetDirection();
}

// Called repeatedly when this Command is scheduled to run
void TurnNDegrees::Execute() {
	Robot::driveTrain -> PutTurnSmartDashboardValues();
	Robot::driveTrain -> TurnXDegrees(degrees, speed, deadturn);
}

// Make this return true when this Command no longer needs to run execute()
bool TurnNDegrees::IsFinished() {
	return Robot::driveTrain -> AtTurnDestination() || this -> IsTimedOut();
}

// Called once after isFinished returns true
void TurnNDegrees::End() {
	Robot::driveTrain -> Stop();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void TurnNDegrees::Interrupted() {
	End();
}

