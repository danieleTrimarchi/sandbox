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
  
	QVBoxLayout* verticalLayout = new QVBoxLayout(centralWidget);
	verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
	verticalLayout->setContentsMargins(0, 0, 0, 0);
	
	QPushButton* addCommandButton = new QPushButton(centralWidget);
	addCommandButton->setObjectName(QString::fromUtf8("addCommandButton"));
	addCommandButton->setGeometry(QRect(0, 0, 40, 28));
	addCommandButton->setText("Add command"); 
	verticalLayout->addWidget(addCommandButton);

	QWidget* horizontalLayoutWidget = new QWidget(centralWidget);
	horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
	////horizontalLayoutWidget->setGeometry(QRect(0, 0, 679, 481));
	verticalLayout->addWidget(horizontalLayoutWidget);

	QHBoxLayout* horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
	horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
	horizontalLayout->setContentsMargins(0, 0, 0, 0);
	horizontalLayoutWidget->setLayout(horizontalLayout); 

	CommandListView* commandlistView = new CommandListView(horizontalLayoutWidget);
	horizontalLayout->addWidget(commandlistView);

	CommandTreeView* commandTreeView = new CommandTreeView(horizontalLayoutWidget);
	horizontalLayout->addWidget(commandTreeView);

	QObject::connect(addCommandButton, &QPushButton::clicked, 
					static_cast<CommandTreeModel*>(commandTreeView->model()), &CommandTreeModel::appendOneChild);

}
	
MainWindow::~MainWindow(){
	
}

