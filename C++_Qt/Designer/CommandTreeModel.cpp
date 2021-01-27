#include "CommandTreeModel.h"
#include <QIcon>
#include <iostream>

CommandTreeModel::CommandTreeModel( QObject* parent/*=nullptr*/)
    : QAbstractItemModel(parent) {

    rootItem = new CommandTreeItem("Command stack",QIcon(":/icons/superLoc.png"));
}

CommandTreeModel::~CommandTreeModel()
{
    delete rootItem;
}

QModelIndex CommandTreeModel::index(int row, int column, const QModelIndex& parent) const
{
    if (!hasIndex(row, column, parent))
        return QModelIndex();

    CommandTreeItem* parentItem;

    if (!parent.isValid())
        parentItem = rootItem;
    else
        parentItem = static_cast<CommandTreeItem*>(parent.internalPointer());

    CommandTreeItem* childItem = parentItem->child(row);
    if (childItem)
        return createIndex(row, column, childItem);
    return QModelIndex();
}

//bool CommandTreeModel::insertColumns(int position, int columns, const QModelIndex& parent)
//{
//    beginInsertColumns(parent, position, position + columns - 1);
//    const bool success = rootItem->insertColumns(position, columns);
//    endInsertColumns();
//
//    return success;
//}

//bool CommandTreeModel::insertRows(int position, int rows, int nCols, const QModelIndex& parent)
//{
//    CommandTreeItem* parentItem = getItem(parent);
//    if (!parentItem)
//        return false;
//
//    int colCnt = rootItem->columnCount(); 
//
//    beginInsertRows(parent, position, position + rows - 1);
//    const bool success = parentItem->insertChildren(position,
//        rows,
//        nCols);
//    endInsertRows();
//
//    return success;
//}

QModelIndex CommandTreeModel::parent(const QModelIndex& index) const
{
    if (!index.isValid())
        return QModelIndex();

    CommandTreeItem* childItem = getItem(index);;
    CommandTreeItem* parentItem = childItem ? childItem->parent() : nullptr;

    if (parentItem == rootItem || !parentItem)
        return QModelIndex();

    return createIndex(parentItem->childNumber(), 0, parentItem);
}

//bool CommandTreeModel::removeColumns(int position, int columns, const QModelIndex& parent)
//{
//    beginRemoveColumns(parent, position, position + columns - 1);
//    const bool success = rootItem->removeColumns(position, columns);
//    endRemoveColumns();
//
//    if (rootItem->columnCount() == 0)
//        removeRows(0, rowCount(),parent);
//
//    return success;
//}
//
//bool CommandTreeModel::removeRows(int position, int rows, const QModelIndex& parent)
//{
//    CommandTreeItem* parentItem = getItem(parent);
//    if (!parentItem)
//        return false;
//
//    beginRemoveRows(parent, position, position + rows - 1);
//    const bool success = parentItem->removeChildren(position, rows);
//    endRemoveRows();
//
//    return success;
//}
bool CommandTreeModel::removeItem(const QModelIndex& item) {

    CommandTreeItem* pItem = getItem(item);
    if(!pItem)
        return false;
    if (!pItem->parent())
        return false; 
    std::cout << "Row" << item.row() << std::endl;
    std::cout << "ChildCount : " << pItem->parent()->childCount() << std::endl;
    beginRemoveRows(item.parent(), item.row(), item.row());
    const bool success = pItem->parent()->removeChildren(item.row(), 1);
    endRemoveRows();

    return success;
}


int CommandTreeModel::rowCount(const QModelIndex& parent) const
{
    CommandTreeItem* parentItem;
    if (parent.column() > 0)
        return 0;

    if (!parent.isValid())
        parentItem = rootItem;
    else
        parentItem = static_cast<CommandTreeItem*>(parent.internalPointer());

    return parentItem->childCount();
}

int CommandTreeModel::columnCount(const QModelIndex& parent) const
{
    if (parent.isValid())
        return static_cast<CommandTreeItem*>(parent.internalPointer())->columnCount();
    return rootItem->columnCount();
}

CommandTreeItem* CommandTreeModel::getItem(const QModelIndex& index) const
{
    if (index.isValid()) {
        CommandTreeItem* item = static_cast<CommandTreeItem*>(index.internalPointer());
        if (item)
            return item;
    }
    return rootItem;
}

bool CommandTreeModel::setData(const QModelIndex& index, const QVariant& value, int role)
{
    if (role != Qt::EditRole)
        return false;

    if (!index.isValid())
        return false; 

    CommandTreeItem* item = getItem(index);
    bool result = item->setData(index.column(), value);

    if (result)
        emit dataChanged(index, index, { Qt::DisplayRole, Qt::EditRole });

    return result;
}


QVariant CommandTreeModel::data(const QModelIndex& index, int role) const
{
    if (!index.isValid())
        return QVariant();

    CommandTreeItem* item = static_cast<CommandTreeItem*>(getItem(index));

    if (role == Qt::DisplayRole || role == Qt::DecorationRole) {
        return item->data(index.column());
    }
    else
        return QVariant();
}


Qt::ItemFlags CommandTreeModel::flags(const QModelIndex& index) const
{
    //if (!index.isValid())
    //    return Qt::NoItemFlags;

    //return QAbstractItemModel::flags(index);

    Qt::ItemFlags defaultFlags = QAbstractItemModel::flags(index);
    return Qt::ItemIsEditable | Qt::ItemIsDropEnabled | defaultFlags;
}

QVariant CommandTreeModel::headerData(int section, Qt::Orientation orientation,
    int role) const
{
    if (orientation == Qt::Horizontal && role == Qt::DisplayRole)
        return rootItem->data(section);

    return QVariant();
}

CommandTreeItem* CommandTreeModel::getRoot() const {
    return rootItem; 
}

bool CommandTreeModel::dropMimeData(const QMimeData* data,
    Qt::DropAction action, int row, int column, const QModelIndex& parent)
{
    std::cout << "dropMimeData!!" << std::endl;
    return true; 
}

Qt::DropActions CommandTreeModel::supportedDropActions() const {
    return Qt::CopyAction | Qt::MoveAction;
}


void CommandTreeModel::appendOneChild() {

    QModelIndex rootIdx;
    CommandTreeItem* pRootItem = getItem(rootIdx);
    int position = rowCount(rootIdx);

    beginInsertRows(rootIdx, position, position);

    std::string name = "SuperLocAnalysis_" + std::to_string(position);
    rootItem->appendChild(new CommandTreeItem(name, QIcon(":/icons/superLoc.png"), pRootItem));

    endInsertRows();

}