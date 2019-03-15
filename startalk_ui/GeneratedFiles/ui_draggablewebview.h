/********************************************************************************
** Form generated from reading UI file 'draggablewebview.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DRAGGABLEWEBVIEW_H
#define UI_DRAGGABLEWEBVIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <webview.h>

QT_BEGIN_NAMESPACE

class Ui_DraggableWebView
{
public:

    void setupUi(webview *DraggableWebView)
    {
        if (DraggableWebView->objectName().isEmpty())
            DraggableWebView->setObjectName(QStringLiteral("DraggableWebView"));
        DraggableWebView->resize(400, 300);

        retranslateUi(DraggableWebView);

        QMetaObject::connectSlotsByName(DraggableWebView);
    } // setupUi

    void retranslateUi(webview *DraggableWebView)
    {
        DraggableWebView->setWindowTitle(QApplication::translate("DraggableWebView", "DraggableWebView", 0));
    } // retranslateUi

};

namespace Ui {
    class DraggableWebView: public Ui_DraggableWebView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DRAGGABLEWEBVIEW_H
