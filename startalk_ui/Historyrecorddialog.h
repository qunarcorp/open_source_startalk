#ifndef HISTORYRECORDDIALOG_H
#define HISTORYRECORDDIALOG_H

#include "LocalManDialog.h"
#include "ui_HistoryRecord.h"
#include "ChatCommObject.h"

#include "WebPage.h"
#include "CallbackReceiver.h"
#include "MessageListData.h"
#include "Historyrecordmodel.h"
#include "Tableview.h"
#include "BaseChatDialog.h"
#include <QMenu>


class HistoryRecordDialog : public BaseChatDialog
{
	Q_OBJECT
        enum PAGE_DIRECTIO
    {
        PAGE_DIRECTIO_BEGIN,
        PAGE_DIRECTIO_LAST,
        PAGE_DIRECTIO_NEXT,
        PAGE_DIRECTIO_END
    };
public:
	static HistoryRecordDialog* instance(const QString&struserid);
	void showHistoryRecordDlg(const QString& strUserid);
	void setcurrentgroupid(const QString& strgroupid);
private:
	static HistoryRecordDialog* pInstance;
	HistoryRecordDialog( const QString&,QWidget *parent=0);
	~HistoryRecordDialog();
	
private:
	void InitData();
	void GetPeerId();
	void showMsg(const QString& strid, const QString strflag="", int direction=2);
	void ShowHtml(const QSharedPointer<Biz::MessageListData> messageList, const QString strflag = "");
    void updatePageNumber(int direction, int currentPage=-1);
	void getBeginAndEndTime(const QString& strid, const QString strflag);
	void DisplayfindTm(const QString& strid, const QString&strflag ,quint64 findtm, int nPageid);
	
signals:
	void sgshowDefaultMsg(int n);
	void sgShowFlagMsg(int n, const QString& msg);
private slots:
	void onMin();
	void onClose();
	void updateCount(int count);
	void onShowDefaultMsg(int n);
	void onSelecRowClick();
	void onSearchFind();
	void onNext();
	void onSearchClean();
	void onBegin();
	void onBlow();
	void onEnd();
	void onSearchAbove();
	void onSearchNext();
	void onShowFlagMsg(int n, const QString& msg);

	virtual void resizeEvent( QResizeEvent * );

    virtual void onMessageReceived(const QSharedPointer<Biz::XmppMessage>&);
    virtual void messageSendPrepare (const QSharedPointer<Biz::XmppMessage>& spMessage);
	virtual void onCollectionMessageReceived(const QSharedPointer<Biz::XmppMessage>&msg) {};
private:
	Ui::HistoryRecordDialog* ui;

	Biz::CallbackReceiver* mReceiver;

	QList<Biz::RecordInfor> mlistInfor;

	TableView *tableView;

	quint64 lasttm;
    quint64 begintm;
	QStringList strlistmsgid;
	QString strCurrentmsgid;
	int ncurrentcount;
	bool bfindSearch;
	QString strCurrentSelectUserid;


    int nPageIndex;

	bool FindRet;
	bool bFirst;

	QString mCurrentGroupid;
};

#endif // HISTORYRECORDDIALOG_H
