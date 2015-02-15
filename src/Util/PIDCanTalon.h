/*
 * PIDCanTalon.h
 *
 *  Created on: Jan 29, 2015
 *      Author: Robotics
 */

#ifndef UTIL_PIDCANTALON_H_
#define UTIL_PIDCANTALON_H_

#include <PIDSource.h>
#include <CANTalon.h>

class PIDCanTalon: public PIDSource {
private:
	CANTalon * _talon;
public:
	PIDCanTalon(CANTalon * talon);
	virtual double PIDGet();
};

#endif /* UTIL_PIDCANTALON_H_ */
