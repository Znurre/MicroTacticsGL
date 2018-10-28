#ifndef VERTEXATTRIBUTE_H
#define VERTEXATTRIBUTE_H

template<int TSize>
class VertexAttribute
{
	public:
		VertexAttribute(const char *name)
			: m_name(name)
		{
		}

		const char *name() const
		{
			return m_name;
		}

		int size() const
		{
			return TSize;
		}

	private:
		const char *m_name;
};

#endif // VERTEXATTRIBUTE_H
