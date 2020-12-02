#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include <QVariant>
#include <QVector>
#include <QStringList>
#include <QAbstractItemModel>
#include <QTreeView>
#include <QSortFilterProxyModel>
#include <QLineEdit>
#include <QRegExp>
#include <QActionGroup>
#include <QMenu>
#include <QToolButton>
#include <QWidgetAction>
#include <iostream>

Q_DECLARE_METATYPE(QRegExp::PatternSyntax)

// from: https://code.qt.io/cgit/qt/qtbase.git/tree/examples/widgets/itemviews/customsortfiltermodel/filterwidget.h?h=5.15
class FilterWidget : public QLineEdit
{
    Q_OBJECT
        Q_PROPERTY(Qt::CaseSensitivity caseSensitivity READ caseSensitivity WRITE setCaseSensitivity)
        Q_PROPERTY(QRegExp::PatternSyntax patternSyntax READ patternSyntax WRITE setPatternSyntax)
public:
    explicit FilterWidget(QWidget* parent = nullptr) : QLineEdit(parent)
        , m_patternGroup(new QActionGroup(this)) {

        setClearButtonEnabled(true);
        connect(this, &QLineEdit::textChanged, this, &FilterWidget::filterChanged);

        QMenu* menu = new QMenu(this);
        m_caseSensitivityAction = menu->addAction(tr("Case Sensitive"));
        m_caseSensitivityAction->setCheckable(true);
        connect(m_caseSensitivityAction, &QAction::toggled, this, &FilterWidget::filterChanged);

        menu->addSeparator();
        m_patternGroup->setExclusive(true);
        QAction* patternAction = menu->addAction("Fixed String");
        patternAction->setData(QVariant(int(QRegExp::FixedString)));
        patternAction->setCheckable(true);
        patternAction->setChecked(true);
        m_patternGroup->addAction(patternAction);
        patternAction = menu->addAction("Regular Expression");
        patternAction->setCheckable(true);
        patternAction->setData(QVariant(int(QRegExp::RegExp2)));
        m_patternGroup->addAction(patternAction);
        patternAction = menu->addAction("Wildcard");
        patternAction->setCheckable(true);
        patternAction->setData(QVariant(int(QRegExp::Wildcard)));
        m_patternGroup->addAction(patternAction);
        connect(m_patternGroup, &QActionGroup::triggered, this, &FilterWidget::filterChanged);

        const QIcon icon = QIcon(QPixmap(":/images/find.png"));
        QToolButton* optionsButton = new QToolButton;
#ifndef QT_NO_CURSOR
        optionsButton->setCursor(Qt::ArrowCursor);
#endif
        optionsButton->setFocusPolicy(Qt::NoFocus);
        optionsButton->setStyleSheet("* { border: none; }");
        optionsButton->setIcon(icon);
        optionsButton->setMenu(menu);
        optionsButton->setPopupMode(QToolButton::InstantPopup);

        QWidgetAction* optionsAction = new QWidgetAction(this);
        optionsAction->setDefaultWidget(optionsButton);
        addAction(optionsAction, QLineEdit::LeadingPosition);
    }

    Qt::CaseSensitivity caseSensitivity() const {
        return m_caseSensitivityAction->isChecked() ? Qt::CaseSensitive : Qt::CaseInsensitive;
    };

    void setCaseSensitivity(Qt::CaseSensitivity cs) {
        m_caseSensitivityAction->setChecked(cs == Qt::CaseSensitive);
    };
    
    static inline QRegExp::PatternSyntax patternSyntaxFromAction(const QAction* a)
    {
        return static_cast<QRegExp::PatternSyntax>(a->data().toInt());
    };

    QRegExp::PatternSyntax patternSyntax() const {
        return patternSyntaxFromAction(m_patternGroup->checkedAction());
    };

    void setPatternSyntax(QRegExp::PatternSyntax s) {
        const QList<QAction*> actions = m_patternGroup->actions();
        for (QAction* a : actions) {
            if (patternSyntaxFromAction(a) == s) {
                a->setChecked(true);
                break;
            }
        }
    };

signals:
    void filterChanged();

private:
    QAction* m_caseSensitivityAction;
    QActionGroup* m_patternGroup;
};


class TreeItem
{
public:
    explicit TreeItem(const QVector<QVariant> &data, TreeItem *parentItem = nullptr): 
    m_itemData(data), m_parentItem(parentItem){};

    ~TreeItem() { qDeleteAll(m_childItems);};

    void appendChild(TreeItem *child){ m_childItems.append(child); };

    bool insertChildren(int position, int count, int columns)
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

    TreeItem *child(int row){
	    if (row < 0 || row >= m_childItems.size())
    	    return nullptr;
	    return m_childItems.at(row); 
	};

    int childCount() const{	return m_childItems.count(); };

    int columnCount() const { return m_itemData.count();};

    QVariant data(int column) const {
   		if (column < 0 || column >= m_itemData.size())
        	return QVariant();
	    return m_itemData.at(column); 
	};

    bool setData(int column, const QVariant& value) {
        if (column < 0 || column >= m_itemData.size())
            return false;

        m_itemData[column] = value;
        return true;
    };

    int row() const {
    	if (m_parentItem)
       		return m_parentItem->m_childItems.indexOf(const_cast<TreeItem*>(this));

   		return 0; 
   	};

    TreeItem *parentItem() { return m_parentItem; };

private:
    QVector<TreeItem*> m_childItems;
    QVector<QVariant> m_itemData;
    TreeItem *m_parentItem;
};


class MySortFilterProxyModel : public QSortFilterProxyModel
{
    Q_OBJECT

public:
    MySortFilterProxyModel(QObject* parent = 0) :
        QSortFilterProxyModel(parent)
    {
    }

protected:

    bool filterAcceptsRow(int sourceRow, const QModelIndex& sourceParent) const override {
    
        QModelIndex index0 = sourceModel()->index(sourceRow, 0, sourceParent);
        QModelIndex index1 = sourceModel()->index(sourceRow, 1, sourceParent);
        QModelIndex index2 = sourceModel()->index(sourceRow, 2, sourceParent);

        return (sourceModel()->data(index0).toString().contains(filterRegExp()));
    }

private:

};


class TreeModel : public QAbstractItemModel
{
    Q_OBJECT

public:
    explicit TreeModel(const QString &data, QObject *parent = nullptr): 
    QAbstractItemModel(parent)
	{
	    rootItem = new TreeItem({tr("Title"), tr("Summary")});
   		setupModelData(data.split('\n'), rootItem);
	};

    ~TreeModel() { delete rootItem; };

    QVariant data(const QModelIndex &index, int role) const override {
	    if (!index.isValid())
	        return QVariant();
	
	    if (role != Qt::DisplayRole)
	        return QVariant();
	
	    TreeItem *item = static_cast<TreeItem*>(index.internalPointer());
	
	    return item->data(index.column());
	};


    Qt::ItemFlags flags(const QModelIndex &index) const override {
	    if (!index.isValid())
	        return Qt::NoItemFlags;
	
	    return QAbstractItemModel::flags(index);
	};
    
    QVariant headerData(int section, Qt::Orientation orientation,
                        int role = Qt::DisplayRole) const override {
	    if (orientation == Qt::Horizontal && role == Qt::DisplayRole)
	        return rootItem->data(section);
	
	    return QVariant();
	};

    QModelIndex index(int row, int column,
                      const QModelIndex &parent = QModelIndex()) const override {
	    if (!hasIndex(row, column, parent))
    	    return QModelIndex();

	    TreeItem *parentItem;

    	if (!parent.isValid())
        	parentItem = rootItem;
	    else
    	    parentItem = static_cast<TreeItem*>(parent.internalPointer());

	    TreeItem *childItem = parentItem->child(row);
    	if (childItem)
        	return createIndex(row, column, childItem);
	    return QModelIndex();
	};

    QModelIndex parent(const QModelIndex &index) const override{
	    if (!index.isValid())
    	    return QModelIndex();

	    TreeItem *childItem = static_cast<TreeItem*>(index.internalPointer());
    	TreeItem *parentItem = childItem->parentItem();

	    if (parentItem == rootItem)
    	    return QModelIndex();

	    return createIndex(parentItem->row(), 0, parentItem);
	};

    int rowCount(const QModelIndex &parent = QModelIndex()) const override {
	    TreeItem *parentItem;
	    if (parent.column() > 0)
	        return 0;
	
	    if (!parent.isValid())
	        parentItem = rootItem;
	    else
	        parentItem = static_cast<TreeItem*>(parent.internalPointer());
	
	    return parentItem->childCount();
	};

    int columnCount(const QModelIndex &parent = QModelIndex()) const override {
	    if (parent.isValid())
	        return static_cast<TreeItem*>(parent.internalPointer())->columnCount();
	    return rootItem->columnCount();
	};

//private:

    void setupModelData(const QStringList &lines, TreeItem *parent) {
        QList<TreeItem*> parents;
        QList<int> indentations;
        parents << parent;
        indentations << 0;

        int number = 0;

        while (number < lines.count()) {
            int position = 0;
            while (position < lines[number].length()) {
                if (lines[number].at(position) != ' ')
                    break;
                ++position;
            }

            QString lineData = lines[number].mid(position).trimmed();

            if (!lineData.isEmpty()) {
                // Read the column data from the rest of the line.
                QStringList columnStrings = lineData.split("\t", QString::SkipEmptyParts);
                QVector<QVariant> columnData;
                for (int column = 0; column < columnStrings.count(); ++column)
                    columnData << columnStrings[column];

                if (position > indentations.last()) {
                    // The last child of the current parent is now the new parent
                    // unless the current parent has no children.

                    if (parents.last()->childCount() > 0) {
                        parents << parents.last()->child(parents.last()->childCount() - 1);
                        indentations << position;
                    }
                }
                else {
                    while (position < indentations.last() && parents.count() > 0) {
                        parents.pop_back();
                        indentations.pop_back();
                    }
                }

                // Append a new item to the current parent's list of children.
                TreeItem* parent = parents.last();
                parent->insertChildren(parent->childCount(), 1, rootItem->columnCount());
                for (int column = 0; column < columnData.size(); ++column)
                    parent->child(parent->childCount() - 1)->setData(column, columnData[column]);
            }

            ++number;
        }
       }

    TreeItem *rootItem;
};


class TreeView : public QTreeView {
    Q_OBJECT
public: 
    explicit TreeView(QWidget* parent = nullptr) :
        QTreeView(parent) {

        // see https://stackoverflow.com/questions/23213929/qt-qlistwidget-item-with-alternating-colors
        setAlternatingRowColors(true);

        // Get the data 
        const QString& data("Item1\n\t\tItemfoo2\n\t\tItem3\t\tItefoom4\nItem5");

        // Instanciate a model 
        TreeModel* srcModel = new TreeModel(data);

        // Instanciate a proxy model and feed it with the src model
        proxyModel = new MySortFilterProxyModel(this);
        proxyModel->setDynamicSortFilter(true);

        proxyModel->setSourceModel(srcModel);

        // Set the proxy model for this view
        setModel(proxyModel);

        srcModel->setupModelData(QString("Item1a\n\t\tItemfoo2a\n\t\tItem3a\n\ttItefoom4a").split('\n'), 
            static_cast<TreeItem*>(srcModel->index(1,0).internalPointer()) );

    };

    MySortFilterProxyModel* getProxyModel() const {
        return proxyModel;
    };

private: 

    MySortFilterProxyModel* proxyModel; 

};


class MainWindow : public QMainWindow {
	
	Q_OBJECT
	
	public: 
	
	// Ctor
	explicit MainWindow(QWidget* parent=nullptr);
	
	// Dtor
	~MainWindow();

	private: 
        TreeView* pTreeview; 
        FilterWidget* pFilterWidget; 

private slots:

    void textFilterChanged() {
        std::cout << "text file changed: " << pFilterWidget->text().toStdString() << std::endl;

        QRegExp regExp(pFilterWidget->text(),
            pFilterWidget->caseSensitivity(),
            pFilterWidget->patternSyntax());
        pTreeview->getProxyModel()->setFilterRegExp(regExp);
    }

};

#endif