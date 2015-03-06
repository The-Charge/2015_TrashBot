#ifndef DelayCommand_H
#define DelayCommand_H

//#include "../CommandBase.h"
#include "WPILib.h"

class DelayCommand: public Command
{
public:
	DelayCommand(int);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
	int timetodelay;
};

#endif
