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

class RobotStrafePIDOutput: public PIDOutput{
private:
	Robot::driveTrain;
public:
	RobotStrafePIDOutput(CANTalon * talon);
	virtual ~RobotStrafePIDOutput();
	virtual void PIDWrite(double);
};

#endif /* SRC_UTIL_ROBOTSTRAFEPIDOUTPUT_H_ */
