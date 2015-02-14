/*
 * EncoderAveragePIDSource.h
 *
 *  Created on: Feb 13, 2015
 *      Author: Robotics
 */

#ifndef SRC_UTIL_ENCODERAVERAGEPIDSOURCE_H_
#define SRC_UTIL_ENCODERAVERAGEPIDSOURCE_H_

class EncoderAveragePIDSource: public PIDSource{
private:
	CANTalon * _talon1;
	CANTalon * _talon2;
	CANTalon * _talon3;
	CANTalon * _talon4;
public:
	EncoderAveragePIDSource(CANTalon*, CANTalon*, CANTalon*, CANTalon* );
	virtual ~EncoderAveragePIDSource();
	virtual double PIDGet();
};

#endif /* SRC_UTIL_ENCODERAVERAGEPIDSOURCE_H_ */
