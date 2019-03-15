#ifndef UNREADMESSAGENOTICE_H
#define UNREADMESSAGENOTICE_H

#include <QWidget>
namespace Ui {
    class UnreadMessageNotice;
};

class CloseableButtonView : public QWidget
{
    Q_OBJECT
public:
        enum ShowType
    {
        ST_UPUNREAD,
        ST_DOWNUNREAD,
        ST_NOTSET
    };
public:
    CloseableButtonView(QWidget *parent = 0);
    ~CloseableButtonView();
    void setUpUnreadText(const QString& text);
    void setDownUnreadText(const QString& text);
    void setAtTipText(const QString& text);
    void setAnchoragePoint(const QString& msgid);
    ShowType getShowType(){return m_showType;};
    void setAutoHid(bool autohid){m_autohid = autohid;};
protected:
    virtual void hideEvent(QHideEvent *);
private:
    void _setText(const QString& text);
	void onClickedclose();

private:
    Ui::UnreadMessageNotice* ui;
    QString m_strAnchorageId;
    ShowType m_showType;
    bool        m_autohid;
signals:
    void sgTextClicked(const QString& anchorageId);
    void sgCancel();


};

#endif // UNREADMESSAGENOTICE_H
