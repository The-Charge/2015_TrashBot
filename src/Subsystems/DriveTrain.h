// RobotBuilder Version: 1.5
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.

#ifndef DRIVETRAIN_H
#define DRIVETRAIN_H
#include "Commands/Subsystem.h"
#include "WPILib.h"
#include "../Util/PIDCanTalon.h"

/**
 *
 *
 * @author ExampleAuthor
 */
class DriveTrain: public Subsystem {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
public:
	CANTalon* CANTalonLeftFront;
	CANTalon* CANTalonLeftRear;
	CANTalon* CANTalonRightFront;
	CANTalon* CANTalonRightRear;
	RobotDrive* robotDrive;
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	Gyro* driveGyro;

	// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	DriveTrain();
	void InitDefaultCommand();

	// drive command drives the mecanum and parameters: x,y z as rotation
	void drive(float, float, float);
	void EncoderReset();
	float GetGyroRate();
	float GetGyroAngle();
	void ResetDistance();
	void SetDistanceInFeet(float);
	bool AtDestination();
	void Init();
	void DisablePIDControllers();

	void ReadDashboardValues();
	void PutEncoderValuesToDashboard();
	void SetPIDControllerOutputRange(float);
	void StrafeSDBFeet();
	void StrafeXFt(float);
	void DriveFtInit();
	void UpdateDashboard();
	void DriveSDBFeet();
	void Stop();

	const float WHEELDIAMETER_IN_INCHES = 8;
	const float WHEELCIRCUMFERENCE_IN_INCHES = WHEELDIAMETER_IN_INCHES * 3.14;
	const float WHEELCIRCUMFERENCE_IN_FEET = WHEELCIRCUMFERENCE_IN_INCHES / 12;
	const float WHEELROTATIONS_PER_FOOT = 1 / WHEELCIRCUMFERENCE_IN_FEET;
	const int ENCODER_TICKS_PER_REVOLUTION = 300 * 4; //250; //2048
	int ticksPerOneFoot;
	const int TICKS_PER_ONE_FOOT_DEFAULT = WHEELROTATIONS_PER_FOOT
			* ENCODER_TICKS_PER_REVOLUTION;
	float TICKS_NEEDED = 0;

	const std::string TICKS_PER_ONE_FOOT_DASHBOARD_KEY =
			"DriveXFeet:Ticks per One Foot";

	PIDController*leftFrontPIDController;
	PIDController*rightFrontPIDController;
	PIDController*leftRearPIDController;
	PIDController*rightRearPIDController;

	PIDController * strafePIDController;

//	RobotStrafePIDOutput * robotStrafePIDOutput;
//	EncoderAveragePIDSource * encoderAveragePIDSource;

	PIDCanTalon*leftRearPIDCanTalon;
	PIDCanTalon*leftFrontPIDCanTalon;
	PIDCanTalon*rightFrontPIDCanTalon;
	PIDCanTalon*rightRearPIDCanTalon;

	const std::string CLOSED_LOOP_ERROR_RIGHT_FRONT_DASHBOARD_KEY =
			"DriveXFeet::Closed Loop Error Right Front";
	const std::string ENCODER_POSITION_RIGHT_FRONT_DASHBOARD_KEY =
			"DriveXFeet::Encoder Position Right Front";

	const std::string CLOSED_LOOP_ERROR_RIGHT_REAR_DASHBOARD_KEY =
			"DriveXFeet::Closed Loop Error Right Rear";
	const std::string ENCODER_POSITION_RIGHT_REAR_DASHBOARD_KEY =
			"DriveXFeet::Encoder Position Right Rear";

	const std::string CLOSED_LOOP_ERROR_LEFT_FRONT_DASHBOARD_KEY =
			"DriveXFeet::Closed Loop Error Left Front";
	const std::string ENCODER_POSITION_LEFT_FRONT_DASHBOARD_KEY =
			"DriveXFeet::Encoder Position Left Front";

	const std::string CLOSED_LOOP_ERROR_LEFT_REAR_DASHBOARD_KEY =
			"DriveXFeet::Closed Loop Error Left Rear";
	const std::string ENCODER_POSITION_LEFT_REAR_DASHBOARD_KEY =
			"DriveXFeet::Encoder Position Left Rear";

	const double CLOSED_LOOP_ERROR_DEFAULT = 0;
	const double ENCODER_POSITION_DEFAULT = 0;

	const double PROPORTIONAL_CONSTANT_DEFAULT = .1;
	const double MAX_PERCENT_DEFAULT = .5;
	const double INTEGRAL_CONSTANT_DEFAULT = 0;
	const double TICKS_NEEDED_DEFAULT = 0;
	const double ABSOLUTE_TOLERANCE_DEFAULT = 75;
	const double FEET_DEFAULT = 2;
	float p;
	float maxpercent;
	float i;
	float feet;
	const std::string DISTANCE_TO_TRAVEL_IN_FEET_DASHBOARD_KEY =
			"DriveXFeet::Distance to Travel in Feet";
	float absolutetolerance;
	const std::string ABSOLUTE_TOLERANCE_DASHBOARD_KEY =
			"DriveTrain: Absolute Tolerance";
	const std::string TICKS_NEEDED_DASHBOARD_KEY = "DriveSDBFeet: Ticks Needed:";
	const std::string PROPORTIONAL_CONSTANT_DASHBOARD_KEY =
			"DriveXFeet::Proportional Constant";
	const std::string MAX_PERCENT_DASHBOARD_KEY = "DriveTrain:Max Percent";
	const std::string INTEGRAL_CONSTANT_DAHSBOARD_KEY =
			"DriveXFeet::Integral Constant";

	const std::string ENCODER_VELOCITY_LEFT_FRONT_DASHBOARD_KEY =
			"DriveTrain:Left Front Encoder Velocity:";
	const std::string ENCODER_VELOCITY_RIGHT_FRONT_DASHBOARD_KEY =
			"DriveTrain:Right Front Encoder Velocity:";
	const std::string ENCODER_VELOCITY_RIGHT_REAR_DASHBOARD_KEY =
			"DriveTrain:Right Rear Encoder Velocity:";
	const std::string ENCODER_VELOCITY_LEFT_REAR_DASHBOARD_KEY =
			"DriveTrain:Left Rear Encoder Velocity:";

	const std::string STRAFE_SDB_FEET_DASHBOARD_KEY =
			"StrafeSDBFeet:Distance to Strafe:";
	const int STRAFE_SBD_FEET_DEFAULT = 0;

	const std::string STRAFE_SDB_FEET_MAX_PERCENT_DASHBOARD_KEY =
			"StrafeXFeet: Max Percent:";
	const int STRAFE_SDB_FEET_MAX_PERCENT_DEFAULT = .5;
	void PutDashboardValues();

	const float TICKS_PER_1_FOOT_STRAFE_DEFAULT = 1232;
	float ticksPerOneFootStrafe;
	float TICKS_TO_STrAFE_IN_FEET;

	const std::string STRAFE_X_FEET_DASHBOARD_KEY =
			"StrafeXFeet:Distance to Strafe:";
	const std::string STRAFE_X_FEET_TICKS_PER_ONE_FOOT_KEY =
			"StrafeXFeet:Ticks per One Foot Strafe";

};

#endif
