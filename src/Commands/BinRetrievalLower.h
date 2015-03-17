#ifndef BinRetrievalLower_H
#define BinRetrievalLower_H

#include "WPILib.h"

class BinRetrievalLower: public Command
{
public:
	BinRetrievalLower();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
