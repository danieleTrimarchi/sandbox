#include "CommandTreeView.h"
#include "CommandTreeModel.h"
#include <QDragEnterEvent>
#include <QDropEvent>
#include <QMimeData>
#include <iostream>
#include <QMenu>
#include "Actions.h"

CommandTreeView::CommandTreeView(QWidget* parent /*= nullptr*/) : 
	QTreeView(parent) {
	setAcceptDrops(true);
	setDropIndicatorShown(true); 
	setDragEnabled(true);
	setDragDropMode(QAbstractItemView::DropOnly);
	
	CommandTreeModel* model = new CommandTreeModel(this);
	setModel(model);

	setWindowTitle(QObject::tr("Command Tree"));

	setContextMenuPolicy(Qt::CustomContextMenu); //  ActionsContextMenu);

	connect(this, SIGNAL(customContextMenuRequested(const QPoint&)), this, SLOT(onCustomContextMenu(const QPoint&)));
}

void CommandTreeView::onCustomContextMenu(const QPoint& point) {

	CommandTreeModel* pModel = static_cast<CommandTreeModel*>(model());
	CommandTreeItemBase* pItem = pModel->getItem(indexAt(point));
	std::cout << pItem->getName() <<std::endl;

	QPoint globalPos = mapToGlobal(point);
	QMenu contextMenu_;
	RemoveItemAction* removeItemAction_ = new RemoveItemAction(pModel, indexAt(point), &contextMenu_);
	contextMenu_.addAction(removeItemAction_);
	contextMenu_.exec(globalPos);
	std::cout << "And now can proceed with item removal... " << std::endl;
	
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
		QModelIndex parentIndex = indexAt(event->pos());
		DropIndicatorPosition dropIndicator = dropIndicatorPosition();
		QVector<QVariant> rootData;
		CommandTreeItemBase* parentItem;
		CommandTreeModel* cmdModel; 

		std::cout << "parentIndex is valid: " << parentIndex.isValid() <<
			"  row: " << parentIndex.row() << "  col: " << parentIndex.column() << std::endl;
		if (parentIndex.isValid() ) // && parentIndex.row() != -1)
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
				parentItem = cmdModel->getItem(parentIndex);
				std::cout << "On parent item " << parentItem->getName() << std::endl;
				std::cout << "     childcount= "<< parentItem->childCount() << std::endl;
				cmdModel->beginInsertRows(parentIndex, 0, 1);

				parentItem->appendChild(
					new CommandTreeItem("DroppedItem_" + std::to_string(parentItem->childCount()) + std::string("_") + event->mimeData()->text().toStdString(),
						event->mimeData()->imageData().value<QIcon>(), parentItem));
				cmdModel->endInsertRows();

				//emit cmdModel->dataChanged(parentIndex, parentIndex, { Qt::DisplayRole, Qt::EditRole });

//				expand(parentIndex);
				expandAll();
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