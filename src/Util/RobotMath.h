#ifndef _ROBOT_MATH_H_
#define _ROBOT_MATH_H_

class RobotMath {
public:
	static float delinearize(float input, float alpha);
	static float delinearize(float input, float alpha, int power);
	static float deadband(float input, float band);
};

#endif
