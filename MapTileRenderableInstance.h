#ifndef MAPTILERENDERABLEINSTANCE_H
#define MAPTILERENDERABLEINSTANCE_H

#include "IRenderableInstance.h"

class IMapTile;

class MapTileRenderableInstance : public IRenderableInstance
{
	public:
		MapTileRenderableInstance(IMapTile *tile);

		void apply(PropertyMapper &mapper) const override;

	private:
		IMapTile *m_tile;
};

#endif // MAPTILERENDERABLEINSTANCE_H
