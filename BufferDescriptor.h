#ifndef BUFFERDESCRIPTOR_H
#define BUFFERDESCRIPTOR_H

#include <GL/gl.h>

#include <QList>

#include "VertexAttributeDescriptor.h"

class BufferDescriptor
{
	public:
		BufferDescriptor(int length, int size, GLfloat *data, QList<VertexAttributeDescriptor> attributes);

		QList<VertexAttributeDescriptor> attributes() const;

		GLfloat *data() const;

		int size() const;
		int length() const;

	private:
		int m_length;
		int m_size;

		GLfloat *m_data;

		QList<VertexAttributeDescriptor> m_attributes;
};

#endif // BUFFERDESCRIPTOR_H
