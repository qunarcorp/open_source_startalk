#ifndef DEMODIALOG_H
#define DEMODIALOG_H

#include <QWidget>
#include "ui_DemoDialog.h"

class DemoDialog : public QWidget
{
    Q_OBJECT

public:
    DemoDialog(QWidget *parent = 0);
    ~DemoDialog();

private:
    Ui::DemoDialog ui;
};

#endif // DEMODIALOG_H
