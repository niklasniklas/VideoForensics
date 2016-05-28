#include "gui/vfmainwindow.h"
#include <QtWidgets/QApplication>
#include "VideoController.h"


int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	VideoController ctrl;
	//gui::VFMainWindow w;
	//w.show();
	return a.exec();




}
