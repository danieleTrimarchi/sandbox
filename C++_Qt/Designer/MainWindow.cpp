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
#include "TreeView.h"
#include "ListWidget.h"

MainWindow::MainWindow(QWidget* parent /*=nullptr*/) : 
	QMainWindow(parent) {

	ui.setupUi(this);

	//todo ! 
	// Set the vertical layout for dynamic resizing (all window width) 
	//ui.verticalLayoutWidget.
	
	// ----------------------------------------------------------

	const QStringList headers({ tr("Command stack") });
	TreeModel* treeModel = new TreeModel(headers);

	QVector<QVariant> columnData;
	columnData.reserve(2);
	columnData << "MagnificItemName";
	columnData << QIcon(":/icons/superLoc.png");

	TreeItem* root(treeModel->getRoot());
	root->insertChildren(root->childCount(), 1, columnData.size());
	for (int column = 0; column < columnData.size(); column++)
		root->child(root->childCount() - 1)->setData(column, columnData[column]);
	// ----------------------------------------------------------
		ListWidget* listWidget = new ListWidget(ui.verticalLayoutWidget);

		new QListWidgetItem(listWidget);
		new QListWidgetItem(listWidget);
		QIcon icon;
		listWidget->setObjectName(QString::fromUtf8("listWidget"));
		QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
		sizePolicy1.setHorizontalStretch(0);
		sizePolicy1.setVerticalStretch(0);
		sizePolicy1.setHeightForWidth(listWidget->sizePolicy().hasHeightForWidth());
		listWidget->setSizePolicy(sizePolicy1);
		listWidget->setDragEnabled(true);
		listWidget->setDragDropOverwriteMode(true);
		listWidget->setDragDropMode(QAbstractItemView::DragOnly);
		const bool __sortingEnabled1 = listWidget->isSortingEnabled();
		listWidget->setSortingEnabled(false);

		listWidget->addItem(new CommandItem(QIcon(":/icons/superLoc.png"), "SuperLoc"));
		listWidget->addItem(new CommandItem(QIcon(":/icons/bandWidthDop.jpg"), "BandWidthDoppler"));

		listWidget->setViewMode(QListWidget::IconMode);
		listWidget->setResizeMode(QListWidget::Adjust);
		listWidget->setIconSize(QSize(100, 100));

		ui.horizontalLayout_2->addWidget(listWidget);

	// ----------------------------------------------------------
	TreeView* treeView = new TreeView(ui.verticalLayoutWidget);
	treeView->setObjectName(QString::fromUtf8("treeView"));
	treeView->setEnabled(true);
	//sizePolicy1.setHeightForWidth(treeView->sizePolicy().hasHeightForWidth());
	//treeView->setSizePolicy(sizePolicy1);
	treeView->setMouseTracking(true);
	treeView->setAutoFillBackground(true);
	treeView->setFrameShape(QFrame::StyledPanel);
	treeView->setFrameShadow(QFrame::Sunken);
	treeView->setMidLineWidth(-1);
	treeView->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
	treeView->setDragEnabled(true);
	treeView->setDragDropOverwriteMode(true);
	treeView->setDragDropMode(QAbstractItemView::DropOnly);
	treeView->setDefaultDropAction(Qt::CopyAction);
	treeView->setAlternatingRowColors(true);
	treeView->setSelectionBehavior(QAbstractItemView::SelectRows);
	treeView->header()->setCascadingSectionResizes(false);

	ui.verticalLayout_2->addWidget(treeView);
	
	QPushButton* pushButton_2 = new QPushButton(ui.verticalLayoutWidget);
	pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
	pushButton_2->setText(QApplication::translate("MainWindow", "Clear", nullptr));

	ui.verticalLayout_2->addWidget(pushButton_2);

	treeView->setModel(treeModel);

	// ----------------------------------------------------------

	QObject::connect(ui.SelectFileRoot, &QPushButton::clicked, this, &MainWindow::getExistingDirectory);

}
	
MainWindow::~MainWindow(){
	
}

