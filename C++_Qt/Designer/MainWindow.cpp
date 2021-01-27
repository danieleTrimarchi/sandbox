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
	buttonBarWidget->setGeometry(QRect(590, 490, 679, 31));

	QPushButton* addCommandButton = new QPushButton(buttonBarWidget);
	addCommandButton->setObjectName(QString::fromUtf8("addCommandButton"));
	addCommandButton->setGeometry(QRect(0, 0, 93, 28));
	addCommandButton->setText("Add command"); 
	
	verticalLayout->addWidget(CommandLayoutWidget);
	verticalLayout->addWidget(buttonBarWidget);

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

}
	
MainWindow::~MainWindow(){
	
}

