/********************************************************************************
** Form generated from reading UI file 'FriendsSearcher.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRIENDSSEARCHER_H
#define UI_FRIENDSSEARCHER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "TitlebarWidget.h"
#include "diywidgit/customviews/qimdroplistview.h"

QT_BEGIN_NAMESPACE

class Ui_FriendsSearcher
{
public:
    QHBoxLayout *horizontalLayout_2;
    QWidget *shadowbg;
    QHBoxLayout *horizontalLayout_3;
    QWidget *shadowinnerbg;
    QVBoxLayout *verticalLayout_5;
    TitlebarWidget *titlebar;
    QWidget *rightpanel;
    QVBoxLayout *verticalLayout_3;
    QWidget *lineEditPanel;
    QVBoxLayout *verticalLayout_4;
    QIMDropListView *dropView;
    QHBoxLayout *horizontalLayout;
    QLineEdit *lineEdit;
    QPushButton *goSearch;
    QWidget *widget;
    QVBoxLayout *verticalLayout_6;
    QStackedWidget *levelStacked;
    QWidget *empty;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QSpacerItem *verticalSpacer;
    QWidget *listpage;
    QVBoxLayout *verticalLayout_2;
    QListWidget *listWidget;

    void setupUi(QWidget *FriendsSearcher)
    {
        if (FriendsSearcher->objectName().isEmpty())
            FriendsSearcher->setObjectName(QStringLiteral("FriendsSearcher"));
        FriendsSearcher->resize(300, 490);
        FriendsSearcher->setMinimumSize(QSize(300, 400));
        FriendsSearcher->setMaximumSize(QSize(300, 16777215));
        FriendsSearcher->setStyleSheet(QStringLiteral(""));
        horizontalLayout_2 = new QHBoxLayout(FriendsSearcher);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        shadowbg = new QWidget(FriendsSearcher);
        shadowbg->setObjectName(QStringLiteral("shadowbg"));
        horizontalLayout_3 = new QHBoxLayout(shadowbg);
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(8, 8, 8, 8);
        shadowinnerbg = new QWidget(shadowbg);
        shadowinnerbg->setObjectName(QStringLiteral("shadowinnerbg"));
        verticalLayout_5 = new QVBoxLayout(shadowinnerbg);
        verticalLayout_5->setSpacing(0);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(1, 1, 1, 1);
        titlebar = new TitlebarWidget(shadowinnerbg);
        titlebar->setObjectName(QStringLiteral("titlebar"));
        titlebar->setStyleSheet(QStringLiteral(""));

        verticalLayout_5->addWidget(titlebar);

        rightpanel = new QWidget(shadowinnerbg);
        rightpanel->setObjectName(QStringLiteral("rightpanel"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(rightpanel->sizePolicy().hasHeightForWidth());
        rightpanel->setSizePolicy(sizePolicy);
        rightpanel->setMinimumSize(QSize(0, 0));
        rightpanel->setMaximumSize(QSize(16777215, 16777215));
        rightpanel->setStyleSheet(QStringLiteral(""));
        verticalLayout_3 = new QVBoxLayout(rightpanel);
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(10, 10, 10, 10);
        lineEditPanel = new QWidget(rightpanel);
        lineEditPanel->setObjectName(QStringLiteral("lineEditPanel"));
        lineEditPanel->setMaximumSize(QSize(16777215, 64));
        verticalLayout_4 = new QVBoxLayout(lineEditPanel);
        verticalLayout_4->setSpacing(5);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        dropView = new QIMDropListView(lineEditPanel);
        dropView->setObjectName(QStringLiteral("dropView"));
        dropView->setMinimumSize(QSize(0, 28));
        dropView->setMaximumSize(QSize(16777215, 28));
        dropView->setSizeIncrement(QSize(0, 28));

        verticalLayout_4->addWidget(dropView);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        lineEdit = new QLineEdit(lineEditPanel);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setMinimumSize(QSize(0, 28));
        lineEdit->setMaximumSize(QSize(16777215, 28));
        lineEdit->setMaxLength(30);

        horizontalLayout->addWidget(lineEdit);

        goSearch = new QPushButton(lineEditPanel);
        goSearch->setObjectName(QStringLiteral("goSearch"));
        goSearch->setMinimumSize(QSize(40, 28));
        goSearch->setMaximumSize(QSize(40, 28));
        goSearch->setAutoDefault(true);
        goSearch->setFlat(true);

        horizontalLayout->addWidget(goSearch);


        verticalLayout_4->addLayout(horizontalLayout);


        verticalLayout_3->addWidget(lineEditPanel);

        widget = new QWidget(rightpanel);
        widget->setObjectName(QStringLiteral("widget"));
        verticalLayout_6 = new QVBoxLayout(widget);
        verticalLayout_6->setSpacing(0);
        verticalLayout_6->setContentsMargins(11, 11, 11, 11);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        verticalLayout_6->setContentsMargins(0, 0, 0, 0);
        levelStacked = new QStackedWidget(widget);
        levelStacked->setObjectName(QStringLiteral("levelStacked"));
        levelStacked->setStyleSheet(QStringLiteral(""));
        empty = new QWidget();
        empty->setObjectName(QStringLiteral("empty"));
        verticalLayout = new QVBoxLayout(empty);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(-1, 100, -1, -1);
        label = new QLabel(empty);
        label->setObjectName(QStringLiteral("label"));
        label->setStyleSheet(QStringLiteral(""));
        label->setTextFormat(Qt::RichText);
        label->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        levelStacked->addWidget(empty);
        listpage = new QWidget();
        listpage->setObjectName(QStringLiteral("listpage"));
        verticalLayout_2 = new QVBoxLayout(listpage);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        listWidget = new QListWidget(listpage);
        listWidget->setObjectName(QStringLiteral("listWidget"));

        verticalLayout_2->addWidget(listWidget);

        levelStacked->addWidget(listpage);

        verticalLayout_6->addWidget(levelStacked);


        verticalLayout_3->addWidget(widget);


        verticalLayout_5->addWidget(rightpanel);


        horizontalLayout_3->addWidget(shadowinnerbg);


        horizontalLayout_2->addWidget(shadowbg);


        retranslateUi(FriendsSearcher);

        levelStacked->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(FriendsSearcher);
    } // setupUi

    void retranslateUi(QWidget *FriendsSearcher)
    {
        FriendsSearcher->setWindowTitle(QApplication::translate("FriendsSearcher", "FriendsSearcher", 0));
        lineEdit->setText(QString());
        lineEdit->setPlaceholderText(QApplication::translate("FriendsSearcher", "\346\220\234\347\264\242\346\211\213\346\234\272\345\217\267\343\200\201\351\202\256\347\256\261\343\200\201ID ...", 0));
        goSearch->setText(QApplication::translate("FriendsSearcher", "\346\220\234\347\264\242", 0));
        label->setText(QApplication::translate("FriendsSearcher", "\347\251\272\357\274\214\347\251\272\347\251\272...\345\246\202\344\271\237", 0));
    } // retranslateUi

};

namespace Ui {
    class FriendsSearcher: public Ui_FriendsSearcher {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRIENDSSEARCHER_H
