#ifndef GROUPMEMBERINPUT_H
#define GROUPMEMBERINPUT_H

#include <QWidget>
#include "ui_groupmemberinput.h"
#include "LocalManDialog.h"
class GroupMemberInput : public LocalManDialog
{
    Q_OBJECT

public:
    GroupMemberInput(LocalManDialog *parent = 0);
    ~GroupMemberInput();
    inline QStringList getInputUserList() const {return mUserList;};
    inline QMap<QString,QString> getInputUserMap() const {return mUserMap;};
protected:
    void chargeInput();
private:
    Ui::GroupMemberInput ui;
    QStringList mUserList;
    QMap<QString,QString> mUserMap;
};

#endif // GROUPMEMBERINPUT_H
