#ifndef COMMANDLISTVIEW_H
#define COMMANDLISTVIEW_H

#include <QListView>
#include <QMouseEvent>
#include <QDragMoveEvent>
#include <QDropEvent>
#include <QDragEnterEvent>

class CommandListView : public QListView {
public: 

	explicit CommandListView(QWidget* parent = nullptr);
	
protected: 

	//void dragMoveEvent(QDragMoveEvent* e);
	//void dropEvent(QDropEvent* event);
	//void startDrag(Qt::DropActions supportedActions);
	//void dragEnterEvent(QDragEnterEvent* event);
	//Qt::DropAction supportedDropActions();
	
	/*void dragEnterEvent(QDragEnterEvent* event) override;
	void dragMoveEvent(QDragMoveEvent* event) override;
	void dropEvent(QDropEvent* event) override;*/

//signals:
//
//	void itemDroped();

private: 

};
#endif