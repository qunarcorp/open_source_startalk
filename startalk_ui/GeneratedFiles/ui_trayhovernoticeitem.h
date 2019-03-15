/********************************************************************************
** Form generated from reading UI file 'trayhovernoticeitem.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TRAYHOVERNOTICEITEM_H
#define UI_TRAYHOVERNOTICEITEM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TrayHoverNoticeItem
{
public:
    QHBoxLayout *horizontalLayout;
    QLabel *header;
    QLabel *name;
    QSpacerItem *horizontalSpacer;
    QLabel *count;

    void setupUi(QWidget *TrayHoverNoticeItem)
    {
        if (TrayHoverNoticeItem->objectName().isEmpty())
            TrayHoverNoticeItem->setObjectName(QStringLiteral("TrayHoverNoticeItem"));
        TrayHoverNoticeItem->resize(260, 47);
        TrayHoverNoticeItem->setStyleSheet(QLatin1String("QWidget#TrayHoverNoticeItem\n"
"{\n"
"	border:none;\n"
"	background:#00000000;\n"
"}\n"
"QLabel#header\n"
"{\n"
"	max-height:33px;\n"
"	max-width:33px;\n"
"	min-height:33px;\n"
"	min-width:33px;\n"
"}\n"
"\n"
"QLabel#name\n"
"{\n"
"	font:bold;\n"
"}\n"
"\n"
"QLabel#count{\n"
"	max-height:14px;\n"
"    font-size: 12px;\n"
"    color: #FFFFFF;\n"
"    background:#D75962;\n"
"	padding:2px;\n"
"	border-radius:7px;\n"
"}"));
        horizontalLayout = new QHBoxLayout(TrayHoverNoticeItem);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        header = new QLabel(TrayHoverNoticeItem);
        header->setObjectName(QStringLiteral("header"));

        horizontalLayout->addWidget(header);

        name = new QLabel(TrayHoverNoticeItem);
        name->setObjectName(QStringLiteral("name"));

        horizontalLayout->addWidget(name);

        horizontalSpacer = new QSpacerItem(178, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        count = new QLabel(TrayHoverNoticeItem);
        count->setObjectName(QStringLiteral("count"));
        count->setMaximumSize(QSize(16777215, 18));

        horizontalLayout->addWidget(count);


        retranslateUi(TrayHoverNoticeItem);

        QMetaObject::connectSlotsByName(TrayHoverNoticeItem);
    } // setupUi

    void retranslateUi(QWidget *TrayHoverNoticeItem)
    {
        TrayHoverNoticeItem->setWindowTitle(QApplication::translate("TrayHoverNoticeItem", "TrayHoverNoticeItem", 0));
        header->setText(QString());
        name->setText(QString());
        count->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class TrayHoverNoticeItem: public Ui_TrayHoverNoticeItem {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TRAYHOVERNOTICEITEM_H
