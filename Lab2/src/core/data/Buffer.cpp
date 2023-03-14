#include "Buffer.h"

#include <exception>

Buffer& BufferAllocator::AllocateBuffer(uint32_t vertexCount, BufferLayout layout)
{
    if (m_Buffers.size() < m_MaxInstances)
    {
        Buffer buffer;
        buffer.verteciesSize = vertexCount * static_cast<uint32_t>(layout);
        buffer.data = new float[buffer.verteciesSize] { 0 };

        m_Buffers.push_back(std::move(buffer));
        return m_Buffers[m_Buffers.size() - 1];
    }

    throw std::exception("Illeagal oparation");
}

BufferAllocator::~BufferAllocator()
{
    for (auto& buffer : m_Buffers)
        delete[] buffer.data;

    m_Buffers.clear();
}
