/*
 * AverageEncodersPIDInput.cpp
 *
 *  Created on: Feb 16, 2015
 *      Author: Paul
 */

#include "AverageEncodersPIDInput.h"

AverageEncodersPIDInput::AverageEncodersPIDInput(CANTalon * CANTalon1, CANTalon * CANTalon2, CANTalon * CANTalon3, CANTalon * CANTalon4 ) {
	// TODO Auto-generated constructor stub
	_CANTalon1 = CANTalon1;
	_CANTalon2 = CANTalon2;
	_CANTalon3 = CANTalon3;
	_CANTalon4 = CANTalon4;

}

double AverageEncodersPIDInput::PIDGet() {
	double average;

	average = _CANTalon1->GetEncPosition() + _CANTalon2->GetEncPosition() + _CANTalon3->GetEncPosition() + _CANTalon4->GetEncPosition();

	average = average / 4;

	return average;
}



