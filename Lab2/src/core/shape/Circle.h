#ifndef CIRCLE_H
#define CIRCLE_H

#include "IShape.h"

#include <cstdint>
#include <glm/glm.hpp>

/// <summary>
/// The class circle is an approximated rapresentation of a circe
/// </summary>
class Circle : public IShape
{
public:
	Circle() = default;
	Circle(uint32_t angles, float radius, glm::vec2 center, glm::vec3 color) :
		m_Angles(angles), m_Radius(radius),
		m_Center(center),
		m_Color(color) {}

	void SetColor(const glm::vec3& color) noexcept;
	void SetCenter(const glm::vec2& center) noexcept;
	
	inline glm::vec3 GetColor() const noexcept { return m_Color; }
	inline glm::vec2 GetCenter() const noexcept { return m_Center; }

	inline float* GetBuffer() const noexcept { return m_Buffer; }
	inline uint32_t GetVertexCount() const noexcept { return m_Angles; }

	// Inherited via IShape
	virtual void Generate() override;
	virtual void Bind() override;

	virtual ~Circle() override;
private:
	void RecalculateBuffer() noexcept;
	void UpdateColorBuffer() noexcept;
	void UpdateVertexBuffer() noexcept;
private:
	uint32_t m_Angles = 10;
	float m_Radius = 5;
	glm::vec3 m_Color;
	glm::vec2 m_Center;

	float* m_Buffer = nullptr;
	size_t m_BufferSize = 0;
};


#endif // !CIRCLE_H