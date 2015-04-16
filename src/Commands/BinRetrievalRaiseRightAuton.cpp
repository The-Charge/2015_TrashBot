#include "BinRetrievalRaiseRightAuton.h"
#include "../Robot.h"

BinRetrievalRaiseRightAuton::BinRetrievalRaiseRightAuton(float t)
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires (Robot::binRetrieval);
	timeout = t;
}

// Called just before this Command runs the first time
void BinRetrievalRaiseRightAuton::Initialize()
{
this -> SetTimeout(timeout);
}

// Called repeatedly when this Command is scheduled to run
void BinRetrievalRaiseRightAuton::Execute()
{
Robot::binRetrieval -> RaiseRight();
}

// Make this return true when this Command no longer needs to run execute()
bool BinRetrievalRaiseRightAuton::IsFinished()
{
	return this -> IsTimedOut();
}

// Called once after isFinished returns true
void BinRetrievalRaiseRightAuton::End()
{
Robot::binRetrieval -> StopBoth();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void BinRetrievalRaiseRightAuton::Interrupted()
{
End();
}
