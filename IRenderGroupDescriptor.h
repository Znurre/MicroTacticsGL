#ifndef IRENDERGROUPDESCRIPTOR_H
#define IRENDERGROUPDESCRIPTOR_H

#include <QList>

#include "BufferDescriptor.h"

template<class TRenderableInstance>
class IRenderGroupDescriptor
{
	public:
		virtual QList<TRenderableInstance> instances() const = 0;

		virtual BufferDescriptor buffer() const = 0;

		virtual QString vertexShader() const = 0;
		virtual QString fragmentShader() const = 0;
};

#endif // IRENDERGROUPDESCRIPTOR_H
