// RobotBuilder Version: 1.5
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#ifndef WINCHOUT_H
#define WINCHOUT_H


#include "Commands/Subsystem.h"
#include "../Robot.h"


/**
 *
 *
 * @author ExampleAuthor
 */
class WinchOut: public Command {
public:
	float SP = 0; // to get the value sent to the command from auton or from Smartdashboard

	const std::string WINCH_TIMER_TIME_STRING = "Winch::Timer Countdown Out: ";
		double timerCountUp = 0;

	//Time needed to drive at 100% voltage/speed
		// These are constants for the setpoints based on position to setpoint
		// for the current command
	const float TIME_CONST_H2L = 1.5;
	const float TIME_CONST_H2M = 1.0;
	const float TIME_CONST_M2L = 0.5;
	//Motor Speed constant (including the +/-)
	const float MOTOR_SPEED = 0.5; // default motor speed for testing (may need to be changed from + to -)

	//Time needed to drive (actual time with speed correction)

	/*
	  adjusts the time needed to get to the desired setpoint
	 by dividing time from point to point by the motor speed
	 */
	const float MOVE_TIME_H2L = TIME_CONST_H2L/MOTOR_SPEED;
	const float MOVE_TIME_H2M = TIME_CONST_H2M/MOTOR_SPEED;
	const float MOVE_TIME_M2L = TIME_CONST_M2L/MOTOR_SPEED;


	WinchOut(float sp = 0); // default position given
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
