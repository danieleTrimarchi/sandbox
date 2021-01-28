#include "Actions.h"
#include "CommandTreeModel.h"
#include <iostream>

RemoveItemAction::RemoveItemAction(CommandTreeModel* pModel, const QModelIndex& idx, QObject* parent /*=nullptr*/) :
	QAction("Delete...", parent),
	pModel_(pModel),
	idx_(idx) {

	if (pModel_->getItem(idx_) == pModel_->getRoot())
		setEnabled(false);

	connect(this, SIGNAL(triggered(bool)), this, SLOT(OnDeleteItem(bool)));
}


void RemoveItemAction::OnDeleteItem(bool checked /*= false*/) {
	pModel_->removeItem(idx_);
}
