/********************************************************************************
** Form generated from reading UI file 'SettingHotKey.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTINGHOTKEY_H
#define UI_SETTINGHOTKEY_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SettingHotKeyDialog
{
public:
    QVBoxLayout *verticalLayout_2;
    QWidget *backgroup;
    QLabel *label_Infor;
    QLabel *label_HotKey;
    QWidget *layoutWidget;
    QHBoxLayout *hboxLayout;
    QSpacerItem *spacerItem;
    QPushButton *okButton;
    QPushButton *cancelButton;

    void setupUi(QWidget *SettingHotKeyDialog)
    {
        if (SettingHotKeyDialog->objectName().isEmpty())
            SettingHotKeyDialog->setObjectName(QStringLiteral("SettingHotKeyDialog"));
        SettingHotKeyDialog->resize(392, 192);
        SettingHotKeyDialog->setStyleSheet(QString::fromUtf8("QWidget#backgroup{\n"
"    background-color:#FFFFFF;\n"
"    border-radius: 4px;\n"
"	font-family:\345\276\256\350\275\257\351\233\205\351\273\221;\n"
"	border:1px solid #DADADA80\n"
"}\n"
"QLabel#label_HotKey\n"
"{\n"
"     font: bold 15px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"     color: red;\n"
"}"));
        verticalLayout_2 = new QVBoxLayout(SettingHotKeyDialog);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        backgroup = new QWidget(SettingHotKeyDialog);
        backgroup->setObjectName(QStringLiteral("backgroup"));
        label_Infor = new QLabel(backgroup);
        label_Infor->setObjectName(QStringLiteral("label_Infor"));
        label_Infor->setGeometry(QRect(9, 9, 321, 16));
        label_HotKey = new QLabel(backgroup);
        label_HotKey->setObjectName(QStringLiteral("label_HotKey"));
        label_HotKey->setGeometry(QRect(120, 60, 120, 45));
        label_HotKey->setMinimumSize(QSize(0, 45));
        label_HotKey->setAlignment(Qt::AlignCenter);
        layoutWidget = new QWidget(backgroup);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(9, 132, 341, 33));
        hboxLayout = new QHBoxLayout(layoutWidget);
        hboxLayout->setSpacing(6);
        hboxLayout->setObjectName(QStringLiteral("hboxLayout"));
        hboxLayout->setContentsMargins(0, 0, 0, 0);
        spacerItem = new QSpacerItem(131, 31, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout->addItem(spacerItem);

        okButton = new QPushButton(layoutWidget);
        okButton->setObjectName(QStringLiteral("okButton"));

        hboxLayout->addWidget(okButton);

        cancelButton = new QPushButton(layoutWidget);
        cancelButton->setObjectName(QStringLiteral("cancelButton"));

        hboxLayout->addWidget(cancelButton);


        verticalLayout_2->addWidget(backgroup);


        retranslateUi(SettingHotKeyDialog);

        QMetaObject::connectSlotsByName(SettingHotKeyDialog);
    } // setupUi

    void retranslateUi(QWidget *SettingHotKeyDialog)
    {
        SettingHotKeyDialog->setWindowTitle(QApplication::translate("SettingHotKeyDialog", "Dialog", 0));
        label_Infor->setText(QApplication::translate("SettingHotKeyDialog", "TextLabel", 0));
        label_HotKey->setText(QApplication::translate("SettingHotKeyDialog", "TextLabel", 0));
        okButton->setText(QApplication::translate("SettingHotKeyDialog", "OK", 0));
        cancelButton->setText(QApplication::translate("SettingHotKeyDialog", "Cancel", 0));
    } // retranslateUi

};

namespace Ui {
    class SettingHotKeyDialog: public Ui_SettingHotKeyDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGHOTKEY_H
