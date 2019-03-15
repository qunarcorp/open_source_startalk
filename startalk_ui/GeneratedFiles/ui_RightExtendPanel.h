/********************************************************************************
** Form generated from reading UI file 'RightExtendPanel.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RIGHTEXTENDPANEL_H
#define UI_RIGHTEXTENDPANEL_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RightExtendPanel
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *widget;
    QVBoxLayout *verticalLayout_2;
    QWidget *Titleswidget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QStackedWidget *stackedWidget_right;

    void setupUi(QWidget *RightExtendPanel)
    {
        if (RightExtendPanel->objectName().isEmpty())
            RightExtendPanel->setObjectName(QStringLiteral("RightExtendPanel"));
        RightExtendPanel->resize(339, 650);
        RightExtendPanel->setStyleSheet(QStringLiteral(""));
        verticalLayout = new QVBoxLayout(RightExtendPanel);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        widget = new QWidget(RightExtendPanel);
        widget->setObjectName(QStringLiteral("widget"));
        verticalLayout_2 = new QVBoxLayout(widget);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(1, 1, 0, 0);
        Titleswidget = new QWidget(widget);
        Titleswidget->setObjectName(QStringLiteral("Titleswidget"));
        Titleswidget->setMinimumSize(QSize(0, 30));
        Titleswidget->setMaximumSize(QSize(16777215, 30));
        Titleswidget->setStyleSheet(QStringLiteral(""));
        horizontalLayout = new QHBoxLayout(Titleswidget);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer = new QSpacerItem(316, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout_2->addWidget(Titleswidget);

        stackedWidget_right = new QStackedWidget(widget);
        stackedWidget_right->setObjectName(QStringLiteral("stackedWidget_right"));

        verticalLayout_2->addWidget(stackedWidget_right);


        verticalLayout->addWidget(widget);


        retranslateUi(RightExtendPanel);

        QMetaObject::connectSlotsByName(RightExtendPanel);
    } // setupUi

    void retranslateUi(QWidget *RightExtendPanel)
    {
        RightExtendPanel->setWindowTitle(QApplication::translate("RightExtendPanel", "Form", 0));
    } // retranslateUi

};

namespace Ui {
    class RightExtendPanel: public Ui_RightExtendPanel {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RIGHTEXTENDPANEL_H
