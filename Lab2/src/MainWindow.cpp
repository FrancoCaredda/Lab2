#include "MainWindow.h"
#include "core/utils/utils.h"

#include <iostream>

void MainWindow::Update(float deltaTime)
{
	static const float ROTATE_LOW_LIMIT = -360;
	static const float ROTATE_HIGH_LIMIT = -180.0f;
	static const float COLOR_HIGH_LIMIT = 0.75;
	static const float COLOR_LOW_LIMIT = 0;

	glClear(GL_COLOR_BUFFER_BIT);

	glm::vec3 rgb = { 0, 1 * offset, 1 * offset };
	glClearColor(rgb.r, rgb.g, rgb.b, 1.0f);

	
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();

	rotate -= 3 * speed * deltaTime;

	glTranslatef(m_Center.x, m_Center.y, 0.0f);
	glRotatef(rotate, 0, 0, 1);
	glTranslatef(-m_Center.x, -m_Center.y, 0.0f);

	glTranslatef(m_ObjectCenter.x, m_ObjectCenter.y, 0.0f);
	glRotatef(1.5f*rotate, 0, 0, 1);
	glTranslatef(-m_ObjectCenter.x, -m_ObjectCenter.y, 0.0f); 

	if (rotate < ROTATE_LOW_LIMIT)
		rotate = 0;

	if (rotate > ROTATE_HIGH_LIMIT)
	{
		if (offset > COLOR_LOW_LIMIT)
			offset -= colorSpeed * deltaTime;

		m_MoonCircle->Bind();
		glDrawArrays(GL_POLYGON, 0, m_MoonCircle->GetVertexCount());

		m_CancelCircle->SetColor(rgb);
		m_CancelCircle->Bind();
		glDrawArrays(GL_POLYGON, 0, m_CancelCircle->GetVertexCount());
	}
	else
	{
		if (offset < COLOR_HIGH_LIMIT)
			offset += colorSpeed * deltaTime;

		m_Circle->Bind();
		glDrawArrays(GL_POLYGON, 0, m_Circle->GetVertexCount());
			
		// DRAWING SUN RAYS
		{
			glBegin(GL_LINES);
			glm::vec3 color = m_Circle->GetColor();

			float* buffer = m_Circle->GetBuffer();
			int vertexComponents = 5;

			for (int i = 0; i < m_Circle->GetVertexCount(); i++)
			{
				int currentPosition = vertexComponents * i;

				glColor3f(color.r, color.g, color.b);
				glVertex2f(m_ObjectCenter.x, m_ObjectCenter.y);

				glm::vec2 vec = {
					buffer[currentPosition] - m_ObjectCenter.x,
					buffer[currentPosition + 1] - m_ObjectCenter.y
				};

				glColor3f(color.r, color.g, color.b);
				glVertex2f(buffer[currentPosition] + vec.x, 
					buffer[currentPosition + 1] + vec.y);
			}

			glEnd();
		}
	}

	glPopMatrix();

#ifdef _DEBUG
		glPointSize(2);
		glBegin(GL_POINTS);
		glColor3f(1.0f, 1.0f, 1.0f);
		glVertex2f(m_Center.x, m_Center.y);
		glEnd();
#endif // _DEBUG
}

void MainWindow::Resize(int width, int height)
{
	m_Center.x = width / 2;
	m_Center.y = height / 2;

	m_Center = { m_Width / 2, m_Height / 2 };
	m_ObjectCenter = { m_Center.x, m_Center.y - 100 };
	m_CancelCenter = { m_Center.x + 10, m_Center.y - 90 };

	if (m_Circle != nullptr)
	{
		m_Circle->SetCenter(m_ObjectCenter);
		m_MoonCircle->SetCenter(m_ObjectCenter);
		m_CancelCircle->SetCenter(m_CancelCenter);
	}
}

void MainWindow::Init()
{
}

MainWindow::~MainWindow()
{
	DeallocateObjects();
}

void MainWindow::AllocateObjects() noexcept
{
	m_Circle = new Circle(20, 20, { m_ObjectCenter.x, m_ObjectCenter.y }, { 1.0, 1.0, 0.0 });
	m_Circle->Generate();

	m_MoonCircle = new Circle(20, 20, { m_ObjectCenter.x, m_ObjectCenter.y }, { 1.0, 1.0, 0.0 });
	m_MoonCircle->Generate();

	m_CancelCircle = new Circle(20, 20, { m_CancelCenter.x, m_CancelCenter.y }, { 0.0, 0.0, 0.0 });
	m_CancelCircle->Generate();
}

void MainWindow::DeallocateObjects() noexcept
{
	delete m_Circle;
	delete m_MoonCircle;
	delete m_CancelCircle;
}
