#include "MainWindow.h"
#include <QRadioButton>
#include <QSpinBox>
#include <QVBoxLayout>
#include <QPushButton>
#include <QLabel>
#include "CommandItem.h"
#include <QListWidget>
#include <QSizePolicy>
#include "CommandListView.h"
#include "CommandTreeView.h"
#include "CommandTreeModel.h"

MainWindow::MainWindow(QWidget* parent /*=nullptr*/) : 
	QMainWindow(parent) {

	setObjectName(QString::fromUtf8("BatchProcessingTool"));

	this->resize(954, 808);
	centralWidget = new QWidget(this);
	centralWidget->setObjectName(QString::fromUtf8("centralwidget"));

	QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
	sizePolicy.setHorizontalStretch(0);
	sizePolicy.setVerticalStretch(0);
	sizePolicy.setHeightForWidth(centralWidget->sizePolicy().hasHeightForWidth());
	centralWidget->setSizePolicy(sizePolicy);

	this->setCentralWidget(centralWidget);

	// Set the widgets and the layouts  
	QWidget* verticalLayoutWidget = new QWidget(centralWidget);
	verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
	verticalLayoutWidget->setGeometry(QRect(60, 20, 681, 521));

	QVBoxLayout* verticalLayout = new QVBoxLayout(verticalLayoutWidget);
	verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
	verticalLayout->setContentsMargins(0, 0, 0, 0);

	QWidget* CommandLayoutWidget = new QWidget(verticalLayoutWidget);
	CommandLayoutWidget->setObjectName(QString::fromUtf8("CommandLayoutWidget"));

	QWidget* horizontalLayoutWidget = new QWidget(CommandLayoutWidget);
	horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
	horizontalLayoutWidget->setGeometry(QRect(0, 0, 679, 481));
	
	QHBoxLayout* horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
	horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
	horizontalLayout->setContentsMargins(0, 0, 0, 0);

	QWidget* buttonBarWidget = new QWidget(CommandLayoutWidget);
	buttonBarWidget->setObjectName(QString::fromUtf8("buttonBarWidget"));

	QPushButton* addCommandButton = new QPushButton(buttonBarWidget);
	addCommandButton->setObjectName(QString::fromUtf8("addCommandButton"));
	addCommandButton->setText("Add command"); 
	addCommandButton->setGeometry(QRect(490, 490, 93, 28));

	QPushButton* rmCommandButton = new QPushButton(buttonBarWidget);
	rmCommandButton->setObjectName(QString::fromUtf8("rmCommandButton"));
	rmCommandButton->setText("Remove command");
	rmCommandButton->setGeometry(QRect(600, 490, 93, 28));

	verticalLayout->addWidget(CommandLayoutWidget);

	// ------------------------------------------------------------------
	// Add the (source) command list widget 
	CommandListView* commandlistView = new CommandListView(horizontalLayoutWidget);
	horizontalLayout->addWidget(commandlistView);

	// ------------------------------------------------------------------
	// Add the (dst) command item tree widget 
	CommandTreeView* commandTreeView = new CommandTreeView(horizontalLayoutWidget);
	horizontalLayout->addWidget(commandTreeView);

	QObject::connect(addCommandButton, &QPushButton::clicked, 
					static_cast<CommandTreeModel*>(commandTreeView->model()), &CommandTreeModel::appendOneChild);
	QObject::connect(rmCommandButton, &QPushButton::clicked,
		static_cast<CommandTreeModel*>(commandTreeView->model()), &CommandTreeModel::removeOneChild);

	//// ------------------------------------------------------------------
	//// ------------------------------------------------------------------
	//QListWidget* commandList = new QListWidget(horizontalLayoutWidget);
	//commandList->setObjectName(QString::fromUtf8("commandList"));

	//horizontalLayout->addWidget(commandList);

	//QPushButton* pushButton = new QPushButton(horizontalLayoutWidget);
	//pushButton->setObjectName(QString::fromUtf8("addItem"));
	//horizontalLayout->addWidget(pushButton);

	////todo ! 
	//// Set the vertical layout for dynamic resizing (all window width) 
	////ui.verticalLayoutWidget.
	//
	//// ----------------------------------------------------------

	//const QStringList headers({ tr("Command stack") });
	//TreeModel* treeModel = new TreeModel(headers);

	//QVector<QVariant> columnData;
	//columnData.reserve(2);
	//columnData << "MagnificItemName";
	//columnData << QIcon(":/icons/superLoc.png");

	//TreeItem* root(treeModel->getRoot());
	//root->insertChildren(root->childCount(), 1, columnData.size());
	//for (int column = 0; column < columnData.size(); column++)
	//	root->child(root->childCount() - 1)->setData(column, columnData[column]);
	//// ----------------------------------------------------------
	//	

	//// ----------------------------------------------------------
	//TreeView* treeView = new TreeView(ui.verticalLayoutWidget);
	//treeView->setObjectName(QString::fromUtf8("treeView"));
	//treeView->setEnabled(true);
	////sizePolicy1.setHeightForWidth(treeView->sizePolicy().hasHeightForWidth());
	////treeView->setSizePolicy(sizePolicy1);
	//treeView->setMouseTracking(true);
	//treeView->setAutoFillBackground(true);
	//treeView->setFrameShape(QFrame::StyledPanel);
	//treeView->setFrameShadow(QFrame::Sunken);
	//treeView->setMidLineWidth(-1);
	//treeView->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
	//treeView->setDragEnabled(true);
	//treeView->setDragDropOverwriteMode(true);
	//treeView->setDragDropMode(QAbstractItemView::DropOnly);
	//treeView->setDefaultDropAction(Qt::CopyAction);
	//treeView->setAlternatingRowColors(true);
	//treeView->setSelectionBehavior(QAbstractItemView::SelectRows);
	//treeView->header()->setCascadingSectionResizes(false);

	//ui.verticalLayout_2->addWidget(treeView);
	//
	//QPushButton* pushButton_2 = new QPushButton(ui.verticalLayoutWidget);
	//pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
	//pushButton_2->setText(QApplication::translate("MainWindow", "Clear", nullptr));

	//ui.verticalLayout_2->addWidget(pushButton_2);

	//treeView->setModel(treeModel);

	//// ----------------------------------------------------------


}
	
MainWindow::~MainWindow(){
	
}

