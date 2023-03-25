#ifndef UTILS_H
#define UTILS_H

#include <cmath>

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
	/// <param name="angle">: must be in radians</param>
	/// <param name="x"></param>
	/// <param name="y"></param>
	void RotatePoint2d(float angle, float& x, float& y);
	void HSLToRGB(Color3f inHSL, Color3f outRGB) noexcept;

	inline float CalculatePercentValue(float percentValue, float value) noexcept;
}

#endif // !UTILS_H

