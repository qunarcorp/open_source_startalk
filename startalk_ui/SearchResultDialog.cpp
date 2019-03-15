#include "SearchResultDialog.h"
#include <QScrollBar>
#include <QPair>
#include <QList>
#include <QPushButton>
#include <QRect>
#include "gloableeventobject.h"

SearchResultDialog::SearchResultDialog(QWidget *parent)
    : QDialog(parent)
{
    ui.setupUi(this);

    using namespace Qt;
    auto remove = WindowTitleHint;
    auto add = Qt::Tool |FramelessWindowHint | Qt::Popup;
    overrideWindowFlags( (Qt::WindowFlags)((windowFlags() & ~remove) | add));

    connect(ui.listWidget, &QListWidget::itemClicked, this, &SearchResultDialog::onItemClicked);
    connect(ui.lianxirenList, &QListWidget::itemClicked, this, &SearchResultDialog::onItemClicked);
    connect(ui.qunList, &QListWidget::itemClicked, this, &SearchResultDialog::onItemClicked);
    connect(ui.lianxirenList, &QListWidget::itemEntered,this,&SearchResultDialog::onLianxirenItemEnter);
    ui.lianxirenList->setMouseTracking(true);

    connect(GloableEventObject::getInstance(),&GloableEventObject::sgMainDialogMoved,this,&SearchResultDialog::onMainWidgetMoved);
}

SearchResultDialog::~SearchResultDialog()
{

}
void SearchResultDialog::onMainWidgetMoved()
{
    this->hide();
}
void SearchResultDialog::setList(const QStringList& resultList)
{
    ui.scrollArea->setVisible(false);
    ui.listWidget->setVisible(true);

    ui.listWidget->clear();
    ui.listWidget->addItems(resultList);
    ui.listWidget->setCurrentRow(0);
}

void SearchResultDialog::setList(const QList<QListWidgetItem*>& resultList)
{
    ui.scrollArea->setVisible(false);
    ui.listWidget->setVisible(true);

    ui.listWidget->clear();
    for(QListWidgetItem* pItem : resultList)
        ui.listWidget->addItem(pItem);
    ui.listWidget->setCurrentRow(0);
}

#if 0

void SearchResultDialog::setList(const QStringList& resultList, const QStringList& groupList)
{
    ui.scrollArea->setVisible(true);
    ui.listWidget->setVisible(false);
    // 设置窗口宽度
    ui.scrollAreaWidgetContents->setFixedWidth(this->width());
    ui.widget->setFixedWidth(this->width());

    ui.listWidget->setVisible(false);
    ui.lianxirenList->clear();
	QString strText;
    
    int ncount = resultList.count();
    QStringList strtmp = resultList.mid(0,ncount>200?200:ncount);
    ui.lianxirenList->addItems(strtmp);
    strText = QStringLiteral("联系人    %1人显示/共%2人").arg(strtmp.count()).arg(ncount);
    ui.lianxirenList->setCurrentRow(0);
    ui.label_2->setText(strText);
    

    if (groupList.isEmpty())
    {
        ui.qun_penal->setVisible(false);
    }
    else
    {
        ui.qun_penal->setVisible(true);
        ui.qunList->clear();

        ui.qunList->addItems(groupList);
		strText = QStringLiteral("群    共%1个群").arg(groupList.count());
		ui.label_4->setText(strText);
        if(resultList.length() > 0)
            ui.qunList->setCurrentRow(-1);
        else
            ui.qunList->setCurrentRow(0);
    }

    int hscrollheight = 10;
    QSize size = QSize(20,19);/*ui.lianxirenList->item(0)->sizeHint()*/;
	
    int h1 ;//= size.height()*resultList.size();
	if (resultList.size() > 200)
	{
		h1 = size.height() * 200;
	}
	else
	{
		h1 = size.height()*resultList.size(); 
	}
    int h2 = size.height()*groupList.size();
    if (/*ui.lianxirenList->horizontalScrollBar()->isVisible()*/1)
    {
        h1 += ui.lianxirenList->horizontalScrollBar()->height();
    }

    if (ui.qunList->horizontalScrollBar()->isVisible())
    {
        h2 += ui.qunList->horizontalScrollBar()->height();
    }
    ui.widget->setFixedWidth(this->width());
    ui.lianxirenList->setFixedHeight(h1);
    ui.qunList->setFixedHeight(h2);
    ui.widget->setFixedHeight(h1+h2+70);
    ui.scrollAreaWidgetContents->setFixedHeight(h1+h2+70);
    int frameHeight = qMin(h1+h2+70,500);
    this->setFixedHeight(frameHeight);
}

#endif
void SearchResultDialog::setList( const QList<QPair<QString,QString>>& resultList,const QStringList& groupList )
{
	ui.scrollArea->setVisible(true);
	ui.listWidget->setVisible(false);
	// 设置窗口宽度
	ui.scrollAreaWidgetContents->setFixedWidth(this->width());
	ui.widget->setFixedWidth(this->width());

	ui.listWidget->setVisible(false);
	ui.lianxirenList->clear();
	QString strText;

	int ncount = resultList.count();
	QList<QPair<QString,QString>> strtmp = resultList.mid(0,ncount>200?200:ncount);

	foreach(auto pairItem,strtmp)
	{
		QString name = pairItem.first;
		QString group = pairItem.second;
		QListWidgetItem* item = new QListWidgetItem(ui.lianxirenList);
		item->setData(Qt::UserRole+1,name);
		item->setData(Qt::UserRole+2,group);
		item->setText(name+ " " + group);
		ui.lianxirenList->addItem(item);
	}
	//ui.lianxirenList->addItems(strtmp);
	strText = QStringLiteral("联系人    %1人显示/共%2人").arg(strtmp.count()).arg(ncount);
	ui.lianxirenList->setCurrentRow(0);
	ui.label_2->setText(strText);


	if (groupList.isEmpty())
	{
		ui.qun_penal->setVisible(false);
	}
	else
	{
		ui.qun_penal->setVisible(true);
		ui.qunList->clear();

		ui.qunList->addItems(groupList);
		strText = QStringLiteral("群    共%1个群").arg(groupList.count());
		ui.label_4->setText(strText);
		if(resultList.length() > 0)
			ui.qunList->setCurrentRow(-1);
		else
			ui.qunList->setCurrentRow(0);
	}

	int hscrollheight = 10;
	QSize size = QSize(20,19);/*ui.lianxirenList->item(0)->sizeHint()*/;

	int h1 ;//= size.height()*resultList.size();
	if (resultList.size() > 200)
	{
		h1 = size.height() * 200;
	}
	else
	{
		h1 = size.height()*resultList.size(); 
	}
	int h2 = size.height()*groupList.size();
	if (/*ui.lianxirenList->horizontalScrollBar()->isVisible()*/1)
	{
		h1 += ui.lianxirenList->horizontalScrollBar()->height();
	}

	if (ui.qunList->horizontalScrollBar()->isVisible())
	{
		h2 += ui.qunList->horizontalScrollBar()->height();
	}
	ui.widget->setFixedWidth(this->width());
	ui.lianxirenList->setFixedHeight(h1);
	ui.qunList->setFixedHeight(h2);
	ui.widget->setFixedHeight(h1+h2+70);
	ui.scrollAreaWidgetContents->setFixedHeight(h1+h2+70);
	int frameHeight = qMin(h1+h2+70,500);
	this->setFixedHeight(frameHeight);
}

void SearchResultDialog::selectItem()
{
    if (ui.listWidget->isVisible() && ui.listWidget->currentRow()!=-1)
    {
        emit sgItemSelected(ui.listWidget->selectedItems().at(0)->text());
        emit sgItemSelectedEx(ui.listWidget->selectedItems().at(0));
        this->hide();
    }
    if (ui.lianxirenList->isVisible() && ui.lianxirenList->currentRow()!=-1)
    {
		QString selectName = ui.lianxirenList->selectedItems().at(0)->data(Qt::UserRole+1).toString();
        emit sgItemSelected(selectName);
        emit sgItemSelectedEx(ui.lianxirenList->selectedItems().at(0));
        this->hide();
    }
    if (ui.qunList->isVisible() && ui.qunList->currentRow()!=-1)
    {
        emit sgGroupSelected(ui.qunList->selectedItems().at(0)->text());
        this->hide();
    }
    
}
void SearchResultDialog::onItemClicked(QListWidgetItem *pItem)
{
    QListWidget* psender = (QListWidget*)sender();
    do 
    {
        if (psender == ui.listWidget)
        {
            emit sgItemSelected(pItem->text());
            emit sgItemSelectedEx(pItem);
            this->hide();
            break;
        }
        if (psender == ui.lianxirenList)
        {
			QString selectName = ui.lianxirenList->selectedItems().at(0)->data(Qt::UserRole+1).toString();
            emit sgItemSelected(selectName);
            emit sgItemSelectedEx(pItem);
            this->hide();
            break;
        }
        if (psender == ui.qunList)
        {
            emit sgGroupSelected(pItem->text());
            this->hide();
            break;
        }
    } while (false);
   
}
void SearchResultDialog::setMoveDown()
{
    if (!ui.scrollArea->isVisible())
    {
        if(ui.listWidget->currentRow() < ui.listWidget->count() )
        {
            ui.listWidget->setCurrentRow(ui.listWidget->currentRow()+1);
        }
    }
    else 
    {
    int curPosLianxiren = ui.lianxirenList->currentRow();
    int curPosQun = ui.qunList->currentRow();
    // 焦点在联系人
    if(curPosLianxiren!=-1)
    {
        int nextRow = curPosLianxiren+1 >= ui.lianxirenList->count() ? -1:curPosLianxiren+1;
        ui.lianxirenList->setCurrentRow(nextRow);
        if (nextRow<0)
        {
            if (ui.qun_penal->isVisible())
            {
                ui.qunList->setCurrentRow(0);
            }
            else
            {
                ui.lianxirenList->setCurrentRow(0);
            }
        }
    }
    // 焦点在群组
    if(curPosQun!=-1)
    {
        int nextRow = curPosQun+1 >= ui.qunList->count() ? -1:curPosQun+1;
        ui.qunList->setCurrentRow(nextRow);
        if (nextRow<0)
        {
            if (ui.lianxirenList->count() > 0)
            {
                ui.lianxirenList->setCurrentRow(0);
                
            }
            else
            {
                ui.qunList->setCurrentRow(0);
            }
            
        }
    }
    }
}

void SearchResultDialog::setMoveUp()
{
    if (!ui.scrollArea->isVisible())
    {
        if(ui.listWidget->currentRow() > 0)
        {
            ui.listWidget->setCurrentRow(ui.listWidget->currentRow()-1);
        }
    }
    else 
    {
    int curPosLianxiren = ui.lianxirenList->currentRow();
    int curPosQun = ui.qunList->currentRow();
    // 焦点在联系人
    if(curPosLianxiren!=-1)
    {
        int nextRow = curPosLianxiren-1;
        ui.lianxirenList->setCurrentRow(nextRow);
        if (nextRow<0)
        {
            if (ui.qun_penal->isVisible())
            {
                ui.qunList->setCurrentRow(ui.qunList->count()-1);
            }
            else
            {
                ui.lianxirenList->setCurrentRow(ui.lianxirenList->count()-1);
            }
        }
    }
    // 焦点在群组
    if(curPosQun!=-1)
    {
        int nextRow = curPosQun-1;
        ui.qunList->setCurrentRow(nextRow);
        if (nextRow<0)
        {
            if (ui.lianxirenList->count() > 0)
            {
                ui.lianxirenList->setCurrentRow(ui.lianxirenList->count()-1);
            }
            else
            {
                ui.qunList->setCurrentRow(ui.qunList->count() -1);
            }
            
        }
    }
    }

}


void SearchResultDialog::onLianxirenItemEnter(const QListWidgetItem* pitem)
{
   
}
