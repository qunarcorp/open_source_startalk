/********************************************************************************
** Form generated from reading UI file 'sysmessagedialog.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SYSMESSAGEDIALOG_H
#define UI_SYSMESSAGEDIALOG_H

#include <LocalManDialog.h>
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "TitlebarWidget.h"

QT_BEGIN_NAMESPACE

class Ui_SysMessageDialog
{
public:
    QVBoxLayout *verticalLayout_2;
    QWidget *widgetBorder;
    QVBoxLayout *verticalLayout;
    TitlebarWidget *titlebarWidget;
    QVBoxLayout *verticalLayout_3;
    QWidget *widget;
    QVBoxLayout *verticalLayout_4;
    QLabel *txtSubject;
    QSpacerItem *verticalSpacer;
    QTextEdit *txtBody;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *btnClose;

    void setupUi(LocalManDialog *SysMessageDialog)
    {
        if (SysMessageDialog->objectName().isEmpty())
            SysMessageDialog->setObjectName(QStringLiteral("SysMessageDialog"));
        SysMessageDialog->resize(447, 229);
        verticalLayout_2 = new QVBoxLayout(SysMessageDialog);
        verticalLayout_2->setSpacing(2);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(2, 6, 2, 2);
        widgetBorder = new QWidget(SysMessageDialog);
        widgetBorder->setObjectName(QStringLiteral("widgetBorder"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(widgetBorder->sizePolicy().hasHeightForWidth());
        widgetBorder->setSizePolicy(sizePolicy);
        verticalLayout = new QVBoxLayout(widgetBorder);
        verticalLayout->setSpacing(0);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(4, 4, 4, 4);
        titlebarWidget = new TitlebarWidget(widgetBorder);
        titlebarWidget->setObjectName(QStringLiteral("titlebarWidget"));
        titlebarWidget->setMinimumSize(QSize(0, 25));
        titlebarWidget->setMaximumSize(QSize(16777215, 40));
        verticalLayout_3 = new QVBoxLayout(titlebarWidget);
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);

        verticalLayout->addWidget(titlebarWidget);

        widget = new QWidget(widgetBorder);
        widget->setObjectName(QStringLiteral("widget"));
        verticalLayout_4 = new QVBoxLayout(widget);
        verticalLayout_4->setSpacing(0);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(4, 4, 4, 4);
        txtSubject = new QLabel(widget);
        txtSubject->setObjectName(QStringLiteral("txtSubject"));

        verticalLayout_4->addWidget(txtSubject);

        verticalSpacer = new QSpacerItem(20, 80, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer);

        txtBody = new QTextEdit(widget);
        txtBody->setObjectName(QStringLiteral("txtBody"));
        txtBody->setReadOnly(true);

        verticalLayout_4->addWidget(txtBody);

        widget_2 = new QWidget(widget);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        horizontalLayout_3 = new QHBoxLayout(widget_2);
        horizontalLayout_3->setSpacing(4);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(4, 4, 4, 4);
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);

        btnClose = new QPushButton(widget_2);
        btnClose->setObjectName(QStringLiteral("btnClose"));

        horizontalLayout_3->addWidget(btnClose);


        verticalLayout_4->addWidget(widget_2);


        verticalLayout->addWidget(widget);


        verticalLayout_2->addWidget(widgetBorder);


        retranslateUi(SysMessageDialog);

        QMetaObject::connectSlotsByName(SysMessageDialog);
    } // setupUi

    void retranslateUi(LocalManDialog *SysMessageDialog)
    {
        SysMessageDialog->setWindowTitle(QApplication::translate("SysMessageDialog", "SysMessageDialog", 0));
        txtSubject->setText(QString());
        btnClose->setText(QApplication::translate("SysMessageDialog", "PushButton", 0));
    } // retranslateUi

};

namespace Ui {
    class SysMessageDialog: public Ui_SysMessageDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SYSMESSAGEDIALOG_H
