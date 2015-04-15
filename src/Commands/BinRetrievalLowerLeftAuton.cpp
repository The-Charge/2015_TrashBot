#include "BinRetrievalLowerLeftAuton.h"
#include "../Robot.h"
BinRetrievalLowerLeftAuton::BinRetrievalLowerLeftAuton(float t)
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(Robot::binRetrieval);
	timeout = t;
}

// Called just before this Command runs the first time
void BinRetrievalLowerLeftAuton::Initialize()
{
this -> SetTimeout(timeout);
}

// Called repeatedly when this Command is scheduled to run
void BinRetrievalLowerLeftAuton::Execute()
{
Robot::binRetrieval -> LowerLeft();
}

// Make this return true when this Command no longer needs to run execute()
bool BinRetrievalLowerLeftAuton::IsFinished()
{
	return this -> IsTimedOut();
}

// Called once after isFinished returns true
void BinRetrievalLowerLeftAuton::End()
{
Robot::binRetrieval -> StopBoth();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void BinRetrievalLowerLeftAuton::Interrupted()
{
End();
}
