/********************************************************************************
** Form generated from reading UI file 'WorkStatusWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WORKSTATUSWIDGET_H
#define UI_WORKSTATUSWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WorkStatusWidget
{
public:
    QVBoxLayout *verticalLayout_4;
    QWidget *widget;
    QVBoxLayout *verticalLayout_3;
    QWidget *widget_title;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLabel *label_shopname;
    QWidget *widget_2;
    QVBoxLayout *verticalLayout_2;
    QWidget *funspanel;
    QVBoxLayout *verticalLayout;
    QRadioButton *radioButton_StandardModel;
    QRadioButton *radioButton_SupermanModel;
    QRadioButton *radioButton_NodisturbModel;

    void setupUi(QWidget *WorkStatusWidget)
    {
        if (WorkStatusWidget->objectName().isEmpty())
            WorkStatusWidget->setObjectName(QStringLiteral("WorkStatusWidget"));
        WorkStatusWidget->resize(400, 120);
        WorkStatusWidget->setMinimumSize(QSize(0, 0));
        WorkStatusWidget->setMaximumSize(QSize(16777215, 120));
        verticalLayout_4 = new QVBoxLayout(WorkStatusWidget);
        verticalLayout_4->setSpacing(0);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        widget = new QWidget(WorkStatusWidget);
        widget->setObjectName(QStringLiteral("widget"));
        verticalLayout_3 = new QVBoxLayout(widget);
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        widget_title = new QWidget(widget);
        widget_title->setObjectName(QStringLiteral("widget_title"));
        widget_title->setMinimumSize(QSize(0, 20));
        widget_title->setMaximumSize(QSize(16777215, 20));
        horizontalLayout = new QHBoxLayout(widget_title);
        horizontalLayout->setSpacing(10);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(120, 0, 80, 0);
        label = new QLabel(widget_title);
        label->setObjectName(QStringLiteral("label"));
        label->setMinimumSize(QSize(40, 0));
        label->setMaximumSize(QSize(40, 16777215));

        horizontalLayout->addWidget(label);

        label_shopname = new QLabel(widget_title);
        label_shopname->setObjectName(QStringLiteral("label_shopname"));

        horizontalLayout->addWidget(label_shopname);


        verticalLayout_3->addWidget(widget_title);

        widget_2 = new QWidget(widget);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        verticalLayout_2 = new QVBoxLayout(widget_2);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        funspanel = new QWidget(widget_2);
        funspanel->setObjectName(QStringLiteral("funspanel"));
        funspanel->setMinimumSize(QSize(0, 100));
        funspanel->setStyleSheet(QStringLiteral(""));
        verticalLayout = new QVBoxLayout(funspanel);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(120, 0, 0, 0);
        radioButton_StandardModel = new QRadioButton(funspanel);
        radioButton_StandardModel->setObjectName(QStringLiteral("radioButton_StandardModel"));

        verticalLayout->addWidget(radioButton_StandardModel);

        radioButton_SupermanModel = new QRadioButton(funspanel);
        radioButton_SupermanModel->setObjectName(QStringLiteral("radioButton_SupermanModel"));

        verticalLayout->addWidget(radioButton_SupermanModel);

        radioButton_NodisturbModel = new QRadioButton(funspanel);
        radioButton_NodisturbModel->setObjectName(QStringLiteral("radioButton_NodisturbModel"));

        verticalLayout->addWidget(radioButton_NodisturbModel);


        verticalLayout_2->addWidget(funspanel);


        verticalLayout_3->addWidget(widget_2);


        verticalLayout_4->addWidget(widget);


        retranslateUi(WorkStatusWidget);

        QMetaObject::connectSlotsByName(WorkStatusWidget);
    } // setupUi

    void retranslateUi(QWidget *WorkStatusWidget)
    {
        WorkStatusWidget->setWindowTitle(QApplication::translate("WorkStatusWidget", "Form", 0));
        label->setText(QApplication::translate("WorkStatusWidget", "\345\272\227\351\223\272\345\220\215:", 0));
        label_shopname->setText(QApplication::translate("WorkStatusWidget", "TextLabel", 0));
        radioButton_StandardModel->setText(QApplication::translate("WorkStatusWidget", "\346\240\207\345\207\206\346\250\241\345\274\217\357\274\210\345\234\250\347\272\277\346\227\266\346\211\215\346\216\245\345\217\227\345\222\250\350\257\242\357\274\214\351\273\230\350\256\244\357\274\211", 0));
        radioButton_SupermanModel->setText(QApplication::translate("WorkStatusWidget", "\350\266\205\344\272\272\346\250\241\345\274\217\357\274\210\344\270\215\345\234\250\347\272\277\344\271\237\346\216\245\345\217\227\345\222\250\350\257\242\357\274\211", 0));
        radioButton_NodisturbModel->setText(QApplication::translate("WorkStatusWidget", "\345\213\277\346\211\260\346\250\241\345\274\217\357\274\210\345\234\250\347\272\277\344\271\237\344\270\215\346\216\245\345\217\227\345\222\250\350\257\242\357\274\211", 0));
    } // retranslateUi

};

namespace Ui {
    class WorkStatusWidget: public Ui_WorkStatusWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WORKSTATUSWIDGET_H
