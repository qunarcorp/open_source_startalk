/********************************************************************************
** Form generated from reading UI file 'FriendsExtendPanel.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRIENDSEXTENDPANEL_H
#define UI_FRIENDSEXTENDPANEL_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "Friendslistview.h"

QT_BEGIN_NAMESPACE

class Ui_FriendsExtendPanel
{
public:
    QVBoxLayout *verticalLayout_4;
    QWidget *widget;
    FriendsListView *listView;
    QWidget *menupanel;
    QVBoxLayout *verticalLayout_2;
    QPushButton *pushButton;
    QListWidget *menuItems;

    void setupUi(QWidget *FriendsExtendPanel)
    {
        if (FriendsExtendPanel->objectName().isEmpty())
            FriendsExtendPanel->setObjectName(QStringLiteral("FriendsExtendPanel"));
        FriendsExtendPanel->resize(418, 514);
        verticalLayout_4 = new QVBoxLayout(FriendsExtendPanel);
        verticalLayout_4->setSpacing(0);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        widget = new QWidget(FriendsExtendPanel);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setStyleSheet(QStringLiteral(""));
        listView = new FriendsListView(widget);
        listView->setObjectName(QStringLiteral("listView"));
        listView->setGeometry(QRect(150, 260, 256, 192));
        menupanel = new QWidget(widget);
        menupanel->setObjectName(QStringLiteral("menupanel"));
        menupanel->setGeometry(QRect(10, 10, 161, 141));
        menupanel->setStyleSheet(QStringLiteral(""));
        verticalLayout_2 = new QVBoxLayout(menupanel);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        pushButton = new QPushButton(menupanel);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setMaximumSize(QSize(16777215, 16777215));
        pushButton->setStyleSheet(QStringLiteral(""));
        pushButton->setIconSize(QSize(0, 0));
        pushButton->setFlat(true);

        verticalLayout_2->addWidget(pushButton);

        menuItems = new QListWidget(menupanel);
        menuItems->setObjectName(QStringLiteral("menuItems"));
        menuItems->setStyleSheet(QStringLiteral(""));
        menuItems->setFlow(QListView::TopToBottom);
        menuItems->setBatchSize(100);

        verticalLayout_2->addWidget(menuItems);


        verticalLayout_4->addWidget(widget);


        retranslateUi(FriendsExtendPanel);

        QMetaObject::connectSlotsByName(FriendsExtendPanel);
    } // setupUi

    void retranslateUi(QWidget *FriendsExtendPanel)
    {
        FriendsExtendPanel->setWindowTitle(QApplication::translate("FriendsExtendPanel", "FriendsExtendPanel", 0));
        pushButton->setText(QApplication::translate("FriendsExtendPanel", "... \346\233\264\345\244\232", 0));
        pushButton->setShortcut(QApplication::translate("FriendsExtendPanel", "Ctrl+S", 0));
    } // retranslateUi

};

namespace Ui {
    class FriendsExtendPanel: public Ui_FriendsExtendPanel {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRIENDSEXTENDPANEL_H
