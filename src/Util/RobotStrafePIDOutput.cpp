/*
 * RobotStrafePIDOutput.cpp
 *
 *  Created on: Feb 16, 2015
 *      Author: Paul
 */

#include "RobotStrafePIDOutput.h"

#include <Gyro.h>
#include <RobotDrive.h>

RobotStrafePIDOutput::RobotStrafePIDOutput(RobotDrive * RDrive, Gyro * G) {
	// TODO Auto-generated constructor stub
	this -> _RDrive = RDrive;
	this -> _G = G;
}

void RobotStrafePIDOutput::PIDWrite(float x)
{
	_RDrive -> MecanumDrive_Cartesian(x , 0, 0, _G->GetAngle());
}

