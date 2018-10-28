#include "Window.h"

Window::Window()
	: m_mapTileRenderGroup(m_mapTileRenderGroupDescriptor)
{
	QSurfaceFormat format;
	format.setSamples(4);
	format.setVersion(4, 1);
	format.setProfile(QSurfaceFormat::CoreProfile);

	setFormat(format);
}

void Window::resizeGL(int w, int h)
{
	glViewport(0, 0, w, h);
}

void Window::initializeGL()
{
	m_mapTileRenderGroup.create();

	glEnable(GL_DEPTH_TEST);
}

void Window::paintGL()
{
	QMatrix4x4 projection;
	projection.perspective(45.0, 1.0, 0.1, 100.0);

	QMatrix4x4 view;
	view.lookAt(QVector3D(-10, 10, -10), QVector3D(), QVector3D(0, 0, 1));

	m_mapTileRenderGroup.draw(projection * view);

	update();
}
