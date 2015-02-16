// RobotBuilder Version: 1.5
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.

#include "WinchIn.h"
#include "../Subsystems/WinchSystem.h"

WinchIn::WinchIn(float sp) {
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
	Requires(Robot::winchSystem);

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
	SP = sp; // gets value sent to it
}

// Called just before this Command runs the first time
void WinchIn::Initialize() {

	this->SetInterruptible(false);
	SP = SmartDashboard::GetNumber(Robot::winchSystem->WINCH_SETPOINT_STRING,
			Robot::winchSystem->WINCH_SETPOINT_DEFAULT);

	if (Robot::winchSystem->Winch_Position == 1 && SP == 0) { // if the winch is at the High position, the winch will not move
		SetTimeout(MOVE_TIME_M2H);
		Robot::winchSystem->Winch_Position = 0;
	} else if (Robot::winchSystem->Winch_Position == 2 && SP == 0) { // if the winch is at the low position, the winch will move to the high position
		SetTimeout(MOVE_TIME_L2H);
		Robot::winchSystem->Winch_Position = 0;
	} else if (Robot::winchSystem->Winch_Position == 2 && SP == 1) { // if the winch is at the medium position, the winch will move to the high position
		SetTimeout(MOVE_TIME_L2M);
		Robot::winchSystem->Winch_Position = 1;
	} else
		SetTimeout(0);
}

// Called repeatedly when this Command is scheduled to run
void WinchIn::Execute() {

	//if (this -> IsTimedOut() == false )
	//Robot::winchSystem->winchMotor->Set(SmartDashboard::GetNumber(WINCH_IN_SPEED_STRING, WINCH_IN_SPEED_DEFAULT)); // when winch needs to get to a lower point
	timerCountUp = this->TimeSinceInitialized();

	SmartDashboard::PutNumber(WINCH_TIMER_TIME_STRING, timerCountUp);
}

// Make this return true when this Command no longer needs to run execute()
bool WinchIn::IsFinished() {
	if (this->IsTimedOut() == true) // when the timer hits zero, the command will stop
		return true;

	return false;
}

// Called once after isFinished returns true
void WinchIn::End() {

	Robot::winchSystem->winchMotor->Set(0);

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void WinchIn::Interrupted() {

	//End(); // Should edit so the commad isn't interrupted / not affected by the interrupt
}
