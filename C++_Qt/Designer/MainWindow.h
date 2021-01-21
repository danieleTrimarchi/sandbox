#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <iostream>
#include <ui_untitled.h>

//#include <QString>
//#include <QVariant>
//#include <QVector>
//#include <QStringList>
//#include <QAbstractItemModel>
//#include <QTreeView>
//#include <QSortFilterProxyModel>
//#include <QLineEdit>
//#include <QActionGroup>
//#include <QMenu>
//#include <QToolButton>
//#include <QWidgetAction>




class MainWindow : public QMainWindow {

	Q_OBJECT

public:

	// Ctor
	explicit MainWindow(QWidget* parent = nullptr);

	// Dtor
	~MainWindow();

private:

	Ui_MainWindow ui;

public slots:

	QString getExistingDirectory(bool checked = false) {
		return QFileDialog::getExistingDirectory(this, tr("Open Directory"),
			"/home",
			QFileDialog::ShowDirsOnly
			| QFileDialog::DontResolveSymlinks);
	}
};

#endif