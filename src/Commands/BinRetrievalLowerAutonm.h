#ifndef BinRetrievalLowerAutonm_H
#define BinRetrievalLowerAutonm_H

#include "WPILib.h"

class BinRetrievalLowerAutonm: public Command
{
public:
	BinRetrievalLowerAutonm(int);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
	int timetorun;
};

#endif
