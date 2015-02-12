/*
 * RobotStrafePIDOutput.cpp
 *
 *  Created on: Feb 5, 2015
 *      Author: Robotics
 */

#include "RobotStrafePIDOutput.h"
#include "../Subsystems/DriveTrain.h"

RobotStrafePIDOutput::RobotStrafePIDOutput()
{
	// TODO Auto-generated constructor stub

}

void RobotStrafePIDOutput::PIDWrite(double output)
{
	Robot::driveTrain -> rightRearPIDController -> SetTolerance(output);
	Robot::driveTrain -> leftRearPIDController -> SetTolerance(output);
	Robot::driveTrain -> leftFrontPIDController -> SetTolerance(output);
	Robot::driveTrain -> rightFrontPIDController -> SetTolerance(output);
}
