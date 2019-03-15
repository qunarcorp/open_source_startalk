/********************************************************************************
** Form generated from reading UI file 'personitem_r.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PERSONITEM_R_H
#define UI_PERSONITEM_R_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PersonItem_R
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QLabel *header;
    QLabel *display;
    QSpacerItem *horizontalSpacer;
    QPushButton *selectButton;
    QWidget *widget_2;

    void setupUi(QWidget *PersonItem_R)
    {
        if (PersonItem_R->objectName().isEmpty())
            PersonItem_R->setObjectName(QStringLiteral("PersonItem_R"));
        PersonItem_R->resize(400, 33);
        PersonItem_R->setMinimumSize(QSize(0, 33));
        PersonItem_R->setMaximumSize(QSize(16777215, 38));
        PersonItem_R->setStyleSheet(QLatin1String("QWidget#widget{\n"
"	background-color:#FFFFFF;\n"
"}\n"
"QWidget#widget2{\n"
"	background-color:#EFEFEF;\n"
"}\n"
"\n"
"QLabel#header{\n"
"	border:1px solid #00000000;\n"
"	image:url(:/Images/mainpanel_buddy_down.png)\n"
"}\n"
"\n"
"QPushButton#selectButton{\n"
"	border-image: url(:/Images/icon_check_empty.png)\n"
"}\n"
"\n"
"QPushButton#selectButton:hover{\n"
"	border-image:url(:/Images/icon_check_close.png)\n"
"}\n"
"\n"
"QWidget#widget_2{\n"
"	background-color:#EAEBED;\n"
"}\n"
""));
        verticalLayout = new QVBoxLayout(PersonItem_R);
        verticalLayout->setSpacing(0);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        widget = new QWidget(PersonItem_R);
        widget->setObjectName(QStringLiteral("widget"));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(20, 0, 20, 0);
        header = new QLabel(widget);
        header->setObjectName(QStringLiteral("header"));
        header->setMinimumSize(QSize(28, 28));
        header->setMaximumSize(QSize(28, 28));

        horizontalLayout->addWidget(header);

        display = new QLabel(widget);
        display->setObjectName(QStringLiteral("display"));

        horizontalLayout->addWidget(display);

        horizontalSpacer = new QSpacerItem(253, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        selectButton = new QPushButton(widget);
        selectButton->setObjectName(QStringLiteral("selectButton"));
        selectButton->setMinimumSize(QSize(24, 24));
        selectButton->setMaximumSize(QSize(24, 24));
        selectButton->setCheckable(true);
        selectButton->setFlat(true);

        horizontalLayout->addWidget(selectButton);


        verticalLayout->addWidget(widget);

        widget_2 = new QWidget(PersonItem_R);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        widget_2->setMinimumSize(QSize(0, 1));
        widget_2->setMaximumSize(QSize(16777215, 1));

        verticalLayout->addWidget(widget_2);


        retranslateUi(PersonItem_R);

        QMetaObject::connectSlotsByName(PersonItem_R);
    } // setupUi

    void retranslateUi(QWidget *PersonItem_R)
    {
        PersonItem_R->setWindowTitle(QApplication::translate("PersonItem_R", "PersonItem_R", 0));
        header->setText(QString());
        display->setText(QApplication::translate("PersonItem_R", "TextLabel", 0));
        selectButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class PersonItem_R: public Ui_PersonItem_R {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PERSONITEM_R_H
