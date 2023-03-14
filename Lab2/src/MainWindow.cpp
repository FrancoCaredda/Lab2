#include "MainWindow.h"

#include <iostream>

void MainWindow::Update(float deltaTime)
{
	glClear(GL_COLOR_BUFFER_BIT);
	
	m_Circle->Bind();
	glDrawElements(GL_TRIANGLES, 3 * 100, GL_UNSIGNED_INT, m_Circle->GetIndecies());

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
