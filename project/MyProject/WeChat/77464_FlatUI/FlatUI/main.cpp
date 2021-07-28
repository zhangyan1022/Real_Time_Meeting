#include "frmmain.h"
#include <QApplication>
#include <QFont>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
    a.setFont(QFont("Microsoft Yahei", 10));

	frmMain w;
	w.show();

	return a.exec();
}
