#include <QVector3D>

#include <tiled/mapreader.h>
#include <tiled/map.h>

#include "MapLoader.h"
#include "Map.h"

class GroundTile : public IMapTile
{
	public:
		GroundTile(int x, int y)
			: m_x(x)
			, m_y(y)
		{
		}

		int x() const override
		{
			return m_x;
		}

		int y() const override
		{
			return m_y;
		}

		QColor color() const
		{
			return QColor(68, 170, 0);
		}

	private:
		int m_x;
		int m_y;
};

class PlayerSpawnTile : public IMapTile
{
	public:
		PlayerSpawnTile(int x, int y)
			: m_x(x)
			, m_y(y)
		{
		}

		int x() const override
		{
			return m_x;
		}

		int y() const override
		{
			return m_y;
		}

		QColor color() const override
		{
			return QColor(255, 0, 0);
		}

	private:
		int m_x;
		int m_y;
};

class CoverTile : public IMapTile
{
	public:
		CoverTile(int x, int y)
			: m_x(x)
			, m_y(y)
		{
		}

		int x() const override
		{
			return m_x;
		}

		int y() const override
		{
			return m_y;
		}

		QColor color() const override
		{
			return QColor(51, 51, 51);
		}

	private:
		int m_x;
		int m_y;
};

IMapTile *resolveTile(int id, int x, int y)
{
	switch (id)
	{
		case 0:
		{
			return new GroundTile(x, y);
		}

		case 1:
		{
			return new PlayerSpawnTile(x, y);
		}

		case 4:
		{
			return new CoverTile(x, y);
		}
	}

	return nullptr;
}

Map *MapLoader::load(const QString &fileName) const
{
	Tiled::MapReader mapReader;
	Tiled::Map *tiledMap = mapReader.readMap(fileName);

	QList<IMapTile *> tiles;

	if (tiledMap)
	{
		for (int i = 0; i < tiledMap->layerCount(); i++)
		{
			Tiled::Layer *layer = tiledMap->layerAt(i);
			Tiled::TileLayer *tileLayer = dynamic_cast<Tiled::TileLayer *>(layer);

			if (tileLayer)
			{
				for (int y = 0; y < tileLayer->height(); y++)
				{
					for (int x = 0; x < tileLayer->width(); x++)
					{
						const Tiled::Cell &cell = tileLayer->cellAt(x, y);
						const Tiled::Tile *tile = cell.tile();

						const int id = tile->id();

						IMapTile *mapTile = resolveTile(id, x, y);

						if (mapTile)
						{
							tiles << mapTile;
						}
					}
				}
			}
		}
	}

	return new Map(tiles);
}
