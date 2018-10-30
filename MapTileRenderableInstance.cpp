#include "MapTileRenderableInstance.h"
#include "IMapTile.h"

MapTileRenderableInstance::MapTileRenderableInstance(IMapTile *tile)
	: m_tile(tile)
{
}

void MapTileRenderableInstance::apply(PropertyMapper &mapper) const
{
	QMatrix4x4 matrix;
	matrix.translate(m_tile->x() * 2, m_tile->y() * 2, 0);

	const QColor &primaryColor = m_tile->color();
	const QColor &secondaryColor = QColor::fromHsl(primaryColor.hue(), primaryColor.saturation(), primaryColor.lightness() - 25);

	mapper.setValue("M", matrix);
	mapper.setValue("primaryColor", QVector3D(primaryColor.redF(), primaryColor.greenF(), primaryColor.blueF()));
	mapper.setValue("secondaryColor", QVector3D(secondaryColor.redF(), secondaryColor.greenF(), secondaryColor.blueF()));
}
