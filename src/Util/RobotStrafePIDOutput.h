/*
 * RobotStrafePIDOutput.h
 *
 *  Created on: Feb 5, 2015
 *      Author: Robotics
 */

#ifndef SRC_UTIL_ROBOTSTRAFEPIDOUTPUT_H_
#define SRC_UTIL_ROBOTSTRAFEPIDOUTPUT_H_
#include "PIDOutput.h"

class RobotStrafePIDOutput: public PIDOutput{
public:
	RobotStrafePIDOutput();
	virtual ~RobotStrafePIDOutput();
};

#endif /* SRC_UTIL_ROBOTSTRAFEPIDOUTPUT_H_ */
