#include "ZN_PIDTune.h"
#include <cmath>

 float* PIDTuner(float Ku, float Tu){
	 float* TPID = new float[3];

	 //Creates the p value for the PID controller
	 TPID[0] = (Ku/3.0);

	 //Creates the i value for the PID controller
	 TPID[1] = ((2.0 * TPID[0])/Tu);

	 //Creates the d value for the PID controller
	 TPID[2] = ((TPID[0] * Tu) / 3.0);

	 return TPID;
 }

/**
 * TODO:
 * 1) Add other Control Types
 * 2) Add control type table
 * 3) Write procedure for finding Ku and Tu
 * -----------------------------------------------
 *
 * What's going on:
 * ---------------------------------------------------------------------------------------------------
 * link to table and what we discovered: https://en.wikipedia.org/wiki/Ziegler%E2%80%93Nichols_method
 * ---------------------------------------------------------------------------------------------------
 * We plan to use this tunning method for the PID Controller for more accurate placement of the robot
 *
 * Legend:
 * Ku - Ultimate Gain
 * Tu - Oscillation Period (at Ku)
 */

