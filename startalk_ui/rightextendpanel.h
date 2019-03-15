#ifndef RIGHTEXTENDPANEL_H
#define RIGHTEXTENDPANEL_H

#include <QWidget>
#include <QSpacerItem>
#include <QHBoxLayout>
#include "MultiDialogContainer.h"
#include <QtNetwork/QNetworkCookie>
#include <QtNetwork/QNetworkCookieJar>
#include <QButtonGroup>
#include "WebPage.h"

namespace Ui
{
    class RightExtendPanel;
}

class ExtendPanelItem : public QObject
{
public :
    ExtendPanelItem(QWidget* parentWidget);;
    ~ExtendPanelItem();;
    QPushButton* m_titleButton;
    QPushButton* m_titleIcon;
    QWidget* m_contentView;
};
class WebExtendPanelItem : public ExtendPanelItem
{
public:
    WebExtendPanelItem(QWidget* parentWidget) : ExtendPanelItem(parentWidget){ };
    ~WebExtendPanelItem(){};
    QString m_strUrl;
};

class LabelExtendPanelItem : public ExtendPanelItem
{
public:
    LabelExtendPanelItem(QWidget* parentWidget) : ExtendPanelItem(parentWidget){
        QLabel* pLabel =  new QLabel(parentWidget);
        pLabel->setStyleSheet("background:#FFFFFF;");
        pLabel->setAlignment(Qt::AlignTop);
        pLabel->setTextInteractionFlags(Qt::TextSelectableByMouse);
        m_contentView = pLabel;
    };
    ~LabelExtendPanelItem(){};
};
class RightExtendPanel : public QWidget
{
	Q_OBJECT
public:
    enum EXTENDID{PRODUCTINFO,HISTORYINFO,PRODUCTINFO888, ROBOTINFO};
public:
	RightExtendPanel(QWidget *parent);
	~RightExtendPanel();
	void addTab(const QString& title, const QString& tiptext, quint64 id);
    void addWebTab(const QString& title, const QString& tiptext, quint64 id,const QString& targetUrl);
	void delTab(quint64 id);
    int  getTabCount();
    ExtendPanelItem* getExtendView(quint64 id);
private:
    void initWebView();
protected:
    virtual void showEvent(QShowEvent *);
    virtual void hideEvent(QHideEvent *);
private:
	Ui::RightExtendPanel* ui;
    
	QMap<quint64, ExtendPanelItem*> mtabmap;
    webview* m_pWebview;
    QButtonGroup* btnGroup;
	WebPage *mPage;
	ChatCommObject* mCommObject;
signals:
    void visibleChange();
    void rightClose();
public slots:
void onOpenUrlbyPc(const QString& url);

};

#endif // RIGHTEXTENDPANEL_H