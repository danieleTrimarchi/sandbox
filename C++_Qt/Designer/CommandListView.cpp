#include "CommandListView.h"
#include <qmimedata.h>
#include <QDrag>
#include <iostream>
#include "CommandModel.h"

CommandListView::CommandListView(QWidget* parent /*=nullptr*/) :
    QListView(parent) {

    setObjectName(QString::fromUtf8("CommandListWiew"));    
    setViewMode(QListWidget::IconMode);
    setDragEnabled(true);
    setResizeMode(QListWidget::Adjust);
    setIconSize(QSize(80, 80));
    setGridSize(QSize(100, 100));
    setSpacing(10);
    setMovement(QListView::Snap);
    setAcceptDrops(true);
    setDropIndicatorShown(true);

    CommandModel* model = new CommandModel(this);
    setModel(model);

//
}

//void ListWidget::dragMoveEvent(QDragMoveEvent* e) {
//
//    if (e->mimeData()->hasFormat("text/plain") && e->source() != this) {
//        e->setDropAction(Qt::MoveAction);
//        e->accept();
//    }
//    else
//        e->ignore();
//}
//
//void ListWidget::dropEvent(QDropEvent* event) {
//    if (event->mimeData()->hasFormat("text/plain")) {
//        event->accept();
//        event->setDropAction(Qt::MoveAction);
//        QListWidgetItem* item = new QListWidgetItem;
//        QString name = event->mimeData()->data("text/plain");
//        item->setText(name);
//        item->setIcon(QIcon(":/images/iString")); //set path to image
//        addItem(item);
//    }
//    else
//        event->ignore();
//}


//void ListWidgetView::startDrag(Qt::DropActions supportedActions) {
//
//    QListWidgetItem* item = currentItem();
//    QMimeData* mimeData = new QMimeData;
//
//    std::cout << "Item text= " << item->text().toStdString() << std::endl;
//    mimeData->setText(item->text());
//    mimeData->setImageData(item->icon());
//
//    QDrag* drag = new QDrag(this);
//    drag->setMimeData(mimeData);
//
//    drag->exec(supportedActions, Qt::MoveAction);
//
//}
//
//void ListWidget::dragEnterEvent(QDragEnterEvent* event) {
//
//    if (event->mimeData()->hasFormat(ListWidgetMimeType())) {
//        event->setDropAction(Qt::MoveAction);
//        event->accept();
//    }
//    else
//        event->ignore();
//}
//
//void ListWidget::dragMoveEvent(QDragMoveEvent* event)
//{
//    if (event->mimeData()->hasFormat(ListWidgetMimeType())) {
//        if (children().contains(event->source())) {
//            event->setDropAction(Qt::MoveAction);
//            event->accept();
//        }
//        else {
//            event->acceptProposedAction();
//        }
//    }
//    else if (event->mimeData()->hasText()) {
//        event->acceptProposedAction();
//    }
//    else {
//        event->ignore();
//    }
//}
//
//void ListWidget::dropEvent(QDropEvent* event)
//{
//    if (event->mimeData()->hasFormat(ListWidgetMimeType())) {
//        const QMimeData* mime = event->mimeData();
//        //! [9] //! [10]
//        QByteArray itemData = mime->data(ListWidgetMimeType());
//        QDataStream dataStream(&itemData, QIODevice::ReadOnly);
//
//        QString text;
//        QPoint offset;
//        dataStream >> text >> offset;
//        //! [10]
//        //! [11]
//        //DragLabel* newLabel = new DragLabel(text, this);
//        //newLabel->move(event->pos() - offset);
//        //newLabel->show();
//        //newLabel->setAttribute(Qt::WA_DeleteOnClose);
//
//        //if (event->source() == this) {
//        //    event->setDropAction(Qt::MoveAction);
//        //    event->accept();
//        //}
//        //else {
//        //    event->acceptProposedAction();
//        //}
//        //! [11] //! [12]
//    }
//    //else if (event->mimeData()->hasText()) {
//    //    QStringList pieces = event->mimeData()->text().split(
//    //        QRegularExpression(QStringLiteral("\\s+")), Qt::SkipEmptyParts);
//    //    QPoint position = event->pos();
//
//    //    for (const QString& piece : pieces) {
//    //        DragLabel* newLabel = new DragLabel(piece, this);
//    //        newLabel->move(position);
//    //        newLabel->show();
//    //        newLabel->setAttribute(Qt::WA_DeleteOnClose);
//
//    //        position += QPoint(newLabel->width(), 0);
//    //    }
//
//    //    event->acceptProposedAction();
//    //}
//    else {
//        event->ignore();
//    }
//}
//! [12]
