/********************************************************************************
** Form generated from reading UI file 'moreselectionpanel.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MORESELECTIONPANEL_H
#define UI_MORESELECTIONPANEL_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MoreSelectionPanel
{
public:
    QHBoxLayout *horizontalLayout;
    QWidget *widgetBorder;
    QHBoxLayout *horizontalLayout_2;
    QWidget *content;
    QVBoxLayout *verticalLayout;
    QWidget *row_0;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *setting;
    QPushButton *version;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *MoreSelectionPanel)
    {
        if (MoreSelectionPanel->objectName().isEmpty())
            MoreSelectionPanel->setObjectName(QStringLiteral("MoreSelectionPanel"));
        MoreSelectionPanel->resize(142, 142);
        horizontalLayout = new QHBoxLayout(MoreSelectionPanel);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        widgetBorder = new QWidget(MoreSelectionPanel);
        widgetBorder->setObjectName(QStringLiteral("widgetBorder"));
        horizontalLayout_2 = new QHBoxLayout(widgetBorder);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        content = new QWidget(widgetBorder);
        content->setObjectName(QStringLiteral("content"));
        content->setMinimumSize(QSize(142, 142));
        verticalLayout = new QVBoxLayout(content);
        verticalLayout->setSpacing(0);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        row_0 = new QWidget(content);
        row_0->setObjectName(QStringLiteral("row_0"));
        horizontalLayout_3 = new QHBoxLayout(row_0);
        horizontalLayout_3->setSpacing(10);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(16, 16, 16, 16);
        setting = new QPushButton(row_0);
        setting->setObjectName(QStringLiteral("setting"));
        setting->setMinimumSize(QSize(50, 50));
        setting->setMaximumSize(QSize(50, 50));
        setting->setFlat(true);

        horizontalLayout_3->addWidget(setting);

        version = new QPushButton(row_0);
        version->setObjectName(QStringLiteral("version"));
        version->setMinimumSize(QSize(50, 50));
        version->setMaximumSize(QSize(50, 50));
        version->setFlat(true);

        horizontalLayout_3->addWidget(version);


        verticalLayout->addWidget(row_0);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        horizontalLayout_2->addWidget(content);


        horizontalLayout->addWidget(widgetBorder);


        retranslateUi(MoreSelectionPanel);

        QMetaObject::connectSlotsByName(MoreSelectionPanel);
    } // setupUi

    void retranslateUi(QWidget *MoreSelectionPanel)
    {
        MoreSelectionPanel->setWindowTitle(QApplication::translate("MoreSelectionPanel", "MoreSelectionPanel", 0));
        setting->setText(QString());
        version->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MoreSelectionPanel: public Ui_MoreSelectionPanel {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MORESELECTIONPANEL_H
