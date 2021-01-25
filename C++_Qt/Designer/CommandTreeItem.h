#include <QString>
#include <QVariant>
#include <QVector>

class CommandTreeItem
{
public:
    explicit CommandTreeItem(const QVector<QVariant> data, CommandTreeItem* =nullptr );

    ~CommandTreeItem();

    void appendChild(CommandTreeItem* child);

    bool insertChildren(int position, int count, int columns);
    bool insertColumns(int position, int columns);

    CommandTreeItem* child(int row);

    int childCount() const;
    int columnCount() const;

    QVariant data(int column) const;

    int row() const;

    CommandTreeItem* parent() const;
    int childNumber() const;

    bool setData(int column, const QVariant& value);

    bool removeColumns(int position, int columns);
    bool removeChildren(int position, int count);

    CommandTreeItem operator=(const CommandTreeItem& rhs); 

private:
    QVector<CommandTreeItem*> m_childItems;
    QVector<QVariant> m_itemData;
    CommandTreeItem* m_parentItem;
};