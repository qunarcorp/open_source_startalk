#include "RecentItemView.h"

#include "ui_RecentItem.h"
#include "LanguageHelper.h"
#include "LocalManDialog.h"
#include "MultiDialogContainer.h"
#include "gloableeventobject.h"

#include "Session.h"
#include "Account.h"
#include "MainWidget.h"
#include "Session.h"
#include "SettingData.h"
#include "GroupChatDialog.h"

#include "diywidgit/customviews/qframelayout.h"
#include "UIFrame.h"
#include "ConversationController.h"
#include "MainDialogController.h"

#include "MarkUserInfoWidget.h"
#include "SystemDefine.h"

#include "colorset.h"
#include "conversationmanager.h"
#include "CustomDefine.h"
#include "PersonCfgManager.h"
#include "CustomDefine.h"
#include "UiHelper.h"

RecentItemViewBase::RecentItemViewBase(QWidget* parent) : QWidget(parent)
{

}

RecentItemViewBase::~RecentItemViewBase()
{

}


const int RecentItemView::sMinTitleWidth = 115;
const int RecentItemView::sMinDescWidth = 115;

RecentItemView::RecentItemView(QWidget *parent) : RecentItemViewBase(parent)
    , ui(new Ui::recentitem)
    , id("") 
    , mIsTop(false)
    , mbChecked(false)
    , mAtCount(0)
    , mAtType(0)
    , headerversion(0)
{
    ui->setupUi(this);

    QFrameLayout* pLayout = new QFrameLayout(this);
    pLayout->appendWidget(ui->ri_panel  , AlinementPolicy::ALINE_FILL);
    pLayout->appendWidget(ui->leftext   , AlinementPolicy::ALINE_LEFT|ALINE_VCENTER,QMargins(0,0,0,0));
    pLayout->appendWidget(ui->unread    , AlinementPolicy::ALINE_RIGHT|ALINE_VCENTER,QMargins(0,0,5,0));
	pLayout->appendWidget(ui->unread_tip, AlinementPolicy::ALINE_RIGHT|ALINE_VCENTER,QMargins(0,0,5,0));
    this->setLayout(pLayout);

    ui->leftext->setVisible(false);
    ui->leftext->adjustSize();

    ui->btnMark->setVisible(false);

    connect(ui->btnMark,&QPushButton::clicked,[this]{
        MarkUserInfoWidgetSingleton::getInstance()->setData(id);
        MarkUserInfoWidgetSingleton::getInstance()->show();
    });

    connect(ui->btnClose,&QPushButton::clicked,[this](bool b){

    });

	connect(GloableEventObject::getInstance(), &GloableEventObject::sgFontSizeChange,this, &RecentItemView::onFontSizeChange);

	if (Biz::Session::getSettingConfig()->SetFontSize())
	{
		InitFontSize();
	}

    connect(MainApp::UIFrame::getMainDialogController(),&MainDialogController::sgMainThemeChanged,this,&RecentItemView::onMainThemeChanged);
	
    onMainThemeChanged();
	ui->titleimage->hide();
	ui->widget_3->setVisible(false);
	ui->widget_3->hide();
	ui->unread_tip->setVisible(false);
	ui->unread->setVisible(false);
}

RecentItemView::~RecentItemView()
{
}

void RecentItemView::setDisplayName(const QString& string)
{
	displayRawName = string;
	updateTitle();

}
QString RecentItemView::getDisplayName()
{
    return displayRawName;
}


void RecentItemView::setDescription(const QString& string)
{
 #ifdef QCHAT
 	updateQChatDesption(string);
 #else 
	this->descStr  = string;

	QString newDisplay = string;
	QFontMetrics elidfont(ui->desc->font());
	QString elidedText = elidfont.elidedText (newDisplay, Qt::ElideRight, qMax(sMinDescWidth,ui->desc->width()));
	//ui->desc->setText(mIsTop?QString("<span style=\"color:#FF555E;\">%1</span>").arg(elidedText):elidedText);
	if (QString::compare(Biz::Session::getSettingConfig()->themeName(), "Light", Qt::CaseInsensitive) == 0)
	{
		int nclr = Biz::Session::getSettingConfig()->LightDescClr();
		QString strclr= QString::number(nclr, 16);
		ui->desc->setStyleSheet( QString("color:#%1;").arg(strclr));
		//ui->desc->setText(QString("<span style=\"color:#%1;\">%2</span>").arg(strclr).arg(elidedText));
	}
	else
	{
		int nclr = Biz::Session::getSettingConfig()->DarkDescClr();
		QString strclr = QString::number(nclr, 16);
		ui->desc->setStyleSheet( QString("color:#%1;").arg(strclr));
		//ui->desc->setText(QString("<span style=\"color:#%1;\">%2</span>").arg(strclr).arg(elidedText));
	}
	ui->desc->setText(elidedText);
	ui->desc->setProperty("desc_text",newDisplay);

#endif // QCHAT
}

void RecentItemView::setUnReadCount(int count)
{
#ifdef QCHAT
	if (ui->unreadimg)
	{
		ui->unreadimg->setVisible(false);
	}
#endif // QCHAT

	//"接收不提醒"====未读消息变成红点，而非现在的未读消息数；
	/*QSharedPointer<Biz::PersonConfInfo> spPersonCfgOfNotice = 
		Biz::Session::getPersonCfgManager()->getPersonCfgInfo(Biz::ConverSationManager::sSetNoticeTipKey);
	QStringList ids;
	if (!spPersonCfgOfNotice.isNull())
	{
		QString jsonData = spPersonCfgOfNotice->infoValue();
		QVariantMap topMostMaps 
			= QJsonDocument::fromJson(jsonData.toUtf8()).toVariant().toMap();


		for (QString conversationId : topMostMaps.keys())
		{
			int nValue = topMostMaps.value(conversationId).toInt();
			if (Biz::SESSION_CFG_SILENCE == (nValue & Biz::SESSION_CFG_SILENCE))
			{
				ids.append(conversationId);
			}
		}
	}

	if (ids.contains(id))
	{
		ui->unread->setVisible(false);
		ui->unread->setText("");
		if (ui->unread)
		{
			if (count > 0)
			{
				//setUnReadPositionImage();
				ui->unread->setVisible(true);
			}
			if(count == 0)
			{
				
				clearUnReadPositionImage();
			}
			return;
		}
	}
	else*/
	{
		if (ui->unread)
		{
			if (count == 0)
			{
				ui->unread->setVisible(false);
				ui->unread->setText("");
				return;
			}
			else if (count > 0)
			{
				ui->unread->setText(QString("%1").arg(count));
				ui->unread->adjustSize();
				ui->unread->setVisible(true);
			}
		}
		
	}

}

void RecentItemView::setAtCount(int count, int type, const QString&senduser)
{
    this->mAtCount = count;
    this->mAtType = type;

    QString atString = "";
    if (mAtCount!=0)
    {
		if (type == Biz::AtOne)
		{
			atString = QString(T_("MultiChatDialog_AtCount").arg(mAtCount));
		}
		else if (type == Biz::AtAll)
		{
			atString = QString(T_("MultiChatDialog_AtAll").arg(senduser));
		}
       
		QString atHtmlString = QString("<span style=\"color:#F55F56;\">%1</span>").arg(atString);
		ui->desc->setText(atHtmlString);
    }

}

void RecentItemView::updateTitle() {
    QString topString = "";
    if (mIsTop) {
        
        topString = QStringLiteral("[置顶] ");
    }

    QString newDisplay = topString+displayRawName;

    QFontMetrics elidfont(ui->title->font());
    QString elidedText = elidfont.elidedText (newDisplay, Qt::ElideRight, qMax(sMinTitleWidth,ui->title->width()));
    ui->title->setText(mIsTop?QString("<span style=\"color:#FF555E;\">%1</span>").arg(elidedText):elidedText);
    ui->title->setProperty("raw_text",newDisplay);
	if (Biz::Session::getSettingConfig()->SetFontSize())
	{
	    InitFontSize();
	}
}


void RecentItemView::updateQChatDesption(const QString& shopname)
{
	QString newDisplay = QStringLiteral("[咨询%1店铺中产品]").arg(shopname);
	ui->titleimage->setToolTip(newDisplay);
}

void RecentItemView::setAtFlag(bool b)
{
}

void RecentItemView::setTopFlag(bool top) {
    this->mIsTop = top;
    updateTitle();
}

void RecentItemView::clearUnreadCount()
{
    ui->unread->setText("");
    setAtFlag(false);
}

void RecentItemView::setHeaderIcon(const QPixmap& pixmap)
{
    //ui->header->setScaledContents(true);
	QPixmap pix = pixmap;
	pix = QPixmap::fromImage(pix.toImage().scaled(ui->header->size()));
    ui->header->setPixmap(pix);
}

void RecentItemView::mousePressEvent(QMouseEvent *e)
{
    setAtCount(0, Biz::AtOne);
    QWidget::mousePressEvent(e);
}

void RecentItemView::enterEvent(QEvent *)
{
    QRect rect = this->rect();

	if (!Biz::MessageUtil::compareUserId(id, Util::SUBSCRIPTIONNUM_ID))
	{
        ui->leftext->setVisible(false & ui->leftext->isEnabled());
	}
    
}

void RecentItemView::leaveEvent(QEvent *)
{
    ui->leftext->setVisible(false);
}

void RecentItemView::setUnReadPositionImage()
{
	ui->unreadimg->setVisible(true);
	QPixmap pixmap(":Images/close.png");
	QSize size = ui->unreadimg->size();
	pixmap = QPixmap::fromImage(pixmap.toImage().scaled(ui->unreadimg->size()));
	ui->unreadimg->setPixmap(pixmap);
}

void RecentItemView::clearUnReadPositionImage()
{
	ui->unreadimg->setVisible(false);
}

void RecentItemView::InitFontSize()
{
	int nFontsize = Biz::Session::getSettingConfig()->MFontSize();
	setFontSize(nFontsize);
}

void RecentItemView::setFontSize( int nsize )
{
	if (nsize < 14)
	{
		nsize = 14;
	}
	else if (nsize >20 )
	{
		nsize = 20;
	}

//     QFont font = ui->title->font();
//     font.setPixelSize(nsize);
//     ui->title->setFont(font);
//	ui->title->setStyleSheet(QString("font-size:%1px;").arg(nsize));
}

void RecentItemView::onFontSizeChange( int nsize )
{
	setFontSize(nsize);
}

QString RecentItemView::description() const
{
    return descStr;
}

int RecentItemView::unreadCount() const
{
    QString unreadText = ui->unread->text();
    int ret =  ui->unread->text().isEmpty()?0:ui->unread->text().toInt();
    return ret;
}

int RecentItemView::atCount() const
{
    return mAtCount;
}

int RecentItemView::atType() const
{
    return mAtType;
}

bool RecentItemView::isTop() const
{
    return mIsTop;
}

void RecentItemView::setHeaderVersion(quint64 version)
{
    this->headerversion = version;
}

quint64 RecentItemView::headerVersion() const
{
    return headerversion;
}

void RecentItemView::resizeEvent(QResizeEvent *e)
{
    QString newDisplay = ui->title->property("raw_text").toString();
    QFontMetrics elidfont(ui->title->font());
    int width = ui->title->width();
    QString elidedText = elidfont.elidedText (newDisplay, Qt::ElideRight, qMax(sMinTitleWidth,width));
    ui->title->setText(mIsTop?QString("<span style=\"color:#FF555E;\">%1</span>").arg(elidedText):elidedText);

	if (atCount()>0)
	{
		setAtCount(mAtCount,mAtType,"");
	} else if (!descStr.isEmpty())
	{
		setDescription(descStr);
	}

    RecentItemViewBase::resizeEvent(e);
}

void RecentItemView::disableCloseBtn()
{
    ui->leftext->setVisible(false);
}

void RecentItemView::enableBtnMark()
{
    ui->btnMark->setVisible(true);
    ui->leftext->adjustSize();
}

void RecentItemView::onMainThemeChanged()
{
    ColorSet* pset = ColorSetSingleton::getInstance();
	//这地方根据设置的北京色来对title 和 desc 进行设置颜色
	//如果黑色背景的desc的颜色需要重新设置一下

	bool bret = mbChecked;
	QString strtitleclor = QString("color:%1;").arg( mbChecked ? ColorSetSingleton::getInstance()->recent_item_title_checked():ColorSetSingleton::getInstance()->recent_item_title_normal());
	QString strdescclor = QString("color:%1;").arg( mbChecked ? ColorSetSingleton::getInstance()->recent_item_desc_checked():ColorSetSingleton::getInstance()->recent_item_desc_normal());
    ui->title->setStyleSheet(QString("color:%1;").arg( mbChecked ? ColorSetSingleton::getInstance()->recent_item_title_checked():ColorSetSingleton::getInstance()->recent_item_title_normal()));
    ui->desc->setStyleSheet( QString("color:%1;").arg( mbChecked ? ColorSetSingleton::getInstance()->recent_item_desc_checked():ColorSetSingleton::getInstance()->recent_item_desc_normal()));
}

void RecentItemView::setStatusIcon( const QPixmap& pixmap )
{
	QPixmap pix = pixmap;
	pix = QPixmap::fromImage(pix.toImage().scaled(ui->header->getlbStaticSize()));
	ui->header->showStatic(true);
	ui->header->setlbStaticPixmap(pix);
}

void RecentItemView::setStatusHide()
{
	ui->header->showStatic(false);
}

void RecentItemView::setVirtualPixmap( const QPixmap&pixmap )
{
	QPixmap pix = pixmap;
	pix = QPixmap::fromImage(pix.toImage().scaled(QSize(16,16)));
	//ui->header->showltStatic(true);
	//ui->header->setltStaticPixmap(pix);
	ui->titleimage->show();
	ui->titleimage->setPixmap(pix);
	ui->widget_3->setVisible(true);
	
}

void RecentItemView::setunReadFlag(bool flag)
{
	if (flag)
	{
		ui->unread_tip->setFixedSize(QSize(8,8));
	}
	ui->unread->setVisible(false);
	ui->unread_tip->setVisible(flag);
}
