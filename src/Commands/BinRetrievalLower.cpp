#include "BinRetrievalLower.h"
#include "../Robot.h"

BinRetrievalLower::BinRetrievalLower()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(Robot::binRetrieval);
}

// Called just before this Command runs the first time
void BinRetrievalLower::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void BinRetrievalLower::Execute()
{
	Robot::binRetrieval-> LowerRight();
}

// Make this return true when this Command no longer needs to run execute()
bool BinRetrievalLower::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void BinRetrievalLower::End()
{
Robot::binRetrieval-> StopBoth();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void BinRetrievalLower::Interrupted()
{
End();
}
