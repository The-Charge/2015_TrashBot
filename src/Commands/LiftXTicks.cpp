// RobotBuilder Version: 1.5
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.

#include "LiftXTicks.h"

LiftXTicks::LiftXTicks(int t, float s) {
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
	Requires(Robot::lift);

<<<<<<< HEAD
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
	LIFT_ENCODER_TICKS = Robot::lift-> encoder->Get();
=======
	// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
	LIFT_ENCODER_TICKS = Robot::lift->encoder->Get();
>>>>>>> origin/develop

	SmartDashboard::PutNumber(MAX_VALUE_TICKS, MAXLIFTTICKS);

	SmartDashboard::PutNumber(LIFT_DEADBAND_STRING, LIFT_DEADBAND_DEFAULT);

	SmartDashboard::PutNumber(LIFT_ENCODER_VALUE, LIFT_ENCODER_TICKS);

	SmartDashboard::PutNumber(LIFT_TICKS_STRING, TICKS_LIFT_DEFAULT);
	SmartDashboard::PutNumber(LIFT_SPEED_STRING, SPEED_LIFT_DEFAULT);

	// intiliatizes speed and tick values sent in
	speed = s;		// postive indicates lift up, negative indicates lift down
	ticks = t;		// where the lift is to end
}

// Called just before this Command runs the first time
void LiftXTicks::Initialize() {
<<<<<<< HEAD
	Robot::brake->BrakeOff(); // turns brakes off of the lift
	this -> SetTimeout(2); // sets timeout for safety
	
	deadbandlift = SmartDashboard::GetNumber(LIFT_DEADBAND_STRING, LIFT_DEADBAND_DEFAULT); // sets deadband value
	//Robot::lift2-> CANTalon1->Set(speed); // sets the speed wanted to drive at from auton
=======

	ticks = SmartDashboard::GetNumber(LIFT_TICKS_STRING, TICKS_LIFT_DEFAULT);
	speed = SmartDashboard::GetNumber(LIFT_SPEED_STRING, SPEED_LIFT_DEFAULT);

	Robot::lift->BrakeOff(); // turns brakes off of the lift
	this->SetTimeout(2); // sets timeout for safety

	deadbandlift = SmartDashboard::GetNumber(LIFT_DEADBAND_STRING,
			LIFT_DEADBAND_DEFAULT); // sets deadband value
	Robot::lift->speedController->Set(speed); // sets the speed wanted to drive at from auton
>>>>>>> origin/develop

}

// Called repeatedly when this Command is scheduled to run
void LiftXTicks::Execute() {
	LIFT_ENCODER_TICKS = Robot::driveTrain->CANTalonLeftFront->GetEncPosition();
	SmartDashboard::PutNumber(LIFT_ENCODER_VALUE, LIFT_ENCODER_TICKS);
}

// Make this return true when this Command no longer needs to run execute()
bool LiftXTicks::IsFinished() {

	/* ticks indicates where to end the lift, so lifting is finished when the current location
	 ** is within +/- deadbandlift/2 of ticks.  The MAX Lift and MIN lift is a soft limit.  Lift up to
	 ** within deadbandlift of MAXLIFTICKS, or lift down to within deadbandlift of 0, the bottom
	 ** or TIMED OUT
	 */
	if (LIFT_ENCODER_TICKS >= ticks - (deadbandlift / 2)
			&& LIFT_ENCODER_TICKS <= ticks + (deadbandlift / 2))
		;
	return true;

	if (speed > 0 && LIFT_ENCODER_TICKS >= MAXLIFTTICKS - deadbandlift)
		return true;

	if (speed < 0 && LIFT_ENCODER_TICKS <= 0 + deadbandlift)
		return true;

	if (this->IsTimedOut())
		return true;

	return false;
}

// Called once after isFinished returns true
void LiftXTicks::End() {
<<<<<<< HEAD
	Robot::lift-> speedController->Set(0);
	Robot::brake-> BrakeOn(); // turns break on
=======
	Robot::lift->speedController->Set(0); //originally a lift2 command
	Robot::lift->BrakeOn(); // turns break on
>>>>>>> origin/develop
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void LiftXTicks::Interrupted() {
<<<<<<< HEAD
	Robot::lift-> speedController->Set(0);
	Robot::brake-> BrakeOn();
=======
	Robot::lift->speedController->Set(0);  //this was originally a lift2 command
	Robot::lift->BrakeOn();
>>>>>>> origin/develop
}
