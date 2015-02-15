// RobotBuilder Version: 1.5
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.

#include "Robot.h"
#include "Commands/AutonomousStrategyPush.h"
#include "Commands/AutonomousStrategy2.h"

#include <CameraServer.h>
#include <Commands/Scheduler.h>
#include <DriverStation.h>
#include <nivision.h>
#include <NIIMAQdx.h>
#include <RobotBase.h>
#include <string>

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INITIALIZATION
DriveTrain* Robot::driveTrain = 0;
Compressor1* Robot::compressor1 = 0;
Lift* Robot::lift = 0;
Arms* Robot::arms = 0;
OI* Robot::oi = 0;

// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INITIALIZATION
IMAQdxSession session;
Image *frame;
IMAQdxError imaqError;
AxisCamera *camera;

SendableChooser*chooser;
//SendableChooser* driveMode;

void Robot::RobotInit() {
	RobotMap::init();
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
	driveTrain = new DriveTrain();
	compressor1 = new Compressor1();
	lift = new Lift();
	arms = new Arms();

	// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
	frame = imaqCreateImage(IMAQ_IMAGE_RGB, 0);
	frame = imaqCreateImage(IMAQ_IMAGE_RGB, 0);
	camera = new AxisCamera("10.26.19.12");
	camera = new AxisCamera("10.26.19.11");

	// This MUST be here. If the OI creates Commands (which it very likely
	// will), constructing it during the construction of CommandBase (from
	// which commands extend), subsystems are not guaranteed to be
	// yet. Thus, their requires() statements may grab null pointers. Bad
	// news. Don't move it.
	oi = new OI();
	lw = LiveWindow::GetInstance();

	// instantiate the command used for the autonomous period
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=AUTONOMOUS
	autonomousCommand = new AutonomousCommand();

	// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=AUTONOMOUS

	//driveMode = new
	chooser = new SendableChooser();
	chooser->AddDefault("Default/Autonomous Push Strategy",
			(new AutonomousStrategyPush()));
	chooser->AddObject("Autonomous Strategy 2", new AutonomousStrategy2());

}

/**
 * This function is called when the disabled button is hit.
 * You can use it to reset subsystems before shutting down.
 */
void Robot::DisabledInit() {

}

void Robot::DisabledPeriodic() {
	Scheduler::GetInstance()->Run();
}

void Robot::AutonomousInit() {
	autonomousCommandGroup = (CommandGroup *) chooser->GetSelected();
	if (autonomousCommandGroup != NULL)
		autonomousCommandGroup->Start();
}

void Robot::AutonomousPeriodic() {
	Scheduler::GetInstance()->Run();
}

void Robot::TeleopInit() {
	// This makes sure that the autonomous stops running when
	// teleop starts running. If you want the autonomous to 
	// continue until interrupted by another command, remove
	// these lines or comment it out.
	if (autonomousCommandGroup != NULL)
		autonomousCommandGroup->Cancel();
}

void Robot::TeleopPeriodic() {
	Scheduler::GetInstance()->Run();
	camera->GetImage(frame);
	CameraServer::GetInstance()->SetImage(frame);
}

void Robot::TestPeriodic() {
	lw->Run();
}

START_ROBOT_CLASS(Robot);

