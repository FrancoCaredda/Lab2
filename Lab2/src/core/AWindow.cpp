#include "AWindow.h"

AWindow::AWindow(const std::string& title, int width, int height)
	: m_Width(width), m_Height(height)
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

