/********************************************************************************
** Form generated from reading UI file 'SearchAtResultDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SEARCHATRESULTDIALOG_H
#define UI_SEARCHATRESULTDIALOG_H

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

class Ui_SearchAtResultDialog
{
public:
    QVBoxLayout *verticalLayout_3;
    QWidget *shadowbg;
    QHBoxLayout *horizontalLayout_2;
    QWidget *shadowinnerbg;
    QHBoxLayout *horizontalLayout;
    QListWidget *listWidget;

    void setupUi(QWidget *SearchAtResultDialog)
    {
        if (SearchAtResultDialog->objectName().isEmpty())
            SearchAtResultDialog->setObjectName(QStringLiteral("SearchAtResultDialog"));
        SearchAtResultDialog->resize(400, 150);
        SearchAtResultDialog->setMaximumSize(QSize(16777215, 16777215));
        SearchAtResultDialog->setStyleSheet(QString::fromUtf8("QWidget{\n"
"    font-family:\345\276\256\350\275\257\351\233\205\351\273\221;\n"
"}\n"
"QListWidget{\n"
"    border:none;\n"
"    background-color:#00000000;\n"
"}"));
        verticalLayout_3 = new QVBoxLayout(SearchAtResultDialog);
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        shadowbg = new QWidget(SearchAtResultDialog);
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


        verticalLayout_3->addWidget(shadowbg);


        retranslateUi(SearchAtResultDialog);

        QMetaObject::connectSlotsByName(SearchAtResultDialog);
    } // setupUi

    void retranslateUi(QWidget *SearchAtResultDialog)
    {
        SearchAtResultDialog->setWindowTitle(QApplication::translate("SearchAtResultDialog", "Form", 0));
    } // retranslateUi

};

namespace Ui {
    class SearchAtResultDialog: public Ui_SearchAtResultDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SEARCHATRESULTDIALOG_H
