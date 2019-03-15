/********************************************************************************
** Form generated from reading UI file 'groupitem_l.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GROUPITEM_L_H
#define UI_GROUPITEM_L_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GroupItem_L
{
public:
    QHBoxLayout *horizontalLayout;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_2;
    QLabel *header;
    QLabel *diaplay;
    QSpacerItem *horizontalSpacer;
    QPushButton *selectbutton;

    void setupUi(QWidget *GroupItem_L)
    {
        if (GroupItem_L->objectName().isEmpty())
            GroupItem_L->setObjectName(QStringLiteral("GroupItem_L"));
        GroupItem_L->resize(400, 28);
        GroupItem_L->setMinimumSize(QSize(0, 28));
        GroupItem_L->setMaximumSize(QSize(16777215, 28));
        GroupItem_L->setStyleSheet(QLatin1String("QWidget#widget{\n"
"	background-color:#EAEBED;\n"
"}\n"
"QWidget#widget:hover{\n"
"	background-color:#4F9AD4;\n"
"}\n"
"\n"
"QLabel#header{\n"
"	border-image:url(:/Images/mainpanel_group_down.png);\n"
"}\n"
"\n"
"QPushButton#selectbutton{\n"
"	border-image: url(:/Images/icon_check_empty.png)\n"
"}\n"
"\n"
"QPushButton#selectbutton:checked{\n"
"	border-image:url(:/Images/icon_check_filled.png);\n"
"}"));
        horizontalLayout = new QHBoxLayout(GroupItem_L);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        widget = new QWidget(GroupItem_L);
        widget->setObjectName(QStringLiteral("widget"));
        horizontalLayout_2 = new QHBoxLayout(widget);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 20, 0);
        header = new QLabel(widget);
        header->setObjectName(QStringLiteral("header"));
        header->setMinimumSize(QSize(28, 24));
        header->setMaximumSize(QSize(28, 24));

        horizontalLayout_2->addWidget(header);

        diaplay = new QLabel(widget);
        diaplay->setObjectName(QStringLiteral("diaplay"));
        diaplay->setMinimumSize(QSize(0, 24));
        diaplay->setMaximumSize(QSize(16777215, 16777215));

        horizontalLayout_2->addWidget(diaplay);

        horizontalSpacer = new QSpacerItem(253, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        selectbutton = new QPushButton(widget);
        selectbutton->setObjectName(QStringLiteral("selectbutton"));
        selectbutton->setMinimumSize(QSize(24, 24));
        selectbutton->setMaximumSize(QSize(24, 24));
        selectbutton->setCheckable(true);
        selectbutton->setFlat(true);

        horizontalLayout_2->addWidget(selectbutton);


        horizontalLayout->addWidget(widget);


        retranslateUi(GroupItem_L);

        QMetaObject::connectSlotsByName(GroupItem_L);
    } // setupUi

    void retranslateUi(QWidget *GroupItem_L)
    {
        GroupItem_L->setWindowTitle(QApplication::translate("GroupItem_L", "GroupItem_L", 0));
        header->setText(QString());
        diaplay->setText(QApplication::translate("GroupItem_L", "TextLabel", 0));
        selectbutton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class GroupItem_L: public Ui_GroupItem_L {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GROUPITEM_L_H
