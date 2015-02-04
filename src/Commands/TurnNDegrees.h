// RobotBuilder Version: 1.5
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#ifndef TURNNDEGREES_H
#define TURNNDEGREES_H


#include "Commands/Subsystem.h"
#include "../Robot.h"

/**
 *
 *
 * @author ExampleAuthor
 */
class TurnNDegrees: public Command {
public:
	float startAngle;
	float DegreestoTurn(float, float);
	float degreesturning;
	float finalAngle = degreesturning + startAngle;
	float d;
	float speed;

	float angleAt;

	const float TURNING_DEFAULT = 90;
	const float TURNING_SPEED_DEFAULT = .25;

	const std::string ANGLE_TO_TURN = "Degrees Wanted to Turn: ";
	const std::string TURNING_SPEED = "Speed to turn (Positive): ";

	TurnNDegrees(float = 0);
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
