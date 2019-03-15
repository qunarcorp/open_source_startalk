/********************************************************************************
** Form generated from reading UI file 'GroupMsgFilterView.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GROUPMSGFILTERVIEW_H
#define UI_GROUPMSGFILTERVIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "TitlebarWidget.h"

QT_BEGIN_NAMESPACE

class Ui_GroupMsgFilterView
{
public:
    QVBoxLayout *verticalLayout_4;
    QWidget *shadowbg;
    QVBoxLayout *verticalLayout_3;
    QWidget *shadowinnerbg;
    QVBoxLayout *verticalLayout_2;
    TitlebarWidget *titlebar;
    QStackedWidget *stackedWidget;
    QWidget *Emptypage;
    QLabel *label;
    QWidget *Filterpage;
    QVBoxLayout *verticalLayout;
    QTreeWidget *treeWidget;
    QWidget *spline;
    QHBoxLayout *horizontalLayout;
    QPushButton *ok;

    void setupUi(QWidget *GroupMsgFilterView)
    {
        if (GroupMsgFilterView->objectName().isEmpty())
            GroupMsgFilterView->setObjectName(QStringLiteral("GroupMsgFilterView"));
        GroupMsgFilterView->resize(468, 308);
        GroupMsgFilterView->setStyleSheet(QLatin1String("#GroupMsgFilterView QWidget#spline{border:none;background:#CCCCCC}\n"
"#GroupMsgFilterView QTreeWidget{border:none;background:#00000000;}\n"
"#GroupMsgFilterView QPushButton#ok{font-size:14px;color:#FFFFFF;border:none;background:#1ba9ba;padding:3px;}\n"
"#GroupMsgFilterView QPushButton#ok:hover{background:#147a84;}\n"
"#GroupMsgFilterView QPushButton#ok:disabled{background-color: #9B9B9B;}"));
        verticalLayout_4 = new QVBoxLayout(GroupMsgFilterView);
        verticalLayout_4->setSpacing(0);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        shadowbg = new QWidget(GroupMsgFilterView);
        shadowbg->setObjectName(QStringLiteral("shadowbg"));
        verticalLayout_3 = new QVBoxLayout(shadowbg);
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(8, 8, 8, 8);
        shadowinnerbg = new QWidget(shadowbg);
        shadowinnerbg->setObjectName(QStringLiteral("shadowinnerbg"));
        verticalLayout_2 = new QVBoxLayout(shadowinnerbg);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        titlebar = new TitlebarWidget(shadowinnerbg);
        titlebar->setObjectName(QStringLiteral("titlebar"));
        titlebar->setMinimumSize(QSize(0, 20));
        titlebar->setMaximumSize(QSize(16777215, 30));

        verticalLayout_2->addWidget(titlebar);

        stackedWidget = new QStackedWidget(shadowinnerbg);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        Emptypage = new QWidget();
        Emptypage->setObjectName(QStringLiteral("Emptypage"));
        label = new QLabel(Emptypage);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(30, 10, 401, 261));
        stackedWidget->addWidget(Emptypage);
        Filterpage = new QWidget();
        Filterpage->setObjectName(QStringLiteral("Filterpage"));
        verticalLayout = new QVBoxLayout(Filterpage);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        treeWidget = new QTreeWidget(Filterpage);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setText(0, QStringLiteral("1"));
        treeWidget->setHeaderItem(__qtreewidgetitem);
        treeWidget->setObjectName(QStringLiteral("treeWidget"));
        treeWidget->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        treeWidget->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        treeWidget->header()->setVisible(false);

        verticalLayout->addWidget(treeWidget);

        spline = new QWidget(Filterpage);
        spline->setObjectName(QStringLiteral("spline"));
        spline->setMinimumSize(QSize(0, 1));
        spline->setMaximumSize(QSize(16777215, 1));

        verticalLayout->addWidget(spline);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        ok = new QPushButton(Filterpage);
        ok->setObjectName(QStringLiteral("ok"));
        ok->setMinimumSize(QSize(100, 25));
        ok->setMaximumSize(QSize(100, 25));

        horizontalLayout->addWidget(ok);


        verticalLayout->addLayout(horizontalLayout);

        stackedWidget->addWidget(Filterpage);

        verticalLayout_2->addWidget(stackedWidget);


        verticalLayout_3->addWidget(shadowinnerbg);


        verticalLayout_4->addWidget(shadowbg);


        retranslateUi(GroupMsgFilterView);

        QMetaObject::connectSlotsByName(GroupMsgFilterView);
    } // setupUi

    void retranslateUi(QWidget *GroupMsgFilterView)
    {
        GroupMsgFilterView->setWindowTitle(QApplication::translate("GroupMsgFilterView", "Form", 0));
        label->setText(QString());
        ok->setText(QApplication::translate("GroupMsgFilterView", "\347\241\256\345\256\232", 0));
    } // retranslateUi

};

namespace Ui {
    class GroupMsgFilterView: public Ui_GroupMsgFilterView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GROUPMSGFILTERVIEW_H
