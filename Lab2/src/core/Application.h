#ifndef APPLICATION_H
#define APPLICATION_H

#include "AWindow.h"

#include <ctime>

class Application
{
public:
	static void Init(int argc, char** argv) noexcept;
	static Application& GetInstance() noexcept;

	void SetCurrentWindow(AWindow* window) noexcept;
	void Run() noexcept;

	static void Shutdown() noexcept;
private:
	Application() = default;
	Application(const Application&) = delete;
	Application(Application&&) = delete;

	Application operator=(const Application&) = delete;

	static void Init(int);
	static void Update();

	static void Resize(int width, int height);
private:
	static Application s_Instance;
	AWindow* m_CurrentContext;

	clock_t m_Tick = 0;
	clock_t m_LastTick = 0;
};

#endif // !APPLICATION_H
