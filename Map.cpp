#include "Map.h"

Map::Map(QList<IMapTile *> tiles)
	: m_tiles(tiles)
{
}

QList<IMapTile *> Map::tiles() const
{
	return m_tiles;
}
