#include "MainWindow.h"
#include "core/utils/utils.h"

#include <iostream>


// TODO(Franco): REFACTOR
float offset = 0.0f;
float speed = 5.0f;

float colorSpeed = 0.2f;

float rotate = -180.0f;

// TODO(Franco): REFACTOR
void MainWindow::Update(float deltaTime)
{
	glClear(GL_COLOR_BUFFER_BIT);

	Utils::Color3f rgb = { 0, 1 * offset, 1 * offset };
	// COLOR
	{
		glClearColor(rgb[0], rgb[1], rgb[2], 1.0f);
	}

	// DRAWING
	{
		glMatrixMode(GL_MODELVIEW);
		glPushMatrix();

		rotate -= 3 * speed * deltaTime;

		glTranslatef(m_CenterX, m_CenterY, 0.0f);
		glRotatef(rotate, 0, 0, 1);
		glTranslatef(-m_CenterX, -m_CenterY, 0.0f);

		glTranslatef(m_ObjectCenterX, m_ObjectCenterY, 0.0f);
		glRotatef(1.5f*rotate, 0, 0, 1);
		glTranslatef(-m_ObjectCenterX, -m_ObjectCenterY, 0.0f);

		if (rotate < -360)
			rotate = 0;

		if (rotate > -180.0f)
		{
			if (offset > 0)
				offset -= colorSpeed * deltaTime;

			m_MoonCircle->Bind();
			glDrawArrays(GL_POLYGON, 0, m_MoonCircle->GetVertexCount());

			m_CancelCircle->SetColor(rgb[0], rgb[1], rgb[2]);
			m_CancelCircle->Bind();
			glDrawArrays(GL_POLYGON, 0, m_CancelCircle->GetVertexCount());
		}
		else
		{
			if (offset < 0.75)
				offset += colorSpeed * deltaTime;

			m_Circle->Bind();
			glDrawArrays(GL_POLYGON, 0, m_Circle->GetVertexCount());
			
			// DRAWING SUN RAYS
			{
				glBegin(GL_LINES);
				float x, y, r, g, b;
				m_Circle->GetCenter(x, y);
				m_Circle->GetColor(r, g, b);

				float* buffer = m_Circle->GetBuffer();
				int vertexComponents = 5;

				for (int i = 0; i < m_Circle->GetVertexCount(); i++)
				{
					int currentPosition = vertexComponents * i;

					glColor3f(r, g, b);
					glVertex2f(x, y);

					float xVec = buffer[currentPosition] - x;
					float yVev = buffer[currentPosition + 1] - y;

					glColor3f(r, g, b);
					glVertex2f(buffer[currentPosition] + xVec, buffer[currentPosition + 1] + yVev);
				}

				glEnd();
			}
		}

		glPopMatrix();

#ifdef _DEBUG
		glPointSize(2);
		glBegin(GL_POINTS);
		glColor3f(1.0f, 1.0f, 1.0f);
		glVertex2f(m_CenterX, m_CenterY);
		glEnd();
#endif // _DEBUG

		std::cout << deltaTime << std::endl;
	}
}

void MainWindow::Resize(int width, int height)
{
	DeallocateObjects();
	AllocateObjects();

	m_CenterX = width / 2;
	m_CenterY = height / 2;
}

void MainWindow::Init()
{
	AllocateObjects();
}

MainWindow::~MainWindow()
{
	DeallocateObjects();
}

void MainWindow::AllocateObjects() noexcept
{
	m_Circle = new Circle(20, 20, m_ObjectCenterX, m_ObjectCenterY, 1.0, 1.0, 0.0);
	m_Circle->Generate();

	m_MoonCircle = new Circle(20, 20, m_ObjectCenterX, m_ObjectCenterY, 1.0, 1.0, 0.0);
	m_MoonCircle->Generate();

	m_CancelCircle = new Circle(20, 20, m_CancelCenterX, m_CancelCenterY, 0.0, 0.0, 0.0);
	m_CancelCircle->Generate();
}

void MainWindow::DeallocateObjects() noexcept
{
	delete m_Circle;
	delete m_MoonCircle;
	delete m_CancelCircle;
}
