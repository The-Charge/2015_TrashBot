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

Lift::Lift() : Subsystem("Lift") {
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
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
void Lift::LiftUpFast()
{
	speedController->Set(SmartDashboard::GetNumber(LIFT_SPEED_UP_FAST_KEY, LIFT_SPEED_UP_FAST_DEFAULT));

	if(encoderLiftvalue >= (maxHeight - deadband))
	{
		Robot::lift->speedController->Set(0);
		Robot::brake-> BrakeOn();
	}
	else
	{
		Robot::lift->speedController->Set(SmartDashboard::GetNumber(LIFT_SPEED_UP_SLOW_KEY, LIFT_SPEED_UP_SLOW_DEFAULT));
		Robot::brake-> BrakeOff();
	}
}
void Lift::LiftDownFast()
{
	speedController->Set(SmartDashboard::GetNumber(LIFT_SPEED_DOWN_FAST_KEY, LIFT_SPEED_DOWN_FAST_DEFAULT));

	if(encoderLiftvalue >= (minHeight + deadband))
	{
		Robot::lift->speedController->Set(0);
		Robot::brake-> BrakeOn();
	}
	else
	{
		Robot::lift->speedController->Set(SmartDashboard::GetNumber(LIFT_SPEED_UP_SLOW_KEY, LIFT_SPEED_UP_SLOW_DEFAULT));
		Robot::brake-> BrakeOff();
	}
}
void Lift::LiftUpSlow()
{
	speedController->Set(SmartDashboard::GetNumber(LIFT_SPEED_UP_SLOW_KEY, LIFT_SPEED_UP_SLOW_DEFAULT));

	if(encoderLiftvalue >= (maxHeight - deadband))
	{
		Robot::lift->speedController->Set(0);
		Robot::brake-> BrakeOn();
	}
	else
	{
		Robot::lift->speedController->Set(SmartDashboard::GetNumber(LIFT_SPEED_UP_SLOW_KEY, LIFT_SPEED_UP_SLOW_DEFAULT));
		Robot::brake-> BrakeOff();
	}
}
void Lift::LiftDownSlow()
{
	speedController->Set(SmartDashboard::GetNumber(LIFT_SPEED_DOWN_SLOW_KEY, LIFT_SPEED_DOWN_SLOW_DEFAULT));

	if(encoderLiftvalue >= (maxHeight - deadband))
	{
		Robot::lift->speedController->Set(0);
		Robot::brake-> BrakeOn();
	}
	else
	{
		Robot::lift->speedController->Set(SmartDashboard::GetNumber(LIFT_SPEED_UP_SLOW_KEY, LIFT_SPEED_UP_SLOW_DEFAULT));
		Robot::brake-> BrakeOff();
	}
}
// Put methods for controlling this subsystem
// here. Call these from Commands.

//----------------------Smart Dashboard-----------------------------------------
void Lift::PutDashboardValues()
{
	SmartDashboard::PutNumber(LIFT_SPEED_UP_FAST_KEY, LIFT_SPEED_UP_FAST_DEFAULT);
	//This is putting an input box for changing the speed of the LiftUpFast method on the SD
	//  (string name displayed next to box, default value in box)

	SmartDashboard::PutNumber(LIFT_SPEED_DOWN_FAST_KEY, LIFT_SPEED_DOWN_FAST_DEFAULT);

	SmartDashboard::PutNumber(LIFT_SPEED_UP_SLOW_KEY, LIFT_SPEED_UP_SLOW_DEFAULT);

	SmartDashboard::PutNumber(LIFT_SPEED_DOWN_SLOW_KEY, LIFT_SPEED_DOWN_SLOW_DEFAULT);
}/*

//Replaced in each specific method to allow button interaction

void Lift::ReadDashboardValues()
{
	//store values
	liftSpeedUpFast = SmartDashboard::GetNumber(LIFT_SPEED_UP_FAST_KEY, LIFT_SPEED_UP_FAST_DEFAULT);

	liftSpeedDownFast = SmartDashboard::GetNumber(LIFT_SPEED_DOWN_FAST_KEY, LIFT_SPEED_DOWN_FAST_DEFAULT);

	liftSpeedUpSlow = SmartDashboard::GetNumber(LIFT_SPEED_UP_SLOW_KEY, LIFT_SPEED_UP_SLOW_DEFAULT);

	liftSpeedDownSlow = SmartDashboard::GetNumber(LIFT_SPEED_DOWN_SLOW_KEY, LIFT_SPEED_DOWN_SLOW_DEFAULT);

	//send to methods
	LiftUpFast(liftSpeedUpFast);
	LiftDownFast(liftSpeedDownFast);
	LiftUpSlow(liftSpeedUpSlow);
	LiftDownSlow(liftSpeedDownSlow);
}
*/
