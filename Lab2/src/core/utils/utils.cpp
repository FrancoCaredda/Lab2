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

void Utils::HSLToRGB(Color3f inHSL, Color3f outRGB) noexcept
{
    float light = CalculatePercentValue(inHSL[2], 1.0f);
    float saturation = CalculatePercentValue(inHSL[1], 1.0f);

    float h = inHSL[0] / 60.0f;
    float c = (1.0f - fabs(2.0f * light - 1.0f)) * saturation;
    float x = c * (1.0f - ((int)fabs(h) % 2) - 1.0f);
    float m = light - c / 2.0;

    if (GREATER_OR_EQUAL(h, 0.0f) && h < 1.0f)
    {
        outRGB[0] = c;
        outRGB[1] = x;
        outRGB[2] = 0;
    }
    else if (GREATER_OR_EQUAL(h, 1.0f) && h < 2.0f)
    {
        outRGB[0] = x;
        outRGB[1] = c;
        outRGB[2] = 0;
    }
    else if (GREATER_OR_EQUAL(h, 2.0f) && h < 3.0f)
    {
        outRGB[0] = 0;
        outRGB[1] = c;
        outRGB[2] = x;
    }
    else if (GREATER_OR_EQUAL(h, 3.0f) && h < 4.0f)
    {

        outRGB[0] = 0;
        outRGB[1] = x;
        outRGB[2] = c;
    }
    else if (GREATER_OR_EQUAL(h, 4.0f) && h < 5.0f)
    {
        outRGB[0] = x;
        outRGB[1] = 0;
        outRGB[2] = c;
    }
    else if (GREATER_OR_EQUAL(h, 5.0f) && h < 6.0f)
    {
        outRGB[0] = c;
        outRGB[1] = 0;
        outRGB[2] = x;
    }
    else
    {
        outRGB[0] = outRGB[1] = outRGB[2] = 0;
    }

    outRGB[0] += m;
    outRGB[1] += m;
    outRGB[2] += m;
}

float Utils::CalculatePercentValue(float percentValue, float value) noexcept
{
    return value * percentValue / 100.0f;
}
