#ifndef BinRetrieval_H
#define BinRetrieval_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class BinRetrieval: public Subsystem
{
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
public:

	SpeedController*speedControllerRight;
	SpeedController*speedControllerLeft;
	BinRetrieval();
	void InitDefaultCommand();
	void LowerRight();
	void RaiseRight();
	void LowerLeft();
	void RaiseLeft();
	void StopBoth();
	void RaiseBoth();
	void LowerBoth();
};

#endif
