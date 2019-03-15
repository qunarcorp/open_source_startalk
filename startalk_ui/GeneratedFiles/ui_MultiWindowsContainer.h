/********************************************************************************
** Form generated from reading UI file 'MultiWindowsContainer.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MULTIWINDOWSCONTAINER_H
#define UI_MULTIWINDOWSCONTAINER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListView>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MultiDialogContainer
{
public:
    QVBoxLayout *verticalLayout_2;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QWidget *titlebar;
    QWidget *widget_3;
    QHBoxLayout *horizontalLayout;
    QWidget *widget_2;
    QVBoxLayout *verticalLayout_3;
    QLineEdit *lineEdit;
    QListView *listView;
    QWidget *widget_5;
    QLabel *label;
    QWidget *widget_4;
    QHBoxLayout *horizontalLayout_2;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QWidget *page_2;

    void setupUi(QWidget *MultiDialogContainer)
    {
        if (MultiDialogContainer->objectName().isEmpty())
            MultiDialogContainer->setObjectName(QStringLiteral("MultiDialogContainer"));
        MultiDialogContainer->resize(1080, 750);
        MultiDialogContainer->setMinimumSize(QSize(1080, 750));
        MultiDialogContainer->setStyleSheet(QStringLiteral(""));
        verticalLayout_2 = new QVBoxLayout(MultiDialogContainer);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 1, 0);
        widget = new QWidget(MultiDialogContainer);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setStyleSheet(QStringLiteral(""));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setSpacing(0);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        titlebar = new QWidget(widget);
        titlebar->setObjectName(QStringLiteral("titlebar"));
        titlebar->setMinimumSize(QSize(0, 30));
        titlebar->setMaximumSize(QSize(16777215, 30));

        verticalLayout->addWidget(titlebar);

        widget_3 = new QWidget(widget);
        widget_3->setObjectName(QStringLiteral("widget_3"));
        horizontalLayout = new QHBoxLayout(widget_3);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        widget_2 = new QWidget(widget_3);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        widget_2->setMinimumSize(QSize(290, 0));
        widget_2->setMaximumSize(QSize(290, 16777215));
        widget_2->setStyleSheet(QStringLiteral("margin: 0px 2px;"));
        verticalLayout_3 = new QVBoxLayout(widget_2);
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        lineEdit = new QLineEdit(widget_2);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setMinimumSize(QSize(0, 35));
        lineEdit->setStyleSheet(QStringLiteral("margin: 5px 0px"));

        verticalLayout_3->addWidget(lineEdit);

        listView = new QListView(widget_2);
        listView->setObjectName(QStringLiteral("listView"));
        listView->setStyleSheet(QStringLiteral("border: none;"));

        verticalLayout_3->addWidget(listView);

        widget_5 = new QWidget(widget_2);
        widget_5->setObjectName(QStringLiteral("widget_5"));
        widget_5->setMinimumSize(QSize(0, 40));
        widget_5->setMaximumSize(QSize(40, 16777215));

        verticalLayout_3->addWidget(widget_5);


        horizontalLayout->addWidget(widget_2);

        label = new QLabel(widget_3);
        label->setObjectName(QStringLiteral("label"));
        label->setMinimumSize(QSize(1, 0));
        label->setMaximumSize(QSize(1, 16777215));
        label->setStyleSheet(QStringLiteral("background-color: #c7ced4; "));

        horizontalLayout->addWidget(label);

        widget_4 = new QWidget(widget_3);
        widget_4->setObjectName(QStringLiteral("widget_4"));
        horizontalLayout_2 = new QHBoxLayout(widget_4);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        stackedWidget = new QStackedWidget(widget_4);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        page = new QWidget();
        page->setObjectName(QStringLiteral("page"));
        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QStringLiteral("page_2"));
        stackedWidget->addWidget(page_2);

        horizontalLayout_2->addWidget(stackedWidget);

        widget_2->raise();
        stackedWidget->raise();

        horizontalLayout->addWidget(widget_4);


        verticalLayout->addWidget(widget_3);


        verticalLayout_2->addWidget(widget);


        retranslateUi(MultiDialogContainer);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MultiDialogContainer);
    } // setupUi

    void retranslateUi(QWidget *MultiDialogContainer)
    {
        MultiDialogContainer->setWindowTitle(QApplication::translate("MultiDialogContainer", "TitlebarWidget", 0));
        label->setText(QApplication::translate("MultiDialogContainer", "TextLabel", 0));
    } // retranslateUi

};

namespace Ui {
    class MultiDialogContainer: public Ui_MultiDialogContainer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MULTIWINDOWSCONTAINER_H
