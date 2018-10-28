#include "MapTileRenderGroupDescriptor.h"
#include "Buffer.h"
#include "VertexAttribute.h"

QList<MapTileRenderableInstance> MapTileRenderGroupDescriptor::instances() const
{
	return
	{
		MapTileRenderableInstance(-2, 0),
		MapTileRenderableInstance(0, 0),
		MapTileRenderableInstance(2, 0),
	};
}

BufferDescriptor MapTileRenderGroupDescriptor::buffer() const
{
	static Vector3D points[] =
	{
		{ -1.0f, -1.0f, -1.0f },
		{ -1.0f, -1.0f,  1.0f },
		{ -1.0f,  1.0f,  1.0f },

		{  1.0f,  1.0f, -1.0f },
		{ -1.0f, -1.0f, -1.0f },
		{ -1.0f,  1.0f, -1.0f },

		{  1.0f, -1.0f,  1.0f },
		{ -1.0f, -1.0f, -1.0f },
		{  1.0f, -1.0f, -1.0f },

		{  1.0f,  1.0f, -1.0f },
		{  1.0f, -1.0f, -1.0f },
		{ -1.0f, -1.0f, -1.0f },

		{ -1.0f, -1.0f, -1.0f },
		{ -1.0f,  1.0f,  1.0f },
		{ -1.0f,  1.0f, -1.0f },

		{  1.0f, -1.0f,  1.0f },
		{ -1.0f, -1.0f,  1.0f },
		{ -1.0f, -1.0f, -1.0f },

		{ -1.0f,  1.0f,  1.0f },
		{ -1.0f, -1.0f,  1.0f },
		{  1.0f, -1.0f,  1.0f },

		{  1.0f,  1.0f,  1.0f },
		{  1.0f, -1.0f, -1.0f },
		{  1.0f,  1.0f, -1.0f },

		{  1.0f, -1.0f, -1.0f },
		{  1.0f,  1.0f,  1.0f },
		{  1.0f, -1.0f,  1.0f },

		{  1.0f,  1.0f,  1.0f },
		{  1.0f,  1.0f, -1.0f },
		{ -1.0f,  1.0f, -1.0f },

		{  1.0f,  1.0f,  1.0f },
		{ -1.0f,  1.0f, -1.0f },
		{ -1.0f,  1.0f,  1.0f },

		{  1.0f,  1.0f,  1.0f },
		{ -1.0f,  1.0f,  1.0f },
		{  1.0f, -1.0f,  1.0f }
	};

	return Buffer::create(points
		, VertexAttribute<3>("vertex")
		);
}

QString MapTileRenderGroupDescriptor::vertexShader() const
{
	return "tile.vert";
}

QString MapTileRenderGroupDescriptor::fragmentShader() const
{
	return "tile.frag";
}
