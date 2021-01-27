#include "CommandTreeView.h"
#include "CommandTreeModel.h"
#include <QDragEnterEvent>
#include <QDropEvent>
#include <QMimeData>
#include <iostream>
#include <QMenu>

CommandTreeView::CommandTreeView(QWidget* parent /*= nullptr*/) : 
	QTreeView(parent) {
	setAcceptDrops(true);
	setDropIndicatorShown(true); 
	setDragEnabled(true);
	setDragDropMode(QAbstractItemView::DropOnly);
	
	CommandTreeModel* model = new CommandTreeModel(this);
	setModel(model);

	setContextMenuPolicy(Qt::CustomContextMenu); //  ActionsContextMenu);

	//connect(removeItemAction_, SIGNAL(triggered()), this, SLOT(removeOneItem()));

	connect(this, SIGNAL(customContextMenuRequested(const QPoint&)), this, SLOT(onCustomContextMenu(const QPoint&)));
}

void CommandTreeView::onCustomContextMenu(const QPoint& point) {

	CommandTreeModel* pModel = static_cast<CommandTreeModel*>(model());
	CommandTreeItem* pItem = pModel->getItem(indexAt(point)); 
	std::cout << pItem->data(CTI::colContent::name).toString().toStdString() <<std::endl;

	QPoint globalPos = mapToGlobal(point);
	QMenu contextMenu_;
	QAction* removeItemAction_ = new QAction("Delete...", &contextMenu_);
	contextMenu_.addAction(removeItemAction_);
	contextMenu_.exec(globalPos);

	std::cout << "And now can proceed with item removal... " << std::endl;
	pModel->removeItem(indexAt(point));
}


void CommandTreeView::dragEnterEvent(QDragEnterEvent* event)
{
	if (event->mimeData()->hasText() &&
			event->mimeData()->hasImage() )
		event->accept();
	else
		event->ignore();
}

void CommandTreeView::dragMoveEvent(QDragMoveEvent* event)
{
	std::cout << "dragMoveEvent for " << event->mimeData()->text().toStdString() << std::endl;
//
//	QRect updateRect = highlightedRect.united(targetSquare(event->pos()));
//
	if (event->mimeData()->hasFormat(CommandModel::CommandModelMimeType())) {
		//		&& findPiece(targetSquare(event->pos())) == -1) {
//
//		highlightedRect = targetSquare(event->pos());
		event->setDropAction(Qt::MoveAction);

		//		event->accept();
	}
	else {
		event->ignore();
	}
//
//	update(updateRect);
}


void CommandTreeView::dropEvent(QDropEvent* event)
{
	std::cout << "dropEvent for " << event->mimeData()->text().toStdString() << std::endl;

	if (event->mimeData()->hasFormat(CommandModel::CommandModelMimeType())) {

		event->accept();
		event->setDropAction(Qt::CopyAction);

		// from: https://stackoverflow.com/questions/37524292/get-the-position-of-a-drop-relative-to-an-item-on-a-qtreewidget
		QModelIndex dropIndex = indexAt(event->pos());
		DropIndicatorPosition dropIndicator = dropIndicatorPosition();
		QVector<QVariant> rootData;
		CommandTreeItem* item; 
		CommandTreeModel* cmdModel; 

		if (!dropIndex.parent().isValid() && dropIndex.row() != -1)
		{
			switch (dropIndicator)
			{
			case QAbstractItemView::AboveItem:
				// manage a boolean for the case when you are above an item
				break;
			case QAbstractItemView::BelowItem:
				// something when being below an item
				break;
			case QAbstractItemView::OnItem:

				cmdModel = static_cast<CommandTreeModel*>(model()); 
				item = cmdModel->getItem(dropIndex);
				std::cout << "On item " << item->data(CTI::colContent::name).toString().toStdString() << std::endl;

				item->appendChild(
					new CommandTreeItem("DroppedItem_" + item->data(CTI::colContent::name).toString().toStdString(),
										QIcon(":/icons/drop.png"), item));
				emit cmdModel->dataChanged(dropIndex, dropIndex, { Qt::DisplayRole, Qt::EditRole });

				//cmdModel->setData(
				//	cmdModel->index(0,0,dropIndex),
				//	QString("DroppedItem"), Qt::EditRole
				//);

//				item->appendChild(new CommandTreeItem(rootData, item)); 

				// you're on an item, maybe add the current one as a child
				break;
			case QAbstractItemView::OnViewport:
				// you are not on your tree
				break;
			}
		}

	//	//QListWidgetItem* item = new QListWidgetItem;
	//	//QString name = event->mimeData()->data("application/x-item");
	//	//item->setText(name);
	//	//item->setIcon(QIcon(":/images/iString")); //set path to image
	//	//addItem(item);
	//	CommandTreeItem* root(static_cast<CommandTreeModel*>(model())->getRoot());
	//	size_t nCols = 2;
	//	root->insertChildren(root->childCount(), 1, nCols);

	//	root->child(root->childCount() - 1)->setData(0, event->mimeData()->text());
	//	root->child(root->childCount() - 1)->setData(1, event->mimeData()->imageData());
	}
	//else
	//	event->ignore();

	//textBrowser->setPlainText(event->mimeData()->text());
	//mimeTypeCombo->clear();
	//mimeTypeCombo->addItems(event->mimeData()->formats());

	//event->acceptProposedAction();
}