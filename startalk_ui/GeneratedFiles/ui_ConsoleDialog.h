/********************************************************************************
** Form generated from reading UI file 'ConsoleDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONSOLEDIALOG_H
#define UI_CONSOLEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ConsoleDialog
{
public:
    QVBoxLayout *verticalLayout;
    QTabWidget *tabWidget;
    QWidget *xmpp;
    QHBoxLayout *horizontalLayout_2;
    QTextBrowser *xmppLogger;
    QWidget *log;
    QHBoxLayout *horizontalLayout_3;
    QTextBrowser *logLogger;
    QWidget *all;
    QHBoxLayout *horizontalLayout_4;
    QTextBrowser *allLogger;
    QWidget *statusbar;
    QHBoxLayout *horizontalLayout;
    QLabel *textLabel;
    QSpacerItem *horizontalSpacer;
    QPushButton *clear;
    QPushButton *hidedialog;

    void setupUi(QDialog *ConsoleDialog)
    {
        if (ConsoleDialog->objectName().isEmpty())
            ConsoleDialog->setObjectName(QStringLiteral("ConsoleDialog"));
        ConsoleDialog->resize(650, 300);
        ConsoleDialog->setMinimumSize(QSize(650, 300));
        ConsoleDialog->setMaximumSize(QSize(650, 300));
        verticalLayout = new QVBoxLayout(ConsoleDialog);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        tabWidget = new QTabWidget(ConsoleDialog);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        xmpp = new QWidget();
        xmpp->setObjectName(QStringLiteral("xmpp"));
        horizontalLayout_2 = new QHBoxLayout(xmpp);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        xmppLogger = new QTextBrowser(xmpp);
        xmppLogger->setObjectName(QStringLiteral("xmppLogger"));

        horizontalLayout_2->addWidget(xmppLogger);

        tabWidget->addTab(xmpp, QString());
        log = new QWidget();
        log->setObjectName(QStringLiteral("log"));
        horizontalLayout_3 = new QHBoxLayout(log);
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        logLogger = new QTextBrowser(log);
        logLogger->setObjectName(QStringLiteral("logLogger"));

        horizontalLayout_3->addWidget(logLogger);

        tabWidget->addTab(log, QString());
        all = new QWidget();
        all->setObjectName(QStringLiteral("all"));
        horizontalLayout_4 = new QHBoxLayout(all);
        horizontalLayout_4->setSpacing(0);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        allLogger = new QTextBrowser(all);
        allLogger->setObjectName(QStringLiteral("allLogger"));

        horizontalLayout_4->addWidget(allLogger);

        tabWidget->addTab(all, QString());

        verticalLayout->addWidget(tabWidget);

        statusbar = new QWidget(ConsoleDialog);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        statusbar->setMinimumSize(QSize(0, 45));
        statusbar->setMaximumSize(QSize(16777215, 45));
        horizontalLayout = new QHBoxLayout(statusbar);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        textLabel = new QLabel(statusbar);
        textLabel->setObjectName(QStringLiteral("textLabel"));

        horizontalLayout->addWidget(textLabel);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        clear = new QPushButton(statusbar);
        clear->setObjectName(QStringLiteral("clear"));

        horizontalLayout->addWidget(clear);

        hidedialog = new QPushButton(statusbar);
        hidedialog->setObjectName(QStringLiteral("hidedialog"));

        horizontalLayout->addWidget(hidedialog);


        verticalLayout->addWidget(statusbar);


        retranslateUi(ConsoleDialog);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(ConsoleDialog);
    } // setupUi

    void retranslateUi(QDialog *ConsoleDialog)
    {
        ConsoleDialog->setWindowTitle(QApplication::translate("ConsoleDialog", "ConsoleDialog", 0));
        tabWidget->setTabText(tabWidget->indexOf(xmpp), QApplication::translate("ConsoleDialog", "Xmpp", 0));
        tabWidget->setTabText(tabWidget->indexOf(log), QApplication::translate("ConsoleDialog", "Log", 0));
        tabWidget->setTabText(tabWidget->indexOf(all), QApplication::translate("ConsoleDialog", "All", 0));
        textLabel->setText(QApplication::translate("ConsoleDialog", "TextLabel", 0));
        clear->setText(QApplication::translate("ConsoleDialog", "PushButton", 0));
        hidedialog->setText(QApplication::translate("ConsoleDialog", "PushButton", 0));
    } // retranslateUi

};

namespace Ui {
    class ConsoleDialog: public Ui_ConsoleDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONSOLEDIALOG_H
