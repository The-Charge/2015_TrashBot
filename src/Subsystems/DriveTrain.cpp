// RobotBuilder Version: 1.5
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.

#include "DriveTrain.h"
#include "../Util/PIDCanTalon.h"
#include "../RobotMap.h"
// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES
#include "../Commands/Drive.h"

// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES

DriveTrain::DriveTrain() :
		Subsystem("DriveTrain") {

	CANTalonLeftFront = RobotMap::driveTrainCANTalonLeftFront;
	CANTalonLeftRear = RobotMap::driveTrainCANTalonLeftRear;
	CANTalonRightFront = RobotMap::driveTrainCANTalonRightFront;
	CANTalonRightRear = RobotMap::driveTrainCANTalonRightRear;
	robotDrive = RobotMap::driveTrainRobotDrive;
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	driveGyro = RobotMap::driveTrainDriveGyro;

	// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS

	//Need to reverse encoder direction for the right hand motors:
	CANTalonRightFront->SetSensorDirection(true);
	CANTalonRightRear->SetSensorDirection(true);
	CANTalonLeftFront->SetSensorDirection(false);
	CANTalonLeftRear->SetSensorDirection(false);

	CANTalonLeftFront->ConfigNeutralMode(CANTalon::kNeutralMode_Brake);
	CANTalonRightFront->ConfigNeutralMode(CANTalon::kNeutralMode_Brake);
	CANTalonLeftRear->ConfigNeutralMode(CANTalon::kNeutralMode_Brake);
	CANTalonRightRear->ConfigNeutralMode(CANTalon::kNeutralMode_Brake);

	leftFrontPIDCanTalon = new PIDCanTalon(CANTalonLeftFront);
	leftFrontPIDController = new PIDController(0, 0, 0, leftFrontPIDCanTalon,
			CANTalonLeftFront);

	rightFrontPIDCanTalon = new PIDCanTalon(CANTalonRightFront);
	rightFrontPIDController = new PIDController(0, 0, 0, rightFrontPIDCanTalon,
			CANTalonRightFront);

	leftRearPIDCanTalon = new PIDCanTalon(CANTalonLeftRear);
	leftRearPIDController = new PIDController(0, 0, 0, leftRearPIDCanTalon,
			CANTalonLeftRear);

	rightRearPIDCanTalon = new PIDCanTalon(CANTalonRightRear);
	rightRearPIDController = new PIDController(0, 0, 0, rightRearPIDCanTalon,
			CANTalonRightRear);

	//*******************************************************
//	robotStrafePIDOutput = new RobotStrafePIDOutput();
//	encoderAveragePIDSource = new EncoderAveragePIDSource();

//	strafePIDController = new PIDController(0, 0, 0, robotStra);

	SmartDashboard::PutNumber(ABSOLUTE_TOLERANCE_DASHBOARD_KEY,
			ABSOLUTE_TOLERANCE_DEFAULT);
	SmartDashboard::PutNumber(INTEGRAL_CONSTANT_DAHSBOARD_KEY,
			INTEGRAL_CONSTANT_DEFAULT);
	SmartDashboard::PutNumber(MAX_PERCENT_DASHBOARD_KEY, MAX_PERCENT_DEFAULT);
	SmartDashboard::PutNumber(PROPORTIONAL_CONSTANT_DASHBOARD_KEY,
			PROPORTIONAL_CONSTANT_DEFAULT);
	SmartDashboard::PutNumber(DISTANCE_TO_TRAVEL_IN_FEET_DASHBOARD_KEY,
			FEET_DEFAULT);
	SmartDashboard::PutNumber(STRAFE_SDB_FEET_DASHBOARD_KEY,
			STRAFE_SBD_FEET_DEFAULT);

}
void DriveTrain::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND
	SetDefaultCommand(new Drive());

	// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND
}

// Put methods for controlling this subsystem

void DriveTrain::drive(float x, float y, float z) {
	robotDrive->MecanumDrive_Cartesian(x, y, z);
}

void DriveTrain::EncoderReset() {
	CANTalonLeftFront->SetPosition(0);
	CANTalonLeftRear->SetPosition(0);
	CANTalonRightFront->SetPosition(0);
	CANTalonRightRear->SetPosition(0);
}
void DriveTrain::UpdateDashboard() {

	SmartDashboard::PutNumber(CLOSED_LOOP_ERROR_LEFT_FRONT_DASHBOARD_KEY,
			leftFrontPIDController->GetError());
	SmartDashboard::PutNumber(ENCODER_POSITION_LEFT_FRONT_DASHBOARD_KEY,
			CANTalonLeftFront->GetEncPosition());
	SmartDashboard::PutNumber(ENCODER_VELOCITY_LEFT_FRONT_DASHBOARD_KEY,
			CANTalonLeftFront->GetEncVel());

	SmartDashboard::PutNumber(CLOSED_LOOP_ERROR_LEFT_REAR_DASHBOARD_KEY,
			leftRearPIDController->GetError());
	SmartDashboard::PutNumber(ENCODER_POSITION_LEFT_REAR_DASHBOARD_KEY,
			CANTalonLeftRear->GetEncPosition());
	SmartDashboard::PutNumber(ENCODER_VELOCITY_LEFT_REAR_DASHBOARD_KEY,
			CANTalonLeftFront->GetEncVel());

	SmartDashboard::PutNumber(CLOSED_LOOP_ERROR_RIGHT_REAR_DASHBOARD_KEY,
			rightRearPIDController->GetError());
	SmartDashboard::PutNumber(ENCODER_POSITION_RIGHT_REAR_DASHBOARD_KEY,
			CANTalonRightRear->GetEncPosition());
	SmartDashboard::PutNumber(ENCODER_VELOCITY_RIGHT_REAR_DASHBOARD_KEY,
			CANTalonRightRear->GetEncVel());

	SmartDashboard::PutNumber(CLOSED_LOOP_ERROR_RIGHT_FRONT_DASHBOARD_KEY,
			rightFrontPIDController->GetError());
	SmartDashboard::PutNumber(ENCODER_POSITION_RIGHT_FRONT_DASHBOARD_KEY,
			CANTalonRightFront->GetEncPosition());
	SmartDashboard::PutNumber(ENCODER_VELOCITY_RIGHT_FRONT_DASHBOARD_KEY,
			CANTalonRightFront->GetEncVel());
	SmartDashboard::PutNumber(TICKS_NEEDED_DASHBOARD_KEY, TICKS_NEEDED);
	SmartDashboard::PutNumber(STRAFE_X_FEET_TICKS_PER_ONE_FOOT_KEY,
			TICKS_PER_1_FOOT_STRAFE_DEFAULT);
	SmartDashboard::PutNumber(TICKS_PER_ONE_FOOT_DASHBOARD_KEY,
			TICKS_PER_ONE_FOOT_DEFAULT);

}

float DriveTrain::GetGyroRate() {
	return driveGyro->GetRate();
}

float DriveTrain::GetGyroAngle() {
	return driveGyro->GetAngle();
}

void DriveTrain::DriveSDBFeet() {

	feet = SmartDashboard::GetNumber(DISTANCE_TO_TRAVEL_IN_FEET_DASHBOARD_KEY,
			FEET_DEFAULT);
	SetDistanceInFeet(feet);
}

void DriveTrain::SetPIDControllerOutputRange(float maxpercent) {
	leftFrontPIDController->SetOutputRange(-1 * maxpercent, maxpercent);
	rightFrontPIDController->SetOutputRange(-1 * maxpercent, maxpercent);
	leftRearPIDController->SetOutputRange(-1 * maxpercent, maxpercent);
	rightRearPIDController->SetOutputRange(-1 * maxpercent, maxpercent);

}

void DriveTrain::ReadDashboardValues() {

	maxpercent = SmartDashboard::GetNumber(MAX_PERCENT_DASHBOARD_KEY,
			MAX_PERCENT_DEFAULT);
	absolutetolerance = SmartDashboard::GetNumber(
			ABSOLUTE_TOLERANCE_DASHBOARD_KEY, ABSOLUTE_TOLERANCE_DEFAULT);
	p = SmartDashboard::GetNumber(PROPORTIONAL_CONSTANT_DASHBOARD_KEY,
			PROPORTIONAL_CONSTANT_DEFAULT);
	i = SmartDashboard::GetNumber(INTEGRAL_CONSTANT_DAHSBOARD_KEY,
			INTEGRAL_CONSTANT_DEFAULT);
	leftFrontPIDController->SetPID(p, i, 0);

	leftFrontPIDController->SetOutputRange(-1 * maxpercent, maxpercent);
	rightFrontPIDController->SetOutputRange(-1 * maxpercent, maxpercent);
	leftRearPIDController->SetOutputRange(-1 * maxpercent, maxpercent);
	rightRearPIDController->SetOutputRange(-1 * maxpercent, maxpercent);

	leftFrontPIDController->SetAbsoluteTolerance(absolutetolerance);
	rightFrontPIDController->SetAbsoluteTolerance(absolutetolerance);
	leftRearPIDController->SetAbsoluteTolerance(absolutetolerance);
	rightRearPIDController->SetAbsoluteTolerance(absolutetolerance);

	rightFrontPIDController->SetPID(p, i, 0);
	leftRearPIDController->SetPID(p, i, 0);
	rightRearPIDController->SetPID(p, i, 0);

	ticksPerOneFootStrafe = SmartDashboard::GetNumber(
			STRAFE_X_FEET_TICKS_PER_ONE_FOOT_KEY,
			TICKS_PER_1_FOOT_STRAFE_DEFAULT);
	ticksPerOneFoot = SmartDashboard::GetNumber(
			TICKS_PER_ONE_FOOT_DASHBOARD_KEY, TICKS_PER_ONE_FOOT_DEFAULT);
}

void DriveTrain::PutEncoderValuesToDashboard() {

	SmartDashboard::PutNumber(CLOSED_LOOP_ERROR_LEFT_FRONT_DASHBOARD_KEY,
			leftFrontPIDController->GetError());
	SmartDashboard::PutNumber(ENCODER_POSITION_LEFT_FRONT_DASHBOARD_KEY,
			CANTalonLeftFront->GetEncPosition());
	SmartDashboard::PutNumber(ENCODER_VELOCITY_LEFT_FRONT_DASHBOARD_KEY,
			CANTalonLeftFront->GetEncVel());

	SmartDashboard::PutNumber(CLOSED_LOOP_ERROR_LEFT_REAR_DASHBOARD_KEY,
			leftRearPIDController->GetError());
	SmartDashboard::PutNumber(ENCODER_POSITION_LEFT_REAR_DASHBOARD_KEY,
			CANTalonLeftRear->GetEncPosition());
	SmartDashboard::PutNumber(ENCODER_VELOCITY_LEFT_REAR_DASHBOARD_KEY,
			CANTalonLeftRear->GetEncVel());

	SmartDashboard::PutNumber(CLOSED_LOOP_ERROR_RIGHT_REAR_DASHBOARD_KEY,
			rightRearPIDController->GetError());
	SmartDashboard::PutNumber(ENCODER_POSITION_RIGHT_REAR_DASHBOARD_KEY,
			CANTalonRightRear->GetEncPosition());
	SmartDashboard::PutNumber(ENCODER_VELOCITY_RIGHT_REAR_DASHBOARD_KEY,
			CANTalonRightRear->GetEncVel());
}

void DriveTrain::ResetDistance() {
	CANTalonLeftFront->SetPosition(0);
	CANTalonLeftRear->SetPosition(0);
	CANTalonRightFront->SetPosition(0);
	CANTalonRightRear->SetPosition(0);
}

void DriveTrain::SetDistanceInFeet(float dist) {
	ReadDashboardValues();
	TICKS_NEEDED = ticksPerOneFoot * dist;

	leftRearPIDController->SetSetpoint(TICKS_NEEDED);
	rightRearPIDController->SetSetpoint(-1 * TICKS_NEEDED);
	leftFrontPIDController->SetSetpoint(TICKS_NEEDED);
	rightFrontPIDController->SetSetpoint(-1 * TICKS_NEEDED);

	DriveTrain::EncoderReset();

	leftFrontPIDController->Enable();
	rightFrontPIDController->Enable();
	rightRearPIDController->Enable();
	leftRearPIDController->Enable();
}

bool DriveTrain::AtDestination() {
	// return frontLeftPIDController->OnTarget();
	//rightFrontPIDController -> OnTarget() &&
	return (leftFrontPIDController->OnTarget());
	//	&& rightRearPIDController-> OnTarget()
	//&& leftRearPIDController -> OnTarget());
}

void DriveTrain::DisablePIDControllers() {
	leftFrontPIDController->Disable();
	rightFrontPIDController->Disable();
	leftRearPIDController->Disable();
	rightRearPIDController->Disable();
}

void DriveTrain::StrafeSDBFeet() {
	float x = SmartDashboard::GetNumber(STRAFE_SDB_FEET_DASHBOARD_KEY,
			STRAFE_SBD_FEET_DEFAULT);
	StrafeXFt(x);
}

void DriveTrain::StrafeXFt(float f) {
	ReadDashboardValues();
	TICKS_NEEDED = ticksPerOneFootStrafe * f;
	EncoderReset();

//	strafePIDOutput =

	leftRearPIDController->SetSetpoint(-1 * TICKS_NEEDED);
	rightRearPIDController->SetSetpoint(-1 * TICKS_NEEDED);
	leftFrontPIDController->SetSetpoint(TICKS_NEEDED);
	rightFrontPIDController->SetSetpoint(TICKS_NEEDED);

	leftFrontPIDController->Enable();
	rightFrontPIDController->Enable();
	rightRearPIDController->Enable();
	leftRearPIDController->Enable();

}

void DriveTrain::Stop() {
	Robot::driveTrain->DisablePIDControllers();
	Robot::driveTrain->drive(0, 0, 0);
}
// here. Call these from Commands.

