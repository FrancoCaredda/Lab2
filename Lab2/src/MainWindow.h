#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include "core/AWindow.h"
#include "core/shape/Circle.h"

class MainWindow : public AWindow
{
public:
	MainWindow(const std::string& title, int width, int height)
		: AWindow(title, width, height),
		m_Center({ m_Width / 2, m_Height / 2 }),
		m_ObjectCenter({ m_Center.x, m_Center.y - 100 }),
		m_CancelCenter({ m_Center.x + 10, m_Center.y - 90 }) {
		AllocateObjects();
	}
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

	float offset = 0.0f;
	float colorSpeed = 0.2f;

	float speed = 5.0f;
	float rotate = -180.0f;

	glm::vec2 m_Center;
	glm::vec2 m_ObjectCenter;
	glm::vec2 m_CancelCenter;
};

#endif // !MAIN_WINDOW_H
