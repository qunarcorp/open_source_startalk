/********************************************************************************
** Form generated from reading UI file 'conversationselectwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONVERSATIONSELECTWIDGET_H
#define UI_CONVERSATIONSELECTWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "LocalManDialog.h"
#include "TitlebarWidget.h"

QT_BEGIN_NAMESPACE

class Ui_ConversationSelectWidget
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *shadowbg;
    QVBoxLayout *verticalLayout_2;
    QWidget *shadowinnerbg;
    QVBoxLayout *verticalLayout_4;
    TitlebarWidget *titlebar;
    QWidget *widget_search;
    QVBoxLayout *verticalLayout_3;
    QLineEdit *searchEdit;
    QWidget *contentview;

    void setupUi(LocalManDialog *ConversationSelectWidget)
    {
        if (ConversationSelectWidget->objectName().isEmpty())
            ConversationSelectWidget->setObjectName(QStringLiteral("ConversationSelectWidget"));
        ConversationSelectWidget->resize(352, 656);
        ConversationSelectWidget->setStyleSheet(QLatin1String(" QWidget#contentview{background-color:#3A3A3A;}\n"
" QListWidget {border:none;background-color:#00000000;}\n"
"QLineEdit#searchEdit{\n"
"    padding-left:20px;\n"
"    border:1px solid #FFFFFF;\n"
"    border-radius: 13px;\n"
"}"));
        verticalLayout = new QVBoxLayout(ConversationSelectWidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        shadowbg = new QWidget(ConversationSelectWidget);
        shadowbg->setObjectName(QStringLiteral("shadowbg"));
        verticalLayout_2 = new QVBoxLayout(shadowbg);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(8, 8, 8, 8);
        shadowinnerbg = new QWidget(shadowbg);
        shadowinnerbg->setObjectName(QStringLiteral("shadowinnerbg"));
        verticalLayout_4 = new QVBoxLayout(shadowinnerbg);
        verticalLayout_4->setSpacing(0);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(1, 1, 1, 1);
        titlebar = new TitlebarWidget(shadowinnerbg);
        titlebar->setObjectName(QStringLiteral("titlebar"));
        titlebar->setMinimumSize(QSize(0, 27));
        titlebar->setMaximumSize(QSize(16777215, 27));

        verticalLayout_4->addWidget(titlebar);

        widget_search = new QWidget(shadowinnerbg);
        widget_search->setObjectName(QStringLiteral("widget_search"));
        widget_search->setMinimumSize(QSize(0, 36));
        widget_search->setMaximumSize(QSize(16777215, 36));
        verticalLayout_3 = new QVBoxLayout(widget_search);
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(16, 2, 16, 2);
        searchEdit = new QLineEdit(widget_search);
        searchEdit->setObjectName(QStringLiteral("searchEdit"));
        searchEdit->setMinimumSize(QSize(0, 26));

        verticalLayout_3->addWidget(searchEdit);


        verticalLayout_4->addWidget(widget_search);

        contentview = new QWidget(shadowinnerbg);
        contentview->setObjectName(QStringLiteral("contentview"));

        verticalLayout_4->addWidget(contentview);


        verticalLayout_2->addWidget(shadowinnerbg);


        verticalLayout->addWidget(shadowbg);


        retranslateUi(ConversationSelectWidget);

        QMetaObject::connectSlotsByName(ConversationSelectWidget);
    } // setupUi

    void retranslateUi(LocalManDialog *ConversationSelectWidget)
    {
        ConversationSelectWidget->setWindowTitle(QApplication::translate("ConversationSelectWidget", "ConversationSelectWidget", 0));
        searchEdit->setText(QString());
        searchEdit->setPlaceholderText(QApplication::translate("ConversationSelectWidget", "\346\220\234\347\264\242\350\201\224\347\263\273\344\272\272", 0));
    } // retranslateUi

};

namespace Ui {
    class ConversationSelectWidget: public Ui_ConversationSelectWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONVERSATIONSELECTWIDGET_H
