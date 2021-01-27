#include "CommandTreeItem.h"
#include <qicon.h>

CommandTreeItem::CommandTreeItem(
    const QVector<QVariant> data, CommandTreeItem* parent/*=nullptr*/ ) :
    m_itemData(data), m_parentItem(parent)
{
}

CommandTreeItem::~CommandTreeItem()
{
    qDeleteAll(m_childItems);
}

void CommandTreeItem::appendChild(CommandTreeItem* item)
{
    m_childItems.append(item);
}


bool CommandTreeItem::insertChildren(int position, int count, int columns)
{
    if (position < 0 || position > m_childItems.size())
        return false;

    for (int row = 0; row < count; ++row) {
        QVector<QVariant> data(columns);
        CommandTreeItem* item = new CommandTreeItem(data, this);
        m_childItems.insert(position, item);
    }

    return true;
}

bool CommandTreeItem::insertColumns(int position, int columns)
{
    if (position < 0 || position > m_childItems.size())
        return false;

    for (int column = 0; column < columns; ++column)
        m_itemData.insert(position, QVariant());

    for (CommandTreeItem* child : qAsConst(m_childItems))
        child->insertColumns(position, columns);

    return true;
}


CommandTreeItem* CommandTreeItem::child(int row)
{
    if (row < 0 || row >= m_childItems.size())
        return nullptr;
    return m_childItems.at(row);
}

int CommandTreeItem::childCount() const
{
    return m_childItems.count();
}

int CommandTreeItem::row() const
{
    if (m_parentItem)
        return m_parentItem->m_childItems.indexOf(const_cast<CommandTreeItem*>(this));

    return 0;
}

int CommandTreeItem::columnCount() const
{
    return m_itemData.size();
}

CommandTreeItem* CommandTreeItem::parent() const {
    return m_parentItem;
}

int CommandTreeItem::childNumber() const {
    if (m_parentItem)
        return m_parentItem->m_childItems.indexOf(const_cast<CommandTreeItem*>(this));
    return 0;
}

QVariant CommandTreeItem::data(int column) const
{
    if (column < 0 || column >= m_itemData.size())
        return QVariant();
    return m_itemData.at(column);
}

bool CommandTreeItem::setData(int column, const QVariant& value)
{
    if (column < 0 || column >= m_itemData.size())
        return false;

    m_itemData[column] = value;
    return true;
}

bool CommandTreeItem::removeColumns(int position, int columns)
{
    if (position < 0 || position + columns > m_itemData.size())
        return false;

    for (int column = 0; column < columns; ++column)
        m_itemData.remove(position);

    for (CommandTreeItem* child : qAsConst(m_childItems))
        child->removeColumns(position, columns);

    return true;
}


bool CommandTreeItem::removeChildren(int position, int count)
{
    if (position < 0 || position + count > m_childItems.size())
        return false;

    for (int row = 0; row < count; ++row)
        delete m_childItems.takeAt(position);

    return true;
}

CommandTreeItem CommandTreeItem::operator=(const CommandTreeItem& rhs) {
    m_childItems = rhs.m_childItems;
    m_itemData = rhs.m_itemData;
    m_parentItem = rhs.m_parentItem;
    return *this;
}
