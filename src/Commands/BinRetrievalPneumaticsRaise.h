#ifndef BinRetrievalPneumaticsRaise_H
#define BinRetrievalPneumaticsRaise_H

#include "WPILib.h"

class BinRetrievalPneumaticsRaise: public Command
{
public:
	BinRetrievalPneumaticsRaise();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
