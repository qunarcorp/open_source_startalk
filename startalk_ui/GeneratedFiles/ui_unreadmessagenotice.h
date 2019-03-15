/********************************************************************************
** Form generated from reading UI file 'unreadmessagenotice.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_UNREADMESSAGENOTICE_H
#define UI_UNREADMESSAGENOTICE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_UnreadMessageNotice
{
public:
    QHBoxLayout *horizontalLayout;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_2;
    QLabel *icon;
    QPushButton *btn_text;
    QWidget *split;
    QPushButton *btn_close;

    void setupUi(QWidget *UnreadMessageNotice)
    {
        if (UnreadMessageNotice->objectName().isEmpty())
            UnreadMessageNotice->setObjectName(QStringLiteral("UnreadMessageNotice"));
        UnreadMessageNotice->resize(175, 28);
        UnreadMessageNotice->setMinimumSize(QSize(53, 28));
        UnreadMessageNotice->setMaximumSize(QSize(16777215, 28));
        UnreadMessageNotice->setStyleSheet(QLatin1String("QWidget#widget{border:none;border-radius:3px;background:#EFEFEF;}\n"
"QWidget#split{background-color: qlineargradient(spread:pad, x1:0, y1:1, x2:0, y2:0, stop:0 #00000000,stop:0.3 #1BA9BA, stop:0.7 #1BA9BA,stop:1 #00000000);}\n"
"\n"
"QPushButton#btn_close{border:none;image: url(:/Images/close_mini_normal.png);}\n"
"QPushButton#btn_close:hover,\n"
"QPushButton#btn_close:pressed{border:none;image: url(:/Images/close_mini_hover.png);}\n"
"\n"
"\n"
"QPushButton#btn_text{border:none;color:#1ba9ba;}\n"
"QPushButton#btn_text:hover,QPushButton#btn_text:pressed{color:#3dbbca;}\n"
"\n"
"QWidget#btn_text,QWidget#icon,QWidget#btn_close\n"
"{\n"
"	font-size:12px;\n"
"}"));
        horizontalLayout = new QHBoxLayout(UnreadMessageNotice);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        widget = new QWidget(UnreadMessageNotice);
        widget->setObjectName(QStringLiteral("widget"));
        horizontalLayout_2 = new QHBoxLayout(widget);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        icon = new QLabel(widget);
        icon->setObjectName(QStringLiteral("icon"));
        icon->setMinimumSize(QSize(28, 28));
        icon->setMaximumSize(QSize(28, 28));
        icon->setPixmap(QPixmap(QString::fromUtf8(":/Images/icon/pointdown.png")));

        horizontalLayout_2->addWidget(icon);

        btn_text = new QPushButton(widget);
        btn_text->setObjectName(QStringLiteral("btn_text"));
        btn_text->setMinimumSize(QSize(0, 28));
        btn_text->setMaximumSize(QSize(16777215, 28));
        btn_text->setIconSize(QSize(16, 16));
        btn_text->setFlat(true);

        horizontalLayout_2->addWidget(btn_text);

        split = new QWidget(widget);
        split->setObjectName(QStringLiteral("split"));
        split->setMaximumSize(QSize(1, 16777215));

        horizontalLayout_2->addWidget(split);

        btn_close = new QPushButton(widget);
        btn_close->setObjectName(QStringLiteral("btn_close"));
        btn_close->setMinimumSize(QSize(28, 28));
        btn_close->setMaximumSize(QSize(28, 28));
        btn_close->setFlat(true);

        horizontalLayout_2->addWidget(btn_close);


        horizontalLayout->addWidget(widget);


        retranslateUi(UnreadMessageNotice);

        QMetaObject::connectSlotsByName(UnreadMessageNotice);
    } // setupUi

    void retranslateUi(QWidget *UnreadMessageNotice)
    {
        UnreadMessageNotice->setWindowTitle(QApplication::translate("UnreadMessageNotice", "UnreadMessageNotice", 0));
        icon->setText(QString());
        btn_text->setText(QApplication::translate("UnreadMessageNotice", "\346\237\245\347\234\213\351\246\226\346\235\241\346\234\252\350\257\273", 0));
        btn_text->setShortcut(QApplication::translate("UnreadMessageNotice", "Ctrl+S", 0));
        btn_close->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class UnreadMessageNotice: public Ui_UnreadMessageNotice {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_UNREADMESSAGENOTICE_H
