/********************************************************************************
** Form generated from reading UI file 'imageviewer.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_IMAGEVIEWER_H
#define UI_IMAGEVIEWER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "webview.h"

QT_BEGIN_NAMESPACE

class Ui_ImageViewer
{
public:
    QHBoxLayout *horizontalLayout_3;
    QWidget *bk2;
    QWidget *bk;
    webview *webRemoteUrl;
    QLabel *ratetext;
    QWidget *miniview;
    QLabel *miniimg;
    QWidget *rectBorder;
    QVBoxLayout *verticalLayout_2;
    QLabel *visiablerect;
    QWidget *boolbar;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *normalsize;
    QPushButton *openfolder;
    QPushButton *saveas;
    QPushButton *turnright;
    QPushButton *bigger;
    QPushButton *smaller;
    QPushButton *pre;
    QPushButton *next;
    QPushButton *btnClose;
    QLabel *lbScledPixmap;

    void setupUi(QWidget *ImageViewer)
    {
        if (ImageViewer->objectName().isEmpty())
            ImageViewer->setObjectName(QStringLiteral("ImageViewer"));
        ImageViewer->resize(491, 322);
        ImageViewer->setStyleSheet(QLatin1String("QWidget{background:#00000000;}\n"
"QWidget#bk2{background:#A0000000;}\n"
"QWidget#bk{border:1pxsolid#999999;}\n"
"\n"
"QWidget#miniview{background:#80333333;}\n"
"QWidget#rectBorder{border:1pxsolid#FFFFFF;}\n"
"\n"
"QPushButton#btnClose{border:none;border-radius:13px;background:#A0000000;image:url(:/Images/close_hover.png);}\n"
"QPushButton#btnClose:hover{background:#F25561;border-image:url(:/Images/close_hover.png);}\n"
"QPushButton#btnClose:pressed{background:#E74450;border-image:url(:/Images/close_hover.png);}\n"
"\n"
"QLabel#ratetext{font-size:15px;border:1pxsolid#d7d8d9;border-radius:4px;background-color:rgb(255,255,255);}\n"
"\n"
"QLabel#visiablerect{border:1pxsolid#000000;}\n"
"\n"
"QPushButton#pre{border-image:url();}\n"
"QPushButton#pre:hover{border-image:url(:/Images/pre_n.png);}\n"
"QPushButton#pre:pressed{border-image:url(:/Images/pre_n.png);}\n"
"\n"
"QPushButton#next{border-image:url();}\n"
"QPushButton#next:hover{border-image:url(:/Images/next_n.png);}\n"
"QPushButton#next:pressed{border-image:u"
                        "rl(:/Images/next_n.png);}\n"
"\n"
"QWidget#boolbar{background:#80333333;border-top-right-radius:4px;border-top-left-radius:4px;}\n"
"\n"
"QPushButton#normalsize{border:none;image:url(:/Images/icon/imagebar/normalsize_normal.png);}\n"
"QPushButton#normalsize:hover ,QPushButton#normalsize:pressed {image:url(:/Images/icon/imagebar/normalsize_hover.png);}\n"
"\n"
"\n"
"QPushButton#openfolder{border:none;image:url(:/Images/icon/imagebar/folder_normal.png);}\n"
"QPushButton#openfolder:hover ,QPushButton#openfolder:pressed {image:url(:/Images/icon/imagebar/folder_hover.png);}\n"
"\n"
"QPushButton#bigger{border:none;image:url(:/Images/icon/imagebar/bigger_normal.png);}\n"
"QPushButton#bigger:hover ,QPushButton#bigger:pressed {image:url(:/Images/icon/imagebar/bigger_hover.png);}\n"
"\n"
"QPushButton#smaller{border:none;image:url(:/Images/icon/imagebar/smaller_normal.png);}\n"
"QPushButton#smaller:hover ,QPushButton#smaller:pressed {image:url(:/Images/icon/imagebar/smaller_hover.png);}\n"
"\n"
"QPushButton#saveas{border"
                        ":none;image:url(:/Images/icon/imagebar/saveas_normal.png);}\n"
"QPushButton#saveas:hover ,QPushButton#saveas:pressed {image:url(:/Images/icon/imagebar/saveas_hover.png);}\n"
"\n"
"QPushButton#turnright{border:none;image:url(:/Images/icon/imagebar/turnright_normal.png);}\n"
"QPushButton#turnright:hover ,QPushButton#turnright:pressed {image:url(:/Images/icon/imagebar/turnright_hover.png);}\n"
"\n"
"\n"
""));
        horizontalLayout_3 = new QHBoxLayout(ImageViewer);
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        bk2 = new QWidget(ImageViewer);
        bk2->setObjectName(QStringLiteral("bk2"));
        bk = new QWidget(bk2);
        bk->setObjectName(QStringLiteral("bk"));
        bk->setGeometry(QRect(9, 9, 430, 350));
        bk->setStyleSheet(QStringLiteral(""));
        webRemoteUrl = new webview(bk);
        webRemoteUrl->setObjectName(QStringLiteral("webRemoteUrl"));
        webRemoteUrl->setGeometry(QRect(130, 120, 300, 200));
        webRemoteUrl->setStyleSheet(QStringLiteral(""));
        ratetext = new QLabel(bk);
        ratetext->setObjectName(QStringLiteral("ratetext"));
        ratetext->setGeometry(QRect(40, 40, 54, 32));
        ratetext->setAlignment(Qt::AlignCenter);
        miniview = new QWidget(bk);
        miniview->setObjectName(QStringLiteral("miniview"));
        miniview->setGeometry(QRect(50, 50, 150, 150));
        miniview->setMinimumSize(QSize(150, 150));
        miniview->setMaximumSize(QSize(150, 150));
        miniimg = new QLabel(miniview);
        miniimg->setObjectName(QStringLiteral("miniimg"));
        miniimg->setGeometry(QRect(0, 0, 54, 12));
        rectBorder = new QWidget(miniview);
        rectBorder->setObjectName(QStringLiteral("rectBorder"));
        rectBorder->setGeometry(QRect(0, 0, 24, 32));
        verticalLayout_2 = new QVBoxLayout(rectBorder);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(1, 1, 1, 1);
        visiablerect = new QLabel(rectBorder);
        visiablerect->setObjectName(QStringLiteral("visiablerect"));

        verticalLayout_2->addWidget(visiablerect);

        boolbar = new QWidget(bk);
        boolbar->setObjectName(QStringLiteral("boolbar"));
        boolbar->setGeometry(QRect(60, 50, 201, 41));
        boolbar->setStyleSheet(QStringLiteral(""));
        horizontalLayout_2 = new QHBoxLayout(boolbar);
        horizontalLayout_2->setSpacing(1);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(9, 0, -1, 0);
        normalsize = new QPushButton(boolbar);
        normalsize->setObjectName(QStringLiteral("normalsize"));
        normalsize->setMinimumSize(QSize(32, 32));
        normalsize->setMaximumSize(QSize(32, 32));
        normalsize->setFocusPolicy(Qt::NoFocus);
        normalsize->setIconSize(QSize(32, 32));
        normalsize->setFlat(true);

        horizontalLayout_2->addWidget(normalsize);

        openfolder = new QPushButton(boolbar);
        openfolder->setObjectName(QStringLiteral("openfolder"));
        openfolder->setMinimumSize(QSize(32, 32));
        openfolder->setMaximumSize(QSize(32, 32));
        openfolder->setFocusPolicy(Qt::NoFocus);
        openfolder->setIconSize(QSize(32, 32));
        openfolder->setFlat(true);

        horizontalLayout_2->addWidget(openfolder);

        saveas = new QPushButton(boolbar);
        saveas->setObjectName(QStringLiteral("saveas"));
        saveas->setMinimumSize(QSize(32, 32));
        saveas->setMaximumSize(QSize(32, 32));
        saveas->setFocusPolicy(Qt::NoFocus);
        saveas->setFlat(true);

        horizontalLayout_2->addWidget(saveas);

        turnright = new QPushButton(boolbar);
        turnright->setObjectName(QStringLiteral("turnright"));
        turnright->setMinimumSize(QSize(32, 32));
        turnright->setMaximumSize(QSize(32, 32));
        turnright->setIconSize(QSize(32, 32));
        turnright->setFlat(true);

        horizontalLayout_2->addWidget(turnright);

        bigger = new QPushButton(boolbar);
        bigger->setObjectName(QStringLiteral("bigger"));
        bigger->setMinimumSize(QSize(32, 32));
        bigger->setMaximumSize(QSize(32, 32));
        bigger->setFocusPolicy(Qt::NoFocus);
        bigger->setStyleSheet(QStringLiteral(""));
        bigger->setIconSize(QSize(32, 32));
        bigger->setFlat(true);

        horizontalLayout_2->addWidget(bigger);

        smaller = new QPushButton(boolbar);
        smaller->setObjectName(QStringLiteral("smaller"));
        smaller->setMinimumSize(QSize(32, 32));
        smaller->setMaximumSize(QSize(32, 32));
        smaller->setFocusPolicy(Qt::NoFocus);
        smaller->setIconSize(QSize(32, 32));
        smaller->setFlat(true);

        horizontalLayout_2->addWidget(smaller);

        pre = new QPushButton(bk);
        pre->setObjectName(QStringLiteral("pre"));
        pre->setGeometry(QRect(0, 0, 50, 50));
        pre->setMinimumSize(QSize(50, 50));
        pre->setMaximumSize(QSize(50, 50));
        pre->setFocusPolicy(Qt::NoFocus);
        pre->setFlat(true);
        next = new QPushButton(bk);
        next->setObjectName(QStringLiteral("next"));
        next->setGeometry(QRect(230, 300, 50, 50));
        next->setMinimumSize(QSize(50, 0));
        next->setMaximumSize(QSize(50, 16777215));
        next->setFocusPolicy(Qt::NoFocus);
        next->setFlat(true);
        btnClose = new QPushButton(bk);
        btnClose->setObjectName(QStringLiteral("btnClose"));
        btnClose->setGeometry(QRect(300, 300, 27, 27));
        btnClose->setMinimumSize(QSize(27, 27));
        btnClose->setMaximumSize(QSize(27, 27));
        btnClose->setFocusPolicy(Qt::NoFocus);
        btnClose->setStyleSheet(QStringLiteral(""));
        btnClose->setIconSize(QSize(27, 27));
        btnClose->setFlat(true);
        lbScledPixmap = new QLabel(bk2);
        lbScledPixmap->setObjectName(QStringLiteral("lbScledPixmap"));
        lbScledPixmap->setGeometry(QRect(310, 310, 16, 16));
        lbScledPixmap->raise();
        bk->raise();

        horizontalLayout_3->addWidget(bk2);


        retranslateUi(ImageViewer);

        QMetaObject::connectSlotsByName(ImageViewer);
    } // setupUi

    void retranslateUi(QWidget *ImageViewer)
    {
        ImageViewer->setWindowTitle(QApplication::translate("ImageViewer", "ImageViewer", 0));
        ratetext->setText(QString());
        miniimg->setText(QString());
        visiablerect->setText(QString());
#ifndef QT_NO_TOOLTIP
        normalsize->setToolTip(QApplication::translate("ImageViewer", "\346\255\243\345\270\270\345\244\247\345\260\217", 0));
#endif // QT_NO_TOOLTIP
        normalsize->setText(QString());
#ifndef QT_NO_TOOLTIP
        openfolder->setToolTip(QApplication::translate("ImageViewer", "\346\211\223\345\274\200\346\211\200\345\234\250\346\226\207\344\273\266\345\244\271", 0));
#endif // QT_NO_TOOLTIP
        openfolder->setText(QString());
#ifndef QT_NO_TOOLTIP
        saveas->setToolTip(QApplication::translate("ImageViewer", "\345\217\246\345\255\230\344\270\272", 0));
#endif // QT_NO_TOOLTIP
        saveas->setText(QString());
#ifndef QT_NO_TOOLTIP
        turnright->setToolTip(QApplication::translate("ImageViewer", "\345\220\221\345\217\263\347\277\273\350\275\25490\302\260", 0));
#endif // QT_NO_TOOLTIP
        turnright->setText(QString());
#ifndef QT_NO_TOOLTIP
        bigger->setToolTip(QApplication::translate("ImageViewer", "\346\224\276\345\244\247", 0));
#endif // QT_NO_TOOLTIP
        bigger->setText(QString());
#ifndef QT_NO_TOOLTIP
        smaller->setToolTip(QApplication::translate("ImageViewer", "\347\274\251\345\260\217", 0));
#endif // QT_NO_TOOLTIP
        smaller->setText(QString());
        pre->setText(QString());
        next->setText(QString());
        btnClose->setText(QString());
        lbScledPixmap->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class ImageViewer: public Ui_ImageViewer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IMAGEVIEWER_H
