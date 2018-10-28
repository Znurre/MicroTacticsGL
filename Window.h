#ifndef WINDOW_H
#define WINDOW_H

#include <QOpenGLWindow>

#include "MapTileRenderGroupDescriptor.h"
#include "RenderGroup.h"

class Window : public QOpenGLWindow
{
	public:
		Window();

		void resizeGL(int w, int h) override;
		void initializeGL() override;
		void paintGL() override;

	private:
		MapTileRenderGroupDescriptor m_mapTileRenderGroupDescriptor;
		RenderGroup<MapTileRenderableInstance> m_mapTileRenderGroup;
};

#endif // WINDOW_H
