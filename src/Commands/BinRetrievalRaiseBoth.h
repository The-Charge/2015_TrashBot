#ifndef BinRetrievalRaiseBoth_H
#define BinRetrievalRaiseBoth_H


#include "WPILib.h"

class BinRetrievalRaiseBoth: public Command
{
public:
	BinRetrievalRaiseBoth();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
