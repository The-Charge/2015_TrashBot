#include "BinRetrievalLowerRight.h"
#include "../Robot.h"
BinRetrievalLowerRight::BinRetrievalLowerRight()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(Robot::binRetrieval);
}

// Called just before this Command runs the first time
void BinRetrievalLowerRight::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void BinRetrievalLowerRight::Execute()
{
Robot::binRetrieval -> LowerRight();
}

// Make this return true when this Command no longer needs to run execute()
bool BinRetrievalLowerRight::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void BinRetrievalLowerRight::End()
{
Robot::binRetrieval -> StopBoth();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void BinRetrievalLowerRight::Interrupted()
{
End();
}
