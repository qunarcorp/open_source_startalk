#ifndef GLOABLEEVENTOBJECT_H
#define GLOABLEEVENTOBJECT_H

#include <QObject>
#include <QMoveEvent>
class QuickReplyMsgItem;
#include <QPushButton>
#include <QLabel>

class GloableEventObject : public QObject
{
    Q_OBJECT

public:
    static GloableEventObject* getInstance();
private:
    static GloableEventObject* pInstance;
    GloableEventObject(QObject *parent);
    ~GloableEventObject();

private:
signals:
    void sgMainDialogMoved(QMoveEvent* event);
    void sgShake();
    void sgMainDialogActivitied(bool activited);
	//recentItemview销毁的信号
	void sgShowDeleteCatchMenu();
	void sgQuickReplyUpdate(const QList<QuickReplyMsgItem*>& replymsgList);
	void sgQuickReplyGroupChange();
	void sgQuickReplyAllContentChange();
	void sgQuickReplyContentChange(const QString &groupCid);

    void sgInputTextChange(qreal val);

    void sgNewVersionPrompt(bool bPrompt);
	void sgFontSizeChange(quint16 nsize);

	void sgHideMainWidge();
	void sgShowMainWidge();

	void sgMainDlgMin();

};

#endif // GLOABLEEVENTOBJECT_H
