#include "qimdroplistview.h"

#include <QLabel>
#include <QStyleHints>
#include <QGuiApplication>
#include <QMouseEvent>
#include <QTextEdit>
#include <QApplication>

#include "qframelayout.h"
#include "colorset.h"



class ItemWidget : public QWidget
{
public:
    ItemWidget(){
        pText = new QLabel();
        QFrameLayout* pLayout = new QFrameLayout(this);
        pLayout->appendWidget (pText,ALINE_FILL,QMargins(10,0,0,0));
        QWidget* pSliline = new QWidget(this);
        pSliline->setFixedHeight (1);
        pSliline->setStyleSheet ("border:none;background:#D1D1D1");
        pLayout->appendWidget (pSliline,ALINE_MATCHWIDTH|ALINE_BOTTOM,QMargins(10,0,10,0));
    };

    ~ItemWidget(){};
    QLabel* pText;
};

QIMDropListView::QIMDropListView(QWidget *parent)
    : QWidget(parent)
    , m_bChecked(false)
    , m_nSpacing(5)
    , m_pSelectedText(NULL)
    , m_pContentView(NULL)
    , m_pListView(NULL)
{
    // 提升的控件不能设置sheetstyle shit,再套一层加样式的
    QWidget* pWidget = new QWidget(this);
    pWidget->setObjectName ("domainpanel");
    QLabel* pStaticText = new QLabel(this);
    pStaticText->setFixedWidth (120);
    pStaticText->setText (QStringLiteral("查找范围："));
    pStaticText->setObjectName ("staticheadertext");
    pStaticText->setAlignment (Qt::AlignRight|Qt::AlignVCenter);
    
    

    QLabel* pSelectedText = new QLabel(this);
    pSelectedText->setFixedWidth (130);
    pSelectedText->setObjectName ("selectedheadertext");
    pSelectedText->setAlignment (Qt::AlignVCenter);
    m_pSelectedText = pSelectedText;

    QLabel* pIcoc = new QLabel(this);
    pIcoc->setFixedSize (16,16);
    
    QPixmap rawPixmap = QPixmap(":/Images/jietu_hover.png");
    

    pIcoc->setPixmap (rawPixmap);
    connect (this,&QIMDropListView::popupVisableChanged,[pIcoc](bool bCheck){
        const QPixmap* rawPixmap = pIcoc->pixmap ();
        QMatrix matrix;
        matrix.rotate(180);
        QPixmap pixmap = rawPixmap->transformed(matrix);
        pIcoc->setPixmap (pixmap);
    });


    QTextEdit* pAutoHideTool = new QTextEdit(this);
    pAutoHideTool->setFixedSize (0,0);
    QFrameLayout* layout = new QFrameLayout(this);
    layout->appendWidget (pAutoHideTool);
    layout->appendWidget (pWidget,ALINE_FILL);
    layout->appendWidget (pStaticText,AlinementPolicy::ALINE_MATCHHEIGHT|ALINE_LEFT);
    layout->appendWidget (pSelectedText,ALINE_MATCHHEIGHT|ALINE_LEFT,QMargins(125,0,0,0));
    layout->appendWidget (pIcoc,ALINE_RIGHT|ALINE_VCENTER,QMargins(0,0,20,0));
    this->setLayout (layout);

    QWidget* pContentView = new QWidget(this);
    QListWidget* pConentList = new QListWidget(pContentView);
    QIMDropListAdapter* pContentAdapter = new QIMDropListAdapter(pConentList);
    QHBoxLayout* pContentLayout = new QHBoxLayout(pContentView);
    pContentLayout->setSpacing (0);
    pContentLayout->setMargin (0);
    pContentLayout->addWidget (pConentList);
    pContentView->setLayout (pContentLayout);
    pContentView->setStyleSheet ("QListWidget{border:1px solid #D1D1D1;background:#F2F2F2;}");
    pContentView->setVisible (false);
    pConentList->setItemDelegate(pContentAdapter);
    m_pContentView = pContentView;
    m_pListView = pConentList;

    connect (m_pListView,&QListWidget::	itemClicked,[this,pContentAdapter](QListWidgetItem * current){
        if (NULL!=current)
        {
            ItemWidget* pWidget = dynamic_cast<ItemWidget*>(m_pListView->itemWidget (current));
            if (NULL!=pWidget)
            {
                QString text = pWidget->pText->text ();
                if (!text.isEmpty ())
                {
                    QSharedPointer<QIMDropListViewUserData> spUser = pContentAdapter->getData (text);
                    if (!spUser.isNull ())
                    {
                        emit this->currentTextChanged (text);
                        emit this->currentUserDataChanged (spUser);

                        this->m_pSelectedText->setText(text);
                        hidePopup ();
                    }
                }
            }
        }
    });

    pAutoHideTool->installEventFilter (this);


//     QList<QSharedPointer<QIMDropListViewUserData>> testdata;
//     QSharedPointer<QIMDropListViewUserData> spData;
//     spData = QSharedPointer<QIMDropListViewUserData>(new QIMDropListViewUserData());
//     spData->m_text=QStringLiteral("去哪员工组");
//     testdata.append (spData);
// 
//     spData = QSharedPointer<QIMDropListViewUserData>(new QIMDropListViewUserData());
//     spData->m_text=QStringLiteral("携程员工组");
//     testdata.append (spData);
//     spData = QSharedPointer<QIMDropListViewUserData>(new QIMDropListViewUserData());
//     spData->m_text=QStringLiteral("去哪商务组");
//     testdata.append (spData);
//     spData = QSharedPointer<QIMDropListViewUserData>(new QIMDropListViewUserData());
//     spData->m_text=QStringLiteral("携程商务组");
//     testdata.append (spData);
//     setData (testdata);
}

QIMDropListView::~QIMDropListView()
{

}

QWidget* QIMDropListView::createHeaderView(QWidget* widget)
{
    return NULL;
}

QWidget* QIMDropListView::createContentView(QWidget* content)
{
    return NULL;
}

void QIMDropListView::showPopup()
{
    if (count() <= 0 || NULL==m_pContentView)
        return;

    m_pContentView->setFixedWidth (this->width ());
    m_pContentView->setFixedHeight (130);

    QString currentText = m_pSelectedText->text ();

    QList<QListWidgetItem*> items = m_pListView->findItems (currentText,Qt::MatchExactly);
    if (!items.isEmpty ())
        m_pListView->setCurrentItem (items.at (0));

    if (!m_bChecked)
    {
        QPoint gThis = mapToGlobal (this->rect ().topLeft ());
        QPoint gContent = m_pContentView->mapToGlobal (m_pContentView->rect ().topLeft ());
        m_pContentView->move (gThis.x ()-gContent.x (), gThis.y ()-gContent.y () + this->height ()+3);
        m_pContentView->raise ();
        m_pContentView->show ();
        m_bChecked = true;
        emit popupVisableChanged(m_bChecked);
    }
    else
    {
        hidePopup();
    }
   
}

void QIMDropListView::hidePopup()
{
    m_bChecked =false;
    m_pContentView->move (QPoint(0,0));
    m_pContentView->hide ();
    emit popupVisableChanged(m_bChecked);
}

QWidget* QIMDropListView::_createDefaultHeaderView(QWidget* widget)
{
    return NULL;
}

QWidget* QIMDropListView::_createDefaultContentView(QWidget* widget)
{
    return NULL;
}

void QIMDropListView::mouseReleaseEvent(QMouseEvent * event)
{
    if (QGuiApplication::styleHints()->setFocusOnTouchRelease() && hasFocus())
        this->showPopupFromMouseEvent(event);
}

void QIMDropListView::mousePressEvent(QMouseEvent* event)
{
    if (!QGuiApplication::styleHints()->setFocusOnTouchRelease())
        this->showPopupFromMouseEvent(event);
}

void QIMDropListView::showPopupFromMouseEvent(QMouseEvent* event)
{
    if (event->button() == Qt::LeftButton) {
        showPopup ();
    } else {
        event->ignore();
    }
}

int QIMDropListView::count()
{
    QIMDropListAdapter* pAdapter = dynamic_cast<QIMDropListAdapter*>(m_pListView->itemDelegate());
    if (NULL!= pAdapter)
        return pAdapter->count ();
    return 0;
}

void QIMDropListView::setContentViewParent(QWidget* subParent)
{
    if (NULL!=m_pContentView)
        m_pContentView->setParent (subParent);
}

void QIMDropListView::setData(const QList<QSharedPointer<QIMDropListViewUserData>>& contentList)
{

    m_pListView->clear ();

    QIMDropListAdapter* pAdapter = dynamic_cast<QIMDropListAdapter*>(m_pListView->itemDelegate());
    if (NULL!=pAdapter)
        pAdapter->setData (contentList);
    
}

bool QIMDropListView::eventFilter(QObject *o, QEvent *event)
{
    QTextEdit* pEdit = dynamic_cast<QTextEdit*>(o);
    if (NULL!=pEdit && QEvent::FocusOut ==  event->type ())
    {
        hidePopup ();
    }

    return QWidget::eventFilter (o,event);
}

void QIMDropListView::setCurrentText(const QString& m_text)
{
    m_pSelectedText->setText (m_text);
}

QSharedPointer<QIMDropListViewUserData> QIMDropListView::getCurrentUserData()
{
    QIMDropListAdapter* pAdapter = dynamic_cast<QIMDropListAdapter*>(m_pListView->itemDelegate());
    if (NULL!=pAdapter)
        return pAdapter->getData (m_pSelectedText->text ());
    return QSharedPointer<QIMDropListViewUserData>();
}

QIMDropListAdapter::QIMDropListAdapter(QListView* parent)
    : ListWidgetBaseAdapter(parent)
{
    
}

QIMDropListAdapter::~QIMDropListAdapter()
{

}

QSize QIMDropListAdapter::sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    return QSize(32,32);
}


QWidget* QIMDropListAdapter::CreateNewWidget(const QModelIndex& index)
{
    QString dropitemId = index.data(DropListDataItemId).toString();

    ItemWidget* pWidget = new ItemWidget();
    pWidget->pText->setText (dropitemId);
    return pWidget;
}


void QIMDropListAdapter::setData(const QList<QSharedPointer<QIMDropListViewUserData>>& contentList)
{
    QListWidget*  pListWidget = dynamic_cast<QListWidget*>(this->parent ());
    values.clear ();
    pListWidget->clear ();

    if (NULL!=pListWidget)
    {
        for (QSharedPointer<QIMDropListViewUserData> spData:contentList)
        {
            if (!spData.isNull () && !spData->m_text.isEmpty ())
            {
                values.insert (spData->m_text,spData);

                QListWidgetItem* pItem = new QListWidgetItem(pListWidget);
                pItem->setText (spData->m_text);
                pItem->setData(DropListDataItemId,spData->m_text);
                pListWidget->addItem(pItem);
            }
        }
    }
}

void QIMDropListAdapter::updateData(QWidget* pWidget,const QModelIndex& index,const QStyleOptionViewItem& option)
{
    ItemWidget* itemWidget = dynamic_cast<ItemWidget*>(pWidget);
    if (NULL!=itemWidget)
    {
        if (option.state & QStyle::State_Selected)
            itemWidget->pText->setStyleSheet (QString("color:%1;").arg(ColorSetSingleton::getInstance ()->main_theme_text_active ()));
        else
            itemWidget->pText->setStyleSheet (QString("color:%1;").arg(ColorSetSingleton::getInstance ()->main_theme_text_normal ()));
    }
}

QSharedPointer<QIMDropListViewUserData> QIMDropListAdapter::getData(const QString& value)
{
    if (values.contains (value))
        return values.value (value);

    return QSharedPointer<QIMDropListViewUserData>();
}
