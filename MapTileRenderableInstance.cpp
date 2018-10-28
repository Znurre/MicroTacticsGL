#include "MapTileRenderableInstance.h"

MapTileRenderableInstance::MapTileRenderableInstance(float x, float y)
	: m_x(x)
	, m_y(y)
{
}

void MapTileRenderableInstance::apply(PropertyMapper &mapper) const
{
	QMatrix4x4 matrix;
	matrix.translate(m_x, 0, m_y);

	mapper.setValue("M", matrix);
	mapper.setValue("color", 0.5f + m_x + m_y);
}
