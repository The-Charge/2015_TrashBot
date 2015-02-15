/*
 * RobotStrafePIDOutput.h
 *
 *  Created on: Feb 5, 2015
 *      Author: Robotics
 */

#ifndef SRC_UTIL_ROBOTSTRAFEPIDOUTPUT_H_
#define SRC_UTIL_ROBOTSTRAFEPIDOUTPUT_H_
#include <PIDOutput.h>
#include <CANTalon.h>
#include "../Robot.h"

class RobotStrafePIDOutput: public PIDOutput {
private:
	RobotDrive * _drive;
public:
	RobotStrafePIDOutput(RobotDrive * _drive);
	virtual void PIDWrite(double);
	const std::string GYRO_CORRECTION_DASHBOARD_KEY = "Drive::Gyro Correction";
	const double CORRECTION_DEFAULT = 4;

};

#endif /* SRC_UTIL_ROBOTSTRAFEPIDOUTPUT_H_ */
