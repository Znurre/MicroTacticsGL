#ifndef MAPTILERENDERABLEINSTANCE_H
#define MAPTILERENDERABLEINSTANCE_H

#include "IRenderableInstance.h"

class MapTileRenderableInstance : public IRenderableInstance
{
	public:
		MapTileRenderableInstance(float x, float y);

		void apply(PropertyMapper &mapper) const override;

	private:
		float m_x;
		float m_y;
};

#endif // MAPTILERENDERABLEINSTANCE_H
