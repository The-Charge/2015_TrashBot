// RobotBuilder Version: 1.5
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.

#include "WinchOut.h"

#include <SmartDashboard/SmartDashboard.h>
#include <SpeedController.h>
#include <string>

#include "../Subsystems/WinchSystem.h"

WinchOut::WinchOut(float sp) {
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
	Requires(Robot::winchSystem);

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES

	SP = sp;

}

// Called just before this Command runs the first time
void WinchOut::Initialize() {

	this->SetInterruptible(false);
	SP = SmartDashboard::GetNumber(Robot::winchSystem->WINCH_SETPOINT_STRING,
			Robot::winchSystem->WINCH_SETPOINT_DEFAULT);

// caculates where you are at
	if (Robot::winchSystem->Winch_Position == 0 && SP == 2) {
		SetTimeout(MOVE_TIME_H2L); // sets timer to calculated value x3
		Robot::winchSystem->Winch_Position = 2; // sets new current position x3
	} else if (Robot::winchSystem->Winch_Position == 1 && SP == 2) {
		SetTimeout(MOVE_TIME_M2L); // x
		Robot::winchSystem->Winch_Position = 2; // x
	} else if (Robot::winchSystem->Winch_Position == 0 && SP == 1) {
		SetTimeout(MOVE_TIME_H2M); // x
		Robot::winchSystem->Winch_Position = 1; // x
	} else
		SetTimeout(0);
}

// Called repeatedly when this Command is scheduled to run
void WinchOut::Execute() {
	timerCountUp = this->TimeSinceInitialized();

	SmartDashboard::PutNumber(WINCH_TIMER_TIME_STRING, timerCountUp);
}

// Make this return true when this Command no longer needs to run execute()
bool WinchOut::IsFinished() {
	if (this->IsTimedOut() == true) // when the timer hits zero, the command will stop
		return true;

	return false;
}

// Called once after isFinished returns true
void WinchOut::End() {

	Robot::winchSystem->winchMotor->Set(0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void WinchOut::Interrupted() {

}
