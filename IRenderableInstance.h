#ifndef IRENDERABLEINSTANCE_H
#define IRENDERABLEINSTANCE_H

#include "PropertyMapper.h"

class IRenderableInstance
{
	public:
		virtual void apply(PropertyMapper &mapper) const = 0;
};

#endif // IRENDERABLEINSTANCE_H
