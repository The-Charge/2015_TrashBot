// RobotBuilder Version: 1.5
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#ifndef WINCHPOSITIONSELECTOR_H
#define WINCHPOSITIONSELECTOR_H


#include "Commands/Subsystem.h"
#include "../Robot.h"

/**
 *
 *
 * @author ExampleAuthor
 */
class WinchPositionSelector: public Command {
public:

	// values that retrive ouput from button box to set the setpoint
	bool winchPosH = Robot::oi->getButtonBox()->GetRawButton(9);
	bool winchPosM = Robot::oi->getButtonBox()->GetRawButton(10);
	bool winchPosL = Robot::oi->getButtonBox()->GetRawButton(11);

	// value from winch subsystem
	int winchCurrentPos = Robot::winchSystem->Winch_Position;

	WinchPositionSelector();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
