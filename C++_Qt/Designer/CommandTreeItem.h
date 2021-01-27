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

class CommandTreeItem {

public:
    explicit CommandTreeItem(const std::string name, const QIcon icon, CommandTreeItem* parent =nullptr );

    ~CommandTreeItem();

    void appendChild(CommandTreeItem* child);

    //bool insertChildren(int position, int count, int columns);
    //bool insertColumns(int position, int columns);

    CommandTreeItem* child(int row);

    int childCount() const;
    int columnCount() const;

    QVariant data(int column) const;

    CommandTreeItem* parent() const;
    int childNumber() const;

    bool setData(int column, const QVariant value);

    //bool removeColumns(int position, int columns);
    bool removeChildren(int position, int count);

    CommandTreeItem operator=(const CommandTreeItem& rhs); 

private:

    std::string name_; 
    QIcon icon_; 
    CommandTreeItem* parent_;
    QVector<CommandTreeItem*> children_;
};