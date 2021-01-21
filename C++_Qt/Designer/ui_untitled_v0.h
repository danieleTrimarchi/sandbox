/********************************************************************************
** Form generated from reading UI file 'untitledsDIjSc.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UNTITLEDSDIJSC_H
#define UNTITLEDSDIJSC_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QUndoView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <QtWidgets/QFileDialog>

QT_BEGIN_NAMESPACE

class Ui_MainWindow 
{

public:
    QWidget *centralwidget;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QTableWidget *fileTableList;
    QUndoView *actionStack;
    QPushButton *SelectFileRoot;
    QPushButton *pushButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(815, 629);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(100, 60, 671, 401));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
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

        actionStack = new QUndoView(verticalLayoutWidget);
        actionStack->setObjectName(QString::fromUtf8("actionStack"));

        verticalLayout->addWidget(actionStack);

        SelectFileRoot = new QPushButton(centralwidget);
        SelectFileRoot->setObjectName(QString::fromUtf8("SelectFileRoot"));
        SelectFileRoot->setGeometry(QRect(680, 20, 93, 28));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(680, 480, 93, 28));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 815, 26));
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

        SelectFileRoot->setText(QApplication::translate("MainWindow", "Select files...", nullptr));
        pushButton->setText(QApplication::translate("MainWindow", "Run..!", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UNTITLEDSDIJSC_H
