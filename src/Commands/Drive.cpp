// RobotBuilder Version: 1.5
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#include "Drive.h"

Drive::Drive() {
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
	Requires(Robot::driveTrain);

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
}

// Called just before this Command runs the first time
void Drive::Initialize() {
	
}
float Drive::delinearize(float input, float alpha) {

	input = (alpha * input * input * input) + ((1 - alpha) * input); // to make the turns run more smoothly.
	return input;

}
float Drive::deadband(float input, float db){
// deadband to control the sensitivity of the controller/joystick
	if ((input > db) || (input < -db)){//checks for the input's position on the controller.
		input = input * 1;

	}
	else{ // if within the deadband.
		input = 0;
	}
	return input;

}
// Called repeatedly when this Command is scheduled to run
void Drive::Execute() {
	float x = Robot::oi->getJoystick1()->GetX();
		float y = Robot::oi->getJoystick1()->GetY();
		float z = Robot::oi->getJoystick1()->GetZ();

		float alpha = Robot::oi->getJoystick1()->GetThrottle();
		float db = 0.2;

	// creats a smartdashboard value to see what the gyro value for its angle and rate
		//float GetTheGyroAngle = Robot::driveTrain->GetGyroAngle(); //gets the value from the float in the driveTrain.cpp
		//double GetTheGyroRate = Robot::driveTrain->GetGyroRate(); //gets the value from the double in the driveTrain.cpp
	// Puts values on the smartdashboard
		//SmartDashboard::PutNumber("The Gyro Rate", GetTheGyroRate);
		//SmartDashboard::PutNumber("The Gyro Angle",GetTheGyroAngle);

		x = delinearize(x,alpha);
		y = delinearize(y,alpha);
		z = delinearize(z,alpha);

		x = deadband(x,db);
		y = deadband(y,db);
		z = deadband(z, db);

		Robot::driveTrain->drive(x,y,z);
}

// Make this return true when this Command no longer needs to run execute()
bool Drive::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void Drive::End() {
	
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void Drive::Interrupted() {

}
