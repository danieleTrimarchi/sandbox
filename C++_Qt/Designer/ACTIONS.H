#ifndef ACTIONS_H
#define ACTIONS_H

#include <QAction>
#include <QObject>

class CommandTreeModel; 
class CommandTreeItem; 

class RemoveItemAction : public QAction {

	Q_OBJECT 

public: 

	RemoveItemAction(CommandTreeModel* pModel, const QModelIndex& idx, QObject* parent = nullptr );

public slots:

	void OnDeleteItem(bool checked = false);

private:

	CommandTreeModel* pModel_; 
	const QModelIndex& idx_;
};

#endif