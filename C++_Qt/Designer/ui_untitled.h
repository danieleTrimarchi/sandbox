/********************************************************************************
** Form generated from reading UI file 'untitlednudkOr.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UNTITLEDNUDKOR_H
#define UNTITLEDNUDKOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTreeView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QTableWidget *fileTableList;
    QHBoxLayout *horizontalLayout_2;
    QListWidget *listWidget;
    QVBoxLayout *verticalLayout_2;
    QTreeView *treeView;
    QPushButton *pushButton_2;
    QPushButton *SelectFileRoot;
    QPushButton *pushButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(954, 808);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(centralwidget->sizePolicy().hasHeightForWidth());
        centralwidget->setSizePolicy(sizePolicy);
        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(40, 30, 771, 511));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setSizeConstraint(QLayout::SetMaximumSize);
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        fileTableList = new QTableWidget(verticalLayoutWidget);
        if (fileTableList->columnCount() < 3)
            fileTableList->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        fileTableList->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        fileTableList->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        fileTableList->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        if (fileTableList->rowCount() < 2)
            fileTableList->setRowCount(2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        fileTableList->setVerticalHeaderItem(0, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        __qtablewidgetitem4->setTextAlignment(Qt::AlignCenter);
        __qtablewidgetitem4->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEditable|Qt::ItemIsDragEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        fileTableList->setItem(0, 0, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        __qtablewidgetitem5->setCheckState(Qt::Unchecked);
        __qtablewidgetitem5->setTextAlignment(Qt::AlignCenter);
        __qtablewidgetitem5->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEditable|Qt::ItemIsDragEnabled|Qt::ItemIsUserCheckable);
        fileTableList->setItem(0, 1, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        __qtablewidgetitem6->setCheckState(Qt::Checked);
        __qtablewidgetitem6->setTextAlignment(Qt::AlignCenter);
        __qtablewidgetitem6->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEditable|Qt::ItemIsDragEnabled|Qt::ItemIsUserCheckable);
        fileTableList->setItem(0, 2, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        fileTableList->setItem(1, 0, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        __qtablewidgetitem8->setCheckState(Qt::Checked);
        fileTableList->setItem(1, 1, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        __qtablewidgetitem9->setCheckState(Qt::Checked);
        fileTableList->setItem(1, 2, __qtablewidgetitem9);
        fileTableList->setObjectName(QString::fromUtf8("fileTableList"));
        fileTableList->setRowCount(2);
        fileTableList->setColumnCount(3);
        fileTableList->horizontalHeader()->setVisible(true);
        fileTableList->horizontalHeader()->setCascadingSectionResizes(true);
        fileTableList->horizontalHeader()->setDefaultSectionSize(145);
        fileTableList->horizontalHeader()->setMinimumSectionSize(40);
        fileTableList->horizontalHeader()->setProperty("showSortIndicator", QVariant(true));
        fileTableList->horizontalHeader()->setStretchLastSection(true);
        fileTableList->verticalHeader()->setVisible(false);
        fileTableList->verticalHeader()->setCascadingSectionResizes(false);

        verticalLayout->addWidget(fileTableList);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setSizeConstraint(QLayout::SetMaximumSize);
        listWidget = new QListWidget(verticalLayoutWidget);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        QIcon icon;
        icon.addFile(QString::fromUtf8("images/superLoc.png"), QSize(), QIcon::Normal, QIcon::Off);
        QListWidgetItem *__qlistwidgetitem = new QListWidgetItem(listWidget);
        __qlistwidgetitem->setIcon(icon);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(listWidget->sizePolicy().hasHeightForWidth());
        listWidget->setSizePolicy(sizePolicy1);
        listWidget->setDragEnabled(true);
        listWidget->setDragDropOverwriteMode(true);
        listWidget->setDragDropMode(QAbstractItemView::DragOnly);

        horizontalLayout_2->addWidget(listWidget);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setSizeConstraint(QLayout::SetNoConstraint);
        treeView = new QTreeView(verticalLayoutWidget);
        treeView->setObjectName(QString::fromUtf8("treeView"));
        treeView->setEnabled(true);
        sizePolicy1.setHeightForWidth(treeView->sizePolicy().hasHeightForWidth());
        treeView->setSizePolicy(sizePolicy1);
        treeView->setMouseTracking(true);
        treeView->setAutoFillBackground(true);
        treeView->setDragEnabled(true);
        treeView->setDragDropOverwriteMode(true);
        treeView->setDragDropMode(QAbstractItemView::DropOnly);
        treeView->setDefaultDropAction(Qt::CopyAction);
        treeView->setAlternatingRowColors(true);
        treeView->setSelectionBehavior(QAbstractItemView::SelectRows);

        verticalLayout_2->addWidget(treeView);

        pushButton_2 = new QPushButton(verticalLayoutWidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        verticalLayout_2->addWidget(pushButton_2);


        horizontalLayout_2->addLayout(verticalLayout_2);


        verticalLayout->addLayout(horizontalLayout_2);

        SelectFileRoot = new QPushButton(centralwidget);
        SelectFileRoot->setObjectName(QString::fromUtf8("SelectFileRoot"));
        SelectFileRoot->setGeometry(QRect(730, 0, 93, 28));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(700, 540, 93, 28));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 954, 26));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        QTableWidgetItem *___qtablewidgetitem = fileTableList->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("MainWindow", "File", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = fileTableList->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("MainWindow", "Edit", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = fileTableList->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("MainWindow", "Edited", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = fileTableList->verticalHeaderItem(0);
        ___qtablewidgetitem3->setText(QApplication::translate("MainWindow", "Nouvelle ligne", nullptr));

        const bool __sortingEnabled = fileTableList->isSortingEnabled();
        fileTableList->setSortingEnabled(false);
        QTableWidgetItem *___qtablewidgetitem4 = fileTableList->item(1, 0);
        ___qtablewidgetitem4->setText(QApplication::translate("MainWindow", "C:/prog/foo/bar", nullptr));
        fileTableList->setSortingEnabled(__sortingEnabled);


        const bool __sortingEnabled1 = listWidget->isSortingEnabled();
        listWidget->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem = listWidget->item(0);
        ___qlistwidgetitem->setText(QApplication::translate("MainWindow", "Run SuperLoc", nullptr));
        QListWidgetItem *___qlistwidgetitem1 = listWidget->item(1);
        ___qlistwidgetitem1->setText(QApplication::translate("MainWindow", "Acquisition Editor", nullptr));
        QListWidgetItem *___qlistwidgetitem2 = listWidget->item(2);
        ___qlistwidgetitem2->setText(QApplication::translate("MainWindow", "Suppression artefacts", nullptr));
        listWidget->setSortingEnabled(__sortingEnabled1);

        pushButton_2->setText(QApplication::translate("MainWindow", "Clear", nullptr));
        SelectFileRoot->setText(QApplication::translate("MainWindow", "Select files...", nullptr));
        pushButton->setText(QApplication::translate("MainWindow", "Run..!", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UNTITLEDNUDKOR_H
