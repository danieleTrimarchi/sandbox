#ifndef COMMANDITEM_H
#define COMMANDITEM_H

#include <QtWidgets/QListWidgetItem>

class CommandItem : public QListWidgetItem {

public: 

	explicit CommandItem(const QIcon& icon, const QString& text,
		QListWidget* view = nullptr, int type = Type);

	//virtual QVariant data(int role) const ;

};
#endif