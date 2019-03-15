/********************************************************************************
** Form generated from reading UI file 'QuicklyEditItemDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QUICKLYEDITITEMDIALOG_H
#define UI_QUICKLYEDITITEMDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>
#include "TitlebarWidget.h"

QT_BEGIN_NAMESPACE

class Ui_QuicklyItemEditDialog
{
public:
    QWidget *widget_bk;
    TitlebarWidget *TitleBar;
    QWidget *widget;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QComboBox *comboBox_group;
    QWidget *widget_3;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_content;
    QTextEdit *textEdit;
    QWidget *widget_4;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *pb_OK;
    QPushButton *pbCancel;

    void setupUi(QDialog *QuicklyItemEditDialog)
    {
        if (QuicklyItemEditDialog->objectName().isEmpty())
            QuicklyItemEditDialog->setObjectName(QStringLiteral("QuicklyItemEditDialog"));
        QuicklyItemEditDialog->resize(350, 230);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(QuicklyItemEditDialog->sizePolicy().hasHeightForWidth());
        QuicklyItemEditDialog->setSizePolicy(sizePolicy);
        widget_bk = new QWidget(QuicklyItemEditDialog);
        widget_bk->setObjectName(QStringLiteral("widget_bk"));
        widget_bk->setGeometry(QRect(0, 0, 350, 230));
        TitleBar = new TitlebarWidget(widget_bk);
        TitleBar->setObjectName(QStringLiteral("TitleBar"));
        TitleBar->setGeometry(QRect(0, 0, 350, 20));
        widget = new QWidget(widget_bk);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(0, 20, 350, 210));
        widget_2 = new QWidget(widget);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        widget_2->setGeometry(QRect(0, 0, 350, 51));
        horizontalLayout_2 = new QHBoxLayout(widget_2);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(50, 0, 190, 0);
        label = new QLabel(widget_2);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout_2->addWidget(label);

        comboBox_group = new QComboBox(widget_2);
        comboBox_group->setObjectName(QStringLiteral("comboBox_group"));
        comboBox_group->setMinimumSize(QSize(75, 20));
        comboBox_group->setMaximumSize(QSize(75, 20));

        horizontalLayout_2->addWidget(comboBox_group);

        widget_3 = new QWidget(widget);
        widget_3->setObjectName(QStringLiteral("widget_3"));
        widget_3->setGeometry(QRect(0, 50, 350, 111));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(widget_3->sizePolicy().hasHeightForWidth());
        widget_3->setSizePolicy(sizePolicy1);
        horizontalLayout_3 = new QHBoxLayout(widget_3);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(50, -1, 50, -1);
        label_content = new QLabel(widget_3);
        label_content->setObjectName(QStringLiteral("label_content"));
        label_content->setMinimumSize(QSize(31, 16));
        label_content->setMaximumSize(QSize(31, 16));

        horizontalLayout_3->addWidget(label_content);

        textEdit = new QTextEdit(widget_3);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setMinimumSize(QSize(210, 93));
        textEdit->setMaximumSize(QSize(210, 93));

        horizontalLayout_3->addWidget(textEdit);

        widget_4 = new QWidget(widget);
        widget_4->setObjectName(QStringLiteral("widget_4"));
        widget_4->setGeometry(QRect(0, 160, 350, 51));
        horizontalLayout = new QHBoxLayout(widget_4);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 10, 0);
        horizontalSpacer = new QSpacerItem(187, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pb_OK = new QPushButton(widget_4);
        pb_OK->setObjectName(QStringLiteral("pb_OK"));

        horizontalLayout->addWidget(pb_OK);

        pbCancel = new QPushButton(widget_4);
        pbCancel->setObjectName(QStringLiteral("pbCancel"));

        horizontalLayout->addWidget(pbCancel);


        retranslateUi(QuicklyItemEditDialog);

        QMetaObject::connectSlotsByName(QuicklyItemEditDialog);
    } // setupUi

    void retranslateUi(QDialog *QuicklyItemEditDialog)
    {
        QuicklyItemEditDialog->setWindowTitle(QApplication::translate("QuicklyItemEditDialog", "Dialog", 0));
        label->setText(QApplication::translate("QuicklyItemEditDialog", "\345\210\206\347\273\204:", 0));
        label_content->setText(QApplication::translate("QuicklyItemEditDialog", "\345\206\205\345\256\271:", 0));
        pb_OK->setText(QApplication::translate("QuicklyItemEditDialog", "\347\241\256\345\256\232", 0));
        pbCancel->setText(QApplication::translate("QuicklyItemEditDialog", "\345\217\226\346\266\210", 0));
    } // retranslateUi

};

namespace Ui {
    class QuicklyItemEditDialog: public Ui_QuicklyItemEditDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QUICKLYEDITITEMDIALOG_H
