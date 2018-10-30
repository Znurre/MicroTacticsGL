#include <GL/gl.h>

#include "VertexAttributeDescriptor.h"

VertexAttributeDescriptor::VertexAttributeDescriptor(int stride, int offset, int size, const char *name)
	: m_offset(offset)
	, m_size(size)
	, m_stride(stride)
	, m_name(name)
{
}

int VertexAttributeDescriptor::offset() const
{
	return m_offset* sizeof(GLfloat);
}

int VertexAttributeDescriptor::size() const
{
	return m_size;
}

int VertexAttributeDescriptor::stride() const
{
	return m_stride* sizeof(GLfloat);
}

const char *VertexAttributeDescriptor::name() const
{
	return m_name;
}
