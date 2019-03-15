/********************************************************************************
** Form generated from reading UI file 'VoiceSetting.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VOICESETTING_H
#define UI_VOICESETTING_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "TitlebarWidget.h"

QT_BEGIN_NAMESPACE

class Ui_VoiceSetting
{
public:
    QVBoxLayout *verticalLayout_2;
    QWidget *shadowbg;
    QVBoxLayout *verticalLayout;
    QWidget *shadowinnerbg;
    QVBoxLayout *verticalLayout_3;
    TitlebarWidget *widget_title;
    QWidget *widget_5;
    QVBoxLayout *verticalLayout_4;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_5;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_4;
    QLabel *label_3;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_5;
    QPushButton *pb_playMsgvoice;
    QPushButton *pb_MsgOpen;
    QLabel *lineEdit_MsgVoicePath;
    QPushButton *pb_selectMsgFolder;
    QWidget *widget_3;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_6;
    QPushButton *pb_playWelvoice;
    QPushButton *pb_WelOpen;
    QLabel *lineEdit_WelVoicePath;
    QPushButton *pb_selectWelFolder;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *VoiceSetting)
    {
        if (VoiceSetting->objectName().isEmpty())
            VoiceSetting->setObjectName(QStringLiteral("VoiceSetting"));
        VoiceSetting->resize(360, 241);
        VoiceSetting->setMinimumSize(QSize(360, 0));
        VoiceSetting->setMaximumSize(QSize(360, 16777215));
        VoiceSetting->setStyleSheet(QLatin1String("QPushButton#pb_playMsgvoice,QPushButton#pb_playWelvoice{  \n"
"	border:none;\n"
"    image : url(:/Images/audio_play_normal.png);\n"
"}\n"
"\n"
"QPushButton#pb_playMsgvoice:hover, QPushButton#pb_playWelvoice:hover{\n"
"    image : url(:/Images/audio_play_hover.png);\n"
"}\n"
"\n"
"QPushButton#pb_playMsgvoice:pressed,QPushButton#pb_playWelvoice:pressed{\n"
"    image : url(:/Images/audio_play_hover.png);\n"
"}\n"
"\n"
"QPushButton#pb_selectMsgFolder, QPushButton#pb_selectWelFolder{  \n"
"	border:none;\n"
"    image : url(:Images/Folder.png);\n"
"}\n"
"\n"
"QLabel#label_3,QLabel#lineEdit_MsgVoicePath,QLabel#lineEdit_WelVoicePath{padding-left:10px;}"));
        verticalLayout_2 = new QVBoxLayout(VoiceSetting);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        shadowbg = new QWidget(VoiceSetting);
        shadowbg->setObjectName(QStringLiteral("shadowbg"));
        shadowbg->setStyleSheet(QStringLiteral(""));
        verticalLayout = new QVBoxLayout(shadowbg);
        verticalLayout->setSpacing(8);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(8, 8, 8, 8);
        shadowinnerbg = new QWidget(shadowbg);
        shadowinnerbg->setObjectName(QStringLiteral("shadowinnerbg"));
        shadowinnerbg->setStyleSheet(QStringLiteral(""));
        verticalLayout_3 = new QVBoxLayout(shadowinnerbg);
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(1, 1, 1, 1);
        widget_title = new TitlebarWidget(shadowinnerbg);
        widget_title->setObjectName(QStringLiteral("widget_title"));
        widget_title->setMinimumSize(QSize(0, 27));
        widget_title->setMaximumSize(QSize(16777215, 27));

        verticalLayout_3->addWidget(widget_title);

        widget_5 = new QWidget(shadowinnerbg);
        widget_5->setObjectName(QStringLiteral("widget_5"));
        verticalLayout_4 = new QVBoxLayout(widget_5);
        verticalLayout_4->setSpacing(0);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        groupBox = new QGroupBox(widget_5);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        verticalLayout_5 = new QVBoxLayout(groupBox);
        verticalLayout_5->setSpacing(4);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        widget = new QWidget(groupBox);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setMinimumSize(QSize(0, 20));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(widget);
        label->setObjectName(QStringLiteral("label"));
        label->setMinimumSize(QSize(70, 0));
        label->setMaximumSize(QSize(70, 16777215));
        label->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label);

        label_2 = new QLabel(widget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setMinimumSize(QSize(30, 0));
        label_2->setMaximumSize(QSize(30, 16777215));
        label_2->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label_2);

        label_4 = new QLabel(widget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setMaximumSize(QSize(30, 16777215));
        label_4->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label_4);

        label_3 = new QLabel(widget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        label_3->setTextInteractionFlags(Qt::NoTextInteraction);

        horizontalLayout->addWidget(label_3);


        verticalLayout_5->addWidget(widget);

        widget_2 = new QWidget(groupBox);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        widget_2->setMinimumSize(QSize(0, 20));
        horizontalLayout_2 = new QHBoxLayout(widget_2);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_5 = new QLabel(widget_2);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setMinimumSize(QSize(70, 0));
        label_5->setMaximumSize(QSize(70, 16777215));
        label_5->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(label_5);

        pb_playMsgvoice = new QPushButton(widget_2);
        pb_playMsgvoice->setObjectName(QStringLiteral("pb_playMsgvoice"));
        pb_playMsgvoice->setMinimumSize(QSize(30, 0));
        pb_playMsgvoice->setMaximumSize(QSize(30, 16777215));
        pb_playMsgvoice->setStyleSheet(QStringLiteral(""));
        pb_playMsgvoice->setFlat(true);

        horizontalLayout_2->addWidget(pb_playMsgvoice);

        pb_MsgOpen = new QPushButton(widget_2);
        pb_MsgOpen->setObjectName(QStringLiteral("pb_MsgOpen"));
        pb_MsgOpen->setMaximumSize(QSize(30, 16777215));
        pb_MsgOpen->setFlat(true);

        horizontalLayout_2->addWidget(pb_MsgOpen);

        lineEdit_MsgVoicePath = new QLabel(widget_2);
        lineEdit_MsgVoicePath->setObjectName(QStringLiteral("lineEdit_MsgVoicePath"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(lineEdit_MsgVoicePath->sizePolicy().hasHeightForWidth());
        lineEdit_MsgVoicePath->setSizePolicy(sizePolicy);
        lineEdit_MsgVoicePath->setAutoFillBackground(false);
        lineEdit_MsgVoicePath->setTextInteractionFlags(Qt::NoTextInteraction);
        lineEdit_MsgVoicePath->setProperty("readOnly", QVariant(true));
        lineEdit_MsgVoicePath->setProperty("clearButtonEnabled", QVariant(false));

        horizontalLayout_2->addWidget(lineEdit_MsgVoicePath);

        pb_selectMsgFolder = new QPushButton(widget_2);
        pb_selectMsgFolder->setObjectName(QStringLiteral("pb_selectMsgFolder"));
        pb_selectMsgFolder->setMinimumSize(QSize(30, 16));
        pb_selectMsgFolder->setMaximumSize(QSize(30, 16777215));
        pb_selectMsgFolder->setFlat(false);

        horizontalLayout_2->addWidget(pb_selectMsgFolder);


        verticalLayout_5->addWidget(widget_2);

        widget_3 = new QWidget(groupBox);
        widget_3->setObjectName(QStringLiteral("widget_3"));
        widget_3->setMinimumSize(QSize(0, 20));
        horizontalLayout_3 = new QHBoxLayout(widget_3);
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_6 = new QLabel(widget_3);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setMinimumSize(QSize(70, 0));
        label_6->setMaximumSize(QSize(70, 16777215));
        label_6->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(label_6);

        pb_playWelvoice = new QPushButton(widget_3);
        pb_playWelvoice->setObjectName(QStringLiteral("pb_playWelvoice"));
        pb_playWelvoice->setMinimumSize(QSize(30, 0));
        pb_playWelvoice->setMaximumSize(QSize(30, 16777215));
        pb_playWelvoice->setFlat(true);

        horizontalLayout_3->addWidget(pb_playWelvoice);

        pb_WelOpen = new QPushButton(widget_3);
        pb_WelOpen->setObjectName(QStringLiteral("pb_WelOpen"));
        pb_WelOpen->setMaximumSize(QSize(30, 16777215));
        pb_WelOpen->setFlat(true);

        horizontalLayout_3->addWidget(pb_WelOpen);

        lineEdit_WelVoicePath = new QLabel(widget_3);
        lineEdit_WelVoicePath->setObjectName(QStringLiteral("lineEdit_WelVoicePath"));
        sizePolicy.setHeightForWidth(lineEdit_WelVoicePath->sizePolicy().hasHeightForWidth());
        lineEdit_WelVoicePath->setSizePolicy(sizePolicy);
        lineEdit_WelVoicePath->setAutoFillBackground(false);
        lineEdit_WelVoicePath->setTextInteractionFlags(Qt::NoTextInteraction);
        lineEdit_WelVoicePath->setProperty("readOnly", QVariant(true));
        lineEdit_WelVoicePath->setProperty("clearButtonEnabled", QVariant(false));

        horizontalLayout_3->addWidget(lineEdit_WelVoicePath);

        pb_selectWelFolder = new QPushButton(widget_3);
        pb_selectWelFolder->setObjectName(QStringLiteral("pb_selectWelFolder"));
        pb_selectWelFolder->setMinimumSize(QSize(30, 16));
        pb_selectWelFolder->setMaximumSize(QSize(30, 16777215));
        pb_selectWelFolder->setFlat(false);

        horizontalLayout_3->addWidget(pb_selectWelFolder);


        verticalLayout_5->addWidget(widget_3);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_5->addItem(verticalSpacer);


        verticalLayout_4->addWidget(groupBox);


        verticalLayout_3->addWidget(widget_5);


        verticalLayout->addWidget(shadowinnerbg);


        verticalLayout_2->addWidget(shadowbg);


        retranslateUi(VoiceSetting);

        QMetaObject::connectSlotsByName(VoiceSetting);
    } // setupUi

    void retranslateUi(QWidget *VoiceSetting)
    {
        VoiceSetting->setWindowTitle(QApplication::translate("VoiceSetting", "Form", 0));
        groupBox->setTitle(QString());
        label->setText(QApplication::translate("VoiceSetting", "\346\266\210\346\201\257\347\261\273\345\236\213", 0));
        label_2->setText(QApplication::translate("VoiceSetting", "\350\257\225\345\220\254", 0));
        label_4->setText(QApplication::translate("VoiceSetting", "\347\212\266\346\200\201", 0));
        label_3->setText(QApplication::translate("VoiceSetting", "\345\243\260\351\237\263\346\226\207\344\273\266", 0));
        label_5->setText(QApplication::translate("VoiceSetting", "\346\231\256\351\200\232\346\266\210\346\201\257", 0));
        pb_playMsgvoice->setText(QString());
        pb_MsgOpen->setText(QApplication::translate("VoiceSetting", "\345\274\200\345\220\257", 0));
        pb_selectMsgFolder->setText(QString());
        label_6->setText(QApplication::translate("VoiceSetting", "\346\254\242\350\277\216\346\266\210\346\201\257", 0));
        pb_playWelvoice->setText(QString());
        pb_WelOpen->setText(QApplication::translate("VoiceSetting", "\345\274\200\345\220\257", 0));
        lineEdit_WelVoicePath->setText(QString());
        pb_selectWelFolder->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class VoiceSetting: public Ui_VoiceSetting {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VOICESETTING_H
