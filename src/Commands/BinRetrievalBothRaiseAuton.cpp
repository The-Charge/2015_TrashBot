#include "BinRetrievalBothRaiseAuton.h"
#include "../Robot.h"

BinRetrievalBothRaiseAuton::BinRetrievalBothRaiseAuton(float t)
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires (Robot::binRetrieval);
	timeout = t;

}

// Called just before this Command runs the first time
void BinRetrievalBothRaiseAuton::Initialize()
{
this -> SetTimeout(timeout);
}

// Called repeatedly when this Command is scheduled to run
void BinRetrievalBothRaiseAuton::Execute()
{
Robot::binRetrieval -> RaiseBoth();
}

// Make this return true when this Command no longer needs to run execute()
bool BinRetrievalBothRaiseAuton::IsFinished()
{
	return this -> IsTimedOut();
}

// Called once after isFinished returns true
void BinRetrievalBothRaiseAuton::End()
{
Robot::binRetrieval -> StopBoth();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void BinRetrievalBothRaiseAuton::Interrupted()
{
End();
}
