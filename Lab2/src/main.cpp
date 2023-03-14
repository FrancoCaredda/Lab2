#include "core/Application.h"
#include "MainWindow.h"

int main(int argc, char** argv)
{
	Application::Init(argc, argv);

	Application& app = Application::GetInstance();
	
	MainWindow* window = new MainWindow("Lab2", 640, 480);
	app.SetCurrentWindow(window);
	app.Run();

	Application::Shutdown();
	return 0;
}