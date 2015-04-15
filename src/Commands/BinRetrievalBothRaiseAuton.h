#ifndef BinRetrievalBothRaiseAuton_H
#define BinRetrievalBothRaiseAuton_H


#include "WPILib.h"

class BinRetrievalBothRaiseAuton: public Command
{
public:
	BinRetrievalBothRaiseAuton(float);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
	float timeout;
};

#endif
