#include "utils.h"

float Utils::AngleToRad(float angle)
{
    return angle * PI / 180.0f;
}

glm::vec2 Utils::RotatePoint2d(float angle, const glm::vec2& point)
{
    return glm::vec2({
         point.x *  cos(angle) + point.y * sin(angle),
         -point.x * sin(angle) + point.y * cos(angle)
    });
}
