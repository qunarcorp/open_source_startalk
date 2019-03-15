/********************************************************************************
** Form generated from reading UI file 'AdvertInfoDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADVERTINFODIALOG_H
#define UI_ADVERTINFODIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "TitlebarWidget.h"

QT_BEGIN_NAMESPACE

class Ui_AdvertInfoDialog
{
public:
    QVBoxLayout *verticalLayout_2;
    QWidget *dialogbg;
    QVBoxLayout *verticalLayout_8;
    TitlebarWidget *titlebar;
    QScrollArea *scrollArea;
    QWidget *center;
    QVBoxLayout *verticalLayout_3;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QLineEdit *lineEdit_productId;
    QPushButton *pbSearch;
    QStackedWidget *stackedWidget;
    QWidget *contentPage;
    QVBoxLayout *verticalLayout_9;
    QWidget *widget_productInfo;
    QVBoxLayout *verticalLayout;
    QLabel *label_productInfo;
    QTextEdit *textEdit;
    QWidget *spliteup;
    QWidget *picbk;
    QLabel *productpic;
    QWidget *tagbk;
    QHBoxLayout *horizontalLayout_4;
    QLabel *producttype;
    QLabel *producttag;
    QWidget *widget_3;
    QVBoxLayout *verticalLayout_11;
    QLabel *label_title;
    QWidget *widget_4;
    QHBoxLayout *horizontalLayout_3;
    QWidget *widget_5;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_markprice_title;
    QLabel *label_qunarprice_title;
    QWidget *widget_6;
    QVBoxLayout *verticalLayout_5;
    QLabel *label_markprice;
    QLabel *label_qunarprice;
    QWidget *emptyPage;
    QVBoxLayout *verticalLayout_7;
    QLabel *label_emptyimg;
    QLabel *label_emptytext;
    QSpacerItem *verticalSpacer_2;
    QWidget *splitedown;
    QWidget *bottompannel;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *pbCancel;
    QPushButton *pbSend;

    void setupUi(QDialog *AdvertInfoDialog)
    {
        if (AdvertInfoDialog->objectName().isEmpty())
            AdvertInfoDialog->setObjectName(QStringLiteral("AdvertInfoDialog"));
        AdvertInfoDialog->resize(397, 479);
        AdvertInfoDialog->setStyleSheet(QString::fromUtf8("QWidget#dialogbg{\n"
"    border:1px solid #none;\n"
"    background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                 stop: 0 #edeeef, stop: 1.0 #d4d7da);\n"
"}\n"
"QScrollArea{\n"
"	border:none;\n"
"	background:#00000000;\n"
"}\n"
"QWidget#center,#stackedWidget,#contentPage,#emptyPage\n"
"{\n"
"	border:none;\n"
"	background:#00000000;\n"
"}\n"
"\n"
"\n"
"QWidget{\n"
"    font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"	color:#666666;\n"
"}\n"
"\n"
"QWidget#spliteup,#splitedown\n"
"{\n"
"	border:1px solid  #D3D3D3;\n"
"}\n"
"QPushButton#pbClose{\n"
"	border:none;\n"
"	height:27px;\n"
"	width:30px;\n"
"	max-width:30px;\n"
"	min-width:30px;\n"
"	 \n"
"	max-height:27px;\n"
"	min-height:27px;\n"
"\n"
"	background:#00000000;\n"
"	border-image: url(:/Images/close_normal.png); \n"
"}\n"
"QPushButton#pbClose:hover{\n"
"	background:#F25561;\n"
"	border-image: url(:/Images/close_hover.png);  \n"
"}\n"
"QPushButton#pbClose:pressed{\n"
"	background:#E74450;\n"
"	borde"
                        "r-image: url(:/Images/close_hover.png);  \n"
"}\n"
"\n"
"QPushButton#pbSearch,#pbSend{\n"
"	border:none;\n"
"	height:23px;\n"
"	width:35px;\n"
"	color:#FFFFFF;\n"
"    background-color:#3DCE3D;\n"
"}\n"
"QPushButton#pbSearch:hover,#pbSend:hover{\n"
"	background-color:#38C738;\n"
"}\n"
"QPushButtonpbSearch:pressed,#pbSend:pressed{\n"
"	background-color:#2FB82F;\n"
"}\n"
"\n"
"QPushButton#pbCancel{\n"
"    color:#666666;\n"
"    border:1px solid #E5E5E5;\n"
"}\n"
"QPushButton#pbCancel:hover{\n"
"    background-color:#f5f5f5;\n"
"}\n"
"QPushButton#pbCancel:pressed{\n"
"    background-color:#EBEBEB;\n"
"}\n"
"\n"
"QLabel#producttag,#producttype\n"
"{\n"
"	border:none;\n"
"	color:#FFFFFF;;\n"
"	font-weight:bold;\n"
"	font-size:20px;\n"
"	\n"
"}\n"
"\n"
"QWidget#tagbk{\n"
"	background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1\n"
"                     stop: 0 #00000000,\n"
"					 stop: 1.0 #D0333333); \n"
"}\n"
"\n"
""));
        verticalLayout_2 = new QVBoxLayout(AdvertInfoDialog);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        dialogbg = new QWidget(AdvertInfoDialog);
        dialogbg->setObjectName(QStringLiteral("dialogbg"));
        dialogbg->setStyleSheet(QStringLiteral(""));
        verticalLayout_8 = new QVBoxLayout(dialogbg);
        verticalLayout_8->setSpacing(0);
        verticalLayout_8->setObjectName(QStringLiteral("verticalLayout_8"));
        verticalLayout_8->setContentsMargins(0, 0, 0, 0);
        titlebar = new TitlebarWidget(dialogbg);
        titlebar->setObjectName(QStringLiteral("titlebar"));
        titlebar->setMinimumSize(QSize(0, 28));
        titlebar->setMaximumSize(QSize(16777215, 28));

        verticalLayout_8->addWidget(titlebar);

        scrollArea = new QScrollArea(dialogbg);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setStyleSheet(QStringLiteral(""));
        scrollArea->setWidgetResizable(true);
        center = new QWidget();
        center->setObjectName(QStringLiteral("center"));
        center->setGeometry(QRect(0, 0, 380, 602));
        center->setStyleSheet(QStringLiteral(""));
        verticalLayout_3 = new QVBoxLayout(center);
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        widget = new QWidget(center);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setMaximumSize(QSize(16777215, 50));
        horizontalLayout_2 = new QHBoxLayout(widget);
        horizontalLayout_2->setSpacing(5);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(10, 10, 10, 5);
        label = new QLabel(widget);
        label->setObjectName(QStringLiteral("label"));
        label->setMinimumSize(QSize(0, 28));

        horizontalLayout_2->addWidget(label);

        lineEdit_productId = new QLineEdit(widget);
        lineEdit_productId->setObjectName(QStringLiteral("lineEdit_productId"));
        lineEdit_productId->setMinimumSize(QSize(0, 28));

        horizontalLayout_2->addWidget(lineEdit_productId);

        pbSearch = new QPushButton(widget);
        pbSearch->setObjectName(QStringLiteral("pbSearch"));
        pbSearch->setMinimumSize(QSize(70, 28));
        pbSearch->setFlat(true);

        horizontalLayout_2->addWidget(pbSearch);


        verticalLayout_3->addWidget(widget);

        stackedWidget = new QStackedWidget(center);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        stackedWidget->setStyleSheet(QStringLiteral(""));
        contentPage = new QWidget();
        contentPage->setObjectName(QStringLiteral("contentPage"));
        verticalLayout_9 = new QVBoxLayout(contentPage);
        verticalLayout_9->setSpacing(0);
        verticalLayout_9->setObjectName(QStringLiteral("verticalLayout_9"));
        verticalLayout_9->setContentsMargins(0, 0, 0, 0);
        widget_productInfo = new QWidget(contentPage);
        widget_productInfo->setObjectName(QStringLiteral("widget_productInfo"));
        widget_productInfo->setMinimumSize(QSize(0, 111));
        widget_productInfo->setMaximumSize(QSize(16777215, 111));
        verticalLayout = new QVBoxLayout(widget_productInfo);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label_productInfo = new QLabel(widget_productInfo);
        label_productInfo->setObjectName(QStringLiteral("label_productInfo"));

        verticalLayout->addWidget(label_productInfo);

        textEdit = new QTextEdit(widget_productInfo);
        textEdit->setObjectName(QStringLiteral("textEdit"));

        verticalLayout->addWidget(textEdit);


        verticalLayout_9->addWidget(widget_productInfo);

        spliteup = new QWidget(contentPage);
        spliteup->setObjectName(QStringLiteral("spliteup"));
        spliteup->setMinimumSize(QSize(0, 1));
        spliteup->setMaximumSize(QSize(16777215, 1));

        verticalLayout_9->addWidget(spliteup);

        picbk = new QWidget(contentPage);
        picbk->setObjectName(QStringLiteral("picbk"));
        picbk->setMinimumSize(QSize(0, 252));
        picbk->setMaximumSize(QSize(16777215, 252));
        productpic = new QLabel(picbk);
        productpic->setObjectName(QStringLiteral("productpic"));
        productpic->setGeometry(QRect(0, 0, 16, 17));
        productpic->setStyleSheet(QStringLiteral(""));
        productpic->setScaledContents(true);
        tagbk = new QWidget(picbk);
        tagbk->setObjectName(QStringLiteral("tagbk"));
        tagbk->setGeometry(QRect(0, 201, 20, 51));
        tagbk->setMinimumSize(QSize(0, 51));
        tagbk->setMaximumSize(QSize(16777215, 51));
        tagbk->setStyleSheet(QStringLiteral(""));
        horizontalLayout_4 = new QHBoxLayout(tagbk);
        horizontalLayout_4->setSpacing(0);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(20, 0, 20, 0);
        producttype = new QLabel(tagbk);
        producttype->setObjectName(QStringLiteral("producttype"));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setBold(true);
        font.setWeight(75);
        producttype->setFont(font);
        producttype->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        producttype->setWordWrap(true);

        horizontalLayout_4->addWidget(producttype);

        producttag = new QLabel(tagbk);
        producttag->setObjectName(QStringLiteral("producttag"));
        producttag->setFont(font);
        producttag->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        producttag->setWordWrap(true);

        horizontalLayout_4->addWidget(producttag);


        verticalLayout_9->addWidget(picbk);

        widget_3 = new QWidget(contentPage);
        widget_3->setObjectName(QStringLiteral("widget_3"));
        verticalLayout_11 = new QVBoxLayout(widget_3);
        verticalLayout_11->setSpacing(0);
        verticalLayout_11->setObjectName(QStringLiteral("verticalLayout_11"));
        verticalLayout_11->setContentsMargins(0, 0, 0, 0);
        label_title = new QLabel(widget_3);
        label_title->setObjectName(QStringLiteral("label_title"));
        label_title->setMinimumSize(QSize(0, 100));
        label_title->setMaximumSize(QSize(16777215, 100));
        label_title->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        verticalLayout_11->addWidget(label_title);


        verticalLayout_9->addWidget(widget_3);

        widget_4 = new QWidget(contentPage);
        widget_4->setObjectName(QStringLiteral("widget_4"));
        widget_4->setMaximumSize(QSize(16777215, 16777215));
        horizontalLayout_3 = new QHBoxLayout(widget_4);
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(20, 10, 0, 10);
        widget_5 = new QWidget(widget_4);
        widget_5->setObjectName(QStringLiteral("widget_5"));
        widget_5->setMaximumSize(QSize(70, 16777215));
        verticalLayout_4 = new QVBoxLayout(widget_5);
        verticalLayout_4->setSpacing(0);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        label_markprice_title = new QLabel(widget_5);
        label_markprice_title->setObjectName(QStringLiteral("label_markprice_title"));
        label_markprice_title->setMinimumSize(QSize(0, 28));
        label_markprice_title->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        verticalLayout_4->addWidget(label_markprice_title);

        label_qunarprice_title = new QLabel(widget_5);
        label_qunarprice_title->setObjectName(QStringLiteral("label_qunarprice_title"));
        label_qunarprice_title->setMinimumSize(QSize(0, 28));
        label_qunarprice_title->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        verticalLayout_4->addWidget(label_qunarprice_title);


        horizontalLayout_3->addWidget(widget_5);

        widget_6 = new QWidget(widget_4);
        widget_6->setObjectName(QStringLiteral("widget_6"));
        verticalLayout_5 = new QVBoxLayout(widget_6);
        verticalLayout_5->setSpacing(0);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(15, 0, 0, 0);
        label_markprice = new QLabel(widget_6);
        label_markprice->setObjectName(QStringLiteral("label_markprice"));
        label_markprice->setWordWrap(false);

        verticalLayout_5->addWidget(label_markprice);

        label_qunarprice = new QLabel(widget_6);
        label_qunarprice->setObjectName(QStringLiteral("label_qunarprice"));

        verticalLayout_5->addWidget(label_qunarprice);


        horizontalLayout_3->addWidget(widget_6);


        verticalLayout_9->addWidget(widget_4);

        stackedWidget->addWidget(contentPage);
        emptyPage = new QWidget();
        emptyPage->setObjectName(QStringLiteral("emptyPage"));
        verticalLayout_7 = new QVBoxLayout(emptyPage);
        verticalLayout_7->setSpacing(20);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        verticalLayout_7->setContentsMargins(89, 50, 89, 0);
        label_emptyimg = new QLabel(emptyPage);
        label_emptyimg->setObjectName(QStringLiteral("label_emptyimg"));
        label_emptyimg->setMinimumSize(QSize(200, 200));
        label_emptyimg->setMaximumSize(QSize(200, 200));
        label_emptyimg->setPixmap(QPixmap(QString::fromUtf8(":/Images/no_session_selected_background.png")));
        label_emptyimg->setScaledContents(true);
        label_emptyimg->setAlignment(Qt::AlignCenter);

        verticalLayout_7->addWidget(label_emptyimg);

        label_emptytext = new QLabel(emptyPage);
        label_emptytext->setObjectName(QStringLiteral("label_emptytext"));
        label_emptytext->setAlignment(Qt::AlignHCenter|Qt::AlignTop);

        verticalLayout_7->addWidget(label_emptytext);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_7->addItem(verticalSpacer_2);

        stackedWidget->addWidget(emptyPage);

        verticalLayout_3->addWidget(stackedWidget);

        splitedown = new QWidget(center);
        splitedown->setObjectName(QStringLiteral("splitedown"));
        splitedown->setMinimumSize(QSize(0, 1));
        splitedown->setMaximumSize(QSize(16777215, 1));

        verticalLayout_3->addWidget(splitedown);

        scrollArea->setWidget(center);

        verticalLayout_8->addWidget(scrollArea);

        bottompannel = new QWidget(dialogbg);
        bottompannel->setObjectName(QStringLiteral("bottompannel"));
        bottompannel->setMaximumSize(QSize(16777215, 50));
        horizontalLayout = new QHBoxLayout(bottompannel);
        horizontalLayout->setSpacing(20);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 10, 20, 10);
        horizontalSpacer = new QSpacerItem(175, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pbCancel = new QPushButton(bottompannel);
        pbCancel->setObjectName(QStringLiteral("pbCancel"));
        pbCancel->setMinimumSize(QSize(70, 28));
        pbCancel->setMaximumSize(QSize(70, 28));
        pbCancel->setFlat(true);

        horizontalLayout->addWidget(pbCancel);

        pbSend = new QPushButton(bottompannel);
        pbSend->setObjectName(QStringLiteral("pbSend"));
        pbSend->setMinimumSize(QSize(70, 28));
        pbSend->setMaximumSize(QSize(70, 28));
        pbSend->setFlat(true);

        horizontalLayout->addWidget(pbSend);


        verticalLayout_8->addWidget(bottompannel);


        verticalLayout_2->addWidget(dialogbg);


        retranslateUi(AdvertInfoDialog);

        QMetaObject::connectSlotsByName(AdvertInfoDialog);
    } // setupUi

    void retranslateUi(QDialog *AdvertInfoDialog)
    {
        AdvertInfoDialog->setWindowTitle(QApplication::translate("AdvertInfoDialog", "Dialog", 0));
        label->setText(QApplication::translate("AdvertInfoDialog", "\350\257\267\350\276\223\345\205\245\344\272\247\345\223\201ID", 0));
        pbSearch->setText(QApplication::translate("AdvertInfoDialog", "\346\237\245\350\257\242", 0));
        label_productInfo->setText(QApplication::translate("AdvertInfoDialog", "\350\257\267\350\276\223\345\205\245\344\272\247\345\223\201\344\277\241\346\201\257\344\273\213\347\273\215:", 0));
        productpic->setText(QString());
        producttype->setText(QString());
        producttag->setText(QString());
        label_title->setText(QString());
        label_markprice_title->setText(QString());
        label_qunarprice_title->setText(QString());
        label_markprice->setText(QString());
        label_qunarprice->setText(QString());
        label_emptytext->setText(QApplication::translate("AdvertInfoDialog", "\346\220\234\347\264\242\344\270\200\344\270\252\344\272\247\345\223\201\345\220\247~", 0));
        pbCancel->setText(QApplication::translate("AdvertInfoDialog", "\345\217\226\346\266\210", 0));
        pbSend->setText(QApplication::translate("AdvertInfoDialog", "\345\217\221\351\200\201", 0));
    } // retranslateUi

};

namespace Ui {
    class AdvertInfoDialog: public Ui_AdvertInfoDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADVERTINFODIALOG_H
