#ifndef BinRetrievalLowerRightAuton_H
#define BinRetrievalLowerRightAuton_H


#include "WPILib.h"

class BinRetrievalLowerRightAuton: public Command
{
public:
	BinRetrievalLowerRightAuton(float);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
	float timeout;
};

#endif
