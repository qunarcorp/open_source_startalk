/********************************************************************************
** Form generated from reading UI file 'EmotionDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EMOTIONDIALOG_H
#define UI_EMOTIONDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_EmotionDialog
{
public:
    QHBoxLayout *horizontalLayout;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout_2;
    QWidget *gridwidget;
    QGridLayout *gridLayout;

    void setupUi(QWidget *EmotionDialog)
    {
        if (EmotionDialog->objectName().isEmpty())
            EmotionDialog->setObjectName(QStringLiteral("EmotionDialog"));
        EmotionDialog->resize(467, 288);
        EmotionDialog->setStyleSheet(QLatin1String("QWidget#gridwidget{ \n"
"	background-color:#d3e4f0;	\n"
"} \n"
"QPushButton{ \n"
"	border:none;	\n"
"	background-color: #FFFFFF;\n"
"} \n"
"QPushButton:hover{ \n"
"	border: 1px solid #4ca0d9;	\n"
"} \n"
"\n"
"QScrollArea\n"
"{\n"
"	border:none;\n"
"}\n"
"\n"
"\n"
""));
        horizontalLayout = new QHBoxLayout(EmotionDialog);
        horizontalLayout->setSpacing(1);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(12, 10, 0, 10);
        scrollArea = new QScrollArea(EmotionDialog);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 455, 268));
        scrollAreaWidgetContents->setMinimumSize(QSize(0, 0));
        scrollAreaWidgetContents->setMaximumSize(QSize(481, 16777215));
        verticalLayout_2 = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        gridwidget = new QWidget(scrollAreaWidgetContents);
        gridwidget->setObjectName(QStringLiteral("gridwidget"));
        gridwidget->setMinimumSize(QSize(435, 0));
        gridwidget->setMaximumSize(QSize(435, 16777215));
        gridwidget->setStyleSheet(QStringLiteral(""));
        gridLayout = new QGridLayout(gridwidget);
        gridLayout->setSpacing(1);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(1, 1, 0, 0);

        verticalLayout_2->addWidget(gridwidget);

        scrollArea->setWidget(scrollAreaWidgetContents);

        horizontalLayout->addWidget(scrollArea);


        retranslateUi(EmotionDialog);

        QMetaObject::connectSlotsByName(EmotionDialog);
    } // setupUi

    void retranslateUi(QWidget *EmotionDialog)
    {
        EmotionDialog->setWindowTitle(QApplication::translate("EmotionDialog", "EmotionDialog", 0));
    } // retranslateUi

};

namespace Ui {
    class EmotionDialog: public Ui_EmotionDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EMOTIONDIALOG_H
