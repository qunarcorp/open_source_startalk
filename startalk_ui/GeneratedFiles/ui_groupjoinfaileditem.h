/********************************************************************************
** Form generated from reading UI file 'groupjoinfaileditem.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GROUPJOINFAILEDITEM_H
#define UI_GROUPJOINFAILEDITEM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GroupJoinFailedItem
{
public:
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLabel *groupname;
    QPushButton *rejoin;
    QPushButton *pushButton_2;

    void setupUi(QWidget *GroupJoinFailedItem)
    {
        if (GroupJoinFailedItem->objectName().isEmpty())
            GroupJoinFailedItem->setObjectName(QStringLiteral("GroupJoinFailedItem"));
        GroupJoinFailedItem->resize(257, 28);
        GroupJoinFailedItem->setMinimumSize(QSize(0, 28));
        GroupJoinFailedItem->setMaximumSize(QSize(16777215, 28));
        GroupJoinFailedItem->setStyleSheet(QLatin1String("QPushButton{\n"
"	border-radius: 0px;\n"
"    color:#FFFFFF;\n"
"    background-color:#3DCE3D;\n"
"	max-height:24px;\n"
"	min-height:24px;\n"
"	max-width:40px;\n"
"	min-width:40px;\n"
"}\n"
"\n"
"QPushButton:hover{\n"
"    background-color:#38C738;\n"
"}\n"
"QPushButton#ok:pressed{\n"
"    background-color:#2FB82F;\n"
"}\n"
"\n"
"QPushButton:disabled{\n"
"    background-color:#9DE69D;\n"
"}"));
        horizontalLayout = new QHBoxLayout(GroupJoinFailedItem);
        horizontalLayout->setSpacing(5);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(10, 0, 10, 0);
        label = new QLabel(GroupJoinFailedItem);
        label->setObjectName(QStringLiteral("label"));
        label->setMinimumSize(QSize(26, 26));
        label->setMaximumSize(QSize(26, 26));
        label->setPixmap(QPixmap(QString::fromUtf8(":/Images/mainpanel_group_down.png")));

        horizontalLayout->addWidget(label);

        groupname = new QLabel(GroupJoinFailedItem);
        groupname->setObjectName(QStringLiteral("groupname"));

        horizontalLayout->addWidget(groupname);

        rejoin = new QPushButton(GroupJoinFailedItem);
        rejoin->setObjectName(QStringLiteral("rejoin"));
        rejoin->setEnabled(true);
        rejoin->setMinimumSize(QSize(40, 24));
        rejoin->setMaximumSize(QSize(40, 24));

        horizontalLayout->addWidget(rejoin);

        pushButton_2 = new QPushButton(GroupJoinFailedItem);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        horizontalLayout->addWidget(pushButton_2);


        retranslateUi(GroupJoinFailedItem);

        QMetaObject::connectSlotsByName(GroupJoinFailedItem);
    } // setupUi

    void retranslateUi(QWidget *GroupJoinFailedItem)
    {
        GroupJoinFailedItem->setWindowTitle(QApplication::translate("GroupJoinFailedItem", "GroupJoinFailedItem", 0));
        label->setText(QString());
        groupname->setText(QString());
        rejoin->setText(QApplication::translate("GroupJoinFailedItem", "\351\207\215\350\257\225", 0));
        pushButton_2->setText(QApplication::translate("GroupJoinFailedItem", "\351\200\200\345\207\272\347\276\244", 0));
    } // retranslateUi

};

namespace Ui {
    class GroupJoinFailedItem: public Ui_GroupJoinFailedItem {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GROUPJOINFAILEDITEM_H
