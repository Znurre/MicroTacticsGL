#ifndef MAPTILERENDERGROUPDESCRIPTOR_H
#define MAPTILERENDERGROUPDESCRIPTOR_H

#include "IRenderGroupDescriptor.h"
#include "MapTileRenderableInstance.h"

class MapTileRenderGroupDescriptor : public IRenderGroupDescriptor<MapTileRenderableInstance>
{
	public:
		QList<MapTileRenderableInstance> instances() const override;

		BufferDescriptor buffer() const override;

		QString vertexShader() const override;
		QString fragmentShader() const override;
};

#endif // MAPTILERENDERGROUPDESCRIPTOR_H
