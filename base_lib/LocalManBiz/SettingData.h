#ifndef SETTINGDATA_H
#define SETTINGDATA_H

#include "../LocalManUtils/IXmlSerializeable.h"
namespace Biz
{
    class AllUserSettingData : public IXmlSerializeable
    {
        Q_OBJECT
        PROPERTY(int, ChatDlgWidth);
        PROPERTY(int, ChatDlgHeight);
        PROPERTY(int, GroupChatDlgWidth);
        PROPERTY(int, GroupChatDlgHeight);
        PROPERTY(int, MultiChatDlgWidth);
        PROPERTY(int, MultiChatDlgHeight);
        PROPERTY(int, MultiChatDlgListWidth);
        PROPERTY(int, MainDlgX);
        PROPERTY(int, MainDlgY);
        PROPERTY(int, MainDlgWidth);
        PROPERTY(int, MainDlgHeight);
        PROPERTY(int, MsgNotifyType); // 0 直接弹出窗口 1 消息提醒 2 消息静默 // 消息提示设置更改，这个选项弃用
        
		//消息通知
        PROPERTY(int, MsgSound);// 0 静默 1 声音提示
		PROPERTY(QString, MsgVoicePath);// 消息提示音的路径
		PROPERTY(QString, NoteVoicePath);// note消息的提示音
		PROPERTY(QString, SystemVoicePath); //系统消息的提示音
		PROPERTY(QString, NoticeVoicePath); //通告消息的提示
		PROPERTY(bool,IsAutoShowMainDialog);
		PROPERTY(bool,IsShowMessageNotice);


        PROPERTY(bool, AutoReplyEnable);// 是否开启自动回复
        PROPERTY(int, AutoReplyTimer);// 开启自动回复生效时间
        PROPERTY(QString, AutoReplySystemMessage);// 开启自动回复内容
        PROPERTY(QString, AutoReplyUserMessage);// 开启自动回复内容,自定义
        PROPERTY(bool,AutoReplyMessageOption); // 1 系统预定义消息，0 自定义消息
        
        

        //字体设置
        PROPERTY(QString, MFontFamily);
        PROPERTY(int, MFontSize);
        PROPERTY(int, MInputFontSize);
        PROPERTY(int, TextColorRGB);
        PROPERTY(int, TextColorRGBOther);
        PROPERTY(int, SelfBubbleColor); // 这里存的实际是index，不是真正色纸，参数废弃掉
        PROPERTY(int, OtherBubbleColor);// 这里存的实际是index，不是真正色纸，参数废弃掉
        PROPERTY(int, SelfBubbleColor2);
        PROPERTY(int, OtherBubbleColor2);

        PROPERTY(qreal, SelfTextColorAlpha);
        PROPERTY(qreal, OtherTextColorAlpha);
        PROPERTY(qreal, SelfBubbleColorAlpha);
        PROPERTY(qreal, OtherBubbleColorAlpha);
     

		//输入框的快捷发送热键
		PROPERTY(QString, MSendHotKey);

		//热键
		PROPERTY(QString, MessageHotKey);//提取消息
		PROPERTY(QString, ScreenHotKey);//捕捉屏幕
		PROPERTY(QString, SearchHotKey); //搜索人
		PROPERTY(QString, MbordHotKey);//主面板

		PROPERTY(int, Run_Style);//运行的进程数

        PROPERTY(QString, UserPath);

		//是否需要激活快捷键
		PROPERTY(bool, AutoReplyActiveHotKey);//提取消息

		//右键保存文件的路径
		PROPERTY(QString, UserSaveAsPath);

        // 最大会话数限制
        PROPERTY(int, MaxSessionLimited);

		//自己的好友模式
		PROPERTY(int, SelfFriendMode);
		PROPERTY(QString, SelfFriendQuestion);
		PROPERTY(QString, SelfFriendAnswer);

		//欢迎语设置
		PROPERTY(bool, AutoReplyWelcomeEnable);// 是否开启欢迎语自动回复
		PROPERTY(bool,AutoReplyWelcomeoption); // 1 系统预定义回复语，0 自定义回复语
		PROPERTY(QString,ReSetWelcome); // 预定义回复语
		PROPERTY(QString,SelfSetWelcome); // 自定义回复语
		//字号设置
		PROPERTY(bool, SetFontSize);// 字号设置
		//截图时是否隐藏聊天会话窗口
		PROPERTY(bool, SetJietu);
		//linux中的截图
		PROPERTY(bool, SetOSLinuxJietu);
		PROPERTY(bool, SetOSLinux3dJietu);
		PROPERTY(QString, SystemMsgType);

        // 提醒窗口的位置
        PROPERTY(int, NotifyWindowPosY);

        // 其他设置
        PROPERTY(bool ,AutoStartUp);
        PROPERTY(int  ,QuitOnClose);
        PROPERTY(int  ,MailSplite);
        PROPERTY(bool ,MessageBoxNotice);

		//http请求的次数设置
		PROPERTY(int, RequestTm);

        // 自动播放震动
        PROPERTY(bool,AutoShake);

        // 主题
        PROPERTY(QString, themeName);


        PROPERTY(QString, macCode);

        // LastConvigVersion 这个流程有缺陷，不能这么写。次参数废掉，功能并入version
		PROPERTY(int, LastConvigVersion);
        PROPERTY(int, Version);
       
		//最近会话列表中是否展示所以会话，还是只显示未读和置顶
		PROPERTY(bool , RecentListShow);

		//自动回复的状态
		PROPERTY(bool , Busystatus);
		PROPERTY(bool , Awaystatus);
		PROPERTY(QString, BusyMsg);
		PROPERTY(QString, AwayMsg);
		//qchat中对声音的设置
		PROPERTY(bool, DefaultVoiceSet);

		//ESC键退出聊天框
		PROPERTY(bool, EscHideChat);

		//客户端中的对拉史的定义（不在界面上展示和设置）
		PROPERTY(bool,     GetOfflineAllMessageResult);
		PROPERTY(long long,     GetOfflineAllMessageLastTimestamp);


		//删除的表情包的信息
		PROPERTY(QString, DeleteEmotionList);

		//群成列表是否展示
		PROPERTY(bool, ShowGroupMemberlist);

		//切换聊天框滚动条不置底
		PROPERTY(bool, ScrollbaronBlew);

		//状态栏上文本的颜色的设置
		PROPERTY(int, TaskTextClr);

		PROPERTY(int, DarkDescClr); //Drak最近联系人列表中描叙文件的内容
		PROPERTY(int, LightDescClr);//LIght最近联系人列表中描叙文件的内容

		//qchat 中自动回复语自动发送
		PROPERTY(bool, QuickReply); 
    public:
        AllUserSettingData(int,int);
        ~AllUserSettingData();
        bool update();
        const static int sVersion;
        const static int sSelfColorDefaultValue;
        const static int sOhterColorDefaultValue;
		const static int sTaskTextColorDefaultValue;
		const static int sDarkTextColorDefaultValue;
		const static int sLightTextColorDefaultValue;
    private:

    };

    
}
#endif // SETTINGDATA_H
