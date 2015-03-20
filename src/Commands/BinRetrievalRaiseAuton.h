#ifndef BinRetrievalRaiseAuton_H
#define BinRetrievalRaiseAuton_H

#include "WPILib.h"

class BinRetrievalRaiseAuton: public Command
{
public:
	BinRetrievalRaiseAuton(int t);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
	int timetorun;
};

#endif
