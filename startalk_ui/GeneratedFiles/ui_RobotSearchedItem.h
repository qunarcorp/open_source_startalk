/********************************************************************************
** Form generated from reading UI file 'RobotSearchedItem.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ROBOTSEARCHEDITEM_H
#define UI_ROBOTSEARCHEDITEM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RobotSearchedItem
{
public:
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QLabel *robotimage;
    QLabel *robottitle;
    QWidget *rbtoperation;
    QHBoxLayout *rbtBtnsGroup;

    void setupUi(QWidget *RobotSearchedItem)
    {
        if (RobotSearchedItem->objectName().isEmpty())
            RobotSearchedItem->setObjectName(QStringLiteral("RobotSearchedItem"));
        RobotSearchedItem->resize(513, 36);
        RobotSearchedItem->setMinimumSize(QSize(0, 36));
        RobotSearchedItem->setMaximumSize(QSize(16777215, 36));
        RobotSearchedItem->setStyleSheet(QString::fromUtf8("\n"
"QWidget{\n"
"font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"}\n"
"\n"
"QLabel{\n"
"color:#666666;\n"
"\n"
"}\n"
"\n"
"QPushButton{\n"
"color:#666666;\n"
"background:#F3E6B0;\n"
"border:none;\n"
"}\n"
"\n"
"QPushButton:hover{\n"
"background:#F6E1A3;\n"
"}\n"
"QPushButton:disabled{\n"
"background:#999999;\n"
"color:#FFFFFF;\n"
"}\n"
"QWidget#widget_2{\n"
"border:none;\n"
"background:#F6E1A3;\n"
"}\n"
"\n"
""));
        widget = new QWidget(RobotSearchedItem);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(0, 0, 598, 36));
        widget->setMinimumSize(QSize(0, 36));
        widget->setMaximumSize(QSize(16777215, 36));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setSpacing(10);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(10, 2, 0, 2);
        robotimage = new QLabel(widget);
        robotimage->setObjectName(QStringLiteral("robotimage"));
        robotimage->setMinimumSize(QSize(32, 32));
        robotimage->setMaximumSize(QSize(32, 32));

        horizontalLayout->addWidget(robotimage);

        robottitle = new QLabel(widget);
        robottitle->setObjectName(QStringLiteral("robottitle"));
        robottitle->setScaledContents(true);
        robottitle->setWordWrap(true);

        horizontalLayout->addWidget(robottitle);

        rbtoperation = new QWidget(RobotSearchedItem);
        rbtoperation->setObjectName(QStringLiteral("rbtoperation"));
        rbtoperation->setGeometry(QRect(255, 0, 71, 41));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(rbtoperation->sizePolicy().hasHeightForWidth());
        rbtoperation->setSizePolicy(sizePolicy);
        rbtBtnsGroup = new QHBoxLayout(rbtoperation);
        rbtBtnsGroup->setSpacing(0);
        rbtBtnsGroup->setContentsMargins(11, 11, 11, 11);
        rbtBtnsGroup->setObjectName(QStringLiteral("rbtBtnsGroup"));
        rbtBtnsGroup->setContentsMargins(0, 0, 0, 0);

        retranslateUi(RobotSearchedItem);

        QMetaObject::connectSlotsByName(RobotSearchedItem);
    } // setupUi

    void retranslateUi(QWidget *RobotSearchedItem)
    {
        RobotSearchedItem->setWindowTitle(QApplication::translate("RobotSearchedItem", "RobotSearchedItem", 0));
        robotimage->setText(QString());
        robottitle->setText(QApplication::translate("RobotSearchedItem", "\346\234\272\345\231\250\347\203\25511111111111", 0));
    } // retranslateUi

};

namespace Ui {
    class RobotSearchedItem: public Ui_RobotSearchedItem {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ROBOTSEARCHEDITEM_H
