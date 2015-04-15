#include "BinRetrievalRaise.h"
#include "../Robot.h"

BinRetrievalRaise::BinRetrievalRaise()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(Robot::binRetrieval);
}

// Called just before this Command runs the first time
void BinRetrievalRaise::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void BinRetrievalRaise::Execute()
{
	Robot::binRetrieval -> RaiseLeft();
}

// Make this return true when this Command no longer needs to run execute()
bool BinRetrievalRaise::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void BinRetrievalRaise::End()
{
Robot::binRetrieval -> StopBoth();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void BinRetrievalRaise::Interrupted()
{
End();
}
