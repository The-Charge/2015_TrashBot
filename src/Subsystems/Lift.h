// RobotBuilder Version: 1.5
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.

#ifndef LIFT_H
#define LIFT_H
#include "Commands/Subsystem.h"
#include "WPILib.h"
#include "../OI.h"

/**
 *
 *
 * @author ExampleAuthor
 */
class Lift: public Subsystem {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities

public:
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	DoubleSolenoid* solenoid1;
	SpeedController* speedController;
	Encoder* encoder;

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS

	Lift();

	void InitDefaultCommand();
	void LiftUpFast();
	void LiftDownFast();
	void LiftUpSlow();
	void LiftDownSlow();
	void BrakeOn();
	void BrakeOff();
	void BrakePowerOff();
	void UpdateSmartDashboard();

	float ReadSlowPotentiometer();
	float ReadFastPotentiometer();
	void PutDashboardValues();
	void ReadDashboardValues();
	int CurrentLiftPosition();
	float GetDeadband();
	bool AtDestination();
	void Stop();
	void SetLift(int, float);
	void SetSDBLift();

	//constants for smart dashboard displaying
	const std::string LIFT_SPEED_UP_FAST_KEY = "Lift::Lift Speed Up Fast";
	const float LIFT_SPEED_UP_FAST_DEFAULT = 1;

	const std::string LIFT_SPEED_DOWN_FAST_KEY = "Lift::Lift Speed Down Fast";
	const float LIFT_SPEED_DOWN_FAST_DEFAULT = -1;

	const std::string LIFT_SPEED_UP_SLOW_KEY = "Lift::Lift Speed Up Slow";
	const float LIFT_SPEED_UP_SLOW_DEFAULT = .4;

	const std::string LIFT_SPEED_DOWN_SLOW_KEY = "Lift::Lift Speed Down Slow";
	const float LIFT_SPEED_DOWN_SLOW_DEFAULT = -.4;

	const std::string LIFT_ENCODER_VALUE_DASHBOARD_KEY =
			"Lift::Encoder Tick Value:";

	const std::string MAX_VALUE_TICKS = "Lift max ticks: ";
	const std::string LIFT_DEADBAND_STRING = "Lift deadband: ";
	const std::string LIFT_SPEED_STRING = "lift::LiftXticks Speed of Lift: ";
	const std::string LIFT_TICKS_STRING = "lift::LiftXticks Placement of Lift: ";

	const std::string LIFT_TICKS_DASHBOARD_KEY = "LiftSDBTicks: Ticks to Lift: ";
	const std::string LIFT_SPEED_DASHBOARD_KEY = "Lift SDBTicks: Speed: ";
	const float TICKS_LIFT_DEFAULT = 30000;
	const float SPEED_LIFT_DEFAULT = .4;

	int LIFT_ENCODER_TICKS = 0;

	//variables for reading smart dashboard values
	float liftSpeedUpFast;
	float liftSpeedDownFast;
	float liftSpeedUpSlow;
	float liftSpeedDownSlow;

	const int LIFT_DEADBAND_DEFAULT = 500;

	const int MAX_LIFT_TICKS = 16200;

	const int UPPER_DEADBAND = 500;
	const int LOWER_DEADBAND_SLOW = 500;
	const int LOWER_DEADBAND_FAST = 1000;

	const int UPPER_SAFETY_LIMIT = MAX_LIFT_TICKS - UPPER_DEADBAND;
	const int LOWER_SAFETY_LIMIT_SLOW = LOWER_DEADBAND_SLOW + 0;
	const int LOWER_SAFETY_LIMIT_FAST = LOWER_DEADBAND_FAST + 0;

	int LIFTSETPOINT = 0;
	int ticks = 0;
	float speed = 0;

};

#endif
