#include "BufferDescriptor.h"

BufferDescriptor::BufferDescriptor(int length, int size, GLfloat *data, QList<VertexAttributeDescriptor> attributes)
	: m_length(length)
	, m_size(size)
	, m_data(data)
	, m_attributes(attributes)
{
}

QList<VertexAttributeDescriptor> BufferDescriptor::attributes() const
{
	return m_attributes;
}

GLfloat *BufferDescriptor::data() const
{
	return m_data;
}

int BufferDescriptor::size() const
{
	return m_size;
}

int BufferDescriptor::length() const
{
	return m_length;
}
