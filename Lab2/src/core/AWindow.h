#ifndef AWINDOW_H
#define AWINDOW_H

#include <GL/freeglut.h>
#include <string>

class AWindow
{
public:
	AWindow(const std::string& title, int width, int height);
	virtual ~AWindow();

	inline int GetNativeHandle() const noexcept { return m_WndHandle; };

	virtual void Update(float deltaTime) = 0;
	virtual void Resize(int width, int height) = 0;
	virtual void Init() = 0;
private:
	int m_WndHandle;
};

#endif // !AWINDOW_H


