/********************************************************************************
** Form generated from reading UI file 'AdvToolbar.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADVTOOLBAR_H
#define UI_ADVTOOLBAR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AdvToolbar
{
public:
    QPushButton *pbclose;

    void setupUi(QWidget *AdvToolbar)
    {
        if (AdvToolbar->objectName().isEmpty())
            AdvToolbar->setObjectName(QStringLiteral("AdvToolbar"));
        AdvToolbar->resize(203, 61);
        AdvToolbar->setStyleSheet(QLatin1String("QWidget {\n"
"    background:#00000000;\n"
"}\n"
"QPushButton#pbclose{\n"
" 	border:1px solid #ebebeb;\n"
"	border-radius: 6px;\n"
"	background:#A0000000;\n"
"	image: url(:/Images/close_mini_hover.png);\n"
"}\n"
"\n"
"QPushButton#pbclose:hover{\n"
"	border:1px solid #A0000000;\n"
"	background:#ebebeb;\n"
"	image: url(:/Images/close_mini_normal.png);\n"
"}\n"
""));
        pbclose = new QPushButton(AdvToolbar);
        pbclose->setObjectName(QStringLiteral("pbclose"));
        pbclose->setGeometry(QRect(50, 10, 12, 12));
        pbclose->setMinimumSize(QSize(12, 12));
        pbclose->setMaximumSize(QSize(12, 12));
        pbclose->setIconSize(QSize(12, 12));
        pbclose->setFlat(true);

        retranslateUi(AdvToolbar);

        QMetaObject::connectSlotsByName(AdvToolbar);
    } // setupUi

    void retranslateUi(QWidget *AdvToolbar)
    {
        AdvToolbar->setWindowTitle(QApplication::translate("AdvToolbar", "Form", 0));
        pbclose->setText(QString());
        pbclose->setShortcut(QApplication::translate("AdvToolbar", "Ctrl+S", 0));
    } // retranslateUi

};

namespace Ui {
    class AdvToolbar: public Ui_AdvToolbar {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADVTOOLBAR_H
