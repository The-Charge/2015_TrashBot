// RobotBuilder Version: 1.5
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.




#include "WinchSystem.h"
#include "../RobotMap.h"
// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES
// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES

WinchSystem::WinchSystem() : Subsystem("WinchSystem") {
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	winchMotor = RobotMap::winchSystemWinchMotor;

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS

	int Winch_Position = 0;

}
    
void WinchSystem::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND
}

void WinchSystem::WinchIn(){

	winchMotor->Set(SmartDashboard::GetNumber(WINCH_IN_SPEED_STRING, WINCH_IN_SPEED_DEFAULT)); // when winch needs to get to a lower point
}

void WinchSystem::WinchOut(){

	winchMotor->Set(SmartDashboard::GetNumber(WINCH_OUT_SPEED_STRING, WINCH_OUT_SPEED_DEFAULT)); // when winch needs to get to a higher point
}

void WinchSystem::PutDashboardValues(){
	 // Puts the smartdashboard defaults on the smartdashboard
	SmartDashboard::PutNumber(WINCH_IN_SPEED_STRING, WINCH_IN_SPEED_DEFAULT);

	SmartDashboard::PutNumber(WINCH_OUT_SPEED_STRING, WINCH_OUT_SPEED_DEFAULT);

	SmartDashboard::PutNumber(WINCH_SETPOINT_STRING, WINCH_SETPOINT_DEFAULT);
}

// Put methods for controlling this subsystem
// here. Call these from Commands.

