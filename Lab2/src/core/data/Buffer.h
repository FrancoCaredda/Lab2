#ifndef BUFFER_H
#define BUFFER_H

#include <cstdint>
#include <vector>

/// <summary>
/// Buffer is the rapresentation of OpenGL GL_VERTEX_ARRAY data.
/// </summary>
typedef struct buffer_t
{
	float* data;
	uint32_t* indecies;

	size_t verteciesSize;
	size_t indeciesSize;
} Buffer;

enum BufferLayout
{
	BUFFER_V2RGB = 5,
	BUFFER_V3RGB = 6,
	BUFFER_V3RGBA = 7
};

class BufferAllocator
{
public:
	BufferAllocator() = default;
	BufferAllocator(int maxInstances)
		: m_MaxInstances(maxInstances) { }

	Buffer& AllocateBuffer(uint32_t vertexCount, BufferLayout layout); 

	~BufferAllocator();
private:
	std::vector<Buffer> m_Buffers;
	uint32_t m_MaxInstances = 20;
};

#endif // !BUFFER_H
