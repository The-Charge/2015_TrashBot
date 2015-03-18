#include "BinRetrievalPneumaticsLower.h"
#include "../Robot.h"

BinRetrievalPneumaticsLower::BinRetrievalPneumaticsLower()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(Robot::binRetrievalPneumatic);
}

// Called just before this Command runs the first time
void BinRetrievalPneumaticsLower::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void BinRetrievalPneumaticsLower::Execute()
{
	Robot::binRetrievalPneumatic -> Raise();
}

// Make this return true when this Command no longer needs to run execute()
bool BinRetrievalPneumaticsLower::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void BinRetrievalPneumaticsLower::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void BinRetrievalPneumaticsLower::Interrupted()
{

}
