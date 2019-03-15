/********************************************************************************
** Form generated from reading UI file 'AtNoticeTip.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ATNOTICETIP_H
#define UI_ATNOTICETIP_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AtNoticeTip
{
public:
    QVBoxLayout *verticalLayout_2;
    QWidget *base;
    QHBoxLayout *horizontalLayout;
    QPushButton *label;
    QPushButton *pushButton;

    void setupUi(QWidget *AtNoticeTip)
    {
        if (AtNoticeTip->objectName().isEmpty())
            AtNoticeTip->setObjectName(QStringLiteral("AtNoticeTip"));
        AtNoticeTip->resize(322, 28);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(AtNoticeTip->sizePolicy().hasHeightForWidth());
        AtNoticeTip->setSizePolicy(sizePolicy);
        AtNoticeTip->setMinimumSize(QSize(0, 28));
        AtNoticeTip->setMaximumSize(QSize(16777215, 28));
        AtNoticeTip->setStyleSheet(QLatin1String("\n"
"QWidget#base \n"
"{\n"
"	background-color: #F38B76;\n"
"	padding:0px 5px;\n"
"}\n"
"QPushButton#label{\n"
"	color:#EFEFEF;\n"
"	border:none;\n"
"	text-align: left;\n"
"}"));
        verticalLayout_2 = new QVBoxLayout(AtNoticeTip);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        base = new QWidget(AtNoticeTip);
        base->setObjectName(QStringLiteral("base"));
        base->setMaximumSize(QSize(16777215, 16777215));
        base->setStyleSheet(QStringLiteral("padding:5px;"));
        horizontalLayout = new QHBoxLayout(base);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(10, 0, 10, 0);
        label = new QPushButton(base);
        label->setObjectName(QStringLiteral("label"));
        label->setMinimumSize(QSize(0, 28));
        label->setStyleSheet(QStringLiteral(""));
        label->setFlat(true);

        horizontalLayout->addWidget(label);

        pushButton = new QPushButton(base);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setMinimumSize(QSize(0, 0));
        pushButton->setMaximumSize(QSize(16, 16));
        pushButton->setStyleSheet(QStringLiteral("border: 0px; "));
        pushButton->setFlat(true);

        horizontalLayout->addWidget(pushButton);


        verticalLayout_2->addWidget(base);


        retranslateUi(AtNoticeTip);

        QMetaObject::connectSlotsByName(AtNoticeTip);
    } // setupUi

    void retranslateUi(QWidget *AtNoticeTip)
    {
        AtNoticeTip->setWindowTitle(QApplication::translate("AtNoticeTip", "GroupChatDialog", 0));
        label->setText(QString());
        pushButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class AtNoticeTip: public Ui_AtNoticeTip {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ATNOTICETIP_H
