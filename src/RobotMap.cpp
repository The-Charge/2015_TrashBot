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
CANJaguar* RobotMap::driveTrainCANJaguarLeftFront = NULL;
CANJaguar* RobotMap::driveTrainCANJaguarLeftRear = NULL;
CANJaguar* RobotMap::driveTrainCANJaguarRightFront = NULL;
CANJaguar* RobotMap::driveTrainCANJaguarRightRear = NULL;
RobotDrive* RobotMap::driveTrainRobotDrive = NULL;
Gyro* RobotMap::driveTrainDriveGyro = NULL;

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=ALLOCATION

void RobotMap::init() {
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
	LiveWindow* lw = LiveWindow::GetInstance();

	driveTrainCANJaguarLeftFront = new CANJaguar(2);
	
	
	driveTrainCANJaguarLeftRear = new CANJaguar(3);
	
	
	driveTrainCANJaguarRightFront = new CANJaguar(4);
	
	
	driveTrainCANJaguarRightRear = new CANJaguar(5);
	
	
	driveTrainRobotDrive = new RobotDrive(driveTrainCANJaguarLeftFront, driveTrainCANJaguarLeftRear,
              driveTrainCANJaguarRightFront, driveTrainCANJaguarRightRear);
	
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
