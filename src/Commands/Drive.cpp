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

#include "c:/workspace/2015_trashbot/Util/RobotMath.h"

Drive::Drive() {
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
	Requires(Robot::driveTrain);

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
	SmartDashboard::PutNumber(DELINEARIZATION_POWER_DASHBOARD_KEY, DELINEARIZATION_POWER_DEFAULT);
	SmartDashboard::PutNumber(DELINEARIZATION_ALPHA_DASHBOARD_KEY, DELINEARIZATION_ALPHA_DEFAULT);
	SmartDashboard::PutNumber(JOYSTICK_DEADBAND_DASHBOARD_KEY, JOYSTICK_DEADBAND_DEFAULT);

	SmartDashboard::PutNumber(SCALEFACTOR_GYRO_DASHBOARD_KEY, SCALEFACTOR_DEFAULT);
	SmartDashboard::PutNumber(GAINFACTOR_GYRO_DASHBOARD_KEY, GAINFACTOR_DEFAULT);
}

// Called just before this Command runs the first time
void Drive::Initialize() {
	joystickDeadband = SmartDashboard::GetNumber(JOYSTICK_DEADBAND_DASHBOARD_KEY, JOYSTICK_DEADBAND_DEFAULT);

	ScaleFactor = SmartDashboard::GetNumber(SCALEFACTOR_GYRO_DASHBOARD_KEY, SCALEFACTOR_DEFAULT);
	GainFactor = SmartDashboard::GetNumber(GAINFACTOR_GYRO_DASHBOARD_KEY, GAINFACTOR_DEFAULT);

	delinearizationPower = SmartDashboard::GetNumber(DELINEARIZATION_POWER_DASHBOARD_KEY, DELINEARIZATION_POWER_DEFAULT);
	delinearizationAlpha = SmartDashboard::GetNumber(DELINEARIZATION_ALPHA_DASHBOARD_KEY, DELINEARIZATION_ALPHA_DEFAULT);


}
/*
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

}*/
// Called repeatedly when this Command is scheduled to run
void Drive::Execute() {

	float x = Robot::oi->getJoystick1()->GetX();
	float y = Robot::oi->getJoystick1()->GetY();
	float z = Robot::oi->getJoystick1()->GetZ();


	// creates a smartdashboard value to see what the gyro value for its angle and rate
		float GetTheGyroAngle = Robot::driveTrain -> GetGyroAngle(); //gets the value from the float in the driveTrain.cpp
		double GetTheGyroRate = Robot::driveTrain -> GetGyroRate(); //gets the value from the double in the driveTrain.cpp
	// Puts values on the smartdashboard

		SmartDashboard::PutNumber("The Gyro Rate", GetTheGyroRate);
		SmartDashboard::PutNumber("The Gyro Angle", GetTheGyroAngle);

/*
		x = delinearize(x,alpha);
		y = delinearize(y,alpha);
		z = delinearize(z,alpha);



		x = deadband(x,db);
		y = deadband(y,db);
		z = deadband(z, db);
*/
		x = RobotMath::deadband(x,joystickDeadband);
			y = RobotMath::deadband(y,joystickDeadband);
			z = RobotMath::deadband(z,joystickDeadband);


			// delinearizes the analog input so it isn't as sensitive when the driver is driving
			// allows for testing different powers to see smoothest performance

			x = RobotMath::delinearize(x,delinearizationAlpha ,(int)delinearizationPower);
			y = RobotMath::delinearize(y,delinearizationAlpha ,(int)delinearizationPower);
			z = RobotMath::delinearize(z,delinearizationAlpha ,(int)delinearizationPower);

			if (Robot:: oi -> getJoystick1() -> GetRawButton(4)) // if the button is held
			{ y = 0; z = 0; } // allows only the x value to pass


			float Gyro_Correction = -1 * GetTheGyroRate;

			//both of these methods return an integer
			//these must be sent to the smart dashboard
			//these should go into the drive command


			//Left Side
			int LeftFrontEncPos = RobotMap::driveTrainCANTalonLeftFront -> GetEncPosition();
			int LeftFrontEncVel = RobotMap::driveTrainCANTalonLeftFront -> GetEncVel();

			int LeftRearEncPos =  RobotMap::driveTrainCANTalonLeftRear -> GetEncPosition();
			int LeftRearEncVel = RobotMap::driveTrainCANTalonLeftRear -> GetEncVel();

			//Right Side
			int RightFrontEncPos = RobotMap::driveTrainCANTalonRightFront -> GetEncPosition();
			int RightFrontEncVel = RobotMap::driveTrainCANTalonRightFront -> GetEncVel();

			int RightRearEncPos = RobotMap::driveTrainCANTalonRightRear -> GetEncPosition();
			int RightRearEncVel = RobotMap::driveTrainCANTalonRightRear -> GetEncVel();

			SmartDashboard::PutNumber("Left Front Encoder Postition", LeftFrontEncPos);
			SmartDashboard::PutNumber("Left Front Encoder Velocity", LeftFrontEncVel);

			SmartDashboard::PutNumber("Left Rear Encoder Postition", LeftRearEncPos);
			SmartDashboard::PutNumber("Left Rear Encoder Velocity", LeftRearEncVel);

			SmartDashboard::PutNumber("Right Front Encoder Postition", RightFrontEncPos);
			SmartDashboard::PutNumber("Right Front Encoder Velocity", RightFrontEncVel);

			SmartDashboard::PutNumber("Right Rear Encoder Postition", RightRearEncPos);
			SmartDashboard::PutNumber("Right Rear Encoder Velocity", RightRearEncVel);

		Robot::driveTrain->drive(x, y, z/3); // z/3 to reduce the speed for more precision while driving
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
