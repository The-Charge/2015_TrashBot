/*
 * PIDCanTalon.cpp
 *
 *  Created on: Jan 29, 2015
 *      Author: shalmezad
 */

#include "PIDCanTalon.h"

PIDCanTalon::PIDCanTalon(CANTalon* talon) {
	// TODO Auto-generated constructor stub
	this->talon = talon;
}

float PIDCanTalon::PIDGet()
{
	return talon->GetEncPosition();
}
