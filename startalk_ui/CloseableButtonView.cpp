#include "CloseableButtonView.h"
#include "ui_unreadmessagenotice.h"
CloseableButtonView::CloseableButtonView(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::UnreadMessageNotice)
    , m_showType(ST_NOTSET)
    , m_autohid(true)
{
    ui->setupUi(this);
    connect(ui->btn_close,&QPushButton::clicked,[this]{emit sgCancel();onClickedclose();});
    connect(ui->btn_text,&QPushButton::clicked,[this]{emit sgTextClicked(m_strAnchorageId);/*this->close();*/onClickedclose();});
}

CloseableButtonView::~CloseableButtonView()
{

}

void CloseableButtonView::setUpUnreadText(const QString& text)
{
    m_showType = ST_UPUNREAD;
    _setText(text);
    ui->icon->setPixmap(QPixmap(":Images/icon/pointup.png"));
}

void CloseableButtonView::setDownUnreadText(const QString& text)
{
    if (ST_UPUNREAD == m_showType)
    {
        // 上方未读消息优先
        return;
    }
     m_showType = ST_DOWNUNREAD;
     ui->icon->setPixmap(QPixmap(":Images/icon/pointdown.png"));
     _setText(text);
}

void CloseableButtonView::setAtTipText(const QString& text)
{
    ui->icon->setPixmap(QPixmap());
    _setText(text);
}

void CloseableButtonView::hideEvent(QHideEvent *)
{
    if (!m_autohid)
        return;
   m_showType = ST_NOTSET;
  // ui->btn_text->setText("");
   //m_strAnchorageId = "";
}

void CloseableButtonView::setAnchoragePoint(const QString& msgid)
{
    if (ST_UPUNREAD == m_showType)
    {
        // 上方未读消息优先
        return;
    }
    m_strAnchorageId = msgid;
}

void CloseableButtonView::_setText(const QString& text)
{
    QFontMetrics fontMetrics(ui->btn_text->font());
    int textwidth = fontMetrics.width(text);
    int finalWidth = qMax(30,qMin(200,textwidth)); // 最小70 最宽200
    QString displayText = fontMetrics.elidedText(text,Qt::ElideRight,finalWidth);
    ui->btn_text->setText(displayText);
    this->setFixedWidth(finalWidth+70);//两边按钮加一条分割线
}   

void CloseableButtonView::onClickedclose()
{
	m_showType = ST_NOTSET;
	ui->btn_text->setText("");
	m_strAnchorageId = "";
	this->hide();
}
