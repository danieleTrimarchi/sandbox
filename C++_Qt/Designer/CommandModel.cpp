#include "CommandModel.h"

#include <QIcon>
#include <QMimeData>
#include <QRandomGenerator>
#include <iostream>

CommandModel::CommandModel(QObject* parent) :
    QAbstractListModel(parent) {

    children.append(new CommandItem(QIcon(":/icons/superLoc.png"), "SuperLoc"));
    children.append(new CommandItem(QIcon(":/icons/bandWidthDop.jpg"), "BandWidthDoppler"));
    children.append(new CommandItem(QIcon(":/icons/drop.png"), "Drop"));
    children.append(new CommandItem(QIcon(":/icons/analysisTreeRoot.png"), "Root"));

}

QVariant CommandModel::data(const QModelIndex& index, int role) const 
{
    if (!index.isValid())
        return QVariant();

    if (role == Qt::DisplayRole)
        return children.at(index.row())->text();
    else if (role == Qt::DecorationRole)
        return children.at(index.row())->icon();
    
    return QVariant();
}

Qt::ItemFlags CommandModel::flags(const QModelIndex& index) const
{
    if (index.isValid())
        return (QAbstractListModel::flags(index) | Qt::ItemIsDragEnabled);

    return Qt::ItemIsDropEnabled;
}


QStringList CommandModel::mimeTypes() const
{
    QStringList types;
    types << CommandModelMimeType();
    return types;
}

QMimeData* CommandModel::mimeData(const QModelIndexList& indexes) const
{
    QMimeData* mimeData = new QMimeData();

    QByteArray encodedData;
    QDataStream stream(&encodedData, QIODevice::WriteOnly);
    for (const QModelIndex& index : indexes) {
        if (index.isValid()) {
            std::cout << "child name= " << children.at(index.row())->text().toStdString() << std::endl;
            stream << children.at(index.row())->icon() << children.at(index.row())->text();
        }
    }
    // todo : remove this crap that is only used for the condition in CommandTreeView::dropEvent
    mimeData->setText(children.at(indexes.at(0).row())->text());
    mimeData->setImageData(children.at(indexes.at(0).row())->icon());

    mimeData->setData(CommandModelMimeType(), encodedData);
    return mimeData;
}

//bool CommandModel::dropMimeData(const QMimeData* data, Qt::DropAction action,
//    int row, int column, const QModelIndex& parent)
//{
//    if (!data->hasFormat(CommandModelMimeType()))
//        return false;
//
//    if (action == Qt::IgnoreAction)
//        return true;
//
//    if (column > 0)
//        return false;
//
//    int endRow;
//
//    if (!parent.isValid()) {
//        if (row < 0)
//            endRow = children.size();
//        else
//            endRow = qMin(row, children.size());
//    }
//    else {
//        endRow = parent.row();
//    }
//
//    QByteArray encodedData = data->data(CommandModelMimeType());
//    QDataStream stream(&encodedData, QIODevice::ReadOnly);
//
//    while (!stream.atEnd()) {
//        QIcon icon;
//        QString text;
//        stream >> icon >> text;
//        CommandItem* item = new CommandItem(icon, text);
//
//        beginInsertRows(QModelIndex(), endRow, endRow);
//        children.append(item);
//        endInsertRows();
//
//        ++endRow;
//    }
//
//    return true;
//}

int CommandModel::rowCount(const QModelIndex& parent) const
{
    return parent.isValid() ? 0 : children.size();
}

Qt::DropActions CommandModel::supportedDropActions() const
{
    return Qt::CopyAction | Qt::MoveAction;
}

