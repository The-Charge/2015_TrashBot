#ifndef BinRetrievalLowerLeftAuton_H
#define BinRetrievalLowerLeftAuton_H


#include "WPILib.h"

class BinRetrievalLowerLeftAuton: public Command
{
public:
	BinRetrievalLowerLeftAuton(float);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
	float timeout;
};

#endif
