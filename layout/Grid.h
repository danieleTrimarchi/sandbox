// Copyright (c) 2016, Coventor, Inc. All rights reserved.
// The contents of this file are Coventor Confidential.

#ifndef GRID_H
#define GRID_H

#include <QtWidgets/QWidget>

class QPushButton;

typedef QPair<QPointF, QString> Data;
typedef QList<Data> DataList;
typedef QList<DataList> DataTable;

class Grid : public QWidget
{
	Q_OBJECT

public:
	Grid();

private:

	QPushButton* b1;
	QPushButton* b2;
	QPushButton* b3;
	QPushButton* b4;

	/// Container with the data to plot
	DataTable dataTable_;

private slots:

	void onClicked();

};

#endif // GRID_H
