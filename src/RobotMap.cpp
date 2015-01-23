// RobotBuilder Version: 1.5
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#include "RobotMap.h"
#include "LiveWindow/LiveWindow.h"


// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=ALLOCATION
CANTalon* RobotMap::driveTrainCANTalonLeftFront = NULL;
CANTalon* RobotMap::driveTrainCANTalonLeftRear = NULL;
CANTalon* RobotMap::driveTrainCANTalonRightFront = NULL;
CANTalon* RobotMap::driveTrainCANTalonRightRear = NULL;
RobotDrive* RobotMap::driveTrainRobotDrive = NULL;

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=ALLOCATION

void RobotMap::init() {
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
	LiveWindow* lw = LiveWindow::GetInstance();

	driveTrainCANTalonLeftFront = new CANTalon(8);
	
	
	driveTrainCANTalonLeftRear = new CANTalon(9);
	
	
	driveTrainCANTalonRightFront = new CANTalon(10);
	
	
	driveTrainCANTalonRightRear = new CANTalon(7);
	
	
	driveTrainRobotDrive = new RobotDrive(driveTrainCANTalonLeftFront, driveTrainCANTalonLeftRear,
              driveTrainCANTalonRightFront, driveTrainCANTalonRightRear);
	
	driveTrainRobotDrive->SetSafetyEnabled(false);
        driveTrainRobotDrive->SetExpiration(0.1);
        driveTrainRobotDrive->SetSensitivity(0.5);
        driveTrainRobotDrive->SetMaxOutput(1.0);

        driveTrainRobotDrive->SetInvertedMotor(RobotDrive::kFrontRightMotor, true);
        driveTrainRobotDrive->SetInvertedMotor(RobotDrive::kRearRightMotor, true);


    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
}
