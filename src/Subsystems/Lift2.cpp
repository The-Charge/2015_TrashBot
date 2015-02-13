// RobotBuilder Version: 1.5
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.




#include "Lift2.h"
#include "../RobotMap.h"
#include <CANTalon.h>
// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES
// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES

Lift2::Lift2() : Subsystem("Lift2") {
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	cANJaguar1 = RobotMap::lift2CANJaguar1;
	testEncoder = RobotMap::lift2TestEncoder;

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	CANTalon1 -> SetSensorDirection(true);
	CANTalon1->ConfigNeutralMode(CANTalon::kNeutralMode_Brake);
}
    
void Lift2::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND
}
void Lift2::LiftUpFast()
{
	//speedController->Set(1);
}
void Lift2::LiftDownFast()
{
	//speedController->Set(-1);
}
void Lift2::LiftUpSlow()
{
	CANTalon1-> Set(.2);
}
void Lift2::LiftDownSlow()
{
	CANTalon1->Set(-.2);
}

// Put methods for controlling this subsystem
// here. Call these from Commands.

