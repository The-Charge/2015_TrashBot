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

class RobotStrafePIDOutput: public PIDOutput{
private:

public:
	RobotStrafePIDOutput();
	virtual void PIDWrite(double);
};

#endif /* SRC_UTIL_ROBOTSTRAFEPIDOUTPUT_H_ */
