#ifndef MAPTILERENDERGROUPDESCRIPTOR_H
#define MAPTILERENDERGROUPDESCRIPTOR_H

#include "IRenderGroupDescriptor.h"
#include "MapTileRenderableInstance.h"

class MapSelector;

class MapTileRenderGroupDescriptor : public IRenderGroupDescriptor<MapTileRenderableInstance>
{
	public:
		MapTileRenderGroupDescriptor(MapSelector &mapSelector);

		QList<MapTileRenderableInstance> instances() const override;

		BufferDescriptor buffer() const override;

		QString vertexShader() const override;
		QString fragmentShader() const override;

	private:
		MapSelector &m_mapSelector;
};

#endif // MAPTILERENDERGROUPDESCRIPTOR_H
