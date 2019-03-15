/********************************************************************************
** Form generated from reading UI file 'trayiconhovernoticewidget.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TRAYICONHOVERNOTICEWIDGET_H
#define UI_TRAYICONHOVERNOTICEWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TrayIconHoverNoticeWidget
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *title;
    QListWidget *listWidget;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *ignore;

    void setupUi(QWidget *TrayIconHoverNoticeWidget)
    {
        if (TrayIconHoverNoticeWidget->objectName().isEmpty())
            TrayIconHoverNoticeWidget->setObjectName(QStringLiteral("TrayIconHoverNoticeWidget"));
        TrayIconHoverNoticeWidget->resize(285, 523);
        TrayIconHoverNoticeWidget->setStyleSheet(QString::fromUtf8("QWidget{\n"
"	font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"}\n"
"\n"
"QWidget#TrayIconHoverNoticeWidget\n"
"{\n"
"	width:200px;\n"
"	min-width:200px;\n"
"	background:#EEF0F0F0;\n"
"	border:1px solid #3A3A3A;\n"
"}\n"
"\n"
"QListWidget\n"
"{\n"
"	border:none;\n"
"	background:#00000000;\n"
"}\n"
"QListWidget:item\n"
"{\n"
"	border:none;\n"
"	background:#00000000;\n"
"}\n"
"\n"
"QListView {\n"
"    show-decoration-selected: 1; \n"
"    outline:0px;\n"
"}\n"
"QListView::item:selected {\n"
"    border: none;\n"
"    background: #FFE090;\n"
"}\n"
"\n"
"QListView::item:hover {\n"
"    background: #FFE090;\n"
"}\n"
"\n"
"QLabel#title\n"
"{\n"
"	min-height:34px;\n"
"	height:34px;\n"
"	font-size:12px;\n"
"	font:bold;\n"
"	padding-left:10px;\n"
"}\n"
"\n"
"QPushButton\n"
"{\n"
"	min-height:34px;\n"
"	height:34px;\n"
"	font-size:12px;\n"
"	border:none;\n"
"	background:#00000000;\n"
"	padding:0px 3px;\n"
"	color:#3DCE3D;\n"
"	font:bold;\n"
"}\n"
"\n"
"QPushButton:hover\n"
"{\n"
"	color:#38C738;\n"
""
                        "}\n"
"\n"
"QPushButton:pressed\n"
"{\n"
"	color:#2FB82F;\n"
"}"));
        verticalLayout = new QVBoxLayout(TrayIconHoverNoticeWidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        title = new QLabel(TrayIconHoverNoticeWidget);
        title->setObjectName(QStringLiteral("title"));

        verticalLayout->addWidget(title);

        listWidget = new QListWidget(TrayIconHoverNoticeWidget);
        listWidget->setObjectName(QStringLiteral("listWidget"));
        listWidget->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        listWidget->setAlternatingRowColors(false);
        listWidget->setVerticalScrollMode(QAbstractItemView::ScrollPerPixel);

        verticalLayout->addWidget(listWidget);

        widget = new QWidget(TrayIconHoverNoticeWidget);
        widget->setObjectName(QStringLiteral("widget"));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(10, 0, 10, 0);
        horizontalSpacer = new QSpacerItem(125, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        ignore = new QPushButton(widget);
        ignore->setObjectName(QStringLiteral("ignore"));

        horizontalLayout->addWidget(ignore);


        verticalLayout->addWidget(widget);


        retranslateUi(TrayIconHoverNoticeWidget);

        QMetaObject::connectSlotsByName(TrayIconHoverNoticeWidget);
    } // setupUi

    void retranslateUi(QWidget *TrayIconHoverNoticeWidget)
    {
        TrayIconHoverNoticeWidget->setWindowTitle(QApplication::translate("TrayIconHoverNoticeWidget", "TrayIconHoverNoticeWidget", 0));
        title->setText(QApplication::translate("TrayIconHoverNoticeWidget", "\346\226\260\346\266\210\346\201\257\357\274\2101\357\274\211", 0));
        ignore->setText(QApplication::translate("TrayIconHoverNoticeWidget", "\345\277\275\347\225\245\345\205\250\351\203\250", 0));
    } // retranslateUi

};

namespace Ui {
    class TrayIconHoverNoticeWidget: public Ui_TrayIconHoverNoticeWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TRAYICONHOVERNOTICEWIDGET_H
