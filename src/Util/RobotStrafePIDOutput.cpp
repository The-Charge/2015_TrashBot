/*
 * RobotStrafePIDOutput.cpp
 *
 *  Created on: Feb 5, 2015
 *      Author: Robotics
 */

#include "RobotStrafePIDOutput.h"

RobotStrafePIDOutput::RobotStrafePIDOutput(CANTalon * talon)
{
	// TODO Auto-generated constructor stub
	_talon = talon;
}

double RobotStrafePIDOutput::PIDGet()
{
	return _talon -> GetEncPosition();
}
