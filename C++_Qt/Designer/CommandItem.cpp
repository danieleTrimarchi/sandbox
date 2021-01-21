#include "CommandItem.h"

CommandItem::CommandItem(const QIcon& icon, const QString& text,
	QListWidget* view /*= nullptr*/, int type /*= Type*/) :
		QListWidgetItem(icon, text, view, type) {};

//QVariant CommandItem::data(int role) const {
//
//	if (role == Qt::DisplayRole) {
//		return QString("SuperLoc");
//		//return text();
//	}
//	else if (role == Qt::DecorationRole) {
//		return QIcon(":/images/superLoc.png");
//		//return icon();
//	} 
//	else
//		return QVariant(); 
//};
