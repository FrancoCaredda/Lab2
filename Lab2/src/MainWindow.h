#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include "core/AWindow.h"
#include "core/shape/Circle.h"

class MainWindow : public AWindow
{
public:
	MainWindow(const std::string& title, int width, int height)
		: AWindow(title, width, height) { 
		m_Circle = new Circle(100, 0.25, 1.0, 0.0, 0.0);
		m_Circle->Generate();
	}
	// Inherited via AWindow
	virtual void Update(float deltaTime) override;
	virtual void Resize(int width, int height) override;
	virtual void Init() override;

	virtual ~MainWindow();
private:
	Circle* m_Circle = nullptr;
};

#endif // !MAIN_WINDOW_H
