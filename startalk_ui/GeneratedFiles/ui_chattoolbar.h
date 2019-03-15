/********************************************************************************
** Form generated from reading UI file 'chattoolbar.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHATTOOLBAR_H
#define UI_CHATTOOLBAR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ChatToolBar
{
public:
    QHBoxLayout *horizontalLayout;
    QPushButton *btnFont;
    QPushButton *btnEmotion;
    QPushButton *btnJietu;
    QPushButton *btnJietusetting;
    QPushButton *btnSendPic;
    QPushButton *btnSendVoice;
    QPushButton *btnQuickReply;
    QPushButton *btnTransfer;
    QPushButton *btnShake;
    QPushButton *btnRCode;
    QPushButton *btnShare;
    QPushButton *btnRobot;
    QPushButton *btnCloseSession;
    QPushButton *btnPingFen;
    QPushButton *btnToolbarMore;
    QToolButton *vidioandaudio;
    QSpacerItem *horizontalSpacer;
    QPushButton *historyRecord;
    QCheckBox *code_checkBox;
    QComboBox *codeStyle_comboBox;
    QComboBox *codetype_comboBox;
    QPushButton *historyRecordWeb;

    void setupUi(QWidget *ChatToolBar)
    {
        if (ChatToolBar->objectName().isEmpty())
            ChatToolBar->setObjectName(QStringLiteral("ChatToolBar"));
        ChatToolBar->resize(856, 32);
        ChatToolBar->setMinimumSize(QSize(500, 0));
        ChatToolBar->setStyleSheet(QString::fromUtf8("QWidget#ChatToolBar{\n"
"	font-family:\345\276\256\350\275\257\351\233\205\351\273\221;\n"
"	font-size:12px;\n"
"}\n"
"\n"
"QPushButton#btnFont{ \n"
"    border:1px solid #00000000;\n"
"	image : url(:/Images/font_normal.png);\n"
"} \n"
"QPushButton#btnFont:hover{ \n"
"    image : url(:/Images/font_hover.png);\n"
"} \n"
"QPushButton#btnFont:pressed{ \n"
"    image : url(:/Images/font_hover.png);\n"
"}\n"
"QPushButton#btnEmotion{ \n"
"    border:1px solid #00000000;\n"
"	image : url(:/Images/toolbar_emoticon_normal.png);\n"
"} \n"
"QPushButton#btnEmotion:hover{ \n"
"	image : url(:/Images/toolbar_emoticon_hover.png);\n"
"} \n"
"QPushButton#btnEmotion:pressed{ \n"
"	image : url(:/Images/toolbar_emoticon_hover.png);\n"
"} \n"
"\n"
"\n"
"\n"
"QPushButton#btnJietu{ \n"
"    border:1px solid #00000000;\n"
"	image : url(:/Images/toolbar_screenCapture_normal.png);\n"
"} \n"
"QPushButton#btnJietu:hover{ \n"
"    image : url(:/Images/toolbar_screenCapture_hover.png);\n"
"} \n"
"QPushButton#btnJietu:pressed{ \n"
"   image "
                        ": url(:/Images/toolbar_screenCapture_hover.png);\n"
"} \n"
"\n"
"\n"
"\n"
"QPushButton#btnSendPic{ \n"
"    border:1px solid #00000000;\n"
"	image : url(:/Images/toolbar_sendfile_normal.png);\n"
"} \n"
"QPushButton#btnSendPic:hover{ \n"
"    image : url(:/Images/toolbar_sendfile_hover.png);\n"
"} \n"
"QPushButton#btnSendPic:pressed{ \n"
"    image : url(:/Images/toolbar_sendfile_hover.png);\n"
"} \n"
"\n"
"\n"
"\n"
"QPushButton#historyRecord{ \n"
"    border:1px solid #00000000;\n"
"	\n"
"	image : url(:/Images/historyicon.png);\n"
"} \n"
"QPushButton#historyRecord:hover{ \n"
"    image : url(:/Images/historyicon.png);\n"
"} \n"
"QPushButton#historyRecord:pressed{ \n"
"    image : url(:/Images/historyicon.png);\n"
"} \n"
"\n"
"QPushButton#historyRecordWeb{ \n"
"    border:1px solid #00000000;\n"
"	\n"
"	image : url(:/Images/aio_group_search_normal.png);\n"
"} \n"
"QPushButton#historyRecordWeb:hover{ \n"
"    image : url(:/Images/aio_group_search_normal.png);\n"
"} \n"
"QPushButton#historyRecordWeb:pressed{ \n"
""
                        "    image : url(:/Images/aio_group_search_normal.png);\n"
"} \n"
"\n"
"\n"
"QPushButton#btnQuickReply{ \n"
"    border:1px solid #00000000;\n"
"	image : url(:/Images/icon/quickreply_normal.png);\n"
"} \n"
"QPushButton#btnQuickReply:hover,\n"
"QPushButton#btnQuickReply:pressed{ \n"
"    image : url(:/Images/icon/quickreply_hover.png);\n"
"} \n"
"\n"
"\n"
"\n"
"QPushButton#btnTransfer{ \n"
"    border:1px solid #00000000;\n"
"	image : url(:/Images/icon/transfor_normal.png);\n"
"} \n"
"QPushButton#btnTransfer:hover,\n"
"QPushButton#btnTransfer:pressed { \n"
"   image : url(:/Images/icon/transfor_hover.png);\n"
"} \n"
"\n"
"\n"
"QPushButton#btnShake{ \n"
"    border:1px solid #00000000;\n"
"	image : url(:/Images/toolbar_shake_normal.png);\n"
"} \n"
"QPushButton#btnShake:hover{ \n"
"    image : url(:/Images/toolbar_shake_hover.png);\n"
"} \n"
"QPushButton#btnShake:pressed{ \n"
"   image : url(:/Images/toolbar_shake_hover.png);\n"
"}\n"
"\n"
"QPushButton#btnJietusetting{ \n"
"    border:1px solid #00000000;\n"
"	ima"
                        "ge : url(:/Images/jietu_normal.png);\n"
"} \n"
"QPushButton#btnJietusetting:hover{ \n"
"    image : url(:/Images/jietu_hover.png);\n"
"} \n"
"QPushButton#btnJietusetting:pressed{ \n"
"   image : url(:/Images/jietu_hover.png);\n"
"} \n"
"\n"
"\n"
"QPushButton#btnShare{ \n"
"    border:1px solid #00000000;\n"
"	image : url(:/Images/icon/share_normal.png);\n"
"} \n"
"QPushButton#btnShare:hover,\n"
"QPushButton#btnShare:pressed{ \n"
"    image : url(:/Images/icon/share_hover.png);\n"
"} \n"
"\n"
"\n"
"QPushButton#btnRCode{ \n"
"    border:1px solid #00000000;\n"
"	image : url(:/Images/rcode_normal.png);\n"
"} \n"
"QPushButton#btnRCode:hover{ \n"
"    image : url(:/Images/rcode_hover.png);\n"
"} \n"
"QPushButton#btnRCode:pressed{ \n"
"   image : url(:/Images/rcode_hover.png);\n"
"} \n"
"\n"
"QPushButton#btnRobot{ \n"
"    border:1px solid #00000000;\n"
"	image : url(:/Images/toolbar_robot_normal.png);\n"
"} \n"
"QPushButton#btnRobot:hover{ \n"
"    image : url(:/Images/toolbar_robot_hover.png);\n"
"} \n"
"QPushButt"
                        "on#btnRobot:pressed{ \n"
"   image : url(:/Images/toolbar_robot_hover.png);\n"
"}\n"
"\n"
"QPushButton#btnCloseSession{ \n"
"    border:1px solid #00000000;\n"
"	image : url(:/Images/icon/toolbar/closesession.png);\n"
"} \n"
"QPushButton#btnPingFen{ \n"
"    border:1px solid #00000000;\n"
"	image : url(:/Images/icon/toolbar/pingfen.png);\n"
"} \n"
"\n"
"\n"
"QPushButton#btnToolbarMore{ \n"
"   color:#666666;\n"
"} \n"
"QPushButton#btnToolbarMore:hover{ \n"
"    color : #1ba9ba;\n"
"} \n"
"QPushButton#btnToolbarMore:pressed{ \n"
"   color : #1ba9ba;\n"
"}\n"
"QToolButton::menu-indicator {\n"
"     image: None;\n"
"}\n"
"\n"
"QComboBox {\n"
"    border: 1px solid #EBEBEB;\n"
"    border-radius: 0px;\n"
"    padding: 1px 18px 1px 3px;\n"
"}\n"
"\n"
"QComboBox:!editable, QComboBox::drop-down:editable {\n"
"     background: #AAFFFFFF;\n"
"}\n"
"\n"
"QComboBox:on { /* shift the text when the popup opens */\n"
"    padding-top: 3px;\n"
"    padding-left: 4px;\n"
"}\n"
"\n"
"QComboBox::drop-down {\n"
"    subcontrol-o"
                        "rigin: padding;\n"
"    subcontrol-position: top right;\n"
"    width: 15px;\n"
"	border-left-width: 1px;\n"
"    border-left-color: #EBEBEB;\n"
"    border-left-style: solid; /* just a single line */\n"
"}\n"
"\n"
"QComboBox::down-arrow {\n"
"    image: url(:/Images/jietu_normal.png);\n"
"}\n"
"\n"
"QComboBox::down-arrow:on { /* shift the arrow when popup is open */\n"
"    top: 1px;\n"
"    left: 1px;\n"
"}\n"
"QWidget#btnToolbarMore,QWidget#chatencrypt,QWidget#code_checkBox,QWidget#codeStyle_comboBox,QWidget#codetype_comboBox{\n"
"    font-size:12px;\n"
"}\n"
"  "));
        horizontalLayout = new QHBoxLayout(ChatToolBar);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        btnFont = new QPushButton(ChatToolBar);
        btnFont->setObjectName(QStringLiteral("btnFont"));
        btnFont->setMinimumSize(QSize(32, 32));
        btnFont->setMaximumSize(QSize(32, 32));
        btnFont->setFlat(true);

        horizontalLayout->addWidget(btnFont);

        btnEmotion = new QPushButton(ChatToolBar);
        btnEmotion->setObjectName(QStringLiteral("btnEmotion"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(btnEmotion->sizePolicy().hasHeightForWidth());
        btnEmotion->setSizePolicy(sizePolicy);
        btnEmotion->setMinimumSize(QSize(32, 32));
        btnEmotion->setMaximumSize(QSize(32, 32));
        btnEmotion->setFlat(true);

        horizontalLayout->addWidget(btnEmotion);

        btnJietu = new QPushButton(ChatToolBar);
        btnJietu->setObjectName(QStringLiteral("btnJietu"));
        btnJietu->setMinimumSize(QSize(20, 32));
        btnJietu->setMaximumSize(QSize(20, 32));
        btnJietu->setFlat(true);

        horizontalLayout->addWidget(btnJietu);

        btnJietusetting = new QPushButton(ChatToolBar);
        btnJietusetting->setObjectName(QStringLiteral("btnJietusetting"));
        btnJietusetting->setMinimumSize(QSize(10, 32));
        btnJietusetting->setMaximumSize(QSize(10, 32));
        btnJietusetting->setFlat(true);

        horizontalLayout->addWidget(btnJietusetting);

        btnSendPic = new QPushButton(ChatToolBar);
        btnSendPic->setObjectName(QStringLiteral("btnSendPic"));
        btnSendPic->setMinimumSize(QSize(32, 32));
        btnSendPic->setMaximumSize(QSize(32, 32));
        btnSendPic->setFlat(true);

        horizontalLayout->addWidget(btnSendPic);

        btnSendVoice = new QPushButton(ChatToolBar);
        btnSendVoice->setObjectName(QStringLiteral("btnSendVoice"));
        btnSendVoice->setMaximumSize(QSize(32, 32));
        btnSendVoice->setFlat(true);

        horizontalLayout->addWidget(btnSendVoice);

        btnQuickReply = new QPushButton(ChatToolBar);
        btnQuickReply->setObjectName(QStringLiteral("btnQuickReply"));
        btnQuickReply->setMinimumSize(QSize(32, 32));
        btnQuickReply->setMaximumSize(QSize(32, 32));
        btnQuickReply->setFlat(true);

        horizontalLayout->addWidget(btnQuickReply);

        btnTransfer = new QPushButton(ChatToolBar);
        btnTransfer->setObjectName(QStringLiteral("btnTransfer"));
        btnTransfer->setMinimumSize(QSize(32, 32));
        btnTransfer->setMaximumSize(QSize(32, 32));
        btnTransfer->setFlat(true);

        horizontalLayout->addWidget(btnTransfer);

        btnShake = new QPushButton(ChatToolBar);
        btnShake->setObjectName(QStringLiteral("btnShake"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(btnShake->sizePolicy().hasHeightForWidth());
        btnShake->setSizePolicy(sizePolicy1);
        btnShake->setMinimumSize(QSize(32, 32));
        btnShake->setMaximumSize(QSize(32, 32));
        btnShake->setFlat(true);

        horizontalLayout->addWidget(btnShake);

        btnRCode = new QPushButton(ChatToolBar);
        btnRCode->setObjectName(QStringLiteral("btnRCode"));
        btnRCode->setMinimumSize(QSize(32, 32));
        btnRCode->setMaximumSize(QSize(32, 32));
        btnRCode->setAutoExclusive(false);
        btnRCode->setFlat(true);

        horizontalLayout->addWidget(btnRCode);

        btnShare = new QPushButton(ChatToolBar);
        btnShare->setObjectName(QStringLiteral("btnShare"));
        btnShare->setMinimumSize(QSize(32, 32));
        btnShare->setMaximumSize(QSize(32, 32));
        btnShare->setAutoExclusive(false);
        btnShare->setFlat(true);

        horizontalLayout->addWidget(btnShare);

        btnRobot = new QPushButton(ChatToolBar);
        btnRobot->setObjectName(QStringLiteral("btnRobot"));
        btnRobot->setMinimumSize(QSize(32, 32));
        btnRobot->setMaximumSize(QSize(32, 32));
        btnRobot->setFlat(true);

        horizontalLayout->addWidget(btnRobot);

        btnCloseSession = new QPushButton(ChatToolBar);
        btnCloseSession->setObjectName(QStringLiteral("btnCloseSession"));
        btnCloseSession->setMinimumSize(QSize(32, 32));
        btnCloseSession->setMaximumSize(QSize(32, 32));
        btnCloseSession->setFlat(true);

        horizontalLayout->addWidget(btnCloseSession);

        btnPingFen = new QPushButton(ChatToolBar);
        btnPingFen->setObjectName(QStringLiteral("btnPingFen"));
        btnPingFen->setMinimumSize(QSize(32, 32));
        btnPingFen->setMaximumSize(QSize(32, 32));
        btnPingFen->setFlat(true);

        horizontalLayout->addWidget(btnPingFen);

        btnToolbarMore = new QPushButton(ChatToolBar);
        btnToolbarMore->setObjectName(QStringLiteral("btnToolbarMore"));
        btnToolbarMore->setMinimumSize(QSize(50, 32));
        btnToolbarMore->setMaximumSize(QSize(50, 32));
        btnToolbarMore->setAutoExclusive(true);
        btnToolbarMore->setFlat(true);

        horizontalLayout->addWidget(btnToolbarMore);

        vidioandaudio = new QToolButton(ChatToolBar);
        vidioandaudio->setObjectName(QStringLiteral("vidioandaudio"));
        vidioandaudio->setMinimumSize(QSize(40, 25));
        vidioandaudio->setMaximumSize(QSize(40, 25));
        vidioandaudio->setLayoutDirection(Qt::LeftToRight);
        QIcon icon;
        icon.addFile(QStringLiteral(":/Images/icon/vidioaud.png"), QSize(), QIcon::Normal, QIcon::Off);
        vidioandaudio->setIcon(icon);
        vidioandaudio->setCheckable(false);
        vidioandaudio->setChecked(false);
        vidioandaudio->setPopupMode(QToolButton::MenuButtonPopup);
        vidioandaudio->setToolButtonStyle(Qt::ToolButtonIconOnly);
        vidioandaudio->setAutoRaise(true);
        vidioandaudio->setArrowType(Qt::NoArrow);

        horizontalLayout->addWidget(vidioandaudio);

        horizontalSpacer = new QSpacerItem(162, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        historyRecord = new QPushButton(ChatToolBar);
        historyRecord->setObjectName(QStringLiteral("historyRecord"));
        historyRecord->setMinimumSize(QSize(2, 2));
        historyRecord->setMaximumSize(QSize(2, 2));
        historyRecord->setStyleSheet(QStringLiteral(""));
        historyRecord->setFlat(true);

        horizontalLayout->addWidget(historyRecord);

        code_checkBox = new QCheckBox(ChatToolBar);
        code_checkBox->setObjectName(QStringLiteral("code_checkBox"));
        code_checkBox->setMinimumSize(QSize(60, 0));
        code_checkBox->setMaximumSize(QSize(60, 16777215));

        horizontalLayout->addWidget(code_checkBox);

        codeStyle_comboBox = new QComboBox(ChatToolBar);
        codeStyle_comboBox->setObjectName(QStringLiteral("codeStyle_comboBox"));
        codeStyle_comboBox->setMinimumSize(QSize(80, 0));
        codeStyle_comboBox->setMaximumSize(QSize(80, 16777215));

        horizontalLayout->addWidget(codeStyle_comboBox);

        codetype_comboBox = new QComboBox(ChatToolBar);
        codetype_comboBox->setObjectName(QStringLiteral("codetype_comboBox"));
        codetype_comboBox->setMinimumSize(QSize(80, 0));
        codetype_comboBox->setMaximumSize(QSize(80, 16777215));

        horizontalLayout->addWidget(codetype_comboBox);

        historyRecordWeb = new QPushButton(ChatToolBar);
        historyRecordWeb->setObjectName(QStringLiteral("historyRecordWeb"));
        historyRecordWeb->setMinimumSize(QSize(30, 30));
        historyRecordWeb->setMaximumSize(QSize(30, 30));
        historyRecordWeb->setFlat(true);

        horizontalLayout->addWidget(historyRecordWeb);


        retranslateUi(ChatToolBar);

        QMetaObject::connectSlotsByName(ChatToolBar);
    } // setupUi

    void retranslateUi(QWidget *ChatToolBar)
    {
        ChatToolBar->setWindowTitle(QApplication::translate("ChatToolBar", "ChatToolBar", 0));
#ifndef QT_NO_TOOLTIP
        btnFont->setToolTip(QApplication::translate("ChatToolBar", "\350\256\276\347\275\256\345\255\227\344\275\223\345\217\212\346\240\267\345\274\217", 0));
#endif // QT_NO_TOOLTIP
        btnFont->setText(QString());
#ifndef QT_NO_TOOLTIP
        btnEmotion->setToolTip(QApplication::translate("ChatToolBar", "\350\241\250\346\203\205", 0));
#endif // QT_NO_TOOLTIP
        btnEmotion->setText(QString());
#ifndef QT_NO_TOOLTIP
        btnJietu->setToolTip(QApplication::translate("ChatToolBar", "\346\210\252\345\233\276", 0));
#endif // QT_NO_TOOLTIP
        btnJietu->setText(QString());
        btnJietusetting->setText(QString());
#ifndef QT_NO_TOOLTIP
        btnSendPic->setToolTip(QApplication::translate("ChatToolBar", "\345\217\221\351\200\201\345\233\276\347\211\207\345\217\212\346\226\207\344\273\266", 0));
#endif // QT_NO_TOOLTIP
        btnSendPic->setText(QString());
        btnSendVoice->setText(QString());
#ifndef QT_NO_TOOLTIP
        btnQuickReply->setToolTip(QApplication::translate("ChatToolBar", "\345\277\253\351\200\237\345\233\236\345\244\215", 0));
#endif // QT_NO_TOOLTIP
        btnQuickReply->setText(QString());
#ifndef QT_NO_TOOLTIP
        btnTransfer->setToolTip(QApplication::translate("ChatToolBar", "\344\274\232\350\257\235\350\275\254\347\247\273", 0));
#endif // QT_NO_TOOLTIP
        btnTransfer->setText(QString());
        btnShake->setText(QString());
#ifndef QT_NO_TOOLTIP
        btnRCode->setToolTip(QApplication::translate("ChatToolBar", "\346\211\253\344\272\214\347\273\264\347\240\201", 0));
#endif // QT_NO_TOOLTIP
        btnRCode->setText(QString());
#ifndef QT_NO_TOOLTIP
        btnShare->setToolTip(QApplication::translate("ChatToolBar", "\345\210\206\344\272\253\346\266\210\346\201\257", 0));
#endif // QT_NO_TOOLTIP
        btnShare->setText(QString());
#ifndef QT_NO_TOOLTIP
        btnRobot->setToolTip(QApplication::translate("ChatToolBar", "\346\211\223\345\274\200\346\234\272\345\231\250\344\272\272", 0));
#endif // QT_NO_TOOLTIP
        btnRobot->setText(QString());
#ifndef QT_NO_TOOLTIP
        btnCloseSession->setToolTip(QApplication::translate("ChatToolBar", "\347\273\223\346\235\237\344\274\232\350\257\235", 0));
#endif // QT_NO_TOOLTIP
        btnCloseSession->setText(QString());
#ifndef QT_NO_TOOLTIP
        btnPingFen->setToolTip(QApplication::translate("ChatToolBar", "\350\257\204\345\210\206", 0));
#endif // QT_NO_TOOLTIP
        btnPingFen->setText(QString());
        btnToolbarMore->setText(QApplication::translate("ChatToolBar", "\346\233\264\345\244\232", 0));
#ifndef QT_NO_TOOLTIP
        vidioandaudio->setToolTip(QApplication::translate("ChatToolBar", "\345\256\236\346\227\266\351\237\263\350\247\206\351\242\221", 0));
#endif // QT_NO_TOOLTIP
        vidioandaudio->setText(QString());
#ifndef QT_NO_TOOLTIP
        historyRecord->setToolTip(QApplication::translate("ChatToolBar", "\346\234\254\346\234\272\346\266\210\346\201\257\346\220\234\347\264\242", 0));
#endif // QT_NO_TOOLTIP
        historyRecord->setText(QString());
        code_checkBox->setText(QApplication::translate("ChatToolBar", "Code", 0));
#ifndef QT_NO_TOOLTIP
        historyRecordWeb->setToolTip(QApplication::translate("ChatToolBar", "\350\277\234\347\250\213\346\266\210\346\201\257\346\220\234\347\264\242", 0));
#endif // QT_NO_TOOLTIP
        historyRecordWeb->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class ChatToolBar: public Ui_ChatToolBar {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHATTOOLBAR_H
