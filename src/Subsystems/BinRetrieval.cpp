#include "BinRetrieval.h"
#include "../RobotMap.h"

BinRetrieval::BinRetrieval() :
		Subsystem("BinRetrieval")
{
	speedController = RobotMap::binRetrievalSpeedController;
}

void BinRetrieval::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
}

void BinRetrieval::Lower()
{
	speedController-> Set(-.25);
}

void BinRetrieval::Raise()
{
	speedController -> Set(.4);
}
void BinRetrieval::Stop()
{
	speedController -> Set(0);
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
