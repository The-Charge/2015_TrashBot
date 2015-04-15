#ifndef BinRetrievalLowerLeft_H
#define BinRetrievalLowerLeft_H


#include "WPILib.h"

class BinRetrievalLowerLeft: public Command
{
public:
	BinRetrievalLowerLeft();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
