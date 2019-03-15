#ifndef ABOUTDIALOG_H
#define ABOUTDIALOG_H

#include "LocalManDialog.h"
#include "ui_AboutDialog.h"

class AboutDialog : public LocalManDialog
{
    Q_OBJECT

public:
    AboutDialog(QDialog *parent = 0);
    ~AboutDialog();
private slots:
        void onClose(bool);

private:
    Ui::AboutDialog ui;
};

#endif // ABOUTDIALOG_H
