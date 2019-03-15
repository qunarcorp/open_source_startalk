/********************************************************************************
** Form generated from reading UI file 'rostertreeview.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ROSTERTREEVIEW_H
#define UI_ROSTERTREEVIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTreeView>

QT_BEGIN_NAMESPACE

class Ui_RosterTreeView
{
public:

    void setupUi(QTreeView *RosterTreeView)
    {
        if (RosterTreeView->objectName().isEmpty())
            RosterTreeView->setObjectName(QStringLiteral("RosterTreeView"));
        RosterTreeView->resize(400, 300);
        if (RosterTreeView->header()->objectName().isEmpty())

        retranslateUi(RosterTreeView);

        QMetaObject::connectSlotsByName(RosterTreeView);
    } // setupUi

    void retranslateUi(QTreeView *RosterTreeView)
    {
        RosterTreeView->setWindowTitle(QApplication::translate("RosterTreeView", "RosterTreeView", 0));
    } // retranslateUi

};

namespace Ui {
    class RosterTreeView: public Ui_RosterTreeView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ROSTERTREEVIEW_H
