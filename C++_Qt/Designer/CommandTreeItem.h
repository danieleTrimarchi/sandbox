#include <QString>
#include <QVariant>
#include <QVector>
#include <QIcon>

namespace CTI {

    enum colContent {
        icon,
        name,
        size
    };

}

class CommandTreeItemBase {

public :

    explicit CommandTreeItemBase();

    explicit CommandTreeItemBase(const std::string name, const QIcon icon);

    ~CommandTreeItemBase();

    void appendChild(CommandTreeItemBase* child);
    
    //bool removeColumns(int position, int columns);
    bool removeChildren(int position, int count);

    CommandTreeItemBase* child(int row);

    int childCount() const;

    int columnCount() const {
        return 1;
        //return CTI::colContent::size;
    }

    bool setData(int column, const QVariant value);

    //virtual QVariant data(int column) const;

    virtual CommandTreeItemBase* parent() const =0;

    virtual int childNumber() const =0;

    QVector<CommandTreeItemBase*> getChildren() const { return children_; };

    QIcon getIcon() const { return icon_; };
    std::string getName() const { return name_; };

protected :

    std::string name_;
    QIcon icon_;
    QVector<CommandTreeItemBase*> children_;

};


class CommandTreeItemRoot : public CommandTreeItemBase {

public:

    explicit CommandTreeItemRoot();

    ~CommandTreeItemRoot();

    virtual CommandTreeItemBase* parent() const { return nullptr; };

    virtual int childNumber() const { return 0; };

    //virtual QVariant data(int column) const override  {
    //    if (column < 0 || column >= CTI::colContent::size)
    //        return QVariant();

    //    switch (column)
    //    {
    //    case CTI::colContent::icon:
    //        return QVariant(name_.c_str());
    //        break;
    //    default:
    //        return QVariant();
    //    }
    //}

};


class CommandTreeItem : public CommandTreeItemBase {

public:
    
    explicit CommandTreeItem();
    
    explicit CommandTreeItem(const std::string name, const QIcon icon, CommandTreeItemBase* parent =nullptr );

    ~CommandTreeItem();

    CommandTreeItemBase* parent() const;

    int childNumber() const;

    CommandTreeItem operator=(const CommandTreeItem& rhs); 

    //bool insertChildren(int position, int count, int columns);
    //bool insertColumns(int position, int columns);

private:

    CommandTreeItemBase* parent_;
};