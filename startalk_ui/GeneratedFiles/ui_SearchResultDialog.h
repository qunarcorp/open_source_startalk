/********************************************************************************
** Form generated from reading UI file 'SearchResultDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SEARCHRESULTDIALOG_H
#define UI_SEARCHRESULTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SearchResultDialog
{
public:
    QVBoxLayout *verticalLayout;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QHBoxLayout *horizontalLayout_3;
    QWidget *widget;
    QVBoxLayout *verticalLayout_2;
    QWidget *widget_2;
    QVBoxLayout *verticalLayout_4;
    QWidget *widget_4;
    QHBoxLayout *horizontalLayout;
    QLabel *lianxiren_icon;
    QLabel *label_2;
    QSpacerItem *horizontalSpacer;
    QWidget *widget_6;
    QVBoxLayout *verticalLayout_6;
    QListWidget *lianxirenList;
    QWidget *qun_penal;
    QVBoxLayout *verticalLayout_3;
    QWidget *widget_5;
    QHBoxLayout *horizontalLayout_2;
    QLabel *qun_icon;
    QLabel *label_4;
    QSpacerItem *horizontalSpacer_2;
    QWidget *widget_3;
    QVBoxLayout *verticalLayout_5;
    QListWidget *qunList;
    QSpacerItem *verticalSpacer;
    QListWidget *listWidget;

    void setupUi(QDialog *SearchResultDialog)
    {
        if (SearchResultDialog->objectName().isEmpty())
            SearchResultDialog->setObjectName(QStringLiteral("SearchResultDialog"));
        SearchResultDialog->resize(597, 500);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(SearchResultDialog->sizePolicy().hasHeightForWidth());
        SearchResultDialog->setSizePolicy(sizePolicy);
        SearchResultDialog->setMaximumSize(QSize(16777215, 500));
        SearchResultDialog->setStyleSheet(QLatin1String("QDialog#SearchResultDialog{\n"
"	border: 1px solid #3A3A3A;\n"
"	background:#EEF0F0F0;\n"
"	border-radius: 0px;\n"
"}\n"
"\n"
"QWidget#scrollArea,#scrollAreaWidgetContents{\n"
"	border: none;\n"
"	background:#00000000;\n"
"}\n"
"\n"
"QListWidget{\n"
"border: none;\n"
"background:#00000000;\n"
"alternate-background-color: #EEF5F5F5;\n"
"}\n"
"\n"
"QListWidget#listWidget{\n"
"background:#00000000;\n"
"alternate-background-color: #EEF5F5F5;\n"
"}\n"
"\n"
"QListWidget::item:selected {\n"
"	border: 1px solid #3A3A3A;\n"
"	color:white;\n"
"	background:#888dd9;\n"
" }\n"
"QListWidget::item:hover {\n"
"	border: 1px solid #3A3A3A;\n"
"	color:white;\n"
"	background:#888dd9;\n"
" }\n"
"\n"
" QListWidget::item:selected:!active {\n"
"     background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                 stop: 0 #ABAFE5, stop: 1 #8588B2);\n"
" }\n"
" \n"
" QListWidget::item:selected:active {\n"
"     background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                 stop:"
                        " 0 #6a6ea9, stop: 1 #888dd9);\n"
" }\n"
"\n"
"\n"
"                  QLabel#lianxiren_icon{\n"
"                  border-image : url(:/Images/default_header.png);\n"
"                  }\n"
"                  QLabel#qun_icon{\n"
"                  border-image : url(:/Images/im_default_header.png);\n"
"                  }\n"
"                "));
        verticalLayout = new QVBoxLayout(SearchResultDialog);
        verticalLayout->setSpacing(0);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        scrollArea = new QScrollArea(SearchResultDialog);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setStyleSheet(QStringLiteral(""));
        scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 597, 308));
        scrollAreaWidgetContents->setStyleSheet(QStringLiteral(""));
        horizontalLayout_3 = new QHBoxLayout(scrollAreaWidgetContents);
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        widget = new QWidget(scrollAreaWidgetContents);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setStyleSheet(QStringLiteral(""));
        verticalLayout_2 = new QVBoxLayout(widget);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        widget_2 = new QWidget(widget);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        verticalLayout_4 = new QVBoxLayout(widget_2);
        verticalLayout_4->setSpacing(0);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        widget_4 = new QWidget(widget_2);
        widget_4->setObjectName(QStringLiteral("widget_4"));
        widget_4->setMaximumSize(QSize(16777215, 16777215));
        horizontalLayout = new QHBoxLayout(widget_4);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        lianxiren_icon = new QLabel(widget_4);
        lianxiren_icon->setObjectName(QStringLiteral("lianxiren_icon"));
        lianxiren_icon->setMinimumSize(QSize(26, 26));
        lianxiren_icon->setMaximumSize(QSize(26, 26));

        horizontalLayout->addWidget(lianxiren_icon);

        label_2 = new QLabel(widget_4);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout->addWidget(label_2);

        horizontalSpacer = new QSpacerItem(490, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout_4->addWidget(widget_4);

        widget_6 = new QWidget(widget_2);
        widget_6->setObjectName(QStringLiteral("widget_6"));
        verticalLayout_6 = new QVBoxLayout(widget_6);
        verticalLayout_6->setSpacing(0);
        verticalLayout_6->setContentsMargins(11, 11, 11, 11);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        verticalLayout_6->setContentsMargins(40, 0, 0, 0);
        lianxirenList = new QListWidget(widget_6);
        lianxirenList->setObjectName(QStringLiteral("lianxirenList"));
        lianxirenList->setMaximumSize(QSize(16777215, 16777215));
        lianxirenList->setStyleSheet(QStringLiteral(""));
        lianxirenList->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        lianxirenList->setAlternatingRowColors(true);

        verticalLayout_6->addWidget(lianxirenList);


        verticalLayout_4->addWidget(widget_6);


        verticalLayout_2->addWidget(widget_2);

        qun_penal = new QWidget(widget);
        qun_penal->setObjectName(QStringLiteral("qun_penal"));
        verticalLayout_3 = new QVBoxLayout(qun_penal);
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        widget_5 = new QWidget(qun_penal);
        widget_5->setObjectName(QStringLiteral("widget_5"));
        horizontalLayout_2 = new QHBoxLayout(widget_5);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        qun_icon = new QLabel(widget_5);
        qun_icon->setObjectName(QStringLiteral("qun_icon"));
        qun_icon->setMinimumSize(QSize(26, 26));
        qun_icon->setMaximumSize(QSize(26, 26));
        qun_icon->setStyleSheet(QStringLiteral(""));

        horizontalLayout_2->addWidget(qun_icon);

        label_4 = new QLabel(widget_5);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout_2->addWidget(label_4);

        horizontalSpacer_2 = new QSpacerItem(514, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);


        verticalLayout_3->addWidget(widget_5);

        widget_3 = new QWidget(qun_penal);
        widget_3->setObjectName(QStringLiteral("widget_3"));
        verticalLayout_5 = new QVBoxLayout(widget_3);
        verticalLayout_5->setSpacing(0);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(40, 0, 0, 0);
        qunList = new QListWidget(widget_3);
        qunList->setObjectName(QStringLiteral("qunList"));
        qunList->setStyleSheet(QStringLiteral(""));
        qunList->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        qunList->setAlternatingRowColors(true);

        verticalLayout_5->addWidget(qunList);


        verticalLayout_3->addWidget(widget_3);


        verticalLayout_2->addWidget(qun_penal);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);


        horizontalLayout_3->addWidget(widget);

        scrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout->addWidget(scrollArea);

        listWidget = new QListWidget(SearchResultDialog);
        listWidget->setObjectName(QStringLiteral("listWidget"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(listWidget->sizePolicy().hasHeightForWidth());
        listWidget->setSizePolicy(sizePolicy1);
        listWidget->setMinimumSize(QSize(0, 0));
        listWidget->setMaximumSize(QSize(16777215, 16777215));
        listWidget->setStyleSheet(QStringLiteral(""));
        listWidget->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        listWidget->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        listWidget->setAlternatingRowColors(true);

        verticalLayout->addWidget(listWidget);


        retranslateUi(SearchResultDialog);

        QMetaObject::connectSlotsByName(SearchResultDialog);
    } // setupUi

    void retranslateUi(QDialog *SearchResultDialog)
    {
        SearchResultDialog->setWindowTitle(QApplication::translate("SearchResultDialog", "SearchResultDialog", 0));
        lianxiren_icon->setText(QString());
        label_2->setText(QApplication::translate("SearchResultDialog", " \350\201\224\347\263\273\344\272\272", 0));
        qun_icon->setText(QString());
        label_4->setText(QApplication::translate("SearchResultDialog", " \347\276\244", 0));
    } // retranslateUi

};

namespace Ui {
    class SearchResultDialog: public Ui_SearchResultDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SEARCHRESULTDIALOG_H
