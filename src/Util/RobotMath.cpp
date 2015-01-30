#include "RobotMath.h"
#include <cmath>

float RobotMath::delinearize(float input, float alpha)
{
  return RobotMath::delinearize(input, alpha, 3);
}

float RobotMath::delinearize(float input, float alpha, int power)
{
  return (alpha * pow(input, power)) + ((1-alpha) * input);
}

float RobotMath::deadband(float input, float band)
{
  return (std::abs(input) > std::abs(band)) ? input : 0;
}
