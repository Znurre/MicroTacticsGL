#ifndef VERTEXATTRIBUTEDESCRIPTOR_H
#define VERTEXATTRIBUTEDESCRIPTOR_H

class VertexAttributeDescriptor
{
	public:
		VertexAttributeDescriptor(int stride, int offset, int size, const char *name);

		int offset() const;
		int size() const;
		int stride() const;

		const char *name() const;

	private:
		int m_offset;
		int m_size;
		int m_stride;

		const char *m_name;
};

#endif // VERTEXATTRIBUTEDESCRIPTOR_H
