#ifndef BUFFER_H
#define BUFFER_H

#include <GL/gl.h>

#include <QList>

#include "VertexAttributeDescriptor.h"

typedef GLfloat Vector1D[1];
typedef GLfloat Vector2D[2];
typedef GLfloat Vector3D[3];
typedef GLfloat Vector4D[4];

class Buffer
{
	public:
		template<class TAttribute>
		static int transformAttributes(int offset, QList<VertexAttributeDescriptor> &result, TAttribute &attribute)
		{
			result << VertexAttributeDescriptor(0
				, offset
				, attribute.size()
				, attribute.name()
				);

			return attribute.size();
		}

		template<class TAttribute, class ...TAttributes>
		static int transformAttributes(int offset, QList<VertexAttributeDescriptor> &result, TAttribute &attribute, TAttributes &...attributes)
		{
			const int stride = transformAttributes(offset + attribute.size(), result, attributes...);

			result << VertexAttributeDescriptor(stride
				, offset
				, attribute.size()
				, attribute.name()
				);

			return stride + attribute.size();
		}

		template<int TLength, int TTupleSize, class ...TAttributes>
		static BufferDescriptor create(GLfloat (&points)[TLength][TTupleSize], TAttributes ...attributes)
		{
			QList<VertexAttributeDescriptor> transformed;

			transformAttributes(0, transformed, attributes...);

			return BufferDescriptor(TLength, sizeof(points), (GLfloat *)points, transformed);
		}
};
#endif // BUFFER_H
