#include "Circle.h"

#include <GL/freeglut.h>

#include "../utils/utils.h"

#include <iostream>

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
		
		m_Buffer[currentPosition] = x;
		m_Buffer[currentPosition + 1] = y;

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
