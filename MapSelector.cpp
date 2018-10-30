#include "MapLoader.h"
#include "MapSelector.h"

MapSelector::MapSelector()
{
	MapLoader mapLoader;

	m_maps << mapLoader.load("resources/maps/first.tmx");
}

Map &MapSelector::map() const
{
	return *m_maps[0];
}
