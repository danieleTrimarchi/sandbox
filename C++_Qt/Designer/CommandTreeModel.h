#include "CommandTreeItem.h"
#include <QAbstractItemModel>

class CommandTreeView;

class CommandTreeModel : public QAbstractItemModel
{
    Q_OBJECT

public:
    CommandTreeModel(CommandTreeView* parent=nullptr);
    ~CommandTreeModel();

    CommandTreeItemBase* getItem(const QModelIndex& index) const; 

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

    // Returns the 'fake' root, or the visible root item 
    CommandTreeItemBase* getRoot() const;

    Qt::DropActions supportedDropActions() const override;

    //QMimeData* mimeData(const QModelIndexList& indexes) const; 

    void appendOneChild();

//    bool insertColumns(int position, int columns, const QModelIndex& parent); 
    //bool insertRows(int position, int rows, int nCols, const QModelIndex& parent); 
  /*  bool removeColumns(int position, int columns, const QModelIndex& parent); 
    bool removeRows(int position, int rows, const QModelIndex& parent); */
    bool removeItem(const QModelIndex& parent); 

    // todo : this is crap, I add this because of CommandTreeView::dropEvent(QDropEvent* event)
    // to be entirely refactored ! 
    void beginInsertRows(const QModelIndex& parent, int first, int last);
    void endInsertRows();

private:

    CommandTreeItemRoot* rootItem_;

};