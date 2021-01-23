#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <iostream>

class MainWindow : public QMainWindow {

	Q_OBJECT

public:

	// Ctor
	explicit MainWindow(QWidget* parent = nullptr);

	// Dtor
	~MainWindow();

private:

	QWidget* centralWidget; 


public slots:

	QString getExistingDirectory(bool checked = false) {
		return QFileDialog::getExistingDirectory(this, tr("Open Directory"),
			"/home",
			QFileDialog::ShowDirsOnly
			| QFileDialog::DontResolveSymlinks);
	}
};

#endif