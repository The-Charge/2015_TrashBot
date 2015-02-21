// RobotBuilder Version: 1.5
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.

#include "Lift.h"
#include "../RobotMap.h"
#include "../Commands/LiftUpSlow.h"
#include "../Commands/LiftUpFast.h"
#include "../Commands/LiftDownSlow.h"
#include "../Commands/LiftDownFast.h"

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES
// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES

Lift::Lift() :
		Subsystem("Lift") {
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	solenoid1 = RobotMap::liftSolenoid1;
	speedController = RobotMap::liftSpeedController;
	encoder = RobotMap::liftEncoder;

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS

	PutDashboardValues();
}

void Lift::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND
}
void Lift::LiftUpFast() {
	UpdateSmartDashboard();
	if (CurrentLiftPosition() >= UPPER_SAFETY_LIMIT) {
		speedController->Set(0);
		BrakeOn();
	} else {
		speedController->Set(
				SmartDashboard::GetNumber(LIFT_SPEED_UP_FAST_KEY,
						LIFT_SPEED_UP_FAST_DEFAULT));
		BrakeOff();
	}
}
void Lift::LiftDownFast() {
	UpdateSmartDashboard();
	if (CurrentLiftPosition() <= LOWER_SAFETY_LIMIT) {
		speedController->Set(0);
		BrakeOn();
	} else {
		speedController->Set(
				SmartDashboard::GetNumber(LIFT_SPEED_DOWN_FAST_KEY,
						LIFT_SPEED_DOWN_FAST_DEFAULT));
		BrakeOff();
	}
}
void Lift::LiftUpSlow() {
	UpdateSmartDashboard();
	if (CurrentLiftPosition() >= UPPER_SAFETY_LIMIT) {
		speedController->Set(0);
		BrakeOn();
	} else {
		speedController->Set(
				SmartDashboard::GetNumber(LIFT_SPEED_UP_SLOW_KEY,
						LIFT_SPEED_UP_SLOW_DEFAULT));
		BrakeOff();
	}
}
void Lift::LiftDownSlow() {
	UpdateSmartDashboard();
	if (CurrentLiftPosition() <= (LOWER_SAFETY_LIMIT)) {
		speedController->Set(0);
		BrakeOn();
	} else {
		speedController->Set(
				SmartDashboard::GetNumber(LIFT_SPEED_DOWN_SLOW_KEY,
						LIFT_SPEED_DOWN_SLOW_DEFAULT));
		BrakeOff();
	}
}
// Put methods for controlling this subsystem
// here. Call these from Commands.

void Lift::UpdateSmartDashboard() {
	SmartDashboard::PutNumber(LIFT_ENCODER_VALUE_DASHBOARD_KEY, encoder->Get());
}

//----------------------Smart Dashboard-----------------------------------------
void Lift::PutDashboardValues() {
	SmartDashboard::PutNumber(LIFT_SPEED_UP_FAST_KEY,
			LIFT_SPEED_UP_FAST_DEFAULT);
	//This is putting an input box for changing the speed of the LiftUpFast method on the SD
	//  (string name displayed next to box, default value in box)

	SmartDashboard::PutNumber(LIFT_SPEED_DOWN_FAST_KEY,
			LIFT_SPEED_DOWN_FAST_DEFAULT);

	SmartDashboard::PutNumber(LIFT_SPEED_UP_SLOW_KEY,
			LIFT_SPEED_UP_SLOW_DEFAULT);

	SmartDashboard::PutNumber(LIFT_SPEED_DOWN_SLOW_KEY,
			LIFT_SPEED_DOWN_SLOW_DEFAULT);


	SmartDashboard::PutNumber(MAX_VALUE_TICKS, MAXLIFTTICKS);

	SmartDashboard::PutNumber(LIFT_DEADBAND_STRING, LIFT_DEADBAND_DEFAULT);

	LIFT_ENCODER_TICKS = Robot::driveTrain->CANTalonLeftFront->GetEncPosition();
	SmartDashboard::PutNumber(LIFT_ENCODER_VALUE, LIFT_ENCODER_TICKS);

	SmartDashboard::PutNumber(LIFT_TICKS_STRING, TICKS_LIFT_DEFAULT);
	SmartDashboard::PutNumber(LIFT_SPEED_STRING, SPEED_LIFT_DEFAULT);
}

bool Lift::KeepLifting(float ticks, float speed)
{
	if (CurrentLiftPosition() >= ticks - (GetDeadband() / 2) && CurrentLiftPosition() <= ticks + (GetDeadband()/ 2))
		{ return true; }
		else if (speed > 0 && CurrentLiftPosition() >= MAXLIFTTICKS - GetDeadband())
		{return true;}
		else if (speed < 0 && CurrentLiftPosition() <= LOWER_SAFETY_LIMIT)
			{ return true; }
		else return false;
}

float Lift::GetDeadband()
{
	return SmartDashboard::GetNumber(LIFT_DEADBAND_STRING,LIFT_DEADBAND_DEFAULT);
}

int Lift::CurrentLiftPosition() {
	return Robot::lift->encoder->Get();
}

void Lift::BrakeOn() {
	solenoid1->Set(DoubleSolenoid::kForward);
}

void Lift::BrakeOff() {
	solenoid1->Set(DoubleSolenoid::kReverse);
}

void Lift::BrakePowerOff() {
	solenoid1->Set(DoubleSolenoid::kOff);
}

