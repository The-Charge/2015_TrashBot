/*
 * PIDCanTalon.cpp
 *
 *  Created on: Jan 29, 2015
 *      Author: Robotics
 */

#include "PIDCanTalon.h"

PIDCanTalon::PIDCanTalon(CANTalon * talon) {
	// TODO Auto-generated constructor stub
	_talon = talon;
}

double PIDCanTalon::PIDGet() {
	return _talon->GetEncPosition();
}
