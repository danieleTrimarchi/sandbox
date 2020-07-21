// Copyright (c) 2016, Coventor, Inc. All rights reserved.
// The contents of this file are Coventor Confidential.

#include "Grid.h"
#include <QtWidgets/QWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QGridLayout>
#include <QtCharts/QChartView>
#include <QtWidgets/QGraphicsGridLayout>

QT_CHARTS_USE_NAMESPACE

Grid::Grid()
{
	b1 = new QPushButton();
	QGridLayout* l1 = new QGridLayout();
	l1->addWidget(b1, 0, 0); 

	b2 = new QPushButton();
	QGridLayout* l2 = new QGridLayout();
	l2->addWidget(b2, 0, 0);

	b3 = new QPushButton();
	QGridLayout* l3 = new QGridLayout();
	l3->addWidget(b3, 0, 0);

	b4 = new QPushButton();
	QGridLayout* l4 = new QGridLayout();
	l4->addWidget(b4, 0, 0);

	QGridLayout* l = new QGridLayout;
	l->addLayout(l1,0,0); 
	l->addLayout(l2, 0, 1);
	l->addLayout(l3, 1, 0);
	l->addLayout(l4, 1, 1);
	setLayout(l);
	connect(b1, SIGNAL(clicked()), this, SLOT(onClicked()));
}

void Grid::onClicked() {
	bool v = !b2->isVisible();
	b2->setVisible(v);
	b3->setVisible(v);
	b4->setVisible(v);
}
