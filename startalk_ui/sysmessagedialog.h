#ifndef SYSMESSAGEDIALOG_H
#define SYSMESSAGEDIALOG_H

#include "ui_sysmessagedialog.h"
#include "LocalManDialog.h"

namespace Biz
{
    class XmppMessage;
}

class SysMessageDialog : public LocalManDialog
{
    Q_OBJECT

public:
    SysMessageDialog(QWidget *parent = 0);
    ~SysMessageDialog();
    void setMessage( const QSharedPointer<Biz::XmppMessage>& msg);
public slots:
    void onClosed(bool);
private:
    Ui::SysMessageDialog ui;
};

#endif // SYSMESSAGEDIALOG_H
