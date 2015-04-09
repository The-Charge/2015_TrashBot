#include "DriveXFeetReeper.h"
#include "../RobotMap.h"

DriveXFeetReeper::DriveXFeetReeper(float f, float m)
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires (Robot::driveTrain);
	feet = f;
	maxpercent = m;
}

// Called just before this Command runs the first time
void DriveXFeetReeper::Initialize()
{
	this->SetTimeout(1);
				//(1.0069 * feet)  - (6 * maxpercent) + 1.7448);
		//8
		Robot::driveTrain->ResetDistance();
		Robot::driveTrain->SetDistanceInFeet(feet);
		Robot::driveTrain->SetPIDControllerOutputRange(maxpercent);
}

// Called repeatedly when this Command is scheduled to run
void DriveXFeetReeper::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool DriveXFeetReeper::IsFinished()
{
	return Robot::driveTrain -> AtDestination() || this -> IsTimedOut();
}

// Called once after isFinished returns true
void DriveXFeetReeper::End()
{
Robot::driveTrain-> Stop();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriveXFeetReeper::Interrupted()
{
End();
}
