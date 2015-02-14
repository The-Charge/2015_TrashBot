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

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
	LIFT_ENCODER_TICKS = Robot::lift-> encoder->Get();

	SmartDashboard::PutNumber(MAX_VALUE_TICKS, MAXLIFTTICKS);

	SmartDashboard::PutNumber(LIFT_DEADBAND_STRING, LIFT_DEADBAND_DEFAULT);

	SmartDashboard::PutNumber(LIFT_ENCODER_VALUE, LIFT_ENCODER_TICKS);

	// intiliatizes speed and tick values sent in
	speed = s;
	ticks = t;
}

// Called just before this Command runs the first time
void LiftXTicks::Initialize() {
	Robot::lift->BrakeOff(); // turns brakes off of the lift
	this -> SetTimeout(2); // sets timeout for safety
	
	deadbandlift = SmartDashboard::GetNumber(LIFT_DEADBAND_STRING, LIFT_DEADBAND_DEFAULT); // sets deadband value
	Robot::lift2-> CANTalon1->Set(speed); // sets the speed wanted to drive at from auton

}

// Called repeatedly when this Command is scheduled to run
void LiftXTicks::Execute() {
	 LIFT_ENCODER_TICKS = Robot::driveTrain->CANTalonLeftFront ->GetEncPosition();
	 SmartDashboard::PutNumber(LIFT_ENCODER_VALUE, LIFT_ENCODER_TICKS);
}

// Make this return true when this Command no longer needs to run execute()
bool LiftXTicks::IsFinished() {
	if (this-> IsTimedOut())
				return true;

	if ((LIFT_ENCODER_TICKS <= ticks + (deadbandlift/2) && LIFT_ENCODER_TICKS >= ticks - (deadbandlift/2)))
		return true;

	if((LIFT_ENCODER_TICKS >= MAXLIFTTICKS - deadbandlift ))   //Need to add later code after first test    //|| LIFT_ENCODER_TICKS <= 0 + deadbandlift))
		return true;

	return false;
}

// Called once after isFinished returns true
void LiftXTicks::End() {
	Robot::lift2-> CANTalon1->Set(0);
	Robot::lift-> BrakeOn(); // turns break on
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void LiftXTicks::Interrupted() {
	Robot::lift2-> CANTalon1->Set(0);
	Robot::lift-> BrakeOn();
}
