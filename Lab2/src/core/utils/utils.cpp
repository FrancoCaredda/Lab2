#include "utils.h"

float Utils::AngleToRad(float angle)
{
    return angle * PI / 180.0f;
}

void Utils::RotatePoint2d(float angle, float& x, float& y)
{
    float tempX = x;
    float tempY = y;

    x = tempX * cos(angle) + y * sin(angle);
    y = -tempX * sin(angle) + y * cos(angle);
}
