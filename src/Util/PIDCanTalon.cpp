/*
 * PIDCanTalon.cpp
 *
 *  Created on: Jan 29, 2015
 *      Author: Robotics
 */

#include "PIDCanTalon.h"

PIDCanTalon::PIDCanTalon(CANTalon * talon) {
	// TODO Auto-generated constructor stub
this ->talon = talon;
}

double PIDCanTalon::PIDGet()
{
	return talon -> GetEncPosition();
}
