#pragma once

#include "diywidgit/customviews/pinnedlistview.h"

namespace Biz{
    class WechatUser;
}
class WechatUserListView : public PinnedListView{
    Q_OBJECT
public:
    WechatUserListView(QWidget* parent) : PinnedListView(parent){};
    ~WechatUserListView(){};
public:
    void setWechatUserInfo(Biz::WechatUser* pUser);
    QString getChannelId(const QString& conversationID);
private:
    QMap<QString,QString> m_channelids;
};