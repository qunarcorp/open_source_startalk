/********************************************************************************
** Form generated from reading UI file 'createnewgroupp2.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATENEWGROUPP2_H
#define UI_CREATENEWGROUPP2_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CreateNewGroupP2
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QWidget *transBorder;
    QWidget *dialogbg;
    QVBoxLayout *verticalLayout_2;
    QWidget *widget_3;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QSpacerItem *horizontalSpacer;
    QPushButton *close;
    QWidget *widget_4;
    QLineEdit *groupnameinput;
    QLabel *label_2;
    QLabel *label_3;
    QCheckBox *hidegroup;
    QCheckBox *linshi;
    QCheckBox *pwdenable;
    QLineEdit *pwdinput;
    QCheckBox *showpwd;
    QLabel *label_4;
    QComboBox *maxcount;
    QCheckBox *modegrouptip;
    QTextEdit *textEdit;
    QWidget *widget_5;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *fixmember;
    QPushButton *docreate;

    void setupUi(QWidget *CreateNewGroupP2)
    {
        if (CreateNewGroupP2->objectName().isEmpty())
            CreateNewGroupP2->setObjectName(QStringLiteral("CreateNewGroupP2"));
        CreateNewGroupP2->resize(752, 550);
        CreateNewGroupP2->setStyleSheet(QString::fromUtf8("QWidget{\n"
"    font-family:\345\276\256\350\275\257\351\233\205\351\273\221;\n"
"}\n"
"QWidget#leftPanel{\n"
"    background-color:#EAEBED;\n"
"}\n"
"QWidget#rightPanel{\n"
"\n"
"    background-color:#FFFFFF;\n"
"}\n"
"QTreeWidget,QListWidget{\n"
"    border:none;\n"
"    background-color:#00000000;\n"
"}\n"
"QTreeWidget::branch{\n"
"	border-image:none;\n"
"	image:none;\n"
"}\n"
"\n"
"QLineEdit#searchEdit{\n"
"    padding-left:20px;\n"
"    border:1px solid #FFFFFF;\n"
"    border-radius: 13px;\n"
"}\n"
"\n"
"QLabel{\n"
"    color:#666666;\n"
"}\n"
"\n"
"QPushButton#docreate,#fixmember{\n"
"    border-radius: 2px;\n"
"    color:#FFFFFF;\n"
"    background-color:#3DCE3D;\n"
"}\n"
"QPushButton#docreate:disabled,#fixmember:disabled{\n"
"    background-color:#9DE69D;\n"
"}\n"
"QPushButton#docreate:hover,#fixmember:hover{\n"
"    background-color:#38C738;\n"
"}\n"
"QPushButton#docreate:pressed,#fixmember:pressed{\n"
"    background-color:#2FB82F;\n"
"}\n"
"\n"
"\n"
"QPushButton#close{\n"
"	border:1px solid #00000"
                        "000;\n"
"	image:url(:/Images/close.png);\n"
"}\n"
"QPushButton#close:hover{\n"
"	image:url(:/Images/close-hover.png);\n"
"}\n"
"QPushButton#close:pressed{\n"
"	image:url(:/Images/close-down.png);\n"
"}\n"
"\n"
"QWidget#transBorder{\n"
"    background: qlineargradient(x1: 0, y1: 0, x2: 1, y2: 0,\n"
"                                 stop: 0 #60000000, stop: 1.0 #C0000000);\n"
"}\n"
"\n"
"\n"
"\n"
"QLineEdit#pwdinput{\n"
"	border-radius: 2px;\n"
"	background-color:#FFFFFF;\n"
"}\n"
"\n"
"QLineEdit#pwdinput:disabled{\n"
"	border-radius: 2px;\n"
"	background-color:#ECECEC;\n"
"}"));
        verticalLayout = new QVBoxLayout(CreateNewGroupP2);
        verticalLayout->setSpacing(0);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        widget = new QWidget(CreateNewGroupP2);
        widget->setObjectName(QStringLiteral("widget"));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        transBorder = new QWidget(widget);
        transBorder->setObjectName(QStringLiteral("transBorder"));
        transBorder->setMinimumSize(QSize(250, 0));
        transBorder->setMaximumSize(QSize(250, 16777215));

        horizontalLayout->addWidget(transBorder);

        dialogbg = new QWidget(widget);
        dialogbg->setObjectName(QStringLiteral("dialogbg"));
        dialogbg->setMaximumSize(QSize(16777215, 16777215));
        verticalLayout_2 = new QVBoxLayout(dialogbg);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        widget_3 = new QWidget(dialogbg);
        widget_3->setObjectName(QStringLiteral("widget_3"));
        widget_3->setMinimumSize(QSize(0, 40));
        widget_3->setMaximumSize(QSize(16777215, 40));
        horizontalLayout_2 = new QHBoxLayout(widget_3);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(20, 0, 20, 0);
        label = new QLabel(widget_3);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout_2->addWidget(label);

        horizontalSpacer = new QSpacerItem(355, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        close = new QPushButton(widget_3);
        close->setObjectName(QStringLiteral("close"));
        close->setMinimumSize(QSize(20, 20));
        close->setMaximumSize(QSize(20, 20));
        close->setFlat(true);

        horizontalLayout_2->addWidget(close);


        verticalLayout_2->addWidget(widget_3);

        widget_4 = new QWidget(dialogbg);
        widget_4->setObjectName(QStringLiteral("widget_4"));
        groupnameinput = new QLineEdit(widget_4);
        groupnameinput->setObjectName(QStringLiteral("groupnameinput"));
        groupnameinput->setGeometry(QRect(100, 64, 311, 26));
        groupnameinput->setStyleSheet(QStringLiteral("background-color:#FFFFFF;border-radius:2px"));
        label_2 = new QLabel(widget_4);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(30, 70, 54, 12));
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_3 = new QLabel(widget_4);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(30, 110, 54, 12));
        label_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        hidegroup = new QCheckBox(widget_4);
        hidegroup->setObjectName(QStringLiteral("hidegroup"));
        hidegroup->setGeometry(QRect(60, 316, 71, 16));
        linshi = new QCheckBox(widget_4);
        linshi->setObjectName(QStringLiteral("linshi"));
        linshi->setGeometry(QRect(160, 316, 71, 16));
        pwdenable = new QCheckBox(widget_4);
        pwdenable->setObjectName(QStringLiteral("pwdenable"));
        pwdenable->setGeometry(QRect(60, 356, 71, 16));
        pwdinput = new QLineEdit(widget_4);
        pwdinput->setObjectName(QStringLiteral("pwdinput"));
        pwdinput->setEnabled(true);
        pwdinput->setGeometry(QRect(128, 355, 120, 20));
        pwdinput->setStyleSheet(QStringLiteral(""));
        showpwd = new QCheckBox(widget_4);
        showpwd->setObjectName(QStringLiteral("showpwd"));
        showpwd->setGeometry(QRect(277, 356, 81, 16));
        label_4 = new QLabel(widget_4);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(11, 256, 71, 16));
        label_4->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        maxcount = new QComboBox(widget_4);
        maxcount->setObjectName(QStringLiteral("maxcount"));
        maxcount->setGeometry(QRect(100, 256, 141, 22));
        modegrouptip = new QCheckBox(widget_4);
        modegrouptip->setObjectName(QStringLiteral("modegrouptip"));
        modegrouptip->setGeometry(QRect(60, 406, 311, 16));
        modegrouptip->setChecked(true);
        textEdit = new QTextEdit(widget_4);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setGeometry(QRect(100, 110, 311, 81));
        textEdit->setStyleSheet(QStringLiteral("background-color:#FFFFFF;border-radius:2px"));

        verticalLayout_2->addWidget(widget_4);

        widget_5 = new QWidget(dialogbg);
        widget_5->setObjectName(QStringLiteral("widget_5"));
        widget_5->setMinimumSize(QSize(0, 40));
        widget_5->setMaximumSize(QSize(16777215, 40));
        horizontalLayout_3 = new QHBoxLayout(widget_5);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 20, 0);
        horizontalSpacer_2 = new QSpacerItem(317, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);

        fixmember = new QPushButton(widget_5);
        fixmember->setObjectName(QStringLiteral("fixmember"));
        fixmember->setMinimumSize(QSize(90, 26));
        fixmember->setFlat(true);

        horizontalLayout_3->addWidget(fixmember);

        docreate = new QPushButton(widget_5);
        docreate->setObjectName(QStringLiteral("docreate"));
        docreate->setEnabled(false);
        docreate->setMinimumSize(QSize(60, 26));
        docreate->setFlat(true);

        horizontalLayout_3->addWidget(docreate);


        verticalLayout_2->addWidget(widget_5);


        horizontalLayout->addWidget(dialogbg);


        verticalLayout->addWidget(widget);


        retranslateUi(CreateNewGroupP2);

        QMetaObject::connectSlotsByName(CreateNewGroupP2);
    } // setupUi

    void retranslateUi(QWidget *CreateNewGroupP2)
    {
        CreateNewGroupP2->setWindowTitle(QApplication::translate("CreateNewGroupP2", "CreateNewGroupP2", 0));
        label->setText(QApplication::translate("CreateNewGroupP2", "\350\257\267\345\241\253\345\206\231\347\276\244\350\265\204\346\226\231", 0));
        close->setText(QString());
        label_2->setText(QApplication::translate("CreateNewGroupP2", "\347\276\244\345\220\215", 0));
        label_3->setText(QApplication::translate("CreateNewGroupP2", "\347\276\244\345\205\254\345\221\212", 0));
        hidegroup->setText(QApplication::translate("CreateNewGroupP2", "\351\232\220\350\227\217\347\276\244\347\273\204", 0));
        linshi->setText(QApplication::translate("CreateNewGroupP2", "\344\270\264\346\227\266\347\276\244\347\273\204", 0));
        pwdenable->setText(QApplication::translate("CreateNewGroupP2", "\345\257\206\347\240\201", 0));
        showpwd->setText(QApplication::translate("CreateNewGroupP2", "\346\230\276\347\244\272\345\257\206\347\240\201", 0));
        label_4->setText(QApplication::translate("CreateNewGroupP2", "\346\234\200\345\244\247\347\224\250\346\210\267\346\225\260", 0));
        modegrouptip->setText(QApplication::translate("CreateNewGroupP2", "\346\230\257\345\220\246\346\210\220\345\221\230\345\217\257\344\273\245\344\277\256\346\224\271\347\276\244\345\205\254\345\221\212", 0));
        fixmember->setText(QApplication::translate("CreateNewGroupP2", "\344\277\256\346\224\271\347\276\244\346\210\220\345\221\230", 0));
        docreate->setText(QApplication::translate("CreateNewGroupP2", "\345\210\233\345\273\272\347\276\244", 0));
    } // retranslateUi

};

namespace Ui {
    class CreateNewGroupP2: public Ui_CreateNewGroupP2 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATENEWGROUPP2_H
