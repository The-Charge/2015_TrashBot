/*
 * PIDCanTalon.cpp
 *
 *  Created on: Jan 29, 2015
 *      Author: Robotics
 */

#include "PIDCanTalon.h"
#include "ZN_KuTuCreater.h"
#include "ZN_PIDTune.h"

PIDCanTalon::PIDCanTalon(CANTalon * talon) {
	// TODO Auto-generated constructor stub
	_talon = talon;

	float KuTu[2], weight = 0;

	KuTu[0] = ZN_KuTuCreater::PIDKuCreator(float weight);
	KuTu[1] = ZN_KuTuCreater::PIDTuCreator(float weight);

	float* TPID = new float[3];
	ZN_PIDTune::PIDTuner(KuTu[0], KuTu[1], float* TPID);

	delete[]TPID;
}

double PIDCanTalon::PIDGet() {
	return _talon->GetEncPosition();
}
