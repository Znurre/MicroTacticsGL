#include "MapTileRenderGroupDescriptor.h"
#include "Buffer.h"
#include "VertexAttribute.h"
#include "MapSelector.h"

MapTileRenderGroupDescriptor::MapTileRenderGroupDescriptor(MapSelector &mapSelector)
	: m_mapSelector(mapSelector)
{
}

QList<MapTileRenderableInstance> MapTileRenderGroupDescriptor::instances() const
{
	QList<MapTileRenderableInstance> result;

	const Map &map = m_mapSelector.map();

	for (IMapTile *tile : map.tiles())
	{
		result << MapTileRenderableInstance(tile);
	}

	return result;
}

BufferDescriptor MapTileRenderGroupDescriptor::buffer() const
{
	static Vector3D points[] =
	{
		{ -1.0f, -1.0f, -1.0f }, { -1.0f,  0.0f,  0.0f },
		{ -1.0f, -1.0f,  1.0f }, { -1.0f,  0.0f,  0.0f },
		{ -1.0f,  1.0f,  1.0f }, { -1.0f,  0.0f,  0.0f },

		{  1.0f,  1.0f, -1.0f }, {  0.0f,  0.0f, -1.0f },
		{ -1.0f, -1.0f, -1.0f }, {  0.0f,  0.0f, -1.0f },
		{ -1.0f,  1.0f, -1.0f }, {  0.0f,  0.0f, -1.0f },

		{  1.0f, -1.0f,  1.0f }, {  0.0f, -1.0f,  0.0f },
		{ -1.0f, -1.0f, -1.0f }, {  0.0f, -1.0f,  0.0f },
		{  1.0f, -1.0f, -1.0f }, {  0.0f, -1.0f,  0.0f },

		{  1.0f,  1.0f, -1.0f }, {  0.0f,  0.0f, -1.0f },
		{  1.0f, -1.0f, -1.0f }, {  0.0f,  0.0f, -1.0f },
		{ -1.0f, -1.0f, -1.0f }, {  0.0f,  0.0f, -1.0f },

		{ -1.0f, -1.0f, -1.0f }, { -1.0f,  0.0f,  0.0f },
		{ -1.0f,  1.0f,  1.0f }, { -1.0f,  0.0f,  0.0f },
		{ -1.0f,  1.0f, -1.0f }, { -1.0f,  0.0f,  0.0f },

		{  1.0f, -1.0f,  1.0f }, {  0.0f, -1.0f,  0.0f },
		{ -1.0f, -1.0f,  1.0f }, {  0.0f, -1.0f,  0.0f },
		{ -1.0f, -1.0f, -1.0f }, {  0.0f, -1.0f,  0.0f },

		{ -1.0f,  1.0f,  1.0f }, {  0.0f,  0.0f,  1.0f },
		{ -1.0f, -1.0f,  1.0f }, {  0.0f,  0.0f,  1.0f },
		{  1.0f, -1.0f,  1.0f }, {  0.0f,  0.0f,  1.0f },

		{  1.0f,  1.0f,  1.0f }, {  1.0f,  0.0f,  0.0f },
		{  1.0f, -1.0f, -1.0f }, {  1.0f,  0.0f,  0.0f },
		{  1.0f,  1.0f, -1.0f }, {  1.0f,  0.0f,  0.0f },

		{  1.0f, -1.0f, -1.0f }, {  1.0f,  0.0f,  0.0f },
		{  1.0f,  1.0f,  1.0f }, {  1.0f,  0.0f,  0.0f },
		{  1.0f, -1.0f,  1.0f }, {  1.0f,  0.0f,  0.0f },

		{  1.0f,  1.0f,  1.0f }, {  0.0f,  1.0f,  0.0f },
		{  1.0f,  1.0f, -1.0f }, {  0.0f,  1.0f,  0.0f },
		{ -1.0f,  1.0f, -1.0f }, {  0.0f,  1.0f,  0.0f },

		{  1.0f,  1.0f,  1.0f }, {  0.0f,  1.0f,  0.0f },
		{ -1.0f,  1.0f, -1.0f }, {  0.0f,  1.0f,  0.0f },
		{ -1.0f,  1.0f,  1.0f }, {  0.0f,  1.0f,  0.0f },

		{  1.0f,  1.0f,  1.0f }, {  0.0f,  0.0f,  1.0f },
		{ -1.0f,  1.0f,  1.0f }, {  0.0f,  0.0f,  1.0f },
		{  1.0f, -1.0f,  1.0f }, {  0.0f,  0.0f,  1.0f },
	};

	return Buffer::create(points
		, VertexAttribute<3>("vertex")
		, VertexAttribute<3>("normal")
		);
}

QString MapTileRenderGroupDescriptor::vertexShader() const
{
	return "resources/shaders/tile.vert";
}

QString MapTileRenderGroupDescriptor::fragmentShader() const
{
	return "resources/shaders/tile.frag";
}
