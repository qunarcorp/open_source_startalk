#ifndef TRANSFERCHATDIALOG_H
#define TRANSFERCHATDIALOG_H

#include "LocalManDialog.h"


#include "ui_TransferChatDialog.h"

#include <QTreeWidgetItem>
#include <QTimeLine>


namespace Biz{
	class CallbackReceiver;
	class XmppMessage;
}
enum TransferType{TRANSFERNUM=1, TRANSFERRELATION, TRANSFERCOLLEGA};
class TransferChatDialog : public LocalManDialog
{
	Q_OBJECT
public:
	static TransferChatDialog* instance(const QString& userid);
	void showTransferDlg();
	void setType(TransferType ntype);

	void setPeerid(const QString& strPid);
	void setChatid(const QString&strchatid);
	void setcctext(const QString& cctext);
	void setbu(const QString&bu);
	void setTransInfo(const QString& productUrl, const QString& vistorurl);
private:
	static TransferChatDialog* pInstance;
	TransferChatDialog(const QString& userid, LocalManDialog *parent=0);
	~TransferChatDialog();
private slots:
	void OnClickedBtnOk();
	void onTreeWidgetItemPress(QTreeWidgetItem *item, int column);
	void onHideTransferDlg();
	void onUpdateStatus(const QStringList& onlineUsers);
	void onSearchShopInfo(const QString&text);
	void createBindTree();
	void onRecivedRetMsg(const QString& from, int );
private:
	void createTree();
	void initColleageTree();
	QString chatid;

	int nType;
	QString mStrclickedTreeText;
	QString mStrclickedTreeId;
	void SendTransferMsg(const QString &strid,const QString& strcontent, const QString& strcolleage);

	void SendTransferMsg(const QString &strid,const QString& strcontent);

	virtual void timerEvent( QTimerEvent * );
	void getOrganizationbyId(QTreeWidgetItem *item,const QString& id);
	void createAddChrildTree(QTreeWidgetItem*item);
	QString strPeerid;
	Biz::CallbackReceiver* mReceiver;
	QTimeLine TimoutTimer;
	QString m_cctext;
	QString m_bu;
	int mncount;
	QString mProductId; //客人所看的产品Id
	QString mBusinessline;//客人所在的业务线
	QMap<QString, QString> mSearchShopmap; //里面存放的是id 和 name
	QMap<QString, QString> mMembermap; // 成员的id 和 webname的

	void SendTransferMsgold(const QString &strid,const QString& strcontent, const QString& strcolleage);

	void SendTransferMsgold(const QString &strid,const QString& strcontent);
private:
	Ui::TransferChatDialog ui;
	QTreeWidgetItem *groupItem;


};

#endif // TRANSFERCHATDIALOG_H
