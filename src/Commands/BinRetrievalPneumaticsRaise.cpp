#include "BinRetrievalPneumaticsRaise.h"
#include "../Robot.h"

BinRetrievalPneumaticsRaise::BinRetrievalPneumaticsRaise()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(Robot::binRetrievalPneumatic);
}

// Called just before this Command runs the first time
void BinRetrievalPneumaticsRaise::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void BinRetrievalPneumaticsRaise::Execute()
{
Robot::binRetrievalPneumatic -> Raise();
}

// Make this return true when this Command no longer needs to run execute()
bool BinRetrievalPneumaticsRaise::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void BinRetrievalPneumaticsRaise::End()
{
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void BinRetrievalPneumaticsRaise::Interrupted()
{

}
