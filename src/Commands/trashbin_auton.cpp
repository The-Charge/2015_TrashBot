#include "trashbin_auton.h"

#include "DriveXFeet.h"
#include "StrafeXFeet.h"
trashbin_auton::trashbin_auton()
{


	//time outs & flip
	AddSequential(new DriveXFeet(-2.15833));
	//add method for drop down of back arm
	AddSequential(new StrafeXFeet(1));
	//add arm up method
	AddSequential(new StrafeXFeet(-1));
	AddSequential(new DriveXFeet(-5.725));
	//add method for drop down of back arm
	AddSequential(new StrafeXFeet(1));
	//add arm up method
	AddSequential(new StrafeXFeet(-1));

	AddSequential(new DriveXFeet(-8.1083));
	//add method for drop down of back arm
	AddSequential(new StrafeXFeet(1));
	//add arm up method
	AddSequential(new StrafeXFeet(-1));
	AddSequential(new DriveXFeet(-5.725));
	//add method for drop down of back arm
	AddSequential(new StrafeXFeet(1));
	//add arm up method
	AddSequential(new StrafeXFeet(-1));

}
