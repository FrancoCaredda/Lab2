#include "Circle.h"

#include <GL/freeglut.h>

#include "../utils/utils.h"

#include <iostream>

void Circle::SetColor(float r, float g, float b) noexcept
{
	m_Red = r;
	m_Green = g;
	m_Blue = b;

	UpdateColorBuffer();
}

void Circle::GetColor(float& r, float& g, float& b) const noexcept
{
	r = m_Red;
	g = m_Green;
	b = m_Blue;
}

void Circle::GetCenter(float& x, float& y) const noexcept
{
	x = m_X;
	y = m_Y;
}

void Circle::Generate()
{
	int vertexComponents = 5;
	m_BufferSize = vertexComponents * m_Angles;
	m_Buffer = new float[m_BufferSize];

	float currentAngle = 0;
	float angleIncrement = 360.0f / m_Angles;

	for (int i = 0; i < m_Angles; i++)
	{
		int currentPosition = i * vertexComponents;
		float x = 0;
		float y = m_Radius;

		Utils::RotatePoint2d(Utils::AngleToRad(currentAngle), x, y);
		
		m_Buffer[currentPosition] = x + m_X;
		m_Buffer[currentPosition + 1] = y + m_Y;

		m_Buffer[currentPosition + 2] = m_Red;
		m_Buffer[currentPosition + 3] = m_Green;
		m_Buffer[currentPosition + 4] = m_Blue;

		currentAngle += angleIncrement;
	}
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

void Circle::UpdateColorBuffer() noexcept
{
	int vertexComponents = 5;
	for (int i = 0; i < m_Angles; i++)
	{
		int currentVertexPosition = i * vertexComponents;

		m_Buffer[currentVertexPosition + 2] = m_Red;
		m_Buffer[currentVertexPosition + 3] = m_Green;
		m_Buffer[currentVertexPosition + 4] = m_Blue;
	}
}
