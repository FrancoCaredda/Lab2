#include "AWindow.h"

AWindow::AWindow(const std::string& title, int width, int height)
{
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(width, height);

	m_WndHandle = glutCreateWindow(title.c_str());
}

AWindow::~AWindow()
{
	if (m_WndHandle > 0)
		glutDestroyWindow(m_WndHandle);
}

