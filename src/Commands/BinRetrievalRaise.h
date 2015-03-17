#ifndef BinRetrievalRaise_H
#define BinRetrievalRaise_H

#include "WPILib.h"

class BinRetrievalRaise: public Command
{
public:
	BinRetrievalRaise();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
