/********************************************************************************
** Form generated from reading UI file 'presencechangewidget.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PRESENCECHANGEWIDGET_H
#define UI_PRESENCECHANGEWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PresenceChangeWidget
{
public:
    QToolButton *busy;
    QToolButton *away;
    QToolButton *online;

    void setupUi(QWidget *PresenceChangeWidget)
    {
        if (PresenceChangeWidget->objectName().isEmpty())
            PresenceChangeWidget->setObjectName(QStringLiteral("PresenceChangeWidget"));
        PresenceChangeWidget->resize(100, 61);
        PresenceChangeWidget->setMinimumSize(QSize(100, 60));
        PresenceChangeWidget->setStyleSheet(QLatin1String("\n"
"\n"
"QWidget\n"
"{\n"
"border: 1px solid 000000;\n"
"}\n"
"QToolButton{\n"
"	color:000000;\n"
"	background:#FFFFFF;\n"
"	border:none;\n"
"}\n"
""));
        busy = new QToolButton(PresenceChangeWidget);
        busy->setObjectName(QStringLiteral("busy"));
        busy->setGeometry(QRect(0, 40, 100, 20));
        busy->setMinimumSize(QSize(100, 20));
        busy->setStyleSheet(QLatin1String("QToolButton{\n"
"	background:#FFFFFF;\n"
"border:none;\n"
"}"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/Images/presence_busy.png"), QSize(), QIcon::Normal, QIcon::Off);
        busy->setIcon(icon);
        busy->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        away = new QToolButton(PresenceChangeWidget);
        away->setObjectName(QStringLiteral("away"));
        away->setGeometry(QRect(0, 20, 100, 20));
        away->setMinimumSize(QSize(100, 20));
        away->setStyleSheet(QLatin1String("QToolButton{\n"
"	background:#FFFFFF;\n"
"border:none;\n"
"}\n"
""));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/Images/presence_away.png"), QSize(), QIcon::Normal, QIcon::Off);
        away->setIcon(icon1);
        away->setPopupMode(QToolButton::DelayedPopup);
        away->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        away->setAutoRaise(false);
        online = new QToolButton(PresenceChangeWidget);
        online->setObjectName(QStringLiteral("online"));
        online->setGeometry(QRect(0, 0, 100, 20));
        online->setMinimumSize(QSize(100, 20));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/Images/presence_online.png"), QSize(), QIcon::Normal, QIcon::Off);
        online->setIcon(icon2);
        online->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

        retranslateUi(PresenceChangeWidget);

        QMetaObject::connectSlotsByName(PresenceChangeWidget);
    } // setupUi

    void retranslateUi(QWidget *PresenceChangeWidget)
    {
        PresenceChangeWidget->setWindowTitle(QApplication::translate("PresenceChangeWidget", "PresenceChangeWidget", 0));
        busy->setText(QApplication::translate("PresenceChangeWidget", "\347\271\201\345\277\231", 0));
        away->setText(QApplication::translate("PresenceChangeWidget", "\347\246\273\345\274\200", 0));
        online->setText(QApplication::translate("PresenceChangeWidget", "\345\234\250\347\272\277", 0));
    } // retranslateUi

};

namespace Ui {
    class PresenceChangeWidget: public Ui_PresenceChangeWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PRESENCECHANGEWIDGET_H
