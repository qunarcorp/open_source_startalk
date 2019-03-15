/********************************************************************************
** Form generated from reading UI file 'groupfilelistview.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GROUPFILELISTVIEW_H
#define UI_GROUPFILELISTVIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "TitlebarWidget.h"

QT_BEGIN_NAMESPACE

class Ui_GroupFileListView
{
public:
    QHBoxLayout *horizontalLayout;
    QWidget *shadowbg;
    QHBoxLayout *horizontalLayout_2;
    QWidget *shadowinnerbg;
    QVBoxLayout *verticalLayout;
    TitlebarWidget *titlebar;
    QWidget *widget_4;
    QVBoxLayout *verticalLayout_2;
    QStackedWidget *stackedWidget;
    QWidget *emptypage;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label;
    QWidget *listpage;
    QVBoxLayout *verticalLayout_4;
    QTreeWidget *treeWidget;

    void setupUi(QWidget *GroupFileListView)
    {
        if (GroupFileListView->objectName().isEmpty())
            GroupFileListView->setObjectName(QStringLiteral("GroupFileListView"));
        GroupFileListView->resize(520, 396);
        horizontalLayout = new QHBoxLayout(GroupFileListView);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        shadowbg = new QWidget(GroupFileListView);
        shadowbg->setObjectName(QStringLiteral("shadowbg"));
        horizontalLayout_2 = new QHBoxLayout(shadowbg);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(8, 8, 8, 8);
        shadowinnerbg = new QWidget(shadowbg);
        shadowinnerbg->setObjectName(QStringLiteral("shadowinnerbg"));
        verticalLayout = new QVBoxLayout(shadowinnerbg);
        verticalLayout->setSpacing(0);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(1, 1, 1, 1);
        titlebar = new TitlebarWidget(shadowinnerbg);
        titlebar->setObjectName(QStringLiteral("titlebar"));

        verticalLayout->addWidget(titlebar);

        widget_4 = new QWidget(shadowinnerbg);
        widget_4->setObjectName(QStringLiteral("widget_4"));
        verticalLayout_2 = new QVBoxLayout(widget_4);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(10, 10, 10, 10);
        stackedWidget = new QStackedWidget(widget_4);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        emptypage = new QWidget();
        emptypage->setObjectName(QStringLiteral("emptypage"));
        horizontalLayout_3 = new QHBoxLayout(emptypage);
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(emptypage);
        label->setObjectName(QStringLiteral("label"));
        label->setPixmap(QPixmap(QString::fromUtf8(":/Images/icon/commen/empty.png")));
        label->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(label);

        stackedWidget->addWidget(emptypage);
        listpage = new QWidget();
        listpage->setObjectName(QStringLiteral("listpage"));
        verticalLayout_4 = new QVBoxLayout(listpage);
        verticalLayout_4->setSpacing(0);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        treeWidget = new QTreeWidget(listpage);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setText(0, QStringLiteral("1"));
        treeWidget->setHeaderItem(__qtreewidgetitem);
        treeWidget->setObjectName(QStringLiteral("treeWidget"));

        verticalLayout_4->addWidget(treeWidget);

        stackedWidget->addWidget(listpage);

        verticalLayout_2->addWidget(stackedWidget);


        verticalLayout->addWidget(widget_4);


        horizontalLayout_2->addWidget(shadowinnerbg);


        horizontalLayout->addWidget(shadowbg);


        retranslateUi(GroupFileListView);

        QMetaObject::connectSlotsByName(GroupFileListView);
    } // setupUi

    void retranslateUi(QWidget *GroupFileListView)
    {
        GroupFileListView->setWindowTitle(QApplication::translate("GroupFileListView", "GroupFileListView", 0));
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class GroupFileListView: public Ui_GroupFileListView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GROUPFILELISTVIEW_H
