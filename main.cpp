#include <QGuiApplication>

#include "Window.h"

int main(int argc, char **argv)
{
	QGuiApplication application(argc, argv);

	Window window;
	window.resize(1280, 720);
	window.show();

	return application.exec();
}
