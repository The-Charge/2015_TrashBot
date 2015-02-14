#include "Trashbin_Auton.h"

#include "DriveXFeet.h"
#include "StrafeXFeet.h"
Trashbin_Auton::Trashbin_Auton()
{



	//time outs & flip

	AddSequential(new DriveXFeet(-2.15833));
	AddSequential(new WinchOut());
	SetTimeout(10);//test
	AddSequential(new StrafeXFeet(1));
	AddSequential(new WinchIn());
	SetTimeout(10);//test
	AddSequential(new StrafeXFeet(-1));
	AddSequential(new DriveXFeet(-5.725));
	AddSequential(new WinchOut());
	SetTimeout(10);//test
	AddSequential(new StrafeXFeet(1));
	AddSequential(new WinchIn());
	AddSequential(new StrafeXFeet(-1));
	SetTimeout(10);//test

	AddSequential(new DriveXFeet(-8.1083));
	AddSequential(new WinchOut());
	SetTimeout(10);//test
	AddSequential(new StrafeXFeet(1));
	AddSequential(new WinchIn());
	SetTimeout(10);//test
	AddSequential(new StrafeXFeet(-1));
	AddSequential(new DriveXFeet(-5.725));
	AddSequential(new WinchOut());
	SetTimeout(10);//test
	AddSequential(new StrafeXFeet(1));
	AddSequential(new WinchIn());
	SetTimeout(10);//test
	AddSequential(new StrafeXFeet(-1));

}
