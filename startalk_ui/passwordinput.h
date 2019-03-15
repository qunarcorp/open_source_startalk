#ifndef PASSWORDINPUT_H
#define PASSWORDINPUT_H

#include <QWidget>
#include "LocalManDialog.h"
#include "ui_passwordinput.h"

class PasswordInput : public LocalManDialog
{
    Q_OBJECT

private:
    PasswordInput(LocalManDialog *parent = 0);
    ~PasswordInput();
public:
    static PasswordInput* getInstance() {
        if (instalce==NULL)
        {
            instalce = new PasswordInput(NULL);
        }
        return instalce;
    };
    void onJoin(bool);
    inline QString getPassword() { return ui.lineEdit->text();};
public slots:
    void onClose(bool);
private:
    Ui::PasswordInput ui;
    static PasswordInput* instalce;
};

#endif // PASSWORDINPUT_H
