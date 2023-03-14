#include "MainWindow.h"

#include <iostream>

void MainWindow::Update(float deltaTime)
{
	glClear(GL_COLOR_BUFFER_BIT);
	
	m_Circle->Bind();
	glDrawArrays(GL_POLYGON, 0, m_Circle->GetVertexCount());

	std::cout << deltaTime << std::endl;
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
