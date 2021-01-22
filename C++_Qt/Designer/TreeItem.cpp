#include "TreeItem.h"
#include <qicon.h>

TreeItem::TreeItem(const QVector<QVariant> data, TreeItem* parent) :
    m_itemData(data), m_parentItem(parent)
{
}

TreeItem::~TreeItem()
{
    qDeleteAll(m_childItems);
}

void TreeItem::appendChild(TreeItem* item)
{
    m_childItems.append(item);
}


bool TreeItem::insertChildren(int position, int count, int columns)
{
    if (position < 0 || position > m_childItems.size())
        return false;

    for (int row = 0; row < count; ++row) {
        QVector<QVariant> data(columns);
        TreeItem* item = new TreeItem(data, this);
        m_childItems.insert(position, item);
    }

    return true;
}

bool TreeItem::insertColumns(int position, int columns)
{
    if (position < 0 || position > m_childItems.size())
        return false;

    for (int column = 0; column < columns; ++column)
        m_itemData.insert(position, QVariant());

    for (TreeItem* child : qAsConst(m_childItems))
        child->insertColumns(position, columns);

    return true;
}


TreeItem* TreeItem::child(int row)
{
    if (row < 0 || row >= m_childItems.size())
        return nullptr;
    return m_childItems.at(row);
}

int TreeItem::childCount() const
{
    return m_childItems.count();
}

int TreeItem::row() const
{
    if (m_parentItem)
        return m_parentItem->m_childItems.indexOf(const_cast<TreeItem*>(this));

    return 0;
}

int TreeItem::columnCount() const
{
    return 1;
}

QVariant TreeItem::data(int column) const
{
    if (column < 0 || column >= m_itemData.size())
        return QVariant();
    return m_itemData.at(column);
}

TreeItem* TreeItem::parentItem()
{
    return m_parentItem;
}

bool TreeItem::setData(int column, const QVariant& value)
{
    if (column < 0 || column >= m_itemData.size())
        return false;

    m_itemData[column] = value;
    return true;
}

TreeItem TreeItem::operator=(const TreeItem& rhs) {
    m_childItems = rhs.m_childItems;
    m_itemData = rhs.m_itemData;
    m_parentItem = rhs.m_parentItem;
    return *this;
}
