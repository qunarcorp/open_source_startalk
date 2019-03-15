#include "wechatuserlist.h"
#include "jsonobject/wechatuserlist.h"
#include "XmppMessage.h"
#include "portraithelper.h"

void WechatUserListView::setWechatUserInfo(Biz::WechatUser* pUser)
{
    if (NULL!=pUser)
    {
        if (pUser->id ().isEmpty())
            return;

        QString userjid = Biz::MessageUtil::makeSureUserJid (pUser->id ());
        QString strdisply = pUser->name ();
        this->insertItem (userjid,strdisply);
        const QImage& image = Biz::PortraitHelper::getUserPortraitImage(userjid);
        this->setItemImage (userjid,image);

        m_channelids.insert (userjid,pUser->channelid ());
    }

}

QString WechatUserListView::getChannelId(const QString& conversationId)
{
    return m_channelids.value (conversationId);
}
