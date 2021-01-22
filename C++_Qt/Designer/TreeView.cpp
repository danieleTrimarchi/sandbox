#include "TreeView.h"
#include "TreeModel.h"
#include <QDragEnterEvent>
#include <QDropEvent>
#include <QMimeData>

TreeView::TreeView(QWidget* parent /*= nullptr*/) : 
	QTreeView(parent) {
	setAcceptDrops(true);
	setDropIndicatorShown(true); 
	setDragEnabled(true);
	//setDragDropMode(QAbstractItemView::DropOnly);

}

void TreeView::dragEnterEvent(QDragEnterEvent* event)
{
	if (event->mimeData()->hasText() &&
			event->mimeData()->hasImage() )
		event->acceptProposedAction();
}

void TreeView::dropEvent(QDropEvent* event)
{
	if (event->mimeData()->hasFormat("text/plain")) {
		event->accept();
		event->setDropAction(Qt::CopyAction);
		//QListWidgetItem* item = new QListWidgetItem;
		//QString name = event->mimeData()->data("application/x-item");
		//item->setText(name);
		//item->setIcon(QIcon(":/images/iString")); //set path to image
		//addItem(item);
		TreeItem* root(static_cast<TreeModel*>(model())->getRoot());
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