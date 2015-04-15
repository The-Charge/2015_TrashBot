#include "BinRetrievalLowerLeft.h"
#include "../Robot.h"

BinRetrievalLowerLeft::BinRetrievalLowerLeft()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(Robot::binRetrieval);
}

// Called just before this Command runs the first time
void BinRetrievalLowerLeft::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void BinRetrievalLowerLeft::Execute()
{
Robot::binRetrieval -> LowerLeft();
}

// Make this return true when this Command no longer needs to run execute()
bool BinRetrievalLowerLeft::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void BinRetrievalLowerLeft::End()
{
Robot::binRetrieval -> StopBoth();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void BinRetrievalLowerLeft::Interrupted()
{
End();
}
