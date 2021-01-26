#include "CommandTreeItem.h"
#include <QAbstractItemModel>

class CommandTreeModel : public QAbstractItemModel
{
    Q_OBJECT

public:
    CommandTreeModel(const QStringList& headers, QObject* parent=nullptr);
    ~CommandTreeModel();

    CommandTreeItem* getItem(const QModelIndex& index) const; 

    bool setData(const QModelIndex& index, const QVariant& value, int role); 
        
    QVariant data(const QModelIndex& index, int role) const override;

    Qt::ItemFlags flags(const QModelIndex& index) const override;

    QVariant headerData(int section, Qt::Orientation orientation,
        int role = Qt::DisplayRole) const override;

    QModelIndex index(int row, int column,
        const QModelIndex& parent = QModelIndex()) const override;

    QModelIndex parent(const QModelIndex& index) const override;

    int rowCount(const QModelIndex& parent = QModelIndex()) const override;

    int columnCount(const QModelIndex& parent = QModelIndex()) const override;

    CommandTreeItem* getRoot() const; 

    bool dropMimeData(const QMimeData* data, Qt::DropAction action, int row, int column, const QModelIndex& parent) override;

    Qt::DropActions supportedDropActions() const override;

    //QMimeData* mimeData(const QModelIndexList& indexes) const; 

    void appendOneChild();
    void removeOneChild();

    bool insertColumns(int position, int columns, const QModelIndex& parent); 
    bool insertRows(int position, int rows, const QModelIndex& parent); 
    bool removeColumns(int position, int columns, const QModelIndex& parent); 
    bool removeRows(int position, int rows, const QModelIndex& parent); 

private:

    CommandTreeItem* rootItem;

};