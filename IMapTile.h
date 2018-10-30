#ifndef IMAPTILE_H
#define IMAPTILE_H

#include <QColor>

class IMapTile
{
	public:
		virtual QColor color() const = 0;

		virtual int x() const = 0;
		virtual int y() const = 0;
};

#endif // IMAPTILE_H
