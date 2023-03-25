#include "MainWindow.h"
#include "core/utils/utils.h"

#include <iostream>

float offset = 0.0f;
float speed = 5.0f;

float colorSpeed = 0.2f;

float rotate = 0;

int dir = 1;

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

		glTranslatef(320.0f, 240.0f, 0.0f);
		glRotatef(rotate, 0, 0, 1);
		glTranslatef(-320.0f, -240.0f, 0.0f);

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
		}

		glPopMatrix();

#ifdef _DEBUG
		glPointSize(2);
		glBegin(GL_POINTS);
		glColor3f(1.0f, 1.0f, 1.0f);
		glVertex2f(320.0f, 240.0f);
		glEnd();
#endif // _DEBUG
	}
}

void MainWindow::Resize(int width, int height)
{
}

void MainWindow::Init()
{
	
}

MainWindow::~MainWindow()
{
	delete m_Circle;
}
