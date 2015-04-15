#ifndef BinRetrievalBothLowerAuton_H
#define BinRetrievalBothLowerAuton_H


#include "WPILib.h"

class BinRetrievalBothLowerAuton: public Command
{
public:
	BinRetrievalBothLowerAuton(float);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
	float timeout;
};

#endif
