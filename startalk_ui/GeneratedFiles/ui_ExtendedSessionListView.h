/********************************************************************************
** Form generated from reading UI file 'ExtendedSessionListView.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EXTENDEDSESSIONLISTVIEW_H
#define UI_EXTENDEDSESSIONLISTVIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ExtendedSessionListView
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *title_panel;
    QHBoxLayout *horizontalLayout_22;
    QPushButton *pb_back;
    QLabel *titleText;
    QPushButton *pb_left_2;
    QWidget *widget;

    void setupUi(QWidget *ExtendedSessionListView)
    {
        if (ExtendedSessionListView->objectName().isEmpty())
            ExtendedSessionListView->setObjectName(QStringLiteral("ExtendedSessionListView"));
        ExtendedSessionListView->resize(300, 618);
        ExtendedSessionListView->setStyleSheet(QString::fromUtf8("\n"
"QWidget\n"
"{\n"
"    font-family:'\345\276\256\350\275\257\351\233\205\351\273\221';\n"
"}\n"
"\n"
"QPushButton#createnewgroup {\n"
"    border: 1px solid #00000000;\n"
"    image: url(:/Images/addButton.png);\n"
"}\n"
"\n"
"\n"
"QLabel#titleText\n"
"{\n"
"	border:none;\n"
"	color:#CFCFCF;\n"
"    font-size:14px;\n"
"}\n"
"\n"
"QPushButton#pb_back{ \n"
"    border:none;\n"
"	image : url(:/Images/previous.png);\n"
"} \n"
"QPushButton#pb_back:hover{ \n"
"    image : url(:/Images/previous_hover.png);\n"
"} \n"
"QPushButton#pb_back:pressed{ \n"
"    image : url(:/Images/previous_hover.png);\n"
"} \n"
"                                    "));
        verticalLayout = new QVBoxLayout(ExtendedSessionListView);
        verticalLayout->setSpacing(0);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, -1);
        title_panel = new QWidget(ExtendedSessionListView);
        title_panel->setObjectName(QStringLiteral("title_panel"));
        title_panel->setMinimumSize(QSize(0, 40));
        title_panel->setMaximumSize(QSize(16777215, 40));
        horizontalLayout_22 = new QHBoxLayout(title_panel);
        horizontalLayout_22->setSpacing(0);
        horizontalLayout_22->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_22->setObjectName(QStringLiteral("horizontalLayout_22"));
        horizontalLayout_22->setContentsMargins(0, 0, 0, 0);
        pb_back = new QPushButton(title_panel);
        pb_back->setObjectName(QStringLiteral("pb_back"));
        pb_back->setMinimumSize(QSize(0, 0));
        pb_back->setMaximumSize(QSize(45, 40));
        pb_back->setFlat(true);

        horizontalLayout_22->addWidget(pb_back);

        titleText = new QLabel(title_panel);
        titleText->setObjectName(QStringLiteral("titleText"));
        titleText->setAlignment(Qt::AlignCenter);

        horizontalLayout_22->addWidget(titleText);

        pb_left_2 = new QPushButton(title_panel);
        pb_left_2->setObjectName(QStringLiteral("pb_left_2"));
        pb_left_2->setMaximumSize(QSize(45, 40));
        pb_left_2->setFlat(true);

        horizontalLayout_22->addWidget(pb_left_2);


        verticalLayout->addWidget(title_panel);

        widget = new QWidget(ExtendedSessionListView);
        widget->setObjectName(QStringLiteral("widget"));

        verticalLayout->addWidget(widget);


        retranslateUi(ExtendedSessionListView);

        QMetaObject::connectSlotsByName(ExtendedSessionListView);
    } // setupUi

    void retranslateUi(QWidget *ExtendedSessionListView)
    {
        ExtendedSessionListView->setWindowTitle(QApplication::translate("ExtendedSessionListView", "ExtendedSessionListView", 0));
        pb_back->setText(QString());
        titleText->setText(QApplication::translate("ExtendedSessionListView", "\350\256\242\351\230\205\345\217\267", 0));
        pb_left_2->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class ExtendedSessionListView: public Ui_ExtendedSessionListView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EXTENDEDSESSIONLISTVIEW_H
