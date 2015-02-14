/*
 * EncoderAveragePIDSource.cpp
 *
 *  Created on: Feb 13, 2015
 *      Author: Robotics
 */
#include "Encoder.h"
#include "EncoderAveragePIDSource.h"

EncoderAveragePIDSource::EncoderAveragePIDSource() {
	//CANTalon * talon1, CANTalon * talon2, CANTalon * talon3, CANTalon * talon4
	// TODO Auto-generated constructor stub
	//_talon1 = talon1;
	//_talon2 = talon2;
	//_talon3 = talon3;
	//_talon4 = talon4;
}

EncoderAveragePIDSource::~EncoderAveragePIDSource() {
	// TODO Auto-generated destructor stub
}

double EncoderAveragePIDSource::PIDGet()
{
	//CANTalonRightFront->GetEncPosition()
	//return (( _encoder1 -> Get() + _encoder2 -> Get() + _encoder3 -> Get() + _encoder4 -> Get()) / 4);
	return 0;
}
