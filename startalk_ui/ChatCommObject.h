#ifndef CHATCOMMOBJECT_H
#define CHATCOMMOBJECT_H

#include "WebViewCommObject.h"
#include "attachmentmanager.h"



namespace Biz{
	class XmppMessage;
	class XmppMessageMark;
}

class WebPage;

class ChatCommObject : public WebViewCommObject
{
	Q_OBJECT

public:
	ChatCommObject(QObject* parent = 0);
	~ChatCommObject();

	Q_INVOKABLE void jsShowBlankMenu();
	Q_INVOKABLE void jsShowContentMenu();

	Q_INVOKABLE void jsTest();
	Q_INVOKABLE void review(quint64 timestamp, int height);

	Q_INVOKABLE void showNewMessageTip(const QString& name,const QString& message);
	Q_INVOKABLE void hideNewMessageTip();
	Q_INVOKABLE void jslog(QString log);
	Q_INVOKABLE void jsCancelSend(const QString &msgid);
	//Q_INVOKABLE void jsDownReciv(const QString&url, const QString&filename, const QString&sectionid, const QString&fileMd5);
	Q_INVOKABLE void jsDownReciv(const QString&sectionid, const QString&fileMd5);
	Q_INVOKABLE void jsSearchRecivFile(const QString&msgid);
	Q_INVOKABLE void jsOpenFile(const QString& msgid);
	Q_INVOKABLE void jsSaveFile(const QString&msgid);
	Q_INVOKABLE void jsSaveFilePic(const QString&strLocalPath);
	Q_INVOKABLE void jsImageClicked(QString src, QString urlsrc);
	Q_INVOKABLE void jsImageDbClicked(QString src, QString urlsrc);
	Q_INVOKABLE void jsSpaceClicked();
	Q_INVOKABLE void jsSelectAll(WebPage* webPage);
	Q_INVOKABLE void jsSelectCopy(WebPage* webPage);
	Q_INVOKABLE void SetClipData(const QString& str);
	Q_INVOKABLE void jsSendFile(const QString& guid, const QString& str);
	Q_INVOKABLE void jsOpenVoice(const QString& guid);
	Q_INVOKABLE void jsGroupPopMenu(const QString& recource);
	Q_INVOKABLE void jsUserIdEnter(const QString& userId);
	Q_INVOKABLE void jsUserIdLeave(const QString& userId);
	Q_INVOKABLE void jsGetScrollTop(const QString& conversationId,int pos);

	Q_INVOKABLE void jsAgreeAddFriend(const QString& str);
	Q_INVOKABLE void jsRefuseAddFriend(const QString& str);
	Q_INVOKABLE void jsChangeclicked(const QString&from);

	// 会议提醒 
	Q_INVOKABLE void jsOpenMeetingInfo(const QString&from);

	// 系统的通知消息，参数是消息id
	Q_INVOKABLE void jsOpenUrl(const QString& messageid);



	// 更新会话抢单消息
	Q_INVOKABLE void updateCardState(const QString& vcardid,const QString& messagedesc);
	Q_INVOKABLE void jsReplyWechatUser(const QString& messageid);



	Q_INVOKABLE void customCentextMenu(const QString& messageid,int selectOption);

	Q_INVOKABLE void hideUpUnreadMessageTip();
	Q_INVOKABLE void showUpUnreadMessageTip();

	Q_INVOKABLE void jsReSendMessage(const QString& message);
	Q_INVOKABLE void jsShareSelectMessage(const QString&shareconversaionId,const QStringList& msgids);
	Q_INVOKABLE void jsShareSelectMessageCountChange(int ncount);
	Q_INVOKABLE void jsConversationDialogMesssageSelectedStatus(bool bshow);
	Q_INVOKABLE void jsWebCopyEvent(){ emit sgPostCopyEvent(); };
	Q_INVOKABLE void jsSingleImageCopy(){ emit sgSingleImageCopy (); };
	Q_INVOKABLE void jshttpgetapicall(const QString&url);
	Q_INVOKABLE void sendSignal(const QString& strjson, const QString&id);
	Q_INVOKABLE void closeRtcWindow( const QString&id);
	Q_INVOKABLE void WriteLocalLog(const QString&id, const QString&log);
	Q_INVOKABLE void StartVideoSound(const QString&id);
	Q_INVOKABLE void StopVideoSound(const QString&id);
	Q_INVOKABLE void OpenUrlbyPc(const QString& url);
	Q_INVOKABLE void openUrl(const QString&url);
	Q_INVOKABLE void TestRetParam();
	Q_INVOKABLE void jsRetunfirstMsgid(const QString&msgatid, const QString&msgid, const QString& conversationId );
	//群视频会议所需要的函数
	Q_INVOKABLE void getCkey();
	Q_INVOKABLE void getUserId();  //返回用户的昵称
	Q_INVOKABLE void getMyNick();  //当前用户的昵称
	Q_INVOKABLE void getRoomID(); //返回房间的uuid
	Q_INVOKABLE void getTopic();//返回房间的标题
	Q_INVOKABLE void getStartTime();//返回会议开始的时间
	Q_INVOKABLE void close_video_room(const QString& roomid);
	Q_INVOKABLE void jsgotoVideoRoom(const QString& roomjid);
	Q_INVOKABLE void getNickByUserId(const QString&id);
	Q_INVOKABLE void enableFullScreen(const QString&roomid);
	Q_INVOKABLE void cancelFullScreen(const QString&roomid);
	//qchat 中机器人发消息的接口
	Q_INVOKABLE void RobotSendMsg(const QString & conversationId,const QString& msg);

	Q_INVOKABLE void jsSetloadStatus(WebPage*webPage, int type);

	//evernote 中的相关
	Q_INVOKABLE void jsgetNoteEdit(const QString&infor);

	// 问题列表点击事件
	Q_INVOKABLE void jsProblemListClick(const QString&infor);
	Q_INVOKABLE void jsProblemListMoreClick(const QString&msgId);
	Q_INVOKABLE void jsProblemListTakeUp(const QString&msgId); 
	Q_INVOKABLE void jsHintsClick(const QString&type, const QString&infor);

signals:

	void sgclose_video_room(const QString& roomid);
	void sgfullScreen(const QString&roomid, bool bret);
	void sggotovideoRoom(const QString&jid);
	void sgsetCkey(const QString cky);
	void sgsetUserId(QString userNickname);  //返回用户的昵称
	void sgsetMyNick(QString mynickname);  //当前用户的昵称
	void sgsetRoomID(QString roomId); //返回房间的uuid
	void sgsetTopic(QString roomName);//返回房间的标题
	void sgsetStartTime(quint64 sttm);//返回会议开始的时间
	void sgsetNickByUserId(const QString&jid, const QString& NickeName);

	void sgTestRetParam(const QString& param);
	void sgOpenUrlbyPc(const QString&url);
	void sgOpenUrlbyPcWeb(const QString& url);
	void sghttpgetapicall(const QString&url);
	void sgStartVideoSound(const QString& id);
	void sgStopVideoSound(const QString&id);
	void sgWriteLocalLog(const QString&id, const QString&log);
	void sgCloseRtcWindow(const QString&id);
	void sgVideoSendSingnal(const QString& json, const QString&id);
	void sgQueryMore(quint64, int heigh);
	void sgShowNewMessageTip(const QString&,const QString&);
	void sgHideNewMessageTip();
	void sgHideUpUnreadMessageTip();
	void sgShowUpUnreadMessageTip();
	void sgCancelSend(const QString&msgid);
	//void sgRecvFile(const QString&url, const QString&filename, const QString&sectionid, const QString&fileMd5);
	void sgReceivalFile(const QString&sectionid, const QString&fileMd5);
	void sgImageClicked(QString src, QString urlsrc);
	void sgImageDbClicked(QString src, QString urlsrc);
	void sgSpaceClicked();
	void sgSendFile(const QString & guid);
	void sgOpenVoice(const QString& guid);
	void sgGroupPopMenu(const QString& resource);
	void sgUserIdEnter(const QString& userId);
	void sgUserIdLeave(const QString& userId);

	void sgOpenFilePath(const QString& msgid);
	void sgOpenFile(const QString& msgid);
	void sgSaveAs(const QString& msgid);
	void sgSaveAsPic(const QString& filename);
	void sgPostCopyEvent();
	void sgSingleImageCopy();
	void sgOpenUrl(const QString& messageid);
	void sgAgreeAddFriend(const QString& userid);
	void sgRefuseAddFriend(const QString& userid);
	void sgTransChatRecord(const QString& from);

	void sgCustomCentextMenu(const QString& messageid,int selectOption);
	void sgResendMessage(const QString& messageid);
	void sgShareSelectMessage(const QString& conversaionId,const QStringList& msglist);
	void sgShareSelectMessageCountChange(int ncount);
	void sgConversationDialogMesssageSelectedStatus(bool bSelectedStatus);
	void sgScrollTop(const QString& conversationId,int pos);
	void sgReplyWechatUser(const QString& msgid);
	void sgReturnfirstMsgid(const QString&msgatid, const QString&msgid, const QString& conversationId);
	void sgRobotSendMsg(const QString& id, const QString&msg);

	void sgSaveNote(const QString&content);

	void sgProblemLisClick(const QString&infor);
	void sgProblemLisMoreClick(const QString&msgId);
	void sgProblemListTakeUpClick(const QString&msgId);
	void sgHintsClick(const QString&type, const QString&infor);

	void sgLookMeetingClick(const QString&infor);
public:
	void appendMessageJavescrip(WebPage* webPage, bool isHistroy,
		bool hasMore, const QList<QSharedPointer<Biz::XmppMessage>>& messages, int  aotuscroll = 0);

	void appendMessageJavescripbyonemsg(WebPage* webPage, bool isHistroy,
		bool hasMore, const QList<QSharedPointer<Biz::XmppMessage>>& messages, int  aotuscroll = 0);

	void appendHistoryMessage(WebPage* webFrame,const QList<QSharedPointer<Biz::XmppMessageMark>>& messages, int aotuscroll, const QString strflag="");

	void scrollToEnd(WebPage* webPage);
	void systemnotify(WebPage* webPage, QString notify);
	void frontsystemnotify(WebPage*webpage, const QString& notify);
	void sendFileProgress(WebPage* webPage,const QString&key, qint64 done, qint64 total);
	void RecvFileProgress(WebPage* webPage,const QString&key,  const QString& fileName,qint64 done, qint64 total);
	void UploadOver(WebPage* webPage,const QString&key);
	void uploadFail(WebPage* webPage,const QString&key);
	void updateVoiceImage(WebPage* webPage,const QString& messageid, const QString& img);
	void clearScreen(WebPage* webPage);
	void cleanHistroyRecordPage(WebPage* webPage);
	void CheckedSysMsg(WebPage* webPage,const QString& strmsg);
	void setVoicePlayed(WebPage* webPage,const QString& messageid);

	void jsChangeIcon(WebPage*webpage, const QString& Jid, const QString&srcIcon);

	void jsChangeGroupMemberName(WebPage* webpage,const QString& jid,const QString& name);

	void jsInsertUnreadMessageTip(WebPage* webpage,const QSharedPointer<Biz::XmppMessage>& message);
	void jsInsertUnreadMessageDownTip(WebPage* webpage,const QSharedPointer<Biz::XmppMessage>& message);
	void deleteLastUnreadTip(WebPage* webpage);
	void jsMsgFindMao(WebPage* webPage, const QString& msgid);
	void jsMsgFindMaobyMsgid(WebPage *webPage, const QString& msgid, const QString& conversationId);
	void updateMessageSendStatus(WebPage* webpage,const QString& messageid,int status);
	void shareSelectedMessages(const QString& shareconversationId,WebPage* webpage);
	void updateShareMessageInput(WebPage* webpage,bool visable);
	void GetScrollTop(const QString& conversationId, WebPage* webPage);
	void setScollPos(int Pos, WebPage* webPage);
	void updateMessageSendPicSrc(WebPage*webPage, const QString& msgid, const QString& newfilepath);
	void setcounthtmlMsgCount(WebPage*webPage, int msgcount);
	void setVedioRoomParam(const QString&roomId, const QString&topic, quint64 starttm, WebPage*page);
	void setFullScreen(WebPage*webPage,  bool bret);
	void setStartVideoRoom(WebPage*webpage, const QString&roomid);
	void loadCSS(WebPage*webpage);
	void loadJS(WebPage*webpage);
	void getNoteEditInfo(WebPage*webpage);
	void appendNote(WebPage*webpage, const QString& NoteInfor);
	void jsSetMessageStatus(WebPage*webpage,const QString& msgId, const QString& statusText);
	void jsSetStatusfontfamy(WebPage*webpage, const QString&fontfamy);


private:
	QString mRoomId;
	QString mTopic;
	quint64 mStarttm;
	WebPage*mwebpage;
};

#endif // CHATCOMMOBJECT_H
