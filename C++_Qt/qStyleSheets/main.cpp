#include <iostream>
#include "MainWindow.h"
#include <QApplication>

int main(int argc, char *argv[]) {
	
	QApplication testApp(argc, argv);
	
	MainWindow myMainWindow;
	myMainWindow.show(); 
	
	// Set the stylesheets, see https://doc.qt.io/archives/qt-4.8/stylesheet-examples.html
	testApp.setStyleSheet(" \
QRadioButton::indicator::unchecked \
		{image:url(images/radiobuttonUNChecked.png);} \
QRadioButton::indicator::checked  \
		{image:url(images/radiobuttonChecked.png);} \
\
QSpinBox \
  		{ border: 1px solid #ABABAB; \
		  border-radius: 3px; } \
\
QDoubleSpinBox::down-button  { \
  subcontrol-origin: margin; \
  subcontrol-position: center left; \
  image: url(images/Minus.png); \
  left: 1px; \
  height: 24px; \
  width: 24px; \
} \
 \
QDoubleSpinBox::up-button  { \
  subcontrol-origin: margin; \
  subcontrol-position: center right; \
  image: url(images/Plus.png); \
  right: 1px; \
  height: 24px; \
  width: 24px; \
} \
QTreeView { \
background: #ff3356; \
alternate-background-color: #00ffcc; \
} \
");
	
	return testApp.exec();
}

/*
\
QTreeView::item:alternate { \
  background-color: #bfffbf; \
} \
QTreeView::item { \
  background-color: red; \
} \*/