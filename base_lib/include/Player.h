#ifndef PLAYER_H
#define PLAYER_H

#include "../LocalManUtils/IXmlSerializeable.h"

namespace Biz
{
    class Player : public IXmlSerializeable
    {
        Q_OBJECT
            
        PROPERTY(QString, UserID);
        PROPERTY(quint64, LastMessageTime);
        PROPERTY(int, UnreadCount);
        PROPERTY(QString,UserName);
        PROPERTY(QString,Department);
        PROPERTY(int, version);
        PROPERTY(QString, userType);
        PROPERTY(QString,searchKeyF);
        PROPERTY(QString,searchKeyS);
        PROPERTY(int,here);
    public:
        Player();
        ~Player();

    private:

    }; 

    class RoomVcard : public IXmlSerializeable
    {
        Q_OBJECT
        PROPERTY(QString, RoomId);
        PROPERTY(QString, RoomName);
        PROPERTY(QString, RoomDescription);
        PROPERTY(QString, RoomTopic);
        PROPERTY(QString, RoomPortrait); //群图片的url
        PROPERTY(QString, RoomSearchKey);
		PROPERTY(QString, RoomDomain);
        PROPERTY(int    , RoomVcardVersion);
    public:
        RoomVcard(){RoomVcardVersion(0);};
        ~RoomVcard(){};
    };
	
	class IncreaRoomInfo : public IXmlSerializeable
	{
		Q_OBJECT
		PROPERTY(QString, RoomId);
		PROPERTY(QString, RoomDomain);
		PROPERTY(quint64, RoomLasttime);
		PROPERTY(int, Flag);
		PROPERTY(QString, ExtendInfo);
	public:
		IncreaRoomInfo(){RoomLasttime(0);Flag(-1);};
		~IncreaRoomInfo(){};
	};

    class RobotVcard : public IXmlSerializeable
    {
        Q_OBJECT
    private:
        PROPERTY(QString,RbtId);
        PROPERTY(QString,RbtName);
        PROPERTY(QString,RbtHeader);
        PROPERTY(QString,RbtTel);
        PROPERTY(QString,RbtSource);
        PROPERTY(QString,RbtDesc);
        PROPERTY(bool,RbtSwitch);
        PROPERTY(int,Rbtversion);
        PROPERTY(QString,RbtRawInfo);
        PROPERTY(QString,RbtLocalHeader);

        RobotVcard(){RbtSwitch(false);Rbtversion(0);};
        ~RobotVcard(){};
    };

	class WebUserInfo :public IXmlSerializeable
	{
		Q_OBJECT
	private:
		PROPERTY(QString,WebUserId);
		PROPERTY(QString,NickName);
		PROPERTY(QString,WebUrl);
		PROPERTY(quint64,Time);
		PROPERTY(int,WebUserType);
		PROPERTY(quint64, WebChatId);
		PROPERTY(QString, IpAddr);
		PROPERTY(QString, WhereAddr);
	public:
		WebUserInfo()
		{
			WebUserType(0);
		}
		~WebUserInfo(){};
	};
	class GroupAtInfo:public IXmlSerializeable
	{
		Q_OBJECT
	private:
		PROPERTY(QString,SenderId);
		PROPERTY(QString,Msg);
		PROPERTY(QString,Msgid);
	public:
		GroupAtInfo()
		{
			this->SenderId("");
			this->Msg("");
			this->Msgid("");
		}
		~GroupAtInfo()
		{

		}
	};
   
	class AttachMentInfo:public IXmlSerializeable
	{
		Q_OBJECT
	private:
		PROPERTY(QString,Name);
		PROPERTY(QString, FileId);
		PROPERTY(QString,Url);
		PROPERTY(QString, MD5);
		PROPERTY(QString,LocalCopy);
		PROPERTY(QString,AttachExternInfo);
		PROPERTY(QString,MsgId);
		PROPERTY(int, Sourcetype);
		PROPERTY(int, AttachType);
        PROPERTY(QString,conversationID);
	public:
		AttachMentInfo()
		{
			this->Name("");
			this->FileId("");
			this->Url("");
			this->MD5("");
			this->LocalCopy("");
			this->AttachExternInfo("");
			this->MsgId("");
			this->Sourcetype(0) ;
			this->AttachType(0);
		}
		~AttachMentInfo()
		{

		}
	};

    class EmoticonPackageInfo:public IXmlSerializeable
    {
        Q_OBJECT
    private:
        PROPERTY(QString, name);
        PROPERTY(QString, downloadUrl);
        PROPERTY(QString, desc);
        PROPERTY(QString, thumb);
        PROPERTY(int, file_size);
        PROPERTY(QString, md5);
        PROPERTY(QString, id);

    public:
        EmoticonPackageInfo(){
            file_size(0);
        }
        ~EmoticonPackageInfo(){};
    };

	class SystemMessageInfo : public IXmlSerializeable
	{
		Q_OBJECT
	private:
		PROPERTY(QString, MsgId);
		PROPERTY(int, Status);
		PROPERTY(QString, MsgType);
		PROPERTY(QString, Extend);
		
	public:
		SystemMessageInfo(){
			Status(0);
			Extend("");

		}
		~SystemMessageInfo(){};
	};

    class PersonConfInfo : public IXmlSerializeable
    {
        Q_OBJECT
    private:
        PROPERTY(QString,infoKey);
        PROPERTY(QString,infoValue);
        PROPERTY(int,infoVersion);
    public:
        PersonConfInfo(){
            infoVersion(0);
        };
        ~PersonConfInfo(){};
    };

    class ConversationMarkInfo : public IXmlSerializeable
    {
        Q_OBJECT
    private:
        PROPERTY(QString,conversationId);
        PROPERTY(QString,markTitle);
        PROPERTY(QString,markInfo);
        PROPERTY(int,markVersion);
    public:
        ConversationMarkInfo(){
            markVersion(0);
        };
		
        ~ConversationMarkInfo(){};
    };

	class UserMoodInfo : public IXmlSerializeable
	{
		Q_OBJECT
	private:
		PROPERTY(QString,userId);
		PROPERTY(int,version);
		PROPERTY(QString,moodInfo);
	public:
		UserMoodInfo(){version(0);};
		~UserMoodInfo(){};
	};
	
	class ImageAttachInfor : public IXmlSerializeable
	{
	
		Q_OBJECT
	private:
		PROPERTY(QString, ImageId );
		PROPERTY(quint64, Imagetime);
		PROPERTY(QString, LocalPath);
		PROPERTY(QString, UrlPath);
	public:
		ImageAttachInfor() {Imagetime(0);}
		~ImageAttachInfor() {};

	};

	class RecentListInfor: public IXmlSerializeable
	{
		Q_OBJECT
		private:
			PROPERTY(QString, MsgId);
			PROPERTY(QString, NameId);
			PROPERTY(QString, Content);
			PROPERTY(quint64, Time);
	public:
		RecentListInfor(){Time(0);}
		~RecentListInfor() {};
	protected:
	
	};
	class TransVistorInfor:public IXmlSerializeable
	{
		Q_OBJECT
	private:
		PROPERTY(QString, ConversationId);
		PROPERTY(QString, ProductUrl);
		PROPERTY(QString, VistorLocal);
	public:
		TransVistorInfor(){};
		~TransVistorInfor() {};
	protected:
	};

	class CollectionSessionInfor:public IXmlSerializeable
	{
		Q_OBJECT
	private:
		PROPERTY(QString, MessageId);
		PROPERTY(QString, OriginTo);
		PROPERTY(QString, OriginFrom);
		PROPERTY(QString, RealJid);
		PROPERTY(int, OriginType);
		PROPERTY(QString, ExtendedFlag);

	public:
		CollectionSessionInfor(){
			OriginType(0);
		};
		~CollectionSessionInfor() {};
	protected:

	};

	class CollectionBindUserInfo:public IXmlSerializeable
	{
		Q_OBJECT
	private:
		PROPERTY(QString, BindUserId);
		PROPERTY(QString, BindUserName);
		PROPERTY(QString, BindDomain);
		PROPERTY(QString, UserImage);
		PROPERTY(QString, DescInfo);
		PROPERTY(int, IncrementVersion);
		PROPERTY(int, LastUpdateTime);
		PROPERTY(int, BindFlag);
		PROPERTY(QString, ExtendedFlag);

	public:
		CollectionBindUserInfo(){
			BindFlag(0);
			IncrementVersion(0);
			LastUpdateTime(0);
		};
		~CollectionBindUserInfo() {};
	protected:
	};

	class QuickReplyGroup:public IXmlSerializeable
	{
		Q_OBJECT
	private:
		PROPERTY(QString, GroupId);
		PROPERTY(QString, GroupCId);
		PROPERTY(QString, GroupName);
		PROPERTY(int, GroupSeq);
		PROPERTY(long, GroupVersion); 
		PROPERTY(QString, ExtendedFlag);
		PROPERTY(int, optionFlag); // 操作状态

		PROPERTY(int, option); // 1 添加 2 更新 3 删除
	public:
		QuickReplyGroup(){
			GroupSeq(0);
			GroupVersion(0); 
		}
		~QuickReplyGroup() {}; 
	protected:
	}; 

	
	class QuickReplyContent:public IXmlSerializeable
	{
		Q_OBJECT
	private:
		PROPERTY(QString, ContentId);
		PROPERTY(QString, ContentCId);
		PROPERTY(QString, GroupId);
		PROPERTY(QString, GroupCId);
		PROPERTY(QString, Content);
		PROPERTY(int, ContentSeq);
		PROPERTY(long, ContentVersion); 
		PROPERTY(QString, ExtendedFlag);
		PROPERTY(int, optionFlag); // 操作状态

		PROPERTY(int, option); // 1 添加 2 更新 3 删除
	public:
		QuickReplyContent(){
			ContentSeq(0);
			ContentVersion(0); 
		}
		~QuickReplyContent() {}; 
	protected:
	}; 

}

#endif // PLAYER_H
