/********************************************************************************
** Form generated from reading UI file 'DealMessageBox.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DEALMESSAGEBOX_H
#define UI_DEALMESSAGEBOX_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <TitlebarWidget.h>

QT_BEGIN_NAMESPACE

class Ui_DealMessageBox
{
public:
    QVBoxLayout *verticalLayout_2;
    QWidget *shadowbg;
    QVBoxLayout *verticalLayout_5;
    QWidget *shadowinnerbg;
    QVBoxLayout *verticalLayout;
    TitlebarWidget *titlebar;
    QWidget *wid_mid;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_3;
    QLabel *label_2;
    QWidget *wid_bottom;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *confirm;
    QPushButton *cancel;

    void setupUi(QWidget *DealMessageBox)
    {
        if (DealMessageBox->objectName().isEmpty())
            DealMessageBox->setObjectName(QStringLiteral("DealMessageBox"));
        DealMessageBox->resize(316, 186);
        DealMessageBox->setStyleSheet(QLatin1String("\n"
"#DealMessageBox QPushButton#cancel{border-radius:3px;border:1px solid #1BA9BA;background:#00000000;color:#1BA9BA;}\n"
"\n"
"#DealMessageBox QPushButton#confirm{border-radius:3px;border:none;background:#1BA9BA;color:#FFFFFF;}"));
        verticalLayout_2 = new QVBoxLayout(DealMessageBox);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        shadowbg = new QWidget(DealMessageBox);
        shadowbg->setObjectName(QStringLiteral("shadowbg"));
        verticalLayout_5 = new QVBoxLayout(shadowbg);
        verticalLayout_5->setSpacing(0);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(8, 8, 8, 8);
        shadowinnerbg = new QWidget(shadowbg);
        shadowinnerbg->setObjectName(QStringLiteral("shadowinnerbg"));
        shadowinnerbg->setMinimumSize(QSize(300, 170));
        shadowinnerbg->setMaximumSize(QSize(300, 170));
        verticalLayout = new QVBoxLayout(shadowinnerbg);
        verticalLayout->setSpacing(0);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        titlebar = new TitlebarWidget(shadowinnerbg);
        titlebar->setObjectName(QStringLiteral("titlebar"));
        titlebar->setMaximumSize(QSize(16777215, 27));

        verticalLayout->addWidget(titlebar);

        wid_mid = new QWidget(shadowinnerbg);
        wid_mid->setObjectName(QStringLiteral("wid_mid"));
        wid_mid->setStyleSheet(QStringLiteral(""));
        horizontalLayout_2 = new QHBoxLayout(wid_mid);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(20, 0, 12, 0);
        label_3 = new QLabel(wid_mid);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setMinimumSize(QSize(50, 50));
        label_3->setMaximumSize(QSize(50, 50));
        label_3->setPixmap(QPixmap(QString::fromUtf8(":/Images/MB_Warning.png")));
        label_3->setScaledContents(true);

        horizontalLayout_2->addWidget(label_3);

        label_2 = new QLabel(wid_mid);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setWordWrap(true);
        label_2->setIndent(16);
        label_2->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);

        horizontalLayout_2->addWidget(label_2);


        verticalLayout->addWidget(wid_mid);

        wid_bottom = new QWidget(shadowinnerbg);
        wid_bottom->setObjectName(QStringLiteral("wid_bottom"));
        wid_bottom->setMinimumSize(QSize(0, 40));
        wid_bottom->setMaximumSize(QSize(16777215, 40));
        horizontalLayout = new QHBoxLayout(wid_bottom);
        horizontalLayout->setSpacing(8);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 10, 10);
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        confirm = new QPushButton(wid_bottom);
        confirm->setObjectName(QStringLiteral("confirm"));
        confirm->setMinimumSize(QSize(62, 22));
        confirm->setMaximumSize(QSize(62, 22));
        confirm->setFlat(true);

        horizontalLayout->addWidget(confirm);

        cancel = new QPushButton(wid_bottom);
        cancel->setObjectName(QStringLiteral("cancel"));
        cancel->setMinimumSize(QSize(62, 22));
        cancel->setMaximumSize(QSize(62, 22));
        cancel->setDefault(true);
        cancel->setFlat(true);

        horizontalLayout->addWidget(cancel);


        verticalLayout->addWidget(wid_bottom);


        verticalLayout_5->addWidget(shadowinnerbg);


        verticalLayout_2->addWidget(shadowbg);


        retranslateUi(DealMessageBox);

        QMetaObject::connectSlotsByName(DealMessageBox);
    } // setupUi

    void retranslateUi(QWidget *DealMessageBox)
    {
        DealMessageBox->setWindowTitle(QApplication::translate("DealMessageBox", "DealMessageBox", 0));
        label_3->setText(QString());
        label_2->setText(QString());
        confirm->setText(QString());
        cancel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class DealMessageBox: public Ui_DealMessageBox {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DEALMESSAGEBOX_H
