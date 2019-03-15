#include "rightextendpanel.h"
#include "ui_RightExtendPanel.h"
#include <QUuid>
#include "ChatDialog.h"
#include "WebPage.h"
#include "Session.h"
#include "accountmanager.h"
#include "webview.h"
#include "diywidgit/customviews/qframelayout.h"
#include "UserSettingData.h"
#include "ChatCommObject.h"
#include <QDesktopServices>

RightExtendPanel::RightExtendPanel(QWidget *parent)
	: QWidget(parent)
    , m_pWebview(NULL)
	, mPage(NULL)
	, mCommObject(NULL)
{
	ui = new Ui::RightExtendPanel();
	ui->setupUi(this);
    btnGroup = new QButtonGroup(ui->Titleswidget);

}

RightExtendPanel::~RightExtendPanel()
{

}

void RightExtendPanel::addTab( const QString& title, const QString& tiptext, quint64 id)
{
    if (mtabmap.contains(id))
    {
        ExtendPanelItem* pItem = mtabmap.value(id);
        pItem->m_titleButton->click();
    }
    else
    {
        ExtendPanelItem* pItem = new LabelExtendPanelItem(NULL);
        pItem->m_titleButton->setParent(ui->Titleswidget);
        pItem->m_titleButton->setText(title);
        pItem->m_titleButton->setToolTip(tiptext);
        ui->horizontalLayout->insertWidget(0,pItem->m_titleButton);
        btnGroup->addButton(pItem->m_titleButton);

        connect(pItem->m_titleButton,&QPushButton::clicked,[this,pItem](bool bcheck){
            ui->stackedWidget_right->setCurrentWidget(pItem->m_contentView);
        });
        connect(pItem->m_titleIcon,&QPushButton::clicked,[this,id]{
            delTab(id);
        });
        ui->stackedWidget_right->addWidget(pItem->m_contentView);
        pItem->m_titleButton->click();
        mtabmap.insert(id,pItem);
		pItem->m_titleIcon->setVisible(false);
    }
   
}


void RightExtendPanel::addWebTab(const QString& title, const QString& tiptext, quint64 id,const QString& targetUrl)
{
    if (mtabmap.contains(id))
    {
        WebExtendPanelItem* pItem = (WebExtendPanelItem*) mtabmap.value(id);
        pItem->m_strUrl = targetUrl;
        pItem->m_titleButton->click();
    }
    else
    {
        WebExtendPanelItem* pItem = new WebExtendPanelItem(NULL);

        pItem->m_titleButton->setParent(ui->Titleswidget);
        pItem->m_titleButton->setText(title);
        pItem->m_titleButton->setToolTip(tiptext);
        pItem->m_strUrl = targetUrl;
        ui->horizontalLayout->insertWidget(0,pItem->m_titleButton);
        btnGroup->addButton(pItem->m_titleButton);

        connect(pItem->m_titleButton,&QPushButton::clicked,[this,pItem](bool bcheck){
            ui->stackedWidget_right->setCurrentWidget(pItem->m_contentView);
            if (NULL == m_pWebview)
                initWebView();

            ui->stackedWidget_right->setCurrentWidget(m_pWebview);
            if (0 != m_pWebview->url().toString().compare(pItem->m_strUrl,Qt::CaseInsensitive))
            {

                m_pWebview->load(QUrl(pItem->m_strUrl));
            }
        });
        
        connect(pItem->m_titleIcon,&QPushButton::clicked,[this,id]{
            delTab(id);
        });

        pItem->m_titleButton->click();

        mtabmap.insert(id,pItem);
		pItem->m_titleIcon->setVisible(false);
    }
    
}

void RightExtendPanel::delTab( quint64 id )
{
    if (mtabmap.contains(id))
    {
        ExtendPanelItem* pItem = mtabmap.value(id);
        if (NULL!=pItem)
        {
            btnGroup->removeButton(pItem->m_titleButton);
            ui->horizontalLayout->removeWidget(pItem->m_titleButton);
            ui->horizontalLayout->update();

            if (NULL!= pItem->m_contentView)
            {
                ui->stackedWidget_right->removeWidget(pItem->m_contentView);
            }
            pItem->deleteLater();
            pItem = NULL;
        }
        mtabmap.remove(id);
    }

    if (mtabmap.isEmpty())
    {
        emit rightClose();
    }
    else
    {
        ExtendPanelItem* pItem = mtabmap.first();
        if (NULL!=pItem && NULL!=pItem->m_titleButton)
        {
            pItem->m_titleButton->click();
        }
    }
}



void RightExtendPanel::initWebView()
{
	mCommObject = new ChatCommObject(ui->stackedWidget_right);
	mPage = new WebPage(ui->stackedWidget_right);
    m_pWebview = new webview(ui->stackedWidget_right);  
	mPage->addChatChannelToHtml("CLIENT_API", mCommObject);
	m_pWebview->setPage(mPage);
	mCommObject->setWebPage(mPage);
    ui->stackedWidget_right->addWidget(m_pWebview);
    WebPage::addQuaryCookie(
    m_pWebview,
    Biz::Session::getAccountManager()->getCurrentUserSettingData()->QCookie(),
    Biz::Session::getAccountManager()->getCurrentUserSettingData()->VCookie(),
    Biz::Session::getAccountManager()->getCurrentUserSettingData()->TCookie());
    
	connect(mCommObject, &ChatCommObject::sgOpenUrlbyPc, this, &RightExtendPanel::onOpenUrlbyPc);
}

int RightExtendPanel::getTabCount()
{
    return mtabmap.size();
}

ExtendPanelItem* RightExtendPanel::getExtendView(quint64 id)
{
    if (mtabmap.contains(id))
    {
        return mtabmap.value(id);
    }
    return NULL;
}

void RightExtendPanel::showEvent(QShowEvent *e)
{
     emit visibleChange();
     QWidget::showEvent(e);
}

void RightExtendPanel::hideEvent(QHideEvent *e)
{
     emit visibleChange();
     QWidget::hideEvent(e);
}

ExtendPanelItem::ExtendPanelItem(QWidget* parentWidget)
{
    m_titleButton = new QPushButton(parentWidget);
    m_titleButton->setAutoExclusive(true);
    m_titleButton->setFixedSize(90,30);
    m_titleButton->setFlat(true);
    m_titleButton->setCheckable(true);
    m_titleButton->setStyleSheet(
        "QPushButton{border:none;border-bottom:1px solid #E5E5E5;border-right:1px solid #E5E5E5;background:#F5F5F5}"
        "QPushButton:checked{border:none;border-right:1px solid #E5E5E5;background:#FFFFFF;}");

    m_titleIcon = new QPushButton(m_titleButton);
    m_titleIcon->setFixedSize(16,16);
    m_titleIcon->setIconSize(QSize(16,16));
    m_titleIcon->setStyleSheet(
        "QPushButton{border:none;background:#00000000;border-radius:8px;}"
        "QPushButton:hover{background:#FFB03F;}");
    m_titleIcon->setIcon(QIcon(":/Images/close_mini_normal.png"));


    QFrameLayout* pTilteFrame = new QFrameLayout(m_titleButton);
    pTilteFrame->appendWidget(m_titleIcon,ALINE_VCENTER|ALINE_RIGHT);

    m_contentView = NULL;
}

ExtendPanelItem::~ExtendPanelItem()
{
    if (NULL!=m_titleIcon)
    {
        m_titleIcon->deleteLater();
        m_titleIcon = NULL;
    }
    if (NULL!=m_titleButton)
    {
        m_titleButton->deleteLater();
        m_titleButton = NULL;
    }
    if (NULL!=m_contentView)
    {
        m_contentView->deleteLater();
        m_contentView = NULL;
    }
}

void RightExtendPanel::onOpenUrlbyPc(const QString&url)
{
	QDesktopServices::openUrl(QUrl(url));
}