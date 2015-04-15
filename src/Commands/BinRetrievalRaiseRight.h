#ifndef BinRetrievalRaiseRight_H
#define BinRetrievalRaiseRight_H

#include "WPILib.h"

class BinRetrievalRaiseRight: public Command
{
public:
	BinRetrievalRaiseRight();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
