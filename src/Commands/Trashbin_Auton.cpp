#include "Trashbin_Auton.h"

#include "DriveXFeet.h"
#include "StrafeXFeet.h"
#include "WinchIn.h"
#include "WinchOut.h"

Trashbin_Auton::Trashbin_Auton()
{

	AddSequential(new DriveXFeet(-2.15833));
	//AddSequential(new WinchOut());

	AddSequential(new StrafeXFeet(1));
	//AddSequential(new WinchIn());

	AddSequential(new StrafeXFeet(-1));
	AddSequential(new DriveXFeet(-5.725));
	//AddSequential(new WinchOut());

	AddSequential(new StrafeXFeet(1));
	//AddSequential(new WinchIn());
	AddSequential(new StrafeXFeet(-1));


	AddSequential(new DriveXFeet(-8.1083));
	//AddSequential(new WinchOut());

	AddSequential(new StrafeXFeet(1));
	//AddSequential(new WinchIn());

	AddSequential(new StrafeXFeet(-1));
	AddSequential(new DriveXFeet(-5.725));
	//AddSequential(new WinchOut());

	AddSequential(new StrafeXFeet(1));
	//AddSequential(new WinchIn());

	AddSequential(new StrafeXFeet(-1));

}
