/********************************************************************************
** Form generated from reading UI file 'AccountListWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ACCOUNTLISTWIDGET_H
#define UI_ACCOUNTLISTWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AccountListWidget
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *shadowbg;
    QHBoxLayout *horizontalLayout_2;
    QWidget *shadowinnerbg;
    QHBoxLayout *horizontalLayout;
    QListWidget *listWidget;

    void setupUi(QWidget *AccountListWidget)
    {
        if (AccountListWidget->objectName().isEmpty())
            AccountListWidget->setObjectName(QStringLiteral("AccountListWidget"));
        AccountListWidget->resize(400, 150);
        AccountListWidget->setStyleSheet(QString::fromUtf8("QWidget{\n"
"    font-family:\345\276\256\350\275\257\351\233\205\351\273\221;\n"
"}\n"
"QListView{\n"
"    border:none;\n"
"    background-color:#00000000;\n"
"}"));
        verticalLayout = new QVBoxLayout(AccountListWidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        shadowbg = new QWidget(AccountListWidget);
        shadowbg->setObjectName(QStringLiteral("shadowbg"));
        shadowbg->setMaximumSize(QSize(16777215, 16777215));
        horizontalLayout_2 = new QHBoxLayout(shadowbg);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 2);
        shadowinnerbg = new QWidget(shadowbg);
        shadowinnerbg->setObjectName(QStringLiteral("shadowinnerbg"));
        shadowinnerbg->setMaximumSize(QSize(16777215, 16777215));
        horizontalLayout = new QHBoxLayout(shadowinnerbg);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        listWidget = new QListWidget(shadowinnerbg);
        listWidget->setObjectName(QStringLiteral("listWidget"));

        horizontalLayout->addWidget(listWidget);


        horizontalLayout_2->addWidget(shadowinnerbg);


        verticalLayout->addWidget(shadowbg);


        retranslateUi(AccountListWidget);

        QMetaObject::connectSlotsByName(AccountListWidget);
    } // setupUi

    void retranslateUi(QWidget *AccountListWidget)
    {
        AccountListWidget->setWindowTitle(QApplication::translate("AccountListWidget", "Form", 0));
    } // retranslateUi

};

namespace Ui {
    class AccountListWidget: public Ui_AccountListWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ACCOUNTLISTWIDGET_H
