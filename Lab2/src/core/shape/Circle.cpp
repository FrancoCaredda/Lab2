#include "Circle.h"

#include <GL/freeglut.h>

#include "../utils/utils.h"

#include <iostream>

void Circle::SetColor(const glm::vec3& color) noexcept
{
	m_Color = color;
	RecalculateBuffer();
}

void Circle::SetCenter(const glm::vec2& center) noexcept
{
	m_Center = center;
	RecalculateBuffer();
}

void Circle::Generate()
{
	int vertexComponents = 5;
	m_BufferSize = vertexComponents * m_Angles;
	m_Buffer = new float[m_BufferSize];

	RecalculateBuffer();
}

void Circle::Bind()
{
	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_COLOR_ARRAY);

	glVertexPointer(2, GL_FLOAT, 5 * sizeof(float), m_Buffer);
	glColorPointer(3, GL_FLOAT, 5 * sizeof(float), &m_Buffer[2]);
}

Circle::~Circle()
{
	if (m_Buffer != nullptr)
	{
		delete[] m_Buffer;
	}
}

void Circle::RecalculateBuffer() noexcept
{
	int vertexComponents = 5;

	float currentAngle = 0;
	float angleIncrement = 360.0f / m_Angles;

	glm::vec2 point({ 0, m_Radius });
	for (int i = 0; i < m_Angles; i++)
	{
		int currentPosition = i * vertexComponents;

		glm::vec2 rotatedPoint = Utils::RotatePoint2d(Utils::AngleToRad(currentAngle), point);

		m_Buffer[currentPosition] = rotatedPoint.x + m_Center.x;
		m_Buffer[currentPosition + 1] = rotatedPoint.y + m_Center.y;

		m_Buffer[currentPosition + 2] = m_Color.x;
		m_Buffer[currentPosition + 3] = m_Color.y;
		m_Buffer[currentPosition + 4] = m_Color.z;

		currentAngle += angleIncrement;
	}
}