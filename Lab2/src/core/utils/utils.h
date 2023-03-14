#ifndef UTILS_H
#define UTILS_H

#include <cmath>

namespace Utils
{
	static const float PI = acos(-1);

	float AngleToRad(float angle);

	/// <summary>
	/// Applies basic rotation transformation
	/// </summary>
	/// <param name="angle">: must be in radians</param>
	/// <param name="x"></param>
	/// <param name="y"></param>
	void RotatePoint2d(float angle, float& x, float& y);
}

#endif // !UTILS_H

