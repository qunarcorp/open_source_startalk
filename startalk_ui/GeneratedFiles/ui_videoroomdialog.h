/********************************************************************************
** Form generated from reading UI file 'videoroomdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VIDEOROOMDIALOG_H
#define UI_VIDEOROOMDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "TitlebarWidget.h"

QT_BEGIN_NAMESPACE

class Ui_VideoRoomDialog
{
public:
    QVBoxLayout *verticalLayout_2;
    QWidget *shadowbg;
    QVBoxLayout *verticalLayout;
    QWidget *shadowinnerbg;
    QVBoxLayout *verticalLayout_3;
    TitlebarWidget *Title_bar;
    QWidget *widget_content;
    QLabel *label;
    QTextEdit *textEdit;
    QWidget *widget_4;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *cancel;
    QPushButton *ok;

    void setupUi(QWidget *VideoRoomDialog)
    {
        if (VideoRoomDialog->objectName().isEmpty())
            VideoRoomDialog->setObjectName(QStringLiteral("VideoRoomDialog"));
        VideoRoomDialog->resize(428, 205);
        VideoRoomDialog->setMaximumSize(QSize(16777215, 468));
        VideoRoomDialog->setStyleSheet(QString::fromUtf8("QWidget{\n"
"    font-family:\345\276\256\350\275\257\351\233\205\351\273\221;\n"
"}\n"
"\n"
"QTextEdit#textEdit{\n"
"    border:1px solid #FFFFFF;\n"
"}\n"
"\n"
"QLabel{\n"
"    color:#666666;\n"
"}\n"
"QPushButton#ok{\n"
"	 border-radius: 0px;\n"
"    color:#FFFFFF;\n"
"    background-color:#3DCE3D;\n"
"}\n"
"QPushButton#ok:disabled{\n"
"    background-color:#9DE69D;\n"
"}\n"
"QPushButton#ok:hover{\n"
"    background-color:#38C738;\n"
"}\n"
"QPushButton#ok:pressed{\n"
"    background-color:#2FB82F;\n"
"}\n"
"\n"
"QPushButton#cancel{\n"
"    color:#666666;\n"
"    border:1px solid #E5E5E5;\n"
"}\n"
"QPushButton#cancel:hover{\n"
"    background-color:#f5f5f5;\n"
"}\n"
"QPushButton#cancel:pressed,#edit:pressed{\n"
"    background-color:#EBEBEB;\n"
"}"));
        verticalLayout_2 = new QVBoxLayout(VideoRoomDialog);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        shadowbg = new QWidget(VideoRoomDialog);
        shadowbg->setObjectName(QStringLiteral("shadowbg"));
        verticalLayout = new QVBoxLayout(shadowbg);
        verticalLayout->setSpacing(0);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(8, 8, 8, 8);
        shadowinnerbg = new QWidget(shadowbg);
        shadowinnerbg->setObjectName(QStringLiteral("shadowinnerbg"));
        shadowinnerbg->setMinimumSize(QSize(0, 0));
        shadowinnerbg->setMaximumSize(QSize(16777215, 16777215));
        verticalLayout_3 = new QVBoxLayout(shadowinnerbg);
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(1, 1, 1, 1);
        Title_bar = new TitlebarWidget(shadowinnerbg);
        Title_bar->setObjectName(QStringLiteral("Title_bar"));
        Title_bar->setMinimumSize(QSize(0, 27));
        Title_bar->setMaximumSize(QSize(16777215, 27));

        verticalLayout_3->addWidget(Title_bar);

        widget_content = new QWidget(shadowinnerbg);
        widget_content->setObjectName(QStringLiteral("widget_content"));
        widget_content->setMinimumSize(QSize(0, 100));
        widget_content->setMaximumSize(QSize(16777215, 100));
        label = new QLabel(widget_content);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 10, 191, 21));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(12);
        label->setFont(font);
        textEdit = new QTextEdit(widget_content);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setGeometry(QRect(40, 40, 321, 51));

        verticalLayout_3->addWidget(widget_content);

        widget_4 = new QWidget(shadowinnerbg);
        widget_4->setObjectName(QStringLiteral("widget_4"));
        widget_4->setMinimumSize(QSize(1, 60));
        widget_4->setMaximumSize(QSize(16777215, 60));
        horizontalLayout = new QHBoxLayout(widget_4);
        horizontalLayout->setSpacing(25);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 10, 25, 0);
        horizontalSpacer = new QSpacerItem(232, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        cancel = new QPushButton(widget_4);
        cancel->setObjectName(QStringLiteral("cancel"));
        cancel->setMinimumSize(QSize(50, 25));
        cancel->setMaximumSize(QSize(50, 25));
        cancel->setFlat(true);

        horizontalLayout->addWidget(cancel);

        ok = new QPushButton(widget_4);
        ok->setObjectName(QStringLiteral("ok"));
        ok->setMinimumSize(QSize(50, 25));
        ok->setMaximumSize(QSize(50, 25));
        ok->setFlat(true);

        horizontalLayout->addWidget(ok);


        verticalLayout_3->addWidget(widget_4);


        verticalLayout->addWidget(shadowinnerbg);


        verticalLayout_2->addWidget(shadowbg);


        retranslateUi(VideoRoomDialog);

        QMetaObject::connectSlotsByName(VideoRoomDialog);
    } // setupUi

    void retranslateUi(QWidget *VideoRoomDialog)
    {
        VideoRoomDialog->setWindowTitle(QApplication::translate("VideoRoomDialog", "VideoRoomDialog", 0));
        label->setText(QApplication::translate("VideoRoomDialog", "\350\257\267\350\276\223\345\205\245\350\247\206\351\242\221\344\274\232\350\256\256\344\270\273\351\242\230\345\220\215\347\247\260:", 0));
        cancel->setText(QApplication::translate("VideoRoomDialog", "\345\217\226\346\266\210", 0));
        ok->setText(QApplication::translate("VideoRoomDialog", "\347\241\256\345\256\232", 0));
    } // retranslateUi

};

namespace Ui {
    class VideoRoomDialog: public Ui_VideoRoomDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VIDEOROOMDIALOG_H
