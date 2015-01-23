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
Gyro* RobotMap::driveTrainDriveGyro = NULL;

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=ALLOCATION

void RobotMap::init() {
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
	LiveWindow* lw = LiveWindow::GetInstance();

	driveTrainCANTalonLeftFront = new CANTalon(2);
	// trashbot id number 8
	// Plybot id number 11
	driveTrainCANTalonLeftRear = new CANTalon(3);
	// trashbot id number 9
	// Plybot id number 2
	driveTrainCANTalonRightFront = new CANTalon(4);
	// trashbot id number 10
	// Plybot id number 3
	driveTrainCANTalonRightRear = new CANTalon(5);
	// trashbot id number 7
	// Plybot id number 5
	driveTrainRobotDrive = new RobotDrive(driveTrainCANTalonLeftFront, driveTrainCANTalonLeftRear,
              driveTrainCANTalonRightFront, driveTrainCANTalonRightRear);
	
	driveTrainRobotDrive->SetSafetyEnabled(true);
        driveTrainRobotDrive->SetExpiration(0.1);
        driveTrainRobotDrive->SetSensitivity(0.5);
        driveTrainRobotDrive->SetMaxOutput(1.0);

        driveTrainRobotDrive->SetInvertedMotor(RobotDrive::kFrontRightMotor, true);
        driveTrainRobotDrive->SetInvertedMotor(RobotDrive::kRearRightMotor, true);
	driveTrainDriveGyro = new Gyro(0);
	lw->AddSensor("DriveTrain", "DriveGyro", driveTrainDriveGyro);
	driveTrainDriveGyro->SetSensitivity(0.007);


    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
}
