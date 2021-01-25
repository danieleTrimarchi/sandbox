#ifndef TREEVIEW_H
#define TREEVIEW_H

#include <QTreeView>

class CommandTreeView : public QTreeView
{
	Q_OBJECT

public:

	explicit CommandTreeView(QWidget* parent = nullptr);

protected:

	void dragEnterEvent(QDragEnterEvent* event) override;

	void dropEvent(QDropEvent* event) override;

};

#endif 