/********************************************************************************
** Form generated from reading UI file 'SettingTabView.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTINGTABVIEW_H
#define UI_SETTINGTABVIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SettingTabView
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *SettingTab_View;
    QVBoxLayout *verticalLayout_2;
    QToolButton *SettingTab_ListItem_2;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *SettingTabView)
    {
        if (SettingTabView->objectName().isEmpty())
            SettingTabView->setObjectName(QStringLiteral("SettingTabView"));
        SettingTabView->resize(400, 300);
        verticalLayout = new QVBoxLayout(SettingTabView);
        verticalLayout->setSpacing(0);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        SettingTab_View = new QWidget(SettingTabView);
        SettingTab_View->setObjectName(QStringLiteral("SettingTab_View"));
        SettingTab_View->setMinimumSize(QSize(0, 20));
        verticalLayout_2 = new QVBoxLayout(SettingTab_View);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        SettingTab_ListItem_2 = new QToolButton(SettingTab_View);
        SettingTab_ListItem_2->setObjectName(QStringLiteral("SettingTab_ListItem_2"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(SettingTab_ListItem_2->sizePolicy().hasHeightForWidth());
        SettingTab_ListItem_2->setSizePolicy(sizePolicy);
        SettingTab_ListItem_2->setCheckable(true);

        verticalLayout_2->addWidget(SettingTab_ListItem_2);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);


        verticalLayout->addWidget(SettingTab_View);


        retranslateUi(SettingTabView);

        QMetaObject::connectSlotsByName(SettingTabView);
    } // setupUi

    void retranslateUi(QWidget *SettingTabView)
    {
        SettingTabView->setWindowTitle(QApplication::translate("SettingTabView", "SettingTabView", 0));
        SettingTab_ListItem_2->setText(QApplication::translate("SettingTabView", "PushButton", 0));
    } // retranslateUi

};

namespace Ui {
    class SettingTabView: public Ui_SettingTabView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGTABVIEW_H
