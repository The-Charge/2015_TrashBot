#include "BinRetrievalLowerBoth.h"
#include "../Robot.h"
BinRetrievalLowerBoth::BinRetrievalLowerBoth()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires (Robot::binRetrieval);
}

// Called just before this Command runs the first time
void BinRetrievalLowerBoth::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void BinRetrievalLowerBoth::Execute()
{
Robot::binRetrieval -> LowerBoth();
}

// Make this return true when this Command no longer needs to run execute()
bool BinRetrievalLowerBoth::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void BinRetrievalLowerBoth::End()
{
Robot::binRetrieval -> StopBoth();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void BinRetrievalLowerBoth::Interrupted()
{
End();
}
