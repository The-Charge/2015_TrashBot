/*
 * PIDCanTalon.h
 *
 *  Created on: Jan 29, 2015
 *      Author: shalmezad
 */

#ifndef UTIL_PIDCANTALON_H_
#define UTIL_PIDCANTALON_H_

#include <PIDSource.h>

class PIDCanTalon: public PIDSource {
private:
	CANTalon* talon;
public:
	PIDCanTalon(CANTalon* talon);
	virtual float PIDGet();
};

#endif /* UTIL_PIDCANTALON_H_ */
