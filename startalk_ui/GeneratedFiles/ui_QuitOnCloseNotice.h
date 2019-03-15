/********************************************************************************
** Form generated from reading UI file 'QuitOnCloseNotice.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QUITONCLOSENOTICE_H
#define UI_QUITONCLOSENOTICE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "TitlebarWidget.h"

QT_BEGIN_NAMESPACE

class Ui_QuitOnCloseNotice
{
public:
    QHBoxLayout *horizontalLayout;
    QWidget *dialogbg;
    QVBoxLayout *verticalLayout;
    TitlebarWidget *titblebar;
    QWidget *widget_2;
    QCheckBox *cbMinOnClose;

    void setupUi(QWidget *QuitOnCloseNotice)
    {
        if (QuitOnCloseNotice->objectName().isEmpty())
            QuitOnCloseNotice->setObjectName(QStringLiteral("QuitOnCloseNotice"));
        QuitOnCloseNotice->resize(244, 107);
        QuitOnCloseNotice->setStyleSheet(QString::fromUtf8("QWidget\n"
"{\n"
"	color:#666666;\n"
"	font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"}"));
        horizontalLayout = new QHBoxLayout(QuitOnCloseNotice);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        dialogbg = new QWidget(QuitOnCloseNotice);
        dialogbg->setObjectName(QStringLiteral("dialogbg"));
        verticalLayout = new QVBoxLayout(dialogbg);
        verticalLayout->setSpacing(0);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        titblebar = new TitlebarWidget(dialogbg);
        titblebar->setObjectName(QStringLiteral("titblebar"));
        titblebar->setMinimumSize(QSize(0, 28));
        titblebar->setMaximumSize(QSize(16777215, 28));

        verticalLayout->addWidget(titblebar);

        widget_2 = new QWidget(dialogbg);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        cbMinOnClose = new QCheckBox(widget_2);
        cbMinOnClose->setObjectName(QStringLiteral("cbMinOnClose"));
        cbMinOnClose->setGeometry(QRect(40, 30, 161, 21));
        cbMinOnClose->setChecked(true);

        verticalLayout->addWidget(widget_2);


        horizontalLayout->addWidget(dialogbg);


        retranslateUi(QuitOnCloseNotice);

        QMetaObject::connectSlotsByName(QuitOnCloseNotice);
    } // setupUi

    void retranslateUi(QWidget *QuitOnCloseNotice)
    {
        QuitOnCloseNotice->setWindowTitle(QApplication::translate("QuitOnCloseNotice", "QuitOnCloseNotice", 0));
        cbMinOnClose->setText(QApplication::translate("QuitOnCloseNotice", "\347\202\271\345\207\273\345\205\263\351\227\255\346\214\211\351\222\256\347\274\251\345\260\217\345\210\260\346\211\230\347\233\230\357\274\237", 0));
    } // retranslateUi

};

namespace Ui {
    class QuitOnCloseNotice: public Ui_QuitOnCloseNotice {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QUITONCLOSENOTICE_H
