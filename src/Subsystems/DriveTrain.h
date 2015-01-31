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
	void SetDistanceInFeet(int);
	bool AtDestination();
	void Init();
	void DisablePIDControllers();
	void ReadDashboardValues();

	const float WHEELDIAMETER_IN_INCHES = 8;
	const float WHEELCIRCUMFERENCE_IN_INCHES = WHEELDIAMETER_IN_INCHES * 3.14;
	const float WHEELCIRCUMFERENCE_IN_FEET = WHEELCIRCUMFERENCE_IN_INCHES / 12;
	const float WHEELROTATIONS_PER_FOOT = 1 / WHEELCIRCUMFERENCE_IN_FEET;
	const int ENCODER_TICKS_PER_REVOLUTION = 2048 * 4; //250;
	float TICKS_NEEDED = 0;

	PIDController*leftFrontPIDController;
	PIDController*rightFrontPIDController;
	PIDController*leftRearPIDController;
	PIDController*rightRearPIDController;

	PIDCanTalon*leftRearPIDCanTalon;
	PIDCanTalon*leftFrontPIDCanTalon;
	PIDCanTalon*rightFrontPIDCanTalon;
	PIDCanTalon*rightRearPIDCanTalon;

	const std::string CLOSED_LOOP_ERROR_RIGHT_FRONT_DASHBOARD_KEY =
			"Drive2Feet::Closed Loop Error Right Front";
	const std::string ENCODER_POSITION_RIGHT_FRONT_DASHBOARD_KEY =
			"Drive2Feet::Encoder Position Right Front";

	const std::string CLOSED_LOOP_ERROR_RIGHT_REAR_DASHBOARD_KEY =
			"Drive2Feet::Closed Loop Error Right Rear";
	const std::string ENCODER_POSITION_RIGHT_REAR_DASHBOARD_KEY =
			"Drive2Feet::Encoder Position Right Rear";

	const std::string CLOSED_LOOP_ERROR_LEFT_FRONT_DASHBOARD_KEY =
			"Drive2Feet::Closed Loop Error Left Front";
	const std::string ENCODER_POSITION_LEFT_FRONT_DASHBOARD_KEY =
			"Drive2Feet::Encoder Position Left Front";

	const std::string CLOSED_LOOP_ERROR_LEFT_REAR_DASHBOARD_KEY =
			"Drive2Feet::Closed Loop Error Left Rear";
	const std::string ENCODER_POSITION_LEFT_REAR_DASHBOARD_KEY =
			"Drive2Feet::Encoder Position Left Rear";

	const double CLOSED_LOOP_ERROR_DEFAULT = 0;
	const double ENCODER_POSITION_DEFAULT = 0;

	const double PROPORTIONAL_CONSTANT_DEFAULT = 1;
	const double MAX_PERCENT_DEFAULT = 6;
	const double INTEGRAL_CONSTANT_DEFAULT = 0;
	const double TICKS_NEEDED_DEFAULT = 0;
	const double ABSOLUTE_TOLERANCE_DEFAULT = 100;
	float p;
	float maxpercent;
	float i;
	float absolutetolerance;
	const std::string ABSOLUTE_TOLERANCE_DASHBOARD_KEY = "DriveTrain: Absolute Tolerance";
	const std::string TICKS_NEEDED_DASHBOARD_KEY = "Drive2Feet: Ticks Needed:";
	const std::string PROPORTIONAL_CONSTANT_DASHBOARD_KEY =
			"Drive2Feet::Proportional Constant";
	const std::string MAX_PERCENT_DASHBOARD_KEY = "Drive2Feet::Max Percent";
	const std::string INTEGRAL_CONSTANT_DAHSBOARD_KEY =
			"Drive2Feet::Integral Constant";


};

#endif
