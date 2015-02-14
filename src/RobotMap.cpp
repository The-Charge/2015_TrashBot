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

CANTalon* RobotMap::driveTrainCANTalonLeftFront = NULL;
CANTalon* RobotMap::driveTrainCANTalonLeftRear = NULL;
CANTalon* RobotMap::driveTrainCANTalonRightFront = NULL;
CANTalon* RobotMap::driveTrainCANTalonRightRear = NULL;
RobotDrive* RobotMap::driveTrainRobotDrive = NULL;
// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=ALLOCATION
Gyro* RobotMap::driveTrainDriveGyro = NULL;
DoubleSolenoid* RobotMap::brakeSolenoid1 = NULL;
Compressor* RobotMap::compressor1AirCompressor = NULL;
SpeedController* RobotMap::liftSpeedController = NULL;
Encoder* RobotMap::liftEncoder = NULL;
DoubleSolenoid* RobotMap::armsLeftArm = NULL;
DoubleSolenoid* RobotMap::armsRightArm = NULL;
SpeedController* RobotMap::winchSystemWinchMotor = NULL;

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=ALLOCATION

void RobotMap::init() {
	driveTrainCANTalonLeftFront = new CANTalon(99); // changed from 11 to 99 for testing

	driveTrainCANTalonLeftRear = new CANTalon(2);

	driveTrainCANTalonRightFront = new CANTalon(3);

	driveTrainCANTalonRightRear = new CANTalon(5);
	driveTrainRobotDrive = new RobotDrive(driveTrainCANTalonLeftFront,
			driveTrainCANTalonLeftRear, driveTrainCANTalonRightFront,
			driveTrainCANTalonRightRear);

	driveTrainRobotDrive->SetSafetyEnabled(false);
	driveTrainRobotDrive->SetExpiration(0.1);
	driveTrainRobotDrive->SetSensitivity(0.5);
	driveTrainRobotDrive->SetMaxOutput(1.0);

	driveTrainRobotDrive->SetInvertedMotor(RobotDrive::kFrontRightMotor, true);
	driveTrainRobotDrive->SetInvertedMotor(RobotDrive::kRearRightMotor, true);


	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
	LiveWindow* lw = LiveWindow::GetInstance();

	driveTrainDriveGyro = new Gyro(0);
	lw->AddSensor("DriveTrain", "DriveGyro", driveTrainDriveGyro);
	driveTrainDriveGyro->SetSensitivity(0.007);
	brakeSolenoid1 = new DoubleSolenoid(0, 0, 1);      
	lw->AddActuator("Brake", "Solenoid1", brakeSolenoid1);
	
	compressor1AirCompressor = new Compressor(1);
	
	
	liftSpeedController = new TalonSRX(0);
	lw->AddActuator("Lift", "SpeedController", (TalonSRX*) liftSpeedController);
	
	liftEncoder = new Encoder(0, 1, false, Encoder::k4X);
	lw->AddSensor("Lift", "Encoder", liftEncoder);
	liftEncoder->SetDistancePerPulse(1.0);
        liftEncoder->SetPIDSourceParameter(Encoder::kRate);
	armsLeftArm = new DoubleSolenoid(0, 2, 3);      
	lw->AddActuator("Arms", "LeftArm", armsLeftArm);
	
	armsRightArm = new DoubleSolenoid(0, 4, 5);      
	lw->AddActuator("Arms", "RightArm", armsRightArm);
	
	winchSystemWinchMotor = new Talon(1);
	lw->AddActuator("WinchSystem", "WinchMotor", (Talon*) winchSystemWinchMotor);
	


    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS

	// sets feed-back device to get values from each encoder
	driveTrainCANTalonLeftFront->SetFeedbackDevice(CANTalon::QuadEncoder);
	driveTrainCANTalonLeftRear->SetFeedbackDevice(CANTalon::QuadEncoder);
	driveTrainCANTalonRightFront->SetFeedbackDevice(CANTalon::QuadEncoder);
	driveTrainCANTalonRightRear->SetFeedbackDevice(CANTalon::QuadEncoder);

	compressor1AirCompressor->SetClosedLoopControl(true);

}
