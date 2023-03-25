#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include "core/AWindow.h"
#include "core/shape/Circle.h"

class MainWindow : public AWindow
{
public:
	MainWindow(const std::string& title, int width, int height)
		: AWindow(title, width, height) { }
	// Inherited via AWindow
	virtual void Update(float deltaTime) override;
	virtual void Resize(int width, int height) override;
	virtual void Init() override;

	virtual ~MainWindow();
private:
	void AllocateObjects() noexcept;
	void DeallocateObjects() noexcept;
private:
	Circle* m_Circle = nullptr;
	Circle* m_MoonCircle = nullptr;
	Circle* m_CancelCircle = nullptr;

	int m_CenterX = m_Width / 2, m_CenterY = m_Height / 2;
};

#endif // !MAIN_WINDOW_H
