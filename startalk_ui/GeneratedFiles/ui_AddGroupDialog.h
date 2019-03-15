/********************************************************************************
** Form generated from reading UI file 'AddGroupDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDGROUPDIALOG_H
#define UI_ADDGROUPDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "TitlebarWidget.h"

QT_BEGIN_NAMESPACE

class Ui_AddGroupDialog
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *dialogbg;
    QVBoxLayout *verticalLayout_2;
    TitlebarWidget *titlebarWidget;
    QVBoxLayout *verticalLayout_3;
    QLabel *lblGroupName;
    QLineEdit *lineEdit;
    QLabel *lblMember;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_4;
    QListWidget *listWidget;
    QWidget *widget_4;
    QVBoxLayout *verticalLayout_4;
    QPushButton *btnAdd;
    QPushButton *btnRemove;
    QSpacerItem *verticalSpacer_2;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *btnOK;
    QPushButton *btnCancel;

    void setupUi(QDialog *AddGroupDialog)
    {
        if (AddGroupDialog->objectName().isEmpty())
            AddGroupDialog->setObjectName(QStringLiteral("AddGroupDialog"));
        AddGroupDialog->resize(496, 349);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(AddGroupDialog->sizePolicy().hasHeightForWidth());
        AddGroupDialog->setSizePolicy(sizePolicy);
        AddGroupDialog->setStyleSheet(QStringLiteral(""));
        verticalLayout = new QVBoxLayout(AddGroupDialog);
        verticalLayout->setSpacing(0);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        dialogbg = new QWidget(AddGroupDialog);
        dialogbg->setObjectName(QStringLiteral("dialogbg"));
        verticalLayout_2 = new QVBoxLayout(dialogbg);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(5, 3, 5, 3);
        titlebarWidget = new TitlebarWidget(dialogbg);
        titlebarWidget->setObjectName(QStringLiteral("titlebarWidget"));
        titlebarWidget->setMinimumSize(QSize(0, 40));
        titlebarWidget->setMaximumSize(QSize(16777215, 40));
        verticalLayout_3 = new QVBoxLayout(titlebarWidget);
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);

        verticalLayout_2->addWidget(titlebarWidget);

        lblGroupName = new QLabel(dialogbg);
        lblGroupName->setObjectName(QStringLiteral("lblGroupName"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(lblGroupName->sizePolicy().hasHeightForWidth());
        lblGroupName->setSizePolicy(sizePolicy1);
        lblGroupName->setMinimumSize(QSize(0, 20));

        verticalLayout_2->addWidget(lblGroupName);

        lineEdit = new QLineEdit(dialogbg);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        verticalLayout_2->addWidget(lineEdit);

        lblMember = new QLabel(dialogbg);
        lblMember->setObjectName(QStringLiteral("lblMember"));
        sizePolicy1.setHeightForWidth(lblMember->sizePolicy().hasHeightForWidth());
        lblMember->setSizePolicy(sizePolicy1);
        lblMember->setMinimumSize(QSize(0, 20));

        verticalLayout_2->addWidget(lblMember);

        widget = new QWidget(dialogbg);
        widget->setObjectName(QStringLiteral("widget"));
        horizontalLayout_4 = new QHBoxLayout(widget);
        horizontalLayout_4->setSpacing(0);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        listWidget = new QListWidget(widget);
        listWidget->setObjectName(QStringLiteral("listWidget"));

        horizontalLayout_4->addWidget(listWidget);

        widget_4 = new QWidget(widget);
        widget_4->setObjectName(QStringLiteral("widget_4"));
        verticalLayout_4 = new QVBoxLayout(widget_4);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        btnAdd = new QPushButton(widget_4);
        btnAdd->setObjectName(QStringLiteral("btnAdd"));

        verticalLayout_4->addWidget(btnAdd);

        btnRemove = new QPushButton(widget_4);
        btnRemove->setObjectName(QStringLiteral("btnRemove"));

        verticalLayout_4->addWidget(btnRemove);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer_2);


        horizontalLayout_4->addWidget(widget_4);


        verticalLayout_2->addWidget(widget);

        widget_2 = new QWidget(dialogbg);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        sizePolicy1.setHeightForWidth(widget_2->sizePolicy().hasHeightForWidth());
        widget_2->setSizePolicy(sizePolicy1);
        widget_2->setMaximumSize(QSize(16777215, 60));
        horizontalLayout_3 = new QHBoxLayout(widget_2);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);

        btnOK = new QPushButton(widget_2);
        btnOK->setObjectName(QStringLiteral("btnOK"));

        horizontalLayout_3->addWidget(btnOK);

        btnCancel = new QPushButton(widget_2);
        btnCancel->setObjectName(QStringLiteral("btnCancel"));

        horizontalLayout_3->addWidget(btnCancel);


        verticalLayout_2->addWidget(widget_2);


        verticalLayout->addWidget(dialogbg);


        retranslateUi(AddGroupDialog);

        QMetaObject::connectSlotsByName(AddGroupDialog);
    } // setupUi

    void retranslateUi(QDialog *AddGroupDialog)
    {
        AddGroupDialog->setWindowTitle(QApplication::translate("AddGroupDialog", "AddGroupDialog", 0));
        lblGroupName->setText(QApplication::translate("AddGroupDialog", "TextLabel", 0));
        lblMember->setText(QApplication::translate("AddGroupDialog", "TextLabel", 0));
        btnAdd->setText(QApplication::translate("AddGroupDialog", "PushButton", 0));
        btnRemove->setText(QApplication::translate("AddGroupDialog", "PushButton", 0));
        btnOK->setText(QApplication::translate("AddGroupDialog", "PushButton", 0));
        btnCancel->setText(QApplication::translate("AddGroupDialog", "PushButton", 0));
    } // retranslateUi

};

namespace Ui {
    class AddGroupDialog: public Ui_AddGroupDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDGROUPDIALOG_H
