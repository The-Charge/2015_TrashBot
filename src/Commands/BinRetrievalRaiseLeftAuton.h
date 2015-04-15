#ifndef BinRetrievalRaiseLeftAuton_H
#define BinRetrievalRaiseLeftAuton_H


#include "WPILib.h"

class BinRetrievalRaiseLeftAuton: public Command
{
public:
	BinRetrievalRaiseLeftAuton(float);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
	float timeout;
};

#endif
