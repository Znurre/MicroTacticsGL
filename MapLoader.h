#ifndef MAPLOADER_H
#define MAPLOADER_H

#include <QString>

class Map;

class MapLoader
{
	public:
		Map *load(const QString &fileName) const;
};

#endif // MAPLOADER_H
