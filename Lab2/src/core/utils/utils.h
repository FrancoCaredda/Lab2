#ifndef UTILS_H
#define UTILS_H

#include <cmath>
#include <glm/glm.hpp>

#define EPSILON 1e-5
#define LESS_OR_EQUAL(X, Y) (  ((X) < (Y)) || ( fabs((X) - (Y)) < EPSILON )  )
#define GREATER_OR_EQUAL(X, Y) (  ((X) > (Y)) || ( fabs((X) - (Y)) < EPSILON )  )

namespace Utils
{
	using Color3f = float[3];

	static const float PI = acos(-1);
	
	float AngleToRad(float angle);
	/// <summary>
	/// Applies basic rotation transformation
	/// </summary>
	glm::vec2 RotatePoint2d(float angle, const glm::vec2& point);
}

#endif // !UTILS_H

