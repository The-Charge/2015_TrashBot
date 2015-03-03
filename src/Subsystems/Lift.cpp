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
#include "../Commands/LiftXTicks.h"
#include "../Commands/LiftSDBTicks.h"
#include "../OI.h"

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES
// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES

const float Lift::SPEED_UP = .7;
const float Lift::SPEED_DOWN = .4;
const float Lift::TOTE_ONE_ENGAGE_TICKS = 0;
const float Lift:: TOTE_TWO_ENGAGE_TICKS = 3015;
const float Lift::TOTE_THREE_ENGAGE_TICKS = TOTE_TWO_ENGAGE_TICKS + TOTE_TWO_ENGAGE_TICKS;
const float Lift::GO_OVER_BIN_TICKS = 14205;

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
		Stop();
	} else {
		BrakeOff();
		speedController->Set(ReadFastPotentiometer() * 1);
	}
}
void Lift::LiftDownFast() {
	UpdateSmartDashboard();
	if (CurrentLiftPosition() <= LOWER_SAFETY_LIMIT_FAST) {
		Stop();
	} else {
		BrakeOff();
		speedController->Set(ReadFastPotentiometer() * -1);
	}
}
void Lift::LiftUpSlow() {
	UpdateSmartDashboard();
	if (CurrentLiftPosition() >= UPPER_SAFETY_LIMIT) {
		Stop();
	} else {
		BrakeOff();
		speedController->Set(ReadSlowPotentiometer() * 1);
	}
}
void Lift::LiftDownSlow() {
	UpdateSmartDashboard();
	if (CurrentLiftPosition() <= (LOWER_SAFETY_LIMIT_SLOW)) {
		Stop();
	} else {
		BrakeOff();
		speedController->Set(ReadSlowPotentiometer() * -1);
	}
}
// Put methods for controlling this subsystem
// here. Call these from Commands.

float Lift::ReadFastPotentiometer()
{
	int x = Robot::oi->getButtonBox()->GetX();

	return .15*x + .85;
}

float Lift::ReadSlowPotentiometer()
{
	int y = Robot::oi->getButtonBox()->GetY();

	if(y < 0)
		return .1*y + .4;
	else
		return .3*y + .4;
}

int Lift::CurrentLiftPosition() {
	return Robot::lift->encoder->Get();

}

void Lift::Stop() {
	BrakeOn();
	speedController->Set(0);
}

void Lift::SetSDBLift() {
	ticks = SmartDashboard::GetNumber(LIFT_TICKS_DASHBOARD_KEY,
			TICKS_LIFT_DEFAULT);
	speed = SmartDashboard::GetNumber(LIFT_SPEED_DASHBOARD_KEY,
			SPEED_LIFT_DEFAULT);
	SetLift(ticks, speed);
}

void Lift::SetLift(int ticks, float speed) {

	LIFTSETPOINT = ticks;
	float sp = fabs(speed);
	if (AtDestination()) {
		Stop();
	} else {
		BrakeOff();
		if (CurrentLiftPosition() < LIFTSETPOINT)
			speedController->Set(sp);
		else
			speedController->Set(-sp);
	}
}

bool Lift::AtDestination() {
	int error = LIFTSETPOINT - CurrentLiftPosition();
	if (abs(error) < GetDeadband())
	{
		//We are at are destination
		return true;
	}
	else if(error > 0 && (CurrentLiftPosition() >= UPPER_SAFETY_LIMIT))
	{
		//We were going up and hit the upper safety limit
		return true;
	}
	else if (error < 0 && (CurrentLiftPosition() <= LOWER_SAFETY_LIMIT_SLOW))
	{
		//We were going down and hit the lower safety limit
		return true;
	}
	else
	{
		//We are going somewhere, we haven't reached it yet, and we haven't hit a safety limit
		return false;
	}
}

float Lift::GetDeadband() {
	return SmartDashboard::GetNumber(LIFT_DEADBAND_STRING,
			LIFT_DEADBAND_DEFAULT);
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

void Lift::UpdateSmartDashboard() {
//#ifdef VERBOSE_DASHBOARD
	SmartDashboard::PutNumber(LIFT_ENCODER_VALUE_DASHBOARD_KEY,
			CurrentLiftPosition());
//#endif
}

void Lift::PutDashboardValues() {
//#ifdef VERBOSE_DASHBOARD
	SmartDashboard::PutNumber(LIFT_SPEED_UP_FAST_KEY,
			LIFT_SPEED_UP_FAST_DEFAULT);

	SmartDashboard::PutNumber(LIFT_SPEED_DOWN_FAST_KEY,
			LIFT_SPEED_DOWN_FAST_DEFAULT);

	SmartDashboard::PutNumber(LIFT_SPEED_UP_SLOW_KEY,
			LIFT_SPEED_UP_SLOW_DEFAULT);

	SmartDashboard::PutNumber(LIFT_SPEED_DOWN_SLOW_KEY,
			LIFT_SPEED_DOWN_SLOW_DEFAULT);

	SmartDashboard::PutNumber(LIFT_DEADBAND_STRING, LIFT_DEADBAND_DEFAULT);

	SmartDashboard::PutNumber(LIFT_TICKS_STRING, TICKS_LIFT_DEFAULT);
	SmartDashboard::PutNumber(LIFT_SPEED_STRING, SPEED_LIFT_DEFAULT);

	SmartDashboard::PutNumber(MAX_VALUE_TICKS, MAX_LIFT_TICKS);
//#endif
}
