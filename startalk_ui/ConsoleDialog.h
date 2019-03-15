#ifndef CONSOLEDIALOG_H
#define CONSOLEDIALOG_H

#include "CoreObject.h"
#include <QDialog>

namespace Ui{
    class ConsoleDialog;
}

class ConsoleDialog : public QDialog
{
    Q_OBJECT

public:
    ConsoleDialog(QWidget *parent = 0);
    ~ConsoleDialog();

private slots:
    void onDebug(const QString&);
    void onError(const QString&);
    void onInfo(const QString&);
    void onWarn(const QString&);

    void onXmpp(QXmppLogger::MessageType type, const QString& val);

    void onClear();
    void onHide();
private:
    Ui::ConsoleDialog* ui;
    LogWriter* mLogWriter;
};

#endif // CONSOLEDIALOG_H
