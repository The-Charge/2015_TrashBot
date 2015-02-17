/*
 * RobotStrafePIDOutput.h
 *
 *  Created on: Feb 16, 2015
 *      Author: Paul
 */

#ifndef SRC_UTIL_ROBOTSTRAFEPIDOUTPUT_H_
#define SRC_UTIL_ROBOTSTRAFEPIDOUTPUT_H_

#include <PIDOutput.h>

#include <Gyro.h>
#include <RobotDrive.h>

class RobotStrafePIDOutput: public PIDOutput {
public:
	RobotStrafePIDOutput(RobotDrive *, Gyro *);
	//virtual ~RobotStrafePIDOutput()=0;
	RobotDrive * _RDrive;
	Gyro * _G;

	virtual void PIDWrite(float);
};

#endif /* SRC_UTIL_ROBOTSTRAFEPIDOUTPUT_H_ */
