// RobotBuilder Version: 1.5
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.

/**
 * LiftUpSlow (actual motor movement) happens in the Lift Subsystem
 */

#include "LiftUpSlow.h"

LiftUpSlow::LiftUpSlow() {
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
	Requires(Robot::lift2);

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES

	SmartDashboard::PutNumber(LIFT_ENCODER_MAX_STRING, LIFT_ENCODER_MAX); // to set a maximum on the robot

	SmartDashboard::PutNumber(DEADBAND_STRING, DEADBAND_VALUE); // for the maximum lift offset
}

// Called just before this Command runs the first time
void LiftUpSlow::Initialize() {
	Robot::brake->BrakeOff();

	deadband  = SmartDashboard::GetNumber(DEADBAND_STRING, DEADBAND_VALUE);

	maxHeight = SmartDashboard::GetNumber(LIFT_ENCODER_MAX_STRING, LIFT_ENCODER_MAX); // gets value from smartdashboard

}

// Called repeatedly when this Command is scheduled to run
void LiftUpSlow::Execute() {

	SmartDashboard::PutNumber("Lift Encoder value: ", Robot::driveTrain->CANTalonLeftFront ->GetEncPosition()); // gets encoder value

}

// Make this return true when this Command no longer needs to run execute()
bool LiftUpSlow::IsFinished() {
	encoderLiftvalue = Robot::driveTrain->CANTalonLeftFront ->GetEncPosition(); // gets encoder value
	if ((encoderLiftvalue >= (maxHeight - deadband)))// if encoder value is in the offset range it stops the command
		return true;

	return false;
}

// Called once after isFinished returns true
void LiftUpSlow::End() {
	Robot::lift2->CANTalon1->Set(0);
	Robot::brake-> BrakeOn();
	
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void LiftUpSlow::Interrupted() {
	Robot::lift2->CANTalon1->Set(0);
		Robot::brake-> BrakeOn();
}
