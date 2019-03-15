/********************************************************************************
** Form generated from reading UI file 'personitem_l.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PERSONITEM_L_H
#define UI_PERSONITEM_L_H

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

class Ui_PersonItem_L
{
public:
    QHBoxLayout *horizontalLayout_2;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QLabel *header;
    QLabel *display;
    QLabel *groupName;
    QSpacerItem *horizontalSpacer;
    QPushButton *selectButton;

    void setupUi(QWidget *PersonItem_L)
    {
        if (PersonItem_L->objectName().isEmpty())
            PersonItem_L->setObjectName(QStringLiteral("PersonItem_L"));
        PersonItem_L->resize(400, 32);
        PersonItem_L->setMinimumSize(QSize(0, 32));
        PersonItem_L->setMaximumSize(QSize(16777215, 32));
        PersonItem_L->setStyleSheet(QLatin1String("QWidget#widget{\n"
"	background-color:#EAEBED;\n"
"}\n"
"\n"
"QWidget#widget:hover{\n"
"	background-color:#4F9AD4;\n"
"}\n"
"\n"
"QLabel#header{\n"
"	border:1px solid #00000000;\n"
"	\n"
"}\n"
"\n"
"QPushButton#selectButton{\n"
"	border-image: url(:/Images/icon_check_empty.png)\n"
"}\n"
"\n"
"QPushButton#selectButton:checked{\n"
"	border-image:url(:/Images/icon_check_filled.png);\n"
"}"));
        horizontalLayout_2 = new QHBoxLayout(PersonItem_L);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        widget = new QWidget(PersonItem_L);
        widget->setObjectName(QStringLiteral("widget"));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 20, 0);
        header = new QLabel(widget);
        header->setObjectName(QStringLiteral("header"));
        header->setMinimumSize(QSize(28, 28));
        header->setMaximumSize(QSize(28, 28));

        horizontalLayout->addWidget(header);

        display = new QLabel(widget);
        display->setObjectName(QStringLiteral("display"));

        horizontalLayout->addWidget(display);

        groupName = new QLabel(widget);
        groupName->setObjectName(QStringLiteral("groupName"));

        horizontalLayout->addWidget(groupName);

        horizontalSpacer = new QSpacerItem(253, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        selectButton = new QPushButton(widget);
        selectButton->setObjectName(QStringLiteral("selectButton"));
        selectButton->setMinimumSize(QSize(24, 24));
        selectButton->setMaximumSize(QSize(24, 24));
        selectButton->setCheckable(true);
        selectButton->setFlat(true);

        horizontalLayout->addWidget(selectButton);


        horizontalLayout_2->addWidget(widget);


        retranslateUi(PersonItem_L);

        QMetaObject::connectSlotsByName(PersonItem_L);
    } // setupUi

    void retranslateUi(QWidget *PersonItem_L)
    {
        PersonItem_L->setWindowTitle(QApplication::translate("PersonItem_L", "PersonItem_L", 0));
        header->setText(QString());
        display->setText(QString());
        groupName->setText(QString());
        selectButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class PersonItem_L: public Ui_PersonItem_L {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PERSONITEM_L_H
