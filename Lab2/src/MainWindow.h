#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include "core/AWindow.h"
#include "core/shape/Circle.h"

class MainWindow : public AWindow
{
public:
	MainWindow(const std::string& title, int width, int height)
		: AWindow(title, width, height) { 
		m_Circle = new Circle(20, 20, m_CenterX, m_CenterY - 100, 1.0, 1.0, 0.0);
		m_Circle->Generate();


		m_MoonCircle = new Circle(20, 20, m_CenterX, m_CenterY - 100, 1.0, 1.0, 0.0);
		m_MoonCircle->Generate();

		m_CancelCircle = new Circle(20, 20, m_CenterX + 10, m_CenterY - 90, 0.0, 0.0, 0.0);
		m_CancelCircle->Generate();
	}
	// Inherited via AWindow
	virtual void Update(float deltaTime) override;
	virtual void Resize(int width, int height) override;
	virtual void Init() override;

	virtual ~MainWindow();
private:
	Circle* m_Circle = nullptr;
	Circle* m_MoonCircle = nullptr;
	Circle* m_CancelCircle = nullptr;

	int m_CenterX = m_Width / 2, m_CenterY = m_Height / 2;
};

#endif // !MAIN_WINDOW_H
