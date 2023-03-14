#ifndef ISHAPE_H
#define ISHAPE_H

class IShape
{
public:
	IShape() = default;
	virtual void Generate() = 0;
	virtual void Bind() = 0;
	virtual ~IShape() {}
private:
	IShape(const IShape&) = delete;
	IShape(IShape&&) = delete;
};

#endif // !ISHAPE_H
