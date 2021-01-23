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
#include "ListWidgetView.h"

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

	QWidget* horiwontalLayoutWidget = new QWidget(centralWidget);
	horiwontalLayoutWidget->setObjectName(QString::fromUtf8("horiwontalLayoutWidget"));
	horiwontalLayoutWidget->setGeometry(QRect(40, 30, 771, 511));

	QHBoxLayout* horizontalLayout = new QHBoxLayout(horiwontalLayoutWidget);
	horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
	horizontalLayout->setSizeConstraint(QLayout::SetMaximumSize);
	horizontalLayout->setContentsMargins(0, 0, 0, 0);

	// ------------------------------------------------------------------
	// ------------------------------------------------------------------
	ListWidgetView* listWidgetView = new ListWidgetView(horiwontalLayoutWidget);
	
	horizontalLayout->addWidget(listWidgetView);

	//// ------------------------------------------------------------------
	//// ------------------------------------------------------------------
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

	//QObject::connect(ui.SelectFileRoot, &QPushButton::clicked, this, &MainWindow::getExistingDirectory);

}
	
MainWindow::~MainWindow(){
	
}

