#include "TreeModel.h"
#include <QIcon>
#include <iostream>

TreeModel::TreeModel(const QStringList& headers, QObject* parent/*=nullptr*/)
    : QAbstractItemModel(parent) {

    QVector<QVariant> rootData;
    for (const QString& header : headers)
        rootData << header;

    rootItem = new TreeItem(rootData);
}

TreeModel::~TreeModel()
{
    delete rootItem;
}

QModelIndex TreeModel::index(int row, int column, const QModelIndex& parent) const
{
    if (!hasIndex(row, column, parent))
        return QModelIndex();

    TreeItem* parentItem;

    if (!parent.isValid())
        parentItem = rootItem;
    else
        parentItem = static_cast<TreeItem*>(parent.internalPointer());

    TreeItem* childItem = parentItem->child(row);
    if (childItem)
        return createIndex(row, column, childItem);
    return QModelIndex();
}

QModelIndex TreeModel::parent(const QModelIndex& index) const
{
    if (!index.isValid())
        return QModelIndex();

    TreeItem* childItem = static_cast<TreeItem*>(index.internalPointer());
    TreeItem* parentItem = childItem->parentItem();

    if (parentItem == rootItem)
        return QModelIndex();

    return createIndex(parentItem->row(), 0, parentItem);
}

int TreeModel::rowCount(const QModelIndex& parent) const
{
    TreeItem* parentItem;
    if (parent.column() > 0)
        return 0;

    if (!parent.isValid())
        parentItem = rootItem;
    else
        parentItem = static_cast<TreeItem*>(parent.internalPointer());

    return parentItem->childCount();
}

int TreeModel::columnCount(const QModelIndex& parent) const
{
    if (parent.isValid())
        return static_cast<TreeItem*>(parent.internalPointer())->columnCount();
    return rootItem->columnCount();
}


QVariant TreeModel::data(const QModelIndex& index, int role) const

{
    if (!index.isValid())
        return QVariant();

    TreeItem* item = static_cast<TreeItem*>(index.internalPointer());

    if (role == Qt::DisplayRole )
        return item->data(index.column());
    else if (role == Qt::DecorationRole) {
        return item->data(1);
    }
    else
        return QVariant();

}


Qt::ItemFlags TreeModel::flags(const QModelIndex& index) const
{
    //if (!index.isValid())
    //    return Qt::NoItemFlags;

    //return QAbstractItemModel::flags(index);

    Qt::ItemFlags defaultFlags = QAbstractItemModel::flags(index);
    return  Qt::ItemIsDropEnabled | defaultFlags;
}

QVariant TreeModel::headerData(int section, Qt::Orientation orientation,
    int role) const
{
    if (orientation == Qt::Horizontal && role == Qt::DisplayRole)
        return rootItem->data(section);

    return QVariant();
}

TreeItem* TreeModel::getRoot() const {
    return rootItem; 
}

bool TreeModel::dropMimeData(const QMimeData* data,
    Qt::DropAction action, int row, int column, const QModelIndex& parent)
{
    std::cout << "dropMimeData!!" << std::endl;
    return true; 
}

Qt::DropActions TreeModel::supportedDropActions() const {
    return Qt::CopyAction | Qt::MoveAction;
}
