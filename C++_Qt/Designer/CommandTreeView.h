#ifndef TREEVIEW_H
#define TREEVIEW_H

#include <QTreeView>
#include "CommandModel.h"

class CommandTreeView : public QTreeView
{
	Q_OBJECT

public:

	explicit CommandTreeView(QWidget* parent = nullptr);

protected:

	void dragEnterEvent(QDragEnterEvent* event) override;
	
	void dragMoveEvent(QDragMoveEvent* event) override;

	void dropEvent(QDropEvent* event) override;

//	void dragLeaveEvent(QDragLeaveEvent* event) override;
//	void mousePressEvent(QMouseEvent* event) override;
//	void paintEvent(QPaintEvent* event) override;


private slots:
	void onCustomContextMenu(const QPoint&);

};

#endif 