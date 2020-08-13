#include "MainWindow.h"
#include <QRadioButton>
#include <QSpinBox>
#include <QVBoxLayout>
#include <QPushButton>
#include <QLabel>

MainWindow::MainWindow(QWidget* parent /*=nullptr*/) : 
	QMainWindow(parent) {
	
	QWidget *centralWidget = new QWidget(this);
	setCentralWidget(centralWidget);

	QVBoxLayout* pVLayout = new QVBoxLayout(this);
	
	pVLayout->addWidget( new QRadioButton("Search from the &cursor",this) );
	pVLayout->addWidget( new QSpinBox(this) );
	pVLayout->addWidget( new QDoubleSpinBox(this) );

	pTreeview = new TreeView(this);
	pVLayout->addWidget(pTreeview);

	// -------------------------------------------
	pFilterWidget = new FilterWidget;
	pFilterWidget->setText(tr("foobar|dfj"));
	connect(pFilterWidget, &FilterWidget::filterChanged, this, &MainWindow::textFilterChanged);

	QLabel* filterPatternLabel = new QLabel(tr("&Filter pattern:"));
	filterPatternLabel->setBuddy(pFilterWidget);

	QHBoxLayout* hLayout = new QHBoxLayout(this); 
	hLayout->addWidget(filterPatternLabel);
	hLayout->addWidget(pFilterWidget);
	pVLayout->addLayout(hLayout);
	// -------------------------------------------

	centralWidget->setLayout(pVLayout);
	
}
	
MainWindow::~MainWindow(){
	
}
