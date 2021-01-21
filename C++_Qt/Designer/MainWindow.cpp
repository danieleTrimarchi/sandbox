#include "MainWindow.h"
#include <QRadioButton>
#include <QSpinBox>
#include <QVBoxLayout>
#include <QPushButton>
#include <QLabel>
#include "CommandItem.h"
#include <QListWidget>

MainWindow::MainWindow(QWidget* parent /*=nullptr*/) : 
	QMainWindow(parent) {

	ui.setupUi(this);
	
	 //Set the items in listWidget
	ui.listWidget->clear();

	QIcon icon;
	icon.addFile(QString::fromUtf8(":/icons/superLoc.png"), QSize(), QIcon::Normal, QIcon::Off);

	QListWidgetItem* ci = new QListWidgetItem("RunSuperLoc");
	ci->setIcon(icon);

	ui.listWidget->addItem(ci); 

	ui.listWidget->setViewMode(QListWidget::IconMode);
	ui.listWidget->setResizeMode(QListWidget::Adjust);
	ui.listWidget->setIconSize(QSize(100, 100));

	QObject::connect(ui.SelectFileRoot, &QPushButton::clicked, this, &MainWindow::getExistingDirectory);

}
	
MainWindow::~MainWindow(){
	
}

