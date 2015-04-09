#ifndef DriveXFeetReeper_H
#define DriveXFeetReeper_H


#include "WPILib.h"
#include "../Robot.h"


class DriveXFeetReeper: public Command
{
public:
	DriveXFeetReeper(float = -1, float = 0);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
	float maxpercent;
	float feet;
};

#endif
