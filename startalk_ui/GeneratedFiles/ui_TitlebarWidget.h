/********************************************************************************
** Form generated from reading UI file 'TitlebarWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TITLEBARWIDGET_H
#define UI_TITLEBARWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TitlebarWidget
{
public:
    QVBoxLayout *verticalLayout_2;
    QWidget *Title_bar;
    QHBoxLayout *horizontalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *leftTitle;
    QLabel *TitleBar_title;
    QSpacerItem *horizontalSpacer_2;
    QToolButton *Titlebar_Min;
    QToolButton *Titlebar_Max;
    QToolButton *Titlebar_Close;

    void setupUi(QWidget *TitlebarWidget)
    {
        if (TitlebarWidget->objectName().isEmpty())
            TitlebarWidget->setObjectName(QStringLiteral("TitlebarWidget"));
        TitlebarWidget->resize(246, 27);
        TitlebarWidget->setMinimumSize(QSize(0, 0));
        TitlebarWidget->setMaximumSize(QSize(16777215, 27));
        TitlebarWidget->setStyleSheet(QStringLiteral(""));
        verticalLayout_2 = new QVBoxLayout(TitlebarWidget);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        Title_bar = new QWidget(TitlebarWidget);
        Title_bar->setObjectName(QStringLiteral("Title_bar"));
        Title_bar->setStyleSheet(QStringLiteral(""));
        horizontalLayout = new QHBoxLayout(Title_bar);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(10, 0, 0, -1);
        leftTitle = new QLabel(Title_bar);
        leftTitle->setObjectName(QStringLiteral("leftTitle"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(leftTitle->sizePolicy().hasHeightForWidth());
        leftTitle->setSizePolicy(sizePolicy);

        horizontalLayout_2->addWidget(leftTitle);

        TitleBar_title = new QLabel(Title_bar);
        TitleBar_title->setObjectName(QStringLiteral("TitleBar_title"));

        horizontalLayout_2->addWidget(TitleBar_title);

        horizontalSpacer_2 = new QSpacerItem(40, 10, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        Titlebar_Min = new QToolButton(Title_bar);
        Titlebar_Min->setObjectName(QStringLiteral("Titlebar_Min"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(Titlebar_Min->sizePolicy().hasHeightForWidth());
        Titlebar_Min->setSizePolicy(sizePolicy1);
        Titlebar_Min->setIconSize(QSize(29, 18));

        horizontalLayout_2->addWidget(Titlebar_Min);

        Titlebar_Max = new QToolButton(Title_bar);
        Titlebar_Max->setObjectName(QStringLiteral("Titlebar_Max"));
        sizePolicy1.setHeightForWidth(Titlebar_Max->sizePolicy().hasHeightForWidth());
        Titlebar_Max->setSizePolicy(sizePolicy1);
        Titlebar_Max->setIconSize(QSize(38, 18));

        horizontalLayout_2->addWidget(Titlebar_Max);

        Titlebar_Close = new QToolButton(Title_bar);
        Titlebar_Close->setObjectName(QStringLiteral("Titlebar_Close"));
        sizePolicy1.setHeightForWidth(Titlebar_Close->sizePolicy().hasHeightForWidth());
        Titlebar_Close->setSizePolicy(sizePolicy1);
        Titlebar_Close->setStyleSheet(QStringLiteral(""));
        Titlebar_Close->setIconSize(QSize(38, 18));

        horizontalLayout_2->addWidget(Titlebar_Close);


        horizontalLayout->addLayout(horizontalLayout_2);


        verticalLayout_2->addWidget(Title_bar);


        retranslateUi(TitlebarWidget);

        QMetaObject::connectSlotsByName(TitlebarWidget);
    } // setupUi

    void retranslateUi(QWidget *TitlebarWidget)
    {
        TitlebarWidget->setWindowTitle(QApplication::translate("TitlebarWidget", "TitlebarWidget", 0));
        leftTitle->setText(QApplication::translate("TitlebarWidget", "Qunar Talk", 0));
        TitleBar_title->setText(QString());
        Titlebar_Min->setText(QString());
        Titlebar_Max->setText(QString());
        Titlebar_Close->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class TitlebarWidget: public Ui_TitlebarWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TITLEBARWIDGET_H
