#ifndef MAP_H
#define MAP_H

#include <QList>

#include "IMapTile.h"

class Map
{
	public:
		Map(QList<IMapTile *> tiles);

		QList<IMapTile *> tiles() const;

	private:
		QList<IMapTile *> m_tiles;
};

#endif // MAP_H
