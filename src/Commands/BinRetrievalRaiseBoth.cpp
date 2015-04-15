#include "BinRetrievalRaiseBoth.h"
#include "../Robot.h"
BinRetrievalRaiseBoth::BinRetrievalRaiseBoth()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires (Robot::binRetrieval);
}

// Called just before this Command runs the first time
void BinRetrievalRaiseBoth::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void BinRetrievalRaiseBoth::Execute()
{
Robot::binRetrieval -> RaiseBoth();
}

// Make this return true when this Command no longer needs to run execute()
bool BinRetrievalRaiseBoth::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void BinRetrievalRaiseBoth::End()
{
Robot::binRetrieval -> StopBoth();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void BinRetrievalRaiseBoth::Interrupted()
{
End();
}
