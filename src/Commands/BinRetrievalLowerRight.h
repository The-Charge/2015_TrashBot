#ifndef BinRetrievalLowerRight_H
#define BinRetrievalLowerRight_H


#include "WPILib.h"

class BinRetrievalLowerRight: public Command
{
public:
	BinRetrievalLowerRight();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
