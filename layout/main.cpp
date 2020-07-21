#include<iostream>

#include <QtWidgets/QApplication>
#include <QtGui>
#include "Grid.h"

int main(int argc, char *argv[])
{
  QApplication app(argc, argv);

  Grid* w = new Grid;
  w->show();
  return app.exec();
}

