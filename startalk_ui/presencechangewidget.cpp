#include "presencechangewidget.h"
#include "QXmppPresence.h"
PresenceChangeWidget::PresenceChangeWidget(QWidget *parent)
    : QWidget(parent)
{
    ui.setupUi(this);

    using namespace Qt;
    auto remove = WindowTitleHint;
    auto add = FramelessWindowHint | WindowMinMaxButtonsHint | Popup;
    setAttribute(Qt::WA_AlwaysShowToolTips, true);
/*    setAttribute(Qt::WA_TranslucentBackground, true); */
    overrideWindowFlags( (Qt::WindowFlags)((windowFlags() & ~remove) | add));


    connect(ui.away,&QToolButton::clicked,this,&PresenceChangeWidget::onPresenceSelect);
    connect(ui.online,&QToolButton::clicked,this,&PresenceChangeWidget::onPresenceSelect);
	connect(ui.busy,&QToolButton::clicked,this,&PresenceChangeWidget::onPresenceSelect);
// 	connect(ui.offline,&QToolButton::clicked,this,&PresenceChangeWidget::onPresenceSelect);
// 	connect(ui.checkin,&QToolButton::clicked,this,&PresenceChangeWidget::onPresenceSelect);
// 	connect(ui.checkout,&QToolButton::clicked,this,&PresenceChangeWidget::onPresenceSelect);
}

PresenceChangeWidget::~PresenceChangeWidget()
{

}

void PresenceChangeWidget::onPresenceSelect(bool b)
{
    
    QToolButton* psender = (QToolButton*) sender();
    do 
    {
        if (psender == ui.away)
        {
            emit sgPresenceChange(QXmppPresence::Away);
            break;
        }
        if (psender == ui.online)
        {
            emit sgPresenceChange(QXmppPresence::Online);
            break;
        }
		if (psender == ui.busy)
		{
			emit sgPresenceChange(QXmppPresence::busy);
			break;
		}
// 		if (psender == ui.offline)
// 		{
// 			emit sgPresenceChange(QXmppPresence::offline);
// 			break;
// 		}
// 		if (psender == ui.checkin)
// 		{
// 			emit sgPresenceChange(QXmppPresence::checkin);
// 			break;
// 		}
// 		if (psender == ui.checkout)
// 		{
// 			emit sgPresenceChange(QXmppPresence::checkout);
// 			break;
// 		}

    } while (false);
    this->close();
}

