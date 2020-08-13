#include "MainWindow.h"
#include <QRadioButton>
#include <QSpinBox>
#include <QVBoxLayout>
#include <QPushButton>

MainWindow::MainWindow(QWidget* parent /*=nullptr*/) : 
	QMainWindow(parent) {
	
	QWidget *centralWidget = new QWidget(this);
	setCentralWidget(centralWidget);

	QVBoxLayout* pVLayout = new QVBoxLayout(this);
	
	pVLayout->addWidget( new QRadioButton("Search from the &cursor",this) );
	pVLayout->addWidget( new QSpinBox(this) );
	pVLayout->addWidget( new QDoubleSpinBox(this) );
	pVLayout->addWidget(new TreeView(this));

	centralWidget->setLayout(pVLayout);
	
}
	
MainWindow::~MainWindow(){
	
}
