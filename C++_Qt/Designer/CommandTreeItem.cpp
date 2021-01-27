#include "CommandTreeItem.h"
#include <qicon.h>
#include <iostream>

CommandTreeItem::CommandTreeItem(
   const std::string name, const QIcon icon, CommandTreeItem* parent /*=nullptr*/):
    name_(std::move(name)),
    icon_(std::move(icon)),
    parent_(parent) {    
    std::cout << "creating item : " << name_ << std::endl;
    children_.clear(); 
}

CommandTreeItem::~CommandTreeItem()
{
    qDeleteAll(children_);
}

void CommandTreeItem::appendChild(CommandTreeItem* item)
{
   children_.append(item);
}


//bool CommandTreeItem::insertChildren(int position, int count, int columns)
//{
//    if (position < 0 || position > children_.size())
//        return false;
//
//    for (int row = 0; row < count; ++row) {
//        QVector<QVariant> data(columns);
//        CommandTreeItem* item = new CommandTreeItem(data, this);
//        children_.insert(position, item);
//    }
//
//    return true;
//}
//
//bool CommandTreeItem::insertColumns(int position, int columns)
//{
//    if (position < 0 || position > children_.size())
//        return false;
//
//    for (int column = 0; column < columns; ++column)
//        m_itemData.insert(position, QVariant());
//
//    for (CommandTreeItem* child : qAsConst(children_))
//        child->insertColumns(position, columns);
//
//    return true;
//}


CommandTreeItem* CommandTreeItem::child(int row)
{
    if (row < 0 || row >= children_.size())
        return nullptr;
    return children_.at(row);
}

int CommandTreeItem::childCount() const
{
    return children_.count();
}

int CommandTreeItem::columnCount() const
{
    return CTI::colContent::size;
}

CommandTreeItem* CommandTreeItem::parent() const {
    return parent_;
}

int CommandTreeItem::childNumber() const {
    if (parent_)
        return parent_->children_.indexOf(const_cast<CommandTreeItem*>(this));
    return 0;
}

QVariant CommandTreeItem::data(int column) const
{
    if (column < 0 || column >= CTI::colContent::size)
        return QVariant();

    switch (column)
    {
    case CTI::colContent::name:
        return QVariant(name_.c_str());
        break;
    case CTI::colContent::icon:
        return QVariant(icon_);
        break;
    default:
        return QVariant();
    }
}

bool CommandTreeItem::setData(int column, const QVariant value)
{
    if (column < 0 || column >= CTI::colContent::size)
        return false;

    switch (column)
    {
    case CTI::colContent::name:
        name_= std::move(value.toString().toStdString());
        return true; 
        break;
    case CTI::colContent::icon:
        icon_ = std::move(value.value<QIcon>());
        return true;
        break;
    default:
        return false;
    }
}

//bool CommandTreeItem::removeColumns(int position, int columns)
//{
//    if (position < 0 || position + columns > m_itemData.size())
//        return false;
//
//    for (int column = 0; column < columns; ++column)
//        m_itemData.remove(position);
//
//    for (CommandTreeItem* child : qAsConst(children_))
//        child->removeColumns(position, columns);
//
//    return true;
//}


bool CommandTreeItem::removeChildren(int position, int count)
{
    if (position < 0 || position + count > children_.size())
        return false;

    for (int row = 0; row < count; ++row)
        delete children_.takeAt(position);

    return true;
}

CommandTreeItem CommandTreeItem::operator=(const CommandTreeItem& rhs) {
    children_ = rhs.children_;
    name_ = rhs.name_;
    icon_ = rhs.icon_;
    parent_ = rhs.parent_;
    return *this;
}
