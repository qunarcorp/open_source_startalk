#ifndef NODIFYWINDOW_H
#define NODIFYWINDOW_H

#include <QWidget>
#include <QTimeLine>
#include <QMap>
#include "localmanwidget.h"
namespace Ui {class NotifyWindow;};

class Animation;
namespace Biz {class XmppMessage;};
class NoticeItem {
public: 
	QSharedPointer<Biz::XmppMessage> spmessage;
	QString title;
	QString ConvsationJId;
};

class NotifyWindow : public LocalManWidget
{
    Q_OBJECT
public:
    

public:
    NotifyWindow(QWidget *parent = 0);
    ~NotifyWindow();
    
public:
    static NotifyWindow& instance();
    static void release();
    static void showNotifyMessage(const QString& jid, const QString& dispalyName, const QSharedPointer<Biz::XmppMessage>& msg );
private:
    void _showNotifyMessage(const QString& jid, const QString& dispalyName,const QSharedPointer<Biz::XmppMessage>& msg);
    void hidePosition();
private:
	void getlineoflaycount(QFontMetrics msgfont, const QString& strlinecontent, int& ncontentlenght, int nlineOfContaincount);
	void showPosition();
	QStringList calcuteContent(const QString& content);
    void showAnimation();
    virtual void showEvent( QShowEvent * );
    virtual void hideEvent( QHideEvent * );
    
    virtual void enterEvent(QEvent *);

    virtual void leaveEvent(QEvent *);

    virtual bool eventFilter(QObject *, QEvent *);

    virtual void windowMove(const QPoint& pos);

private:
    Ui::NotifyWindow *ui;
    QTimeLine holderLine;
    
    Animation* m_animIn;
	NoticeItem msgNoticeItem;


signals:
    void sgOpenConversation(const QString&);

    private slots:
        void onClosed(bool);
        void onTextClicked();
        void showNotifyItems();
        void onTrayIconDoubleClick();
		void onChangeNotifyItem();

        

      

};


#define gNotifyWindow NotifyWindow::instance()

#endif // NODIFYWINDOW_H
