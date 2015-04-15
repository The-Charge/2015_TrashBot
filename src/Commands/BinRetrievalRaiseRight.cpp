#include "BinRetrievalRaiseRight.h"
#include "../Robot.h"

BinRetrievalRaiseRight::BinRetrievalRaiseRight()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires (Robot::binRetrieval);
}

// Called just before this Command runs the first time
void BinRetrievalRaiseRight::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void BinRetrievalRaiseRight::Execute()
{
Robot::binRetrieval -> RaiseRight();
}

// Make this return true when this Command no longer needs to run execute()
bool BinRetrievalRaiseRight::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void BinRetrievalRaiseRight::End()
{
Robot::binRetrieval -> StopBoth();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void BinRetrievalRaiseRight::Interrupted()
{
End();
}
