#ifndef BinRetrievalPneumatic_H
#define BinRetrievalPneumatic_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class BinRetrievalPneumatic: public Subsystem
{
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
public:
	BinRetrievalPneumatic();
	void InitDefaultCommand();
	DoubleSolenoid* solenoid1;
	void Lower();
	void Raise();
};

#endif
