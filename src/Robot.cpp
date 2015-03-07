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
#define VERBOSE_DASHBOARD
#include <CameraServer.h>
#include <Commands/Scheduler.h>
#include <DriverStation.h>
#include <nivision.h>
#include <NIIMAQdx.h>
#include <RobotBase.h>
#include <string>
#include "Commands/AutonOneTote.h"
#include "Commands/Auton2HardYellowTotes.h"
#include "Commands/Auton3TotesStack.h"
#include "Commands/AutonStrategyPush.h"
#include "Commands/AutonOneTote.h"
#include "Commands/GreenBinsAuto.h"
#include "Commands/AutonPushOverScoringPlatform.h"
#include "Commands/DelayCommand.h"

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
	camera->WriteMaxFPS(15);
	camera->WriteResolution(AxisCamera::kResolution_320x240);
	camera->WriteCompression(70);
	camera = new AxisCamera("10.26.19.11");
	camera->WriteMaxFPS(15);
	camera->WriteResolution(AxisCamera::kResolution_320x240);
	camera->WriteCompression(70);

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

	//Autonomus Mode Sendable Chooser
	sc = new SendableChooser();
	sc -> AddDefault ("AutonDrive", new AutonStrategyPush());
	sc -> AddObject ("DoNothing", new DelayCommand(15));
	sc -> AddObject ("AutonDriveOver", new AutonPushOverScoringPlatform);
	sc -> AddObject ("PushGreenBins", new GreenBinsAuto());
	sc -> AddObject ("Auton2HardYellowTotes", new Auton2HardYellowTotes());
	sc -> AddObject ("Auton3ToteStack", new Auton3TotesStack());
	sc -> AddObject("Auton1ToteStack", new AutonOneTote());
	SmartDashboard::PutData ("Auton Mode Chooser", sc);
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
	autonomousCommandGroup = (CommandGroup *) sc->GetSelected();
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
	SmartDashboard::PutData("schedulder", Scheduler::GetInstance());

}

void Robot::TeleopPeriodic() {
	Scheduler::GetInstance()->Run();

	//camera->GetImage(frame);
//	CameraServer::GetInstance()->SetImage(frame);
}

void Robot::TestPeriodic() {
	lw->Run();
}

START_ROBOT_CLASS(Robot);

