/********************************************************************************
** Form generated from reading UI file 'popupnoticeview.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_POPUPNOTICEVIEW_H
#define UI_POPUPNOTICEVIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "TitlebarWidget.h"

QT_BEGIN_NAMESPACE

class Ui_PopupNoticeView
{
public:
    QWidget *shadowbg;
    QVBoxLayout *verticalLayout_5;
    QWidget *dialogbg;
    QVBoxLayout *verticalLayout;
    TitlebarWidget *titlebar;
    QWidget *wid_mid;
    QHBoxLayout *horizontalLayout_2;
    QLabel *content;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *PopupNoticeView)
    {
        if (PopupNoticeView->objectName().isEmpty())
            PopupNoticeView->setObjectName(QStringLiteral("PopupNoticeView"));
        PopupNoticeView->resize(278, 112);
        PopupNoticeView->setMinimumSize(QSize(278, 112));
        PopupNoticeView->setMaximumSize(QSize(278, 112));
        PopupNoticeView->setStyleSheet(QStringLiteral(""));
        shadowbg = new QWidget(PopupNoticeView);
        shadowbg->setObjectName(QStringLiteral("shadowbg"));
        shadowbg->setGeometry(QRect(0, 0, 278, 86));
        verticalLayout_5 = new QVBoxLayout(shadowbg);
        verticalLayout_5->setSpacing(0);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(8, 8, 8, 8);
        dialogbg = new QWidget(shadowbg);
        dialogbg->setObjectName(QStringLiteral("dialogbg"));
        verticalLayout = new QVBoxLayout(dialogbg);
        verticalLayout->setSpacing(0);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        titlebar = new TitlebarWidget(dialogbg);
        titlebar->setObjectName(QStringLiteral("titlebar"));
        titlebar->setMaximumSize(QSize(16777215, 27));

        verticalLayout->addWidget(titlebar);

        wid_mid = new QWidget(dialogbg);
        wid_mid->setObjectName(QStringLiteral("wid_mid"));
        wid_mid->setMinimumSize(QSize(0, 44));
        wid_mid->setStyleSheet(QStringLiteral(""));
        horizontalLayout_2 = new QHBoxLayout(wid_mid);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(16, 0, 16, 0);
        content = new QLabel(wid_mid);
        content->setObjectName(QStringLiteral("content"));

        horizontalLayout_2->addWidget(content);


        verticalLayout->addWidget(wid_mid);

        verticalSpacer = new QSpacerItem(20, 13, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        verticalLayout_5->addWidget(dialogbg);


        retranslateUi(PopupNoticeView);

        QMetaObject::connectSlotsByName(PopupNoticeView);
    } // setupUi

    void retranslateUi(QWidget *PopupNoticeView)
    {
        PopupNoticeView->setWindowTitle(QApplication::translate("PopupNoticeView", "PopupNoticeView", 0));
        content->setText(QApplication::translate("PopupNoticeView", "TextLabel", 0));
    } // retranslateUi

};

namespace Ui {
    class PopupNoticeView: public Ui_PopupNoticeView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_POPUPNOTICEVIEW_H
