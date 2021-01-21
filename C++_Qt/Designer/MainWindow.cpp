#include "MainWindow.h"
#include <QRadioButton>
#include <QSpinBox>
#include <QVBoxLayout>
#include <QPushButton>
#include <QLabel>
#include "CommandItem.h"
#include <QListWidget>
#include <QSizePolicy>
#include "TreeModel.h"

MainWindow::MainWindow(QWidget* parent /*=nullptr*/) : 
	QMainWindow(parent) {

	ui.setupUi(this);

	//todo ! 
	// Set the vertical layout for dynamic resizing (all window width) 
	//ui.verticalLayoutWidget.
	
	// Set the items in listWidget
	ui.listWidget->clear();

	ui.listWidget->addItem(new CommandItem(QIcon(":/icons/superLoc.png"), "SuperLoc"));
	ui.listWidget->addItem(new CommandItem(QIcon(":/icons/bandWidthDop.jpg"), "BandWidthDoppler"));

	ui.listWidget->setViewMode(QListWidget::IconMode);
	ui.listWidget->setResizeMode(QListWidget::Adjust);
	ui.listWidget->setIconSize(QSize(100, 100));

	// Add an analysis root item to the tree 
	const QStringList headers({ tr("Title"), tr("Description") });

	TreeModel* treeModel = new TreeModel(headers,"Command stack");
	//treeModel->getRoot()->appendChild(new TreeItem("SuperLoc")); 

	QVector<QVariant> columnData;
	columnData.reserve(2);
	columnData << "MagnificItemName";
	columnData << QIcon(":/icons/superLoc.png");

	TreeItem* root(treeModel->getRoot());
	root->insertChildren(root->childCount(), 1, root->columnCount());
	for (int column = 0; column < columnData.size(); ++column)
		root->child(root->childCount() - 1)->setData(column, columnData[column]);

	ui.treeView->setModel(treeModel);

	QObject::connect(ui.SelectFileRoot, &QPushButton::clicked, this, &MainWindow::getExistingDirectory);

}
	
MainWindow::~MainWindow(){
	
}

