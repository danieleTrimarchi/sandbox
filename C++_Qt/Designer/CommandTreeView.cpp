#include "CommandTreeView.h"
#include "CommandTreeModel.h"
#include <QDragEnterEvent>
#include <QDropEvent>
#include <QMimeData>

CommandTreeView::CommandTreeView(QWidget* parent /*= nullptr*/) : 
	QTreeView(parent) {
	setAcceptDrops(true);
	setDropIndicatorShown(true); 
	setDragEnabled(true);
	//setDragDropMode(QAbstractItemView::DropOnly);
	
	QStringList headers{ tr("User Command Stack") };

	CommandTreeModel* model = new CommandTreeModel(headers, this);
	setModel(model);

}

void CommandTreeView::dragEnterEvent(QDragEnterEvent* event)
{
	if (event->mimeData()->hasText() &&
			event->mimeData()->hasImage() )
		event->acceptProposedAction();
}

void CommandTreeView::dropEvent(QDropEvent* event)
{
	if (event->mimeData()->hasFormat("text/plain")) {
		event->accept();
		event->setDropAction(Qt::CopyAction);
		//QListWidgetItem* item = new QListWidgetItem;
		//QString name = event->mimeData()->data("application/x-item");
		//item->setText(name);
		//item->setIcon(QIcon(":/images/iString")); //set path to image
		//addItem(item);
		CommandTreeItem* root(static_cast<CommandTreeModel*>(model())->getRoot());
		size_t nCols = 2;
		root->insertChildren(root->childCount(), 1, nCols);

		root->child(root->childCount() - 1)->setData(0, event->mimeData()->text());
		root->child(root->childCount() - 1)->setData(1, event->mimeData()->imageData());
	}
	else
		event->ignore();

	//textBrowser->setPlainText(event->mimeData()->text());
	//mimeTypeCombo->clear();
	//mimeTypeCombo->addItems(event->mimeData()->formats());

	event->acceptProposedAction();
}