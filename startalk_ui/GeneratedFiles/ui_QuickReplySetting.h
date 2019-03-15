/********************************************************************************
** Form generated from reading UI file 'QuickReplySetting.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QUICKREPLYSETTING_H
#define UI_QUICKREPLYSETTING_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "Tableview.h"
#include "TitlebarWidget.h"

QT_BEGIN_NAMESPACE

class Ui_QuickRepySettingDialog
{
public:
    QWidget *widget_bk;
    TitlebarWidget *TitleBar;
    QWidget *widget_2;
    QWidget *widget_3;
    QVBoxLayout *verticalLayout;
    QPushButton *pbAdd;
    QPushButton *pbMody;
    QPushButton *pbDelete;
    QPushButton *pbMoveUp;
    QPushButton *pbMoveDown;
    QWidget *widget_4;
    QHBoxLayout *horizontalLayout;
    QPushButton *pbAddGroup;
    QSpacerItem *horizontalSpacer;
    QPushButton *pbCancel;
    QPushButton *pbOk;
    TableView *QtableView;
    TableView *QtableView_2;

    void setupUi(QDialog *QuickRepySettingDialog)
    {
        if (QuickRepySettingDialog->objectName().isEmpty())
            QuickRepySettingDialog->setObjectName(QStringLiteral("QuickRepySettingDialog"));
        QuickRepySettingDialog->resize(600, 400);
        QuickRepySettingDialog->setStyleSheet(QLatin1String("QDialog {\n"
"    border: 1px solid #000000;\n"
"   background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,  \n"
"                                 stop: 0 #FFFFFF, stop: 0.1 #A3A6A9,  \n"
"                                 stop: 0.9 #A3A6A9, stop: 1.0 #FFFFFF);\n"
"}\n"
"TableView::item::selected\n"
"{\n"
"	color:white;\n"
"	background:blue;  \n"
"}"));
        widget_bk = new QWidget(QuickRepySettingDialog);
        widget_bk->setObjectName(QStringLiteral("widget_bk"));
        widget_bk->setGeometry(QRect(0, 0, 600, 400));
        TitleBar = new TitlebarWidget(widget_bk);
        TitleBar->setObjectName(QStringLiteral("TitleBar"));
        TitleBar->setGeometry(QRect(0, 0, 600, 30));
        widget_2 = new QWidget(widget_bk);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        widget_2->setGeometry(QRect(10, 30, 590, 370));
        widget_3 = new QWidget(widget_2);
        widget_3->setObjectName(QStringLiteral("widget_3"));
        widget_3->setGeometry(QRect(500, 0, 93, 320));
        verticalLayout = new QVBoxLayout(widget_3);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        pbAdd = new QPushButton(widget_3);
        pbAdd->setObjectName(QStringLiteral("pbAdd"));

        verticalLayout->addWidget(pbAdd);

        pbMody = new QPushButton(widget_3);
        pbMody->setObjectName(QStringLiteral("pbMody"));

        verticalLayout->addWidget(pbMody);

        pbDelete = new QPushButton(widget_3);
        pbDelete->setObjectName(QStringLiteral("pbDelete"));

        verticalLayout->addWidget(pbDelete);

        pbMoveUp = new QPushButton(widget_3);
        pbMoveUp->setObjectName(QStringLiteral("pbMoveUp"));

        verticalLayout->addWidget(pbMoveUp);

        pbMoveDown = new QPushButton(widget_3);
        pbMoveDown->setObjectName(QStringLiteral("pbMoveDown"));

        verticalLayout->addWidget(pbMoveDown);

        widget_4 = new QWidget(widget_2);
        widget_4->setObjectName(QStringLiteral("widget_4"));
        widget_4->setGeometry(QRect(0, 320, 580, 50));
        horizontalLayout = new QHBoxLayout(widget_4);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 10, 0);
        pbAddGroup = new QPushButton(widget_4);
        pbAddGroup->setObjectName(QStringLiteral("pbAddGroup"));

        horizontalLayout->addWidget(pbAddGroup);

        horizontalSpacer = new QSpacerItem(372, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pbCancel = new QPushButton(widget_4);
        pbCancel->setObjectName(QStringLiteral("pbCancel"));

        horizontalLayout->addWidget(pbCancel);

        pbOk = new QPushButton(widget_4);
        pbOk->setObjectName(QStringLiteral("pbOk"));

        horizontalLayout->addWidget(pbOk);

        QtableView = new TableView(widget_2);
        QtableView->setObjectName(QStringLiteral("QtableView"));
        QtableView->setGeometry(QRect(134, 0, 371, 320));
        QtableView_2 = new TableView(widget_2);
        QtableView_2->setObjectName(QStringLiteral("QtableView_2"));
        QtableView_2->setGeometry(QRect(0, 0, 134, 320));

        retranslateUi(QuickRepySettingDialog);

        QMetaObject::connectSlotsByName(QuickRepySettingDialog);
    } // setupUi

    void retranslateUi(QDialog *QuickRepySettingDialog)
    {
        QuickRepySettingDialog->setWindowTitle(QApplication::translate("QuickRepySettingDialog", "Dialog", 0));
        pbAdd->setText(QApplication::translate("QuickRepySettingDialog", "\346\267\273\345\212\240", 0));
        pbMody->setText(QApplication::translate("QuickRepySettingDialog", "\344\277\256\346\224\271", 0));
        pbDelete->setText(QApplication::translate("QuickRepySettingDialog", "\345\210\240\351\231\244", 0));
        pbMoveUp->setText(QApplication::translate("QuickRepySettingDialog", "\344\270\212\347\247\273", 0));
        pbMoveDown->setText(QApplication::translate("QuickRepySettingDialog", "\344\270\213\347\247\273", 0));
        pbAddGroup->setText(QApplication::translate("QuickRepySettingDialog", "\347\256\241\347\220\206\347\273\204", 0));
        pbCancel->setText(QApplication::translate("QuickRepySettingDialog", "\345\217\226\346\266\210", 0));
        pbOk->setText(QApplication::translate("QuickRepySettingDialog", "\344\270\212\344\274\240\351\205\215\347\275\256", 0));
    } // retranslateUi

};

namespace Ui {
    class QuickRepySettingDialog: public Ui_QuickRepySettingDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QUICKREPLYSETTING_H
