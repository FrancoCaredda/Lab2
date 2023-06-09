#ifndef CIRCLE_H
#define CIRCLE_H

#include "IShape.h"

#include <cstdint>

/// <summary>
/// The class circle is an approximated rapresentation of a circe
/// </summary>
class Circle : public IShape
{
public:
	Circle() = default;
	Circle(uint32_t angles, float radius, float x, float y, float red, float green, float blue) : 
		m_Angles(angles), m_Radius(radius), 
		m_X(x), m_Y(y),
		m_Red(red), m_Green(green), m_Blue(blue) {}

	void SetColor(float r, float g, float b) noexcept;
	void GetColor(float& r, float& g, float& b) const noexcept;

	void GetCenter(float& x, float& y) const noexcept;

	inline float* GetBuffer() const noexcept { return m_Buffer; }
	inline uint32_t GetVertexCount() const noexcept { return m_Angles; }

	// Inherited via IShape
	virtual void Generate() override;
	virtual void Bind() override;

	virtual ~Circle() override;
private:
	void UpdateColorBuffer() noexcept;
private:
	uint32_t m_Angles = 10;
	float m_Radius = 5;
	float m_Red = 1.0, m_Green = 1.0, m_Blue = 1.0;
	float m_X, m_Y;

	float* m_Buffer = nullptr;
	size_t m_BufferSize = 0;
};


#endif // !CIRCLE_H