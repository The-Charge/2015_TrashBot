#include "BinRetrievalRaiseLeftAuton.h"
#include "../Robot.h"
BinRetrievalRaiseLeftAuton::BinRetrievalRaiseLeftAuton(float t)
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires (Robot::binRetrieval);
	timeout = t;
}

// Called just before this Command runs the first time
void BinRetrievalRaiseLeftAuton::Initialize()
{
this -> SetTimeout (timeout);
}

// Called repeatedly when this Command is scheduled to run
void BinRetrievalRaiseLeftAuton::Execute()
{
Robot::binRetrieval -> RaiseLeft();
}

// Make this return true when this Command no longer needs to run execute()
bool BinRetrievalRaiseLeftAuton::IsFinished()
{
	return this -> IsTimedOut();
}

// Called once after isFinished returns true
void BinRetrievalRaiseLeftAuton::End()
{
Robot::binRetrieval -> StopBoth();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void BinRetrievalRaiseLeftAuton::Interrupted()
{
End();
}
