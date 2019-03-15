/********************************************************************************
** Form generated from reading UI file 'groupquitview.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GROUPQUITVIEW_H
#define UI_GROUPQUITVIEW_H

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

class Ui_GroupQuitView
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *shadowbg;
    QVBoxLayout *verticalLayout_2;
    QWidget *shadowinnerbg;
    QVBoxLayout *verticalLayout_3;
    TitlebarWidget *titlebar;
    QStackedWidget *sw;
    QWidget *emptypage;
    QVBoxLayout *verticalLayout_5;
    QLabel *label;
    QWidget *wrap;
    QVBoxLayout *verticalLayout_4;
    QLabel *tip;
    QTreeWidget *treeWidget;
    QWidget *spline;
    QHBoxLayout *horizontalLayout;
    QPushButton *quit;
    QLabel *warning;

    void setupUi(QWidget *GroupQuitView)
    {
        if (GroupQuitView->objectName().isEmpty())
            GroupQuitView->setObjectName(QStringLiteral("GroupQuitView"));
        GroupQuitView->resize(441, 441);
        GroupQuitView->setStyleSheet(QLatin1String("#GroupQuitView QLabel#tip{font-size:14px;color:#333333}\n"
"#GroupQuitView QPushButton#quit{font-size:14px;color:#FFFFFF;border:none;background:#1ba9ba;padding:3px;}\n"
"#GroupQuitView QPushButton#quit:hover{background:#147a84;}\n"
"#GroupQuitView QPushButton#quit:disabled{background-color: #9B9B9B;}\n"
"\n"
"#GroupQuitView QWidget#spline{border:none;background:#CCCCCC}\n"
"#GroupQuitView QLabel#warning{font-size:12px;color:#FF3300;}\n"
"#GroupQuitView QTreeWidget{border:none;background:#00000000;}\n"
""));
        verticalLayout = new QVBoxLayout(GroupQuitView);
        verticalLayout->setSpacing(0);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        shadowbg = new QWidget(GroupQuitView);
        shadowbg->setObjectName(QStringLiteral("shadowbg"));
        verticalLayout_2 = new QVBoxLayout(shadowbg);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(8, 8, 8, 8);
        shadowinnerbg = new QWidget(shadowbg);
        shadowinnerbg->setObjectName(QStringLiteral("shadowinnerbg"));
        shadowinnerbg->setMinimumSize(QSize(425, 425));
        verticalLayout_3 = new QVBoxLayout(shadowinnerbg);
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        titlebar = new TitlebarWidget(shadowinnerbg);
        titlebar->setObjectName(QStringLiteral("titlebar"));
        titlebar->setMaximumSize(QSize(16777215, 30));

        verticalLayout_3->addWidget(titlebar);

        sw = new QStackedWidget(shadowinnerbg);
        sw->setObjectName(QStringLiteral("sw"));
        emptypage = new QWidget();
        emptypage->setObjectName(QStringLiteral("emptypage"));
        verticalLayout_5 = new QVBoxLayout(emptypage);
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        label = new QLabel(emptypage);
        label->setObjectName(QStringLiteral("label"));
        label->setPixmap(QPixmap(QString::fromUtf8(":/Images/icon/commen/empty.png")));
        label->setAlignment(Qt::AlignCenter);

        verticalLayout_5->addWidget(label);

        sw->addWidget(emptypage);
        wrap = new QWidget();
        wrap->setObjectName(QStringLiteral("wrap"));
        verticalLayout_4 = new QVBoxLayout(wrap);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(10, 0, 10, 10);
        tip = new QLabel(wrap);
        tip->setObjectName(QStringLiteral("tip"));

        verticalLayout_4->addWidget(tip);

        treeWidget = new QTreeWidget(wrap);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setText(0, QStringLiteral("1"));
        treeWidget->setHeaderItem(__qtreewidgetitem);
        treeWidget->setObjectName(QStringLiteral("treeWidget"));
        treeWidget->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        treeWidget->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        treeWidget->setHeaderHidden(true);
        treeWidget->setExpandsOnDoubleClick(true);
        treeWidget->header()->setVisible(false);
        treeWidget->header()->setProperty("showSortIndicator", QVariant(false));

        verticalLayout_4->addWidget(treeWidget);

        spline = new QWidget(wrap);
        spline->setObjectName(QStringLiteral("spline"));
        spline->setMinimumSize(QSize(0, 1));
        spline->setMaximumSize(QSize(16777215, 1));

        verticalLayout_4->addWidget(spline);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        quit = new QPushButton(wrap);
        quit->setObjectName(QStringLiteral("quit"));
        quit->setMinimumSize(QSize(0, 28));
        quit->setMaximumSize(QSize(100, 28));
        quit->setFlat(true);

        horizontalLayout->addWidget(quit);


        verticalLayout_4->addLayout(horizontalLayout);

        warning = new QLabel(wrap);
        warning->setObjectName(QStringLiteral("warning"));
        warning->setAlignment(Qt::AlignCenter);
        warning->setTextInteractionFlags(Qt::NoTextInteraction);

        verticalLayout_4->addWidget(warning);

        sw->addWidget(wrap);

        verticalLayout_3->addWidget(sw);


        verticalLayout_2->addWidget(shadowinnerbg);


        verticalLayout->addWidget(shadowbg);


        retranslateUi(GroupQuitView);

        sw->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(GroupQuitView);
    } // setupUi

    void retranslateUi(QWidget *GroupQuitView)
    {
        GroupQuitView->setWindowTitle(QApplication::translate("GroupQuitView", "GroupQuitView", 0));
        label->setText(QString());
        tip->setText(QApplication::translate("GroupQuitView", "\346\210\221\347\232\204\347\276\244\347\273\204:", 0));
        quit->setText(QApplication::translate("GroupQuitView", "\344\270\200\351\224\256\351\200\200\347\276\244", 0));
        warning->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class GroupQuitView: public Ui_GroupQuitView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GROUPQUITVIEW_H
