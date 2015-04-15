#ifndef BinRetrievalRaiseLeft_H
#define BinRetrievalRaiseLeft_H


#include "WPILib.h"

class BinRetrievalRaiseLeft: public Command
{
public:
	BinRetrievalRaiseLeft();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
