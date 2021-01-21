#include <QString>
#include <QVariant>
#include <QVector>

class TreeItem
{
public:
    explicit TreeItem(const QVector<QVariant> data, TreeItem* parentItem = nullptr);

    ~TreeItem();

    void appendChild(TreeItem* child);

    bool insertChildren(int position, int count, int columns);
    bool insertColumns(int position, int columns);

    TreeItem* child(int row);
    int childCount() const;
    int columnCount() const;
    QVariant data(int column) const;
    int row() const;
    TreeItem* parentItem();
    bool setData(int column, const QVariant& value);

private:
    QVector<TreeItem*> m_childItems;
    QVector<QVariant> m_itemData;
    TreeItem* m_parentItem;
};