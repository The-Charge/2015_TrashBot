/*
 * AverageEncodersPIDInput.h
 *
 *  Created on: Feb 16, 2015
 *      Author: Paul
 */

#ifndef SRC_UTIL_AVERAGEENCODERSPIDINPUT_H_
#define SRC_UTIL_AVERAGEENCODERSPIDINPUT_H_

#include <PIDSource.h>
#include <CANTalon.h>

class AverageEncodersPIDInput: public PIDSource {
public:
	AverageEncodersPIDInput(CANTalon*, CANTalon*, CANTalon*, CANTalon*);
	CANTalon* _CANTalon1;
	CANTalon* _CANTalon2;
	CANTalon* _CANTalon3;
	CANTalon* _CANTalon4;

	double average;

	double PIDGet();
};

#endif /* SRC_UTIL_AVERAGEENCODERSPIDINPUT_H_ */
