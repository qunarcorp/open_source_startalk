/********************************************************************************
** Form generated from reading UI file 'QRCodeWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QRCODEWIDGET_H
#define UI_QRCODEWIDGET_H

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

class Ui_QRCodeWidget
{
public:
    QHBoxLayout *horizontalLayout_2;
    QWidget *bk;
    QWidget *qrcodebk;
    QVBoxLayout *verticalLayout_2;
    QWidget *bt;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout;
    QWidget *bl;
    QWidget *center;
    QWidget *wtl;
    QWidget *wtr;
    QWidget *wbr;
    QWidget *wbl;
    QWidget *splitLine;
    QWidget *br;
    QWidget *bb;
    QPushButton *btnClose;

    void setupUi(QWidget *QRCodeWidget)
    {
        if (QRCodeWidget->objectName().isEmpty())
            QRCodeWidget->setObjectName(QStringLiteral("QRCodeWidget"));
        QRCodeWidget->resize(308, 304);
        QRCodeWidget->setStyleSheet(QLatin1String("QWidget#title,#bottom\n"
"{\n"
"	background:#FFFFFF;\n"
"	border:none;\n"
"}\n"
"\n"
"QWidget#qrcodebk\n"
"{\n"
"	border:2px solid #1ba9ba;\n"
"}\n"
"\n"
"QWidget#wtl\n"
"{\n"
"	border-left:2px solid #1ba9ba;\n"
"	border-top:2px solid #1ba9ba;\n"
"}\n"
"\n"
"QWidget#wtr\n"
"{\n"
"	border-right:2px solid #1ba9ba;\n"
"	border-top:2px solid #1ba9ba;\n"
"}\n"
"\n"
"QWidget#wbl\n"
"{\n"
"	border-left:2px solid #1ba9ba;\n"
"	border-bottom:2px solid #1ba9ba;\n"
"}\n"
"\n"
"QWidget#wbr\n"
"{\n"
"	border-right:2px solid #1ba9ba;\n"
"	border-bottom:2px solid #1ba9ba;\n"
"}\n"
"\n"
"QWidget#splitLine\n"
"{\n"
"	background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 #001ba9ba,stop:0.2 #1ba9ba, stop:0.8 #1ba9ba, stop:1 #001ba9ba);\n"
"}\n"
"\n"
"QWidget#bt,#bb,#bl,#br\n"
"{\n"
"	background-color:#60000000;\n"
"}\n"
"QWidget#center\n"
"{\n"
"	background-color:#01000000;\n"
"}\n"
"\n"
"QPushButton#btnClose{\n"
" border:none;\n"
"border-radius: 13px;\n"
"background:#A0000000;\n"
"image:url(:/Images/close"
                        "_hover.png);\n"
"}\n"
"QPushButton#btnClose:hover{\n"
"	background:#F25561;\n"
"}\n"
"QPushButton#btnClose:pressed{\n"
"	background:#E74450;\n"
"}"));
        horizontalLayout_2 = new QHBoxLayout(QRCodeWidget);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        bk = new QWidget(QRCodeWidget);
        bk->setObjectName(QStringLiteral("bk"));
        qrcodebk = new QWidget(bk);
        qrcodebk->setObjectName(QStringLiteral("qrcodebk"));
        qrcodebk->setGeometry(QRect(0, 0, 106, 96));
        qrcodebk->setCursor(QCursor(Qt::OpenHandCursor));
        verticalLayout_2 = new QVBoxLayout(qrcodebk);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        bt = new QWidget(qrcodebk);
        bt->setObjectName(QStringLiteral("bt"));
        bt->setMinimumSize(QSize(0, 48));
        bt->setMaximumSize(QSize(16777215, 48));

        verticalLayout_2->addWidget(bt);

        widget_2 = new QWidget(qrcodebk);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        horizontalLayout = new QHBoxLayout(widget_2);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        bl = new QWidget(widget_2);
        bl->setObjectName(QStringLiteral("bl"));
        bl->setMinimumSize(QSize(48, 0));
        bl->setMaximumSize(QSize(48, 16777215));

        horizontalLayout->addWidget(bl);

        center = new QWidget(widget_2);
        center->setObjectName(QStringLiteral("center"));
        wtl = new QWidget(center);
        wtl->setObjectName(QStringLiteral("wtl"));
        wtl->setGeometry(QRect(140, 140, 22, 22));
        wtl->setMinimumSize(QSize(22, 22));
        wtl->setMaximumSize(QSize(22, 22));
        wtr = new QWidget(center);
        wtr->setObjectName(QStringLiteral("wtr"));
        wtr->setGeometry(QRect(202, 140, 22, 22));
        wtr->setMinimumSize(QSize(22, 22));
        wtr->setMaximumSize(QSize(22, 22));
        wbr = new QWidget(center);
        wbr->setObjectName(QStringLiteral("wbr"));
        wbr->setGeometry(QRect(212, 150, 22, 22));
        wbr->setMinimumSize(QSize(22, 22));
        wbr->setMaximumSize(QSize(22, 22));
        wbl = new QWidget(center);
        wbl->setObjectName(QStringLiteral("wbl"));
        wbl->setGeometry(QRect(150, 150, 22, 22));
        wbl->setMinimumSize(QSize(22, 22));
        wbl->setMaximumSize(QSize(22, 22));
        splitLine = new QWidget(center);
        splitLine->setObjectName(QStringLiteral("splitLine"));
        splitLine->setGeometry(QRect(30, 40, 120, 4));
        splitLine->setMinimumSize(QSize(0, 4));
        splitLine->setMaximumSize(QSize(16777215, 4));

        horizontalLayout->addWidget(center);

        br = new QWidget(widget_2);
        br->setObjectName(QStringLiteral("br"));
        br->setMinimumSize(QSize(48, 0));
        br->setMaximumSize(QSize(48, 16777215));

        horizontalLayout->addWidget(br);


        verticalLayout_2->addWidget(widget_2);

        bb = new QWidget(qrcodebk);
        bb->setObjectName(QStringLiteral("bb"));
        bb->setMinimumSize(QSize(0, 48));
        bb->setMaximumSize(QSize(16777215, 48));

        verticalLayout_2->addWidget(bb);

        btnClose = new QPushButton(bk);
        btnClose->setObjectName(QStringLiteral("btnClose"));
        btnClose->setGeometry(QRect(70, 70, 27, 27));
        btnClose->setMinimumSize(QSize(27, 27));
        btnClose->setMaximumSize(QSize(27, 27));
        btnClose->setCursor(QCursor(Qt::ArrowCursor));

        horizontalLayout_2->addWidget(bk);


        retranslateUi(QRCodeWidget);

        QMetaObject::connectSlotsByName(QRCodeWidget);
    } // setupUi

    void retranslateUi(QWidget *QRCodeWidget)
    {
        QRCodeWidget->setWindowTitle(QApplication::translate("QRCodeWidget", "QRCodeWidget", 0));
        btnClose->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class QRCodeWidget: public Ui_QRCodeWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QRCODEWIDGET_H
