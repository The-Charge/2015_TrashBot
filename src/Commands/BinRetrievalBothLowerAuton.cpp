#include "BinRetrievalBothLowerAuton.h"
#include "../Robot.h"
BinRetrievalBothLowerAuton::BinRetrievalBothLowerAuton(float t)
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires (Robot:: binRetrieval);
	timeout = t;
}

// Called just before this Command runs the first time
void BinRetrievalBothLowerAuton::Initialize()
{
this -> SetTimeout(timeout);
}

// Called repeatedly when this Command is scheduled to run
void BinRetrievalBothLowerAuton::Execute()
{
Robot::binRetrieval -> LowerBoth();
}

// Make this return true when this Command no longer needs to run execute()
bool BinRetrievalBothLowerAuton::IsFinished()
{
	return this -> IsTimedOut();
}

// Called once after isFinished returns true
void BinRetrievalBothLowerAuton::End()
{
Robot::binRetrieval -> StopBoth();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void BinRetrievalBothLowerAuton::Interrupted()
{
End();
}
