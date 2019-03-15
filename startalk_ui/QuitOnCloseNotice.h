#ifndef QUITONCLOSENOTICE_H
#define QUITONCLOSENOTICE_H

#include <QWidget>
#include "ui_QuitOnCloseNotice.h"
#include "LocalManDialog.h"
class QuitOnCloseNotice : public LocalManDialog
{
    Q_OBJECT

public:
    QuitOnCloseNotice(QWidget *parent = 0);
    ~QuitOnCloseNotice();

private:
    Ui::QuitOnCloseNotice ui;
};

#endif // QUITONCLOSENOTICE_H
