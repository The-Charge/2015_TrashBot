#ifndef BinRetrievalLowerBoth_H
#define BinRetrievalLowerBoth_H


#include "WPILib.h"

class BinRetrievalLowerBoth: public Command
{
public:
	BinRetrievalLowerBoth();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
