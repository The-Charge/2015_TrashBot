#ifndef BinRetrievalPneumaticsLower_H
#define BinRetrievalPneumaticsLower_H


#include "WPILib.h"

class BinRetrievalPneumaticsLower: public Command
{
public:
	BinRetrievalPneumaticsLower();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
