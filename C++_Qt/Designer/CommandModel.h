#ifndef COMMANDMODEL_H
#define COMMANDMODEL_H

#include <QAbstractListModel>
#include <QVector>
#include <QVector>
#include "CommandItem.h"

class CommandModel : public QAbstractListModel
{

    Q_OBJECT

public:
    explicit CommandModel(QObject * parent = nullptr);

    QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override;
    Qt::ItemFlags flags(const QModelIndex& index) const override;

    bool dropMimeData(const QMimeData* data, Qt::DropAction action,
        int row, int column, const QModelIndex& parent) override;
    QMimeData* mimeData(const QModelIndexList& indexes) const override;
    QStringList mimeTypes() const override;
    int rowCount(const QModelIndex& parent) const override;
    Qt::DropActions supportedDropActions() const override;

private:
    QVector<CommandItem*> children;

};

#endif
