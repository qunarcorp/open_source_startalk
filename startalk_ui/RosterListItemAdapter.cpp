#include "RosterListItemAdapter.h"

#include "RosterListItems.h"
#include "RecentItemView.h"
#include "portraithelper.h"
#include "UiHelper.h"
#include "AccountData.h"
#include "accountmanager.h"
#include "Session.h"
#include "UserVcardManager.h"
#include "colorset.h"
#include "GroupListData.h"
#include "UIFrame.h"
#include "portraitcontroller.h"


RosterListItemAdapter::RosterListItemAdapter(QListView *parent)
    : ListWidgetBaseAdapter(parent,QColor::fromRgb(0,0,0,0),QColor::fromRgb(0x4A,0x4A,0x4A),QColor::fromRgb(0x51,0x50,0x50))
{
    this->setNormalBackground(ColorSetSingleton::getInstance()->transparent());
    this->setHoverBackground(ColorSetSingleton::getInstance()->recent_item_bk_hover());
    this->setSelectBackground(ColorSetSingleton::getInstance()->recent_item_bk_checked());
}

RosterListItemAdapter::~RosterListItemAdapter()
{

}

QWidget* RosterListItemAdapter::CreateNewWidget(const QModelIndex& index)
{

    //     enum RosterListItemData
    //     {
    //         RosterListItemDataBase = Qt::UserRole,
    //         RosterListItemDataConversationTypeGroup,
    //         RosterListItemDataConversationTypeChat,
    //         RosterListItemDataConversationTypeNews,
    //         RosterListItemDataConversationTypeRobot,
    //         RosterListItemDataConversationTypeLinked,
    //         RosterListItemDataConversationId,
    //         RosterListItemDataTitle,
    //         RosterListItemDataDesc,
    //         RosterListItemDataUnreadCount,
    //         RosterListItemDataIsTop,
    //         RosterListItemDataAtFlag,
    //         RosterListItemDataAtCount,
    //         RosterListItemDataLastTimeStamp,
    //         RosterListItemDataHeaderChange,
    //         RosterListItemDataChildData,
    //     };
    // 
    //     enum RosterListItemChildData
    //     {
    //         RosterListItemDataChildBase = RosterListItemData::RosterListItemDataChildData,
    //         RosterListItemDataLinkedId,
    //     };
    QString conversationId  = index.data(RosterListItemDataConversationId).toString();
    QString title           = index.data(RosterListItemDataTitle).toString();
    QString desc            = index.data(RosterListItemDataDesc).toString();
    int unreadCount         = index.data(RosterListItemDataUnreadCount).toInt();
    int attype              = index.data(RosterListItemDataAtFlag).toInt();
    int atcount             = index.data(RosterListItemDataAtCount).toInt();
    bool isTop              = index.data(RosterListItemDataIsTop).toBool();

    bool isGroupChat        = index.data(RosterListItemDataConversationTypeGroup).toBool();
    bool isSimpleChat       = index.data(RosterListItemDataConversationTypeChat).toBool();
	bool isConsultChat		= index.data(RosterListItemDataConversationTypeConsult).toBool();

    bool isLinked           = index.data(RosterListItemDataConversationTypeLinked).toBool();
	int noticetip           =  index.data(RosterListItemDataNoticeTip).toInt();
	QString strvirtualId    = index.data(RosterListItemDataVirtualId).toString();
	bool isSeat				= index.data(RosterListItemDataBIsSeat).toBool();

    RecentItemView* pItemView = new RecentItemView(NULL);
    pItemView->setID(conversationId);
	
	pItemView->setDisplayName(title);
#ifdef QCHAT
	if (!strvirtualId.isEmpty())
	{
		pItemView->setDescription(strvirtualId);
	}
#else
	if (!desc.isEmpty() && atcount <=0)
	{
		pItemView->setDescription(desc);
	}
	
#endif // QCHAT

    
    
    if (isSimpleChat || isConsultChat)
    {
        QPixmap pixmap = Biz::PortraitHelper::getUserPortrait(conversationId);
		//QPixmap pixmap = MainApp::UIFrame::getportraitcontroller()->getSinglePixmap(conversationId);
        if (Biz::Session::getUserVcardManager()->isUserOnline(conversationId))
        {
            pItemView->setHeaderIcon(pixmap);
        }
        else
        {
            QImage greyImg = pixmap.toImage();
            MainApp::imageToGray(greyImg);             
            pItemView->setHeaderIcon(QPixmap::fromImage(greyImg));
        }

        pItemView->enableBtnMark();
		
		if (isConsultChat )
		{
			if (isSeat)
			{
				QPixmap noticewithouttip(":Images/icon/shopvirtual.png");
				pItemView->setVirtualPixmap(noticewithouttip);
			}
		}
		
    }
    else if (isGroupChat)
    {
		//ÔÚÕâÀï¼ÓÉÏÈºÏûÏ¢ÉèÖÃÖÐµÄ1.½ÓÊÕ²»ÌáÐÑÏûÏ¢2.½ÓÊÕÌáÐÑÏûÏ¢µÄÄ£Ê½
		
		pItemView->setHeaderIcon(Biz::PortraitHelper::getGroupPortrait(conversationId));
		
		if (Biz::GroupSetting::RECV_WITHOUT_NOTICE == (Biz::GroupSetting::RECV_WITHOUT_NOTICE&noticetip))
		{
			QPixmap noticewithouttip(":Images/withoutnotice.png");
			pItemView->setStatusIcon(noticewithouttip);
			if (unreadCount > 0)
			{
				pItemView->setunReadFlag(true);
			}
			
		}
		else
		{
			pItemView->setStatusHide();
			pItemView->setUnReadCount(unreadCount);
		}
    }
    else
    {
        pItemView->setHeaderIcon(Biz::PortraitHelper::getUserPortrait(conversationId));
    }

    if (isLinked)
    {
		
        pItemView->disableCloseBtn();
    }
	if (!isGroupChat)
	{
		pItemView->setUnReadCount(unreadCount);
	}
    
    pItemView->setAtCount(atcount,attype,"");
    pItemView->setTopFlag(isTop);
    return pItemView;
}

QSize RosterListItemAdapter::sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    return QSize(40,60);
}

void RosterListItemAdapter::updateData(QWidget* pWidget,const QModelIndex& index,const QStyleOptionViewItem& option)
{
    RecentItemView* pItemView = dynamic_cast<RecentItemView*>(pWidget);
    if (NULL!=pItemView)
    {
        QString conversationId  = index.data(RosterListItemDataConversationId).toString();
        QString title           = index.data(RosterListItemDataTitle).toString();
        QString markTitle       = index.data(RosterListItemDataMarkTitle).toString();
        QString desc            = index.data(RosterListItemDataDesc).toString();
        int unreadCount         = index.data(RosterListItemDataUnreadCount).toInt();
        int attype              = index.data(RosterListItemDataAtFlag).toInt();
        int atcount             = index.data(RosterListItemDataAtCount).toInt();
        bool isTop              = index.data(RosterListItemDataIsTop).toBool();
        quint64 headerChange    = index.data(RosterListItemDataHeaderChange).toLongLong();

        bool isGroupChat        = index.data(RosterListItemDataConversationTypeGroup).toBool();
        bool isSimpleChat       = index.data(RosterListItemDataConversationTypeChat).toBool();
		bool isConsultChat		= index.data(RosterListItemDataConversationTypeConsult).toBool();

		int noticetip           =  index.data(RosterListItemDataNoticeTip).toInt();
		QString strvirtualid    = index.data(RosterListItemDataVirtualId).toString();
		bool isSeat				= index.data(RosterListItemDataBIsSeat).toBool();

        if (!markTitle.isEmpty())
            title = markTitle;

        if (pItemView->getDisplayName()!=title)
        {
            pItemView->setDisplayName(title);
        }

		if (Util::PlatfromCode::PLATFROM_QCHAT == Util::nPlatformType)
		{
			if (isSeat)
			{
				pItemView->setDescription(strvirtualid);
			}
		}
		else {
			if (pItemView->description()!=desc)
			{
				if (!desc.isEmpty() &&  atcount <=0)
				{
					pItemView->setDescription(desc);
				}

			}
		}

        
		//消息提醒的标识
		if (Biz::GroupSetting::RECV_WITHOUT_NOTICE == (Biz::GroupSetting::RECV_WITHOUT_NOTICE&noticetip))
		{
			
			//pItemView->setStatusIcon(noticewithouttip);
			if (unreadCount > 0)
			{
				pItemView->setunReadFlag(true);
			}
			else
			{
				pItemView->setunReadFlag(false);
			}
		}
		else
		{
			//pItemView->setStatusHide();
			if (pItemView->unreadCount()!=unreadCount)
			{
				pItemView->setUnReadCount(unreadCount);
			}
		}

        

        if (pItemView->atCount()!=atcount || pItemView->atType()!=attype)
        {
            pItemView->setAtCount(atcount,attype,"");
        } 
     

        if (pItemView->isTop() != isTop)
        {
            pItemView->setTopFlag(isTop);
        }

        if (pItemView->headerVersion()!=headerChange)
        {
            pItemView->setHeaderVersion(headerChange);

            if (isSimpleChat || isConsultChat)
            {
                QPixmap pixmap = Biz::PortraitHelper::getUserPortrait(conversationId);
				//QPixmap pixmap = MainApp::UIFrame::getportraitcontroller()->getSinglePixmap(conversationId);
                if (Biz::Session::getUserVcardManager()->isUserOnline(conversationId))
                {
                    pItemView->setHeaderIcon(pixmap);
                }
                else
                {
                    QImage greyImg = pixmap.toImage();
                    MainApp::imageToGray(greyImg);             
                    pItemView->setHeaderIcon(QPixmap::fromImage(greyImg));

                }
				if (isSimpleChat)
				{
					if (Biz::GroupSetting::RECV_WITHOUT_NOTICE == (Biz::GroupSetting::RECV_WITHOUT_NOTICE&noticetip))
					{
						QPixmap noticewithouttip(":Images/withoutnotice.png");
						pItemView->setStatusIcon(noticewithouttip);
					}
					else
					{
						pItemView->setStatusHide();
					}
				}
#ifdef QCHAT
				if (isConsultChat )
				{
					if (isSeat)
					{
						QPixmap noticewithouttip(":Images/icon/shopvirtual.png");
						pItemView->setVirtualPixmap(noticewithouttip);
					}
				}

#endif // QCHAT

				

            }
            else if (isGroupChat)
            {
                pItemView->setHeaderIcon(Biz::PortraitHelper::getGroupPortraitWithNoticeFlag(conversationId));

				if (Biz::GroupSetting::RECV_WITHOUT_NOTICE == (Biz::GroupSetting::RECV_WITHOUT_NOTICE&noticetip))
				{
					QPixmap noticewithouttip(":Images/withoutnotice.png");
					pItemView->setStatusIcon(noticewithouttip);
				}
				else
				{
					pItemView->setStatusHide();
				}
				
            }
            else
            {
                pItemView->setHeaderIcon(Biz::PortraitHelper::getUserPortrait(conversationId));
            }

        }

        pItemView->setChecked(option.state & QStyle::State_Selected && index.data(ListWidgetBaseAdapterRoleDisableSelecte).toBool());
    }
    
}
