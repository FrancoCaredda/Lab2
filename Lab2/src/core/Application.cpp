#include "Application.h"

#include <GL/freeglut.h>

Application Application::s_Instance;

void Application::Init(int argc, char** argv) noexcept
{
	glutInit(&argc, argv);
}

Application& Application::GetInstance() noexcept
{
	return s_Instance;
}

void Application::SetCurrentWindow(AWindow* window) noexcept
{
	s_Instance.m_CurrentContext = window;
	glutSetWindow(window->GetNativeHandle());
	glutEntryFunc(Init);
	glutDisplayFunc(Update);
	glutReshapeFunc(Resize);
}

void Application::Run() noexcept
{
	glutMainLoop();
}

void Application::Shutdown() noexcept
{
	delete s_Instance.m_CurrentContext;
}

void Application::Init(int)
{
	s_Instance.m_CurrentContext->Init();
}

void Application::Update()
{
	clock_t currentTick = clock();
	s_Instance.m_Tick = currentTick - s_Instance.m_LastTick;
	s_Instance.m_LastTick = currentTick;

	s_Instance.m_CurrentContext->Update(((float)s_Instance.m_Tick / CLOCKS_PER_SEC));

	glutPostRedisplay();
	glutSwapBuffers();
}

void Application::Resize(int width, int height)
{
	s_Instance.m_CurrentContext->Resize(width, height);
}
