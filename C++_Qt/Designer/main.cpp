#include<iostream>

#include <QtWidgets/QApplication>
#include <QtGui>

#include "MainWindow.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

	MainWindow myMainWindow;

	myMainWindow.show(); 

	return app.exec();

}