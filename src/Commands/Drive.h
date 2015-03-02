// RobotBuilder Version: 1.5
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.

#ifndef DRIVE_H
#define DRIVE_H

#include "Commands/Subsystem.h"
#include "../Robot.h"

/**
 *
 *
 * @author ExampleAuthor
 */
class Drive: public Command {
private:
	const std::string DELINEARIZATION_POWER_DASHBOARD_KEY =
			"Drive::delinearizationPower";
	const std::string DELINEARIZATION_ALPHA_DASHBOARD_KEY =
			"Drive::delinearizationAlpha";
	const std::string JOYSTICK_DEADBAND_DASHBOARD_KEY =
			"Drive::joystickDeadband";
	const double DELINEARIZATION_ALPHA_DEFAULT = .8;
	const double DELINEARIZATION_POWER_DEFAULT = 5;
	const double JOYSTICK_DEADBAND_DEFAULT = .2;

	const std::string SCALEFACTOR_GYRO_DASHBOARD_KEY = "Drive::ScaleFactor";
	const std::string GAINFACTOR_GYRO_DASHBOARD_KEY = "Drive::GainFactor";

	double joystickDeadband;
	double delinearizationPower;
	double delinearizationAlpha;

	float ScaleFactor;
	float GainFactor;

	const float CORRECTION_DEFAULT = 4;
	const std::string GYRO_CORRECTION_DASHBOARD_KEY = "Drive::Gyro Correction";

	const float SPEED_PERCENT_DEFAULT = 0.8;
	const std::string SPEED_PERCENT_STRING = "Button 'half' speed: ";
	float speedpercent = 0;

public:
	Drive();
	//float delinearize(float, float);
	//float deadband(float, float);
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
private:
	SendableChooser*sc;
	std::string*xDrive;
	std::string*jDrive;
	std::string*tDrive;
};

#endif
