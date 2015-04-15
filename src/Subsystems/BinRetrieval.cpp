#include "BinRetrieval.h"
#include "../RobotMap.h"

BinRetrieval::BinRetrieval() :
		Subsystem("BinRetrieval")
{
	speedControllerRight = RobotMap::binRetrievalSpeedControllerRight;
	speedControllerLeft = RobotMap::binRetrievalSpeedControllerLeft;
}

void BinRetrieval::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
}

void BinRetrieval::LowerRight()
{
	speedControllerRight-> Set(-.25);
}

void BinRetrieval::RaiseRight()
{
	speedControllerRight -> Set(.4);
}
void BinRetrieval::StopBoth()
{
	speedControllerRight -> Set(0);
}

void BinRetrieval::RaiseLeft()
{
	speedControllerLeft -> Set(-.25);
}

void BinRetrieval::LowerLeft()
{
	speedControllerLeft -> Set(.4);
}

void BinRetrieval::LowerBoth()
{
	speedControllerLeft -> Set(.4);
	speedControllerRight -> Set(.4);
}

void BinRetrieval::RaiseBoth()
{
	speedControllerLeft -> Set(-.25);
	speedControllerRight -> Set(-.25);
}
// Put methods for controlling this subsystem
// here. Call these from Commands.
