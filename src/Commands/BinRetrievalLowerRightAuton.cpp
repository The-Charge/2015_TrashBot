#include "BinRetrievalLowerRightAuton.h"
#include "../Robot.h"

BinRetrievalLowerRightAuton::BinRetrievalLowerRightAuton(float t)
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires (Robot::binRetrieval);
	timeout = t;
}

// Called just before this Command runs the first time
void BinRetrievalLowerRightAuton::Initialize()
{
this -> SetTimeout(timeout);
}

// Called repeatedly when this Command is scheduled to run
void BinRetrievalLowerRightAuton::Execute()
{
Robot::binRetrieval -> LowerRight();
}

// Make this return true when this Command no longer needs to run execute()
bool BinRetrievalLowerRightAuton::IsFinished()
{
	return this -> IsTimedOut();
}

// Called once after isFinished returns true
void BinRetrievalLowerRightAuton::End()
{
Robot::binRetrieval -> StopBoth();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void BinRetrievalLowerRightAuton::Interrupted()
{
End();
}
