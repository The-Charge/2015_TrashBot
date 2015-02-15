/*
 * RobotStrafePIDOutput.cpp
 *
 *  Created on: Feb 5, 2015
 *      Author: Robotics
 */

#include "RobotStrafePIDOutput.h"


RobotStrafePIDOutput::RobotStrafePIDOutput(RobotDrive * drive) {
	// TODO Auto-generated constructor stub
	_drive = drive;
}

void RobotStrafePIDOutput::PIDWrite(double x) {

	//float correction = SmartDashboard::GetNumber(GYRO_CORRECTION_DASHBOARD_KEY,
		//	CORRECTION_DEFAULT);
	/*
	 Robot::driveTrain -> rightRearPIDController -> SetTolerance(output);
	 Robot::driveTrain -> leftRearPIDController -> SetTolerance(output);
	 Robot::driveTrain -> leftFrontPIDController -> SetTolerance(output);
	 Robot::driveTrain -> rightFrontPIDController -> SetTolerance(output);
	 */
}
