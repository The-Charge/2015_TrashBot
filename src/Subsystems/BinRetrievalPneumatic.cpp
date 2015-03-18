#include "BinRetrievalPneumatic.h"
#include "../RobotMap.h"

BinRetrievalPneumatic::BinRetrievalPneumatic() :
		Subsystem("BinRetrievalPneumatic")
{
solenoid1 = RobotMap::binRetrievalSolenoid;
}

void BinRetrievalPneumatic::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
}


void BinRetrievalPneumatic:: Lower()
{
	solenoid1 -> Set(DoubleSolenoid::kForward);
}

void BinRetrievalPneumatic::Raise()
{
	solenoid1 -> Set(DoubleSolenoid::kReverse);
}
// Put methods for controlling this subsystem
// here. Call these from Commands.
