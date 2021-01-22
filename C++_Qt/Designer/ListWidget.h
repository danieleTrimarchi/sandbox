#ifndef LISTWIDGET_H
#define LISTWIDGET_H

#include <QListWidget>
#include <QMouseEvent>
#include <QDragMoveEvent>
#include <QDropEvent>
#include <QDragEnterEvent>

class ListWidget : public QListWidget {
public: 

	explicit ListWidget(QWidget* parent = nullptr);
	
protected: 

	//void dragMoveEvent(QDragMoveEvent* e);
	//void dropEvent(QDropEvent* event);
	void startDrag(Qt::DropActions supportedActions);
	//void dragEnterEvent(QDragEnterEvent* event);
	//Qt::DropAction supportedDropActions();
	
	void dragEnterEvent(QDragEnterEvent* event) override;
	void dragMoveEvent(QDragMoveEvent* event) override;
	void dropEvent(QDropEvent* event) override;

//signals:
//
//	void itemDroped();

private: 

};
#endif