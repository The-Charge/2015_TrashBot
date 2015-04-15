#ifndef BinRetrievalRaiseRightAuton_H
#define BinRetrievalRaiseRightAuton_H


#include "WPILib.h"

class BinRetrievalRaiseRightAuton: public Command
{
public:
	BinRetrievalRaiseRightAuton(float);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
	float timeout;
};

#endif
