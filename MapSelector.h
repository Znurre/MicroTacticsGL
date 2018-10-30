#ifndef MAPSELECTOR_H
#define MAPSELECTOR_H

#include "Map.h"

class MapSelector
{
	public:
		MapSelector();

		Map &map() const;

	private:
		QList<Map *> m_maps;
};

#endif // MAPSELECTOR_H
