// RobotBuilder Version: 1.5
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#include "Drive2Feet.h"
#include "../Util/PIDCanTalon.h"

Drive2Feet::Drive2Feet() {
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
	Requires(Robot::driveTrain);

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
	p = 0;
	TICKS_NEEDED = Robot::driveTrain->ENCODER_TICKS_PER_REVOLUTION * 2;//Robot:: driveTrain -> WHEELROTATIONS_PER_FOOT * 20 * Robot::driveTrain -> ENCODER_TICKS_PER_REVOLUTION;
	SmartDashboard:: PutNumber ("Ticks Needed", TICKS_NEEDED);
	SmartDashboard::PutNumber("Max Voltage", .5);
	SmartDashboard::PutNumber("Integral constant" , .00);
	SmartDashboard::PutNumber("Closed loop ramp rate" , .00);
	SmartDashboard::PutNumber(PROPORTIONAL_CONSTANT_DASHBOARD_KEY , p_default);
	SmartDashboard:: PutNumber("Closed Loop Error:",0);
	SmartDashboard :: PutNumber (" Encoder Position", 0);
}

// Called just before this Command runs the first time
void Drive2Feet::Initialize() {
	p = SmartDashboard::GetNumber(PROPORTIONAL_CONSTANT_DASHBOARD_KEY , p_default);
	float i = SmartDashboard::GetNumber("Integral constant" , .00);
	float rampRate = SmartDashboard::GetNumber("Closed loop ramp rate" , 6);
	this -> SetTimeout(10);
	float maxvoltage = SmartDashboard::GetNumber("Max Voltage", .5);

	Robot::driveTrain -> EncoderReset();

	/*
	//Change the mode to position instead of percent:
	Robot:: driveTrain -> CANTalonLeftFront -> SetControlMode(CANTalon::kPosition);
	Robot::driveTrain -> CANTalonLeftRear -> SetControlMode(CANTalon::kPosition);
	Robot:: driveTrain -> CANTalonRightFront -> SetControlMode(CANTalon::kPosition);
	Robot::driveTrain -> CANTalonRightRear -> SetControlMode(CANTalon::kPosition);

	//You need to immediately set the position to 0:
	Robot::driveTrain->CANTalonLeftFront->Set(0);
	Robot::driveTrain->CANTalonLeftRear->Set(0);
	Robot::driveTrain->CANTalonRightFront->Set(0);
	Robot::driveTrain->CANTalonRightRear->Set(0);

	Robot:: driveTrain -> CANTalonLeftFront -> ConfigMaxOutputVoltage(maxvoltage);
		Robot:: driveTrain -> CANTalonLeftRear -> ConfigMaxOutputVoltage(maxvoltage);
		Robot:: driveTrain -> CANTalonRightFront -> ConfigMaxOutputVoltage(maxvoltage);
		Robot:: driveTrain -> CANTalonRightRear -> ConfigMaxOutputVoltage(maxvoltage);

	Robot:: driveTrain -> CANTalonLeftFront -> SetPID(p, i, 0);
	Robot:: driveTrain -> CANTalonLeftRear -> SetPID(p, i, 0);
	Robot:: driveTrain -> CANTalonRightFront -> SetPID(p, i, 0);
	Robot:: driveTrain -> CANTalonRightRear -> SetPID(p, i, 0);

	//Robot::driveTrain->CANTalonRightFront->SetCloseLoopRampRate(rampRate);
	Robot::driveTrain->CANTalonLeftFront->SetVoltageRampRate(rampRate);
	Robot::driveTrain->CANTalonRightFront->SetVoltageRampRate(rampRate);
	Robot::driveTrain->CANTalonLeftRear->SetVoltageRampRate(rampRate);
	Robot::driveTrain->CANTalonRightRear->SetVoltageRampRate(rampRate);


	Robot:: driveTrain -> CANTalonLeftFront -> Set(TICKS_NEEDED);
	Robot:: driveTrain -> CANTalonLeftRear -> Set(TICKS_NEEDED);
	Robot:: driveTrain -> CANTalonRightFront -> Set(-TICKS_NEEDED);
	Robot:: driveTrain -> CANTalonRightRear -> Set(-TICKS_NEEDED);
	*/

	PIDCanTalon *frontLeftPIDCanTalon;
	frontLeftPIDCanTalon = new PIDCanTalon(Robot::driveTrain -> CANTalonLeftFront);
	Robot::driveTrain->CANTalonLeftFront->SetSensorDirection(true);
	frontLeftPIDController = new PIDController(p, i, 0, frontLeftPIDCanTalon, Robot::driveTrain -> CANTalonLeftFront);
	frontLeftPIDController -> SetOutputRange(-1 * maxvoltage, maxvoltage);
	frontLeftPIDController -> SetSetpoint(TICKS_NEEDED);
	frontLeftPIDController -> SetAbsoluteTolerance(100);
	frontLeftPIDController -> Enable();

}

// Called repeatedly when this Command is scheduled to run
void Drive2Feet::Execute() {
	SmartDashboard:: PutNumber("Closed Loop Error:",frontLeftPIDController->GetError());
	SmartDashboard :: PutNumber (" Encoder Position", Robot:: driveTrain -> CANTalonLeftFront -> GetEncPosition());
}

// Make this return true when this Command no longer needs to run execute()
bool Drive2Feet::IsFinished() {
	/*float ticksrf = Robot:: driveTrain -> CANTalonRightFront -> GetEncPosition();
	float ticksrr = Robot:: driveTrain -> CANTalonRightRear -> GetEncPosition();

	float tickslr = Robot:: driveTrain -> CANTalonLeftRear -> GetEncPosition();
	float tickslf = Robot:: driveTrain -> CANTalonLeftFront -> GetEncPosition();


	//float average_ticks = (ticksrf + ticksrr + tickslf + tickslr )/4;
	//if (ticksrf >= TICKS_NEEDED || this -> IsTimedOut()) return true;
	//return this->IsTimedOut();
	return false;
	//else return false;
	 * */

	 return frontLeftPIDController->OnTarget();
}

// Called once after isFinished returns true
void Drive2Feet::End() {
		frontLeftPIDController->Disable();

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void Drive2Feet::Interrupted() {
	End();
}
