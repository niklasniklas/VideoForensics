#include "vfmainwindow.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	VFMainWindow w;
	w.show();
	return a.exec();
}
