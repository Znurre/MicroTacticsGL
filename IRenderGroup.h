#ifndef IRENDERGROUP_H
#define IRENDERGROUP_H

#include <QMatrix4x4>

class IRenderGroup
{
	public:
		virtual void create() = 0;
		virtual void draw(const QMatrix4x4 &matrix) = 0;
};

#endif // IRENDERGROUP_H
