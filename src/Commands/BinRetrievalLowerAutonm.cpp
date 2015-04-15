#include "BinRetrievalLowerAutonm.h"
#include "../Robot.h"

BinRetrievalLowerAutonm::BinRetrievalLowerAutonm(int t)
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(Robot::binRetrieval);
	timetorun = t;
}

// Called just before this Command runs the first time
void BinRetrievalLowerAutonm::Initialize()
{
this -> SetTimeout(timetorun);
}

// Called repeatedly when this Command is scheduled to run
void BinRetrievalLowerAutonm::Execute()
{
Robot::binRetrieval->LowerLeft();
}

// Make this return true when this Command no longer needs to run execute()
bool BinRetrievalLowerAutonm::IsFinished()
{
	return this->IsTimedOut();
}

// Called once after isFinished returns true
void BinRetrievalLowerAutonm::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void BinRetrievalLowerAutonm::Interrupted()
{

}
