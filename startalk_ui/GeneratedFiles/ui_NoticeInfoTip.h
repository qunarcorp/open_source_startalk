/********************************************************************************
** Form generated from reading UI file 'NoticeInfoTip.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NOTICEINFOTIP_H
#define UI_NOTICEINFOTIP_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_NoticeInfoTip
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *base;
    QHBoxLayout *horizontalLayout_base;
    QWidget *widget;
    QVBoxLayout *verticalLayout_2;
    QScrollArea *scrollArea;
    QWidget *groupbtn;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton;

    void setupUi(QWidget *NoticeInfoTip)
    {
        if (NoticeInfoTip->objectName().isEmpty())
            NoticeInfoTip->setObjectName(QStringLiteral("NoticeInfoTip"));
        NoticeInfoTip->resize(386, 40);
        NoticeInfoTip->setMinimumSize(QSize(0, 40));
        NoticeInfoTip->setMaximumSize(QSize(16777215, 40));
        NoticeInfoTip->setStyleSheet(QLatin1String("\n"
"QWidget#base \n"
"{\n"
"	border:none;\n"
"	background-color:#f8fbdf;\n"
"\n"
"}\n"
"QWidget#widget\n"
"{\n"
"	border:none;\n"
"	background-color:#f8fbdf;\n"
"}\n"
"QPushButton#pushButton\n"
"{\n"
"	border:none;\n"
"    image : url(:Images/icon_close.png);\n"
"}\n"
"QPushButton#pushButton:hover\n"
"{\n"
"	image : url(:Images/icon_close_hover.png);\n"
"}\n"
"\n"
"QScrollArea#scrollArea\n"
"{\n"
"	border:none;\n"
"	background-color:transparent;\n"
"}\n"
"QWidget#groupbtn\n"
"{\n"
"	border:none;\n"
"	background-color:#f8fbdf;\n"
"}"));
        verticalLayout = new QVBoxLayout(NoticeInfoTip);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        base = new QWidget(NoticeInfoTip);
        base->setObjectName(QStringLiteral("base"));
        base->setMinimumSize(QSize(0, 40));
        base->setMaximumSize(QSize(16777215, 40));
        base->setStyleSheet(QStringLiteral("padding:5px;"));
        horizontalLayout_base = new QHBoxLayout(base);
        horizontalLayout_base->setSpacing(0);
        horizontalLayout_base->setObjectName(QStringLiteral("horizontalLayout_base"));
        horizontalLayout_base->setContentsMargins(0, 0, 0, 0);
        widget = new QWidget(base);
        widget->setObjectName(QStringLiteral("widget"));
        verticalLayout_2 = new QVBoxLayout(widget);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        scrollArea = new QScrollArea(widget);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        scrollArea->setWidgetResizable(true);
        groupbtn = new QWidget();
        groupbtn->setObjectName(QStringLiteral("groupbtn"));
        groupbtn->setGeometry(QRect(0, 0, 356, 30));
        groupbtn->setMinimumSize(QSize(0, 30));
        groupbtn->setMaximumSize(QSize(16777215, 30));
        horizontalLayout = new QHBoxLayout(groupbtn);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        scrollArea->setWidget(groupbtn);

        verticalLayout_2->addWidget(scrollArea);


        horizontalLayout_base->addWidget(widget);

        pushButton = new QPushButton(base);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setMinimumSize(QSize(20, 20));
        pushButton->setMaximumSize(QSize(20, 20));
        pushButton->setFlat(true);

        horizontalLayout_base->addWidget(pushButton);


        verticalLayout->addWidget(base);


        retranslateUi(NoticeInfoTip);

        QMetaObject::connectSlotsByName(NoticeInfoTip);
    } // setupUi

    void retranslateUi(QWidget *NoticeInfoTip)
    {
        NoticeInfoTip->setWindowTitle(QApplication::translate("NoticeInfoTip", "Form", 0));
        pushButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class NoticeInfoTip: public Ui_NoticeInfoTip {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NOTICEINFOTIP_H
