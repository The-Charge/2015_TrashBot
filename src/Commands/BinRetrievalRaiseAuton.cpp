#include "BinRetrievalRaiseAuton.h"
#include "../Robot.h"

BinRetrievalRaiseAuton::BinRetrievalRaiseAuton(int t)
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires (Robot::binRetrieval);
	timetorun = t;
}

// Called just before this Command runs the first time
void BinRetrievalRaiseAuton::Initialize()
{
this -> SetTimeout(timetorun);
}

// Called repeatedly when this Command is scheduled to run
void BinRetrievalRaiseAuton::Execute()
{
Robot::binRetrieval -> Raise();
}

// Make this return true when this Command no longer needs to run execute()
bool BinRetrievalRaiseAuton::IsFinished()
{
	return this -> IsTimedOut();
}

// Called once after isFinished returns true
void BinRetrievalRaiseAuton::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void BinRetrievalRaiseAuton::Interrupted()
{

}
