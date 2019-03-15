#include "selgroupmember.h"
#include <QScrollBar>
#include "createnewgroup.h"
#include "portraithelper.h"
#include "SpellHelper.h"
#include "Session.h"
#include "Account.h"
#include "AccountData.h"



const QSize MEMMBERSIZE = QSize(32, 32);
const QSize MEMMBERSIZE_R = QSize(33, 33);
const int MAX_HC_STEP = 30;

SelGroupMember::SelGroupMember(LocalManDialog *parent)
	: LocalManDialog(parent)
	, ui(new Ui::SelGroupMember)
	, cacheIndex(0)
{
	ui->setupUi(this);

	using namespace Qt;
	auto remove = WindowTitleHint;
	auto add = FramelessWindowHint | WindowMinMaxButtonsHint;
	setAttribute(Qt::WA_AlwaysShowToolTips, true);
	setAttribute(Qt::WA_TranslucentBackground, true);
	overrideWindowFlags((Qt::WindowFlags)((windowFlags() & ~remove) | add));
#ifdef QCHAT
	setWindowIcon(QIcon(":/Images/Deal_chat.ico"));
#else
	setWindowIcon(QIcon(":/Images/Deal.ico"));
#endif

	ui->splitter->setOpaqueResize(true);
	ui->splitter->setStretchFactor(0, 5);
	ui->splitter->setStretchFactor(1, 5);
	ui->splitter->setAutoFillBackground(true);

	ui->stackedWidget->setCurrentWidget(ui->memberpage);
	ui->memberstack->setCurrentWidget(ui->friendPage);
	

	connect(ui->close, &QPushButton::clicked, [this](bool){this->close(); });
	connect(ui->cancle, &QPushButton::clicked, [this](bool){this->close(); });
	connect(ui->searchEdit, &QLineEdit::textChanged, this, &SelGroupMember::onSearchEditInputChange);
	connect(ui->ok, &QPushButton::clicked, this, &SelGroupMember::onselmember);

	connect(ui->listWidget->verticalScrollBar(), &QScrollBar::valueChanged, this, &SelGroupMember::onRightScrollBarValueChange);

}

SelGroupMember::~SelGroupMember()
{

}

void SelGroupMember::initGroupMember(const QMap<QString, QString>& membermap)
{
	//先对map进行排序
	//qSort(membermap.begin(), membermap.end());

	// 清除所有节点
	ui->friendList->setHeaderHidden(true);
	ui->friendList->clear();
	QTreeWidgetItem* pMemberItem = NULL;
	foreach(QString strone, membermap.keys())
	{
		// 将个人加在这
		QTreeWidgetItem* pPersonItem = new QTreeWidgetItem(ui->friendList);
		pPersonItem->setSizeHint(0, MEMMBERSIZE);
		PersonItem_L* pGroupL = new PersonItem_L(NULL);
		pGroupL->setDisaplay(membermap.value(strone));
		pGroupL->setTreeWidgetItemHolder(pPersonItem);
		pGroupL->setJid(strone);
		QString filePath = Biz::PortraitHelper::getUserPortraitPath(strone);
		pGroupL->setHeader(filePath);
		connect(pGroupL, &PersonItem_L::sgSelectPerson, this, &SelGroupMember::onMemberSelectChange);
		ui->friendList->addTopLevelItem(pPersonItem);
		ui->friendList->setItemWidget(pPersonItem, 0, pGroupL);

		//这里需要把自己给选中，然后放到右边
		//左边的不能点击，右边的也不能点击
		if (strone.compare(Biz::Session::currentAccount().accountData().UserID()) == 0)
		{
			pGroupL->setSelectDisEnable();
			onMemberSelectChange(pGroupL, true);
		}

		if (pMemberItem == NULL)
		{
			pMemberItem = pPersonItem;
		}
		m_mapTotalMembers.insert(strone, membermap.value(strone));
	}

	ui->friendList->setCurrentItem(pMemberItem);
	

}

void SelGroupMember::setGroupJid(const QString&jid)
{
	mGroupJid = jid;
}

void SelGroupMember::addNewPerson2Right(const QString& jid, const QString& displayName, bool closeable /*= true*/, bool stayTop /*= true*/)
{
	if (!m_mapPersonsR.contains(jid))
	{
		if (closeable&&m_mapExistMembers.contains(jid))
		{
			return;
		}
		QListWidgetItem* pItem = new QListWidgetItem();
		pItem->setSizeHint(MEMMBERSIZE_R);
		PersonItem_R* pWidget = new PersonItem_R(ui->listWidget);
		pWidget->setDisplayName(displayName);
		pWidget->setJid(jid);
		pWidget->setCloseable(closeable);
		connect(pWidget, &PersonItem_R::sgDeletePerson, this, &SelGroupMember::onRDeletePerson);
		if (stayTop)
		{
			ui->listWidget->insertItem(0, pItem);
		}
		else
		{
			ui->listWidget->addItem(pItem);
		}

		ui->listWidget->setItemWidget(pItem, pWidget);
		m_mapPersonsR.insert(jid, pItem);
	}
	AdjuestCreateButton();
}

void SelGroupMember::removePerson2Right(const QString& jid)
{
	if (m_mapPersonsR.contains(jid) && !m_mapExistMembers.contains(jid))
	{
		QListWidgetItem* pItem = m_mapPersonsR[jid];
		if (NULL != pItem)
		{
			int row = ui->listWidget->row(pItem);
			pItem = ui->listWidget->takeItem(row);
			delete pItem;
			m_mapPersonsR.remove(jid);
		}
	}
	if (m_mapPersonsCache.contains(jid))
	{
		m_mapPersonsCache.remove(jid);
	}
}

void SelGroupMember::AdjuestCreateButton()
{
	QStringList lst = m_mapPersonsR.keys();

	if (lst.count() > 1)
	{
		ui->ok->setEnabled(true);
	}
	else
	{
		ui->ok->setEnabled(false);
	}
}

void SelGroupMember::onSearchEditInputChange(const QString& key)
{
	if (key.length() <= 0)
	{
		ui->stackedWidget->setCurrentWidget(ui->memberpage);
		ui->memberstack->setCurrentWidget(ui->friendPage);
		return;
	}
	
	if (key.length()<3)
	{
		QTimeLine* pTimeLine = new QTimeLine(300);
		connect(pTimeLine, &QTimeLine::finished, [this, key, pTimeLine]{
			pTimeLine->deleteLater();
			QString strCurentText = ui->searchEdit->text();
			QMap<QString, QString> searchmap;
			if (strCurentText == key)
			{
				foreach(QString stroneid, m_mapTotalMembers.keys())
				{
					QString searchKey = Biz::SpellHelper::MakeSpellCode(key, (Biz::SpellHelper::SpellOptions)0).trimmed();
					QString rawVal = Biz::SpellHelper::MakeSpellCode(stroneid + ";" + m_mapTotalMembers.value(stroneid) , (Biz::SpellHelper::SpellOptions)0);
					if (rawVal.contains(searchKey, Qt::CaseInsensitive))
					{
						searchmap.insert(stroneid, m_mapTotalMembers.value(stroneid));
					}
				}
				
				rebuildSearchList(searchmap);

				ui->searchEdit->activateWindow();
				ui->searchEdit->setFocus();
			}
		});
		pTimeLine->start();
	}
	else
	{
		QMap<QString, QString> searchmap;
		foreach(QString stroneid, m_mapTotalMembers.keys())
		{
			QString searchKey = Biz::SpellHelper::MakeSpellCode(key, (Biz::SpellHelper::SpellOptions)0).trimmed();
			QString rawVal = Biz::SpellHelper::MakeSpellCode(stroneid + ";" + m_mapTotalMembers.value(stroneid), (Biz::SpellHelper::SpellOptions)0);
			if (rawVal.contains(searchKey, Qt::CaseInsensitive))
			{
				searchmap.insert(stroneid, m_mapTotalMembers.value(stroneid));
			}
		}

		rebuildSearchList(searchmap);

		ui->searchEdit->activateWindow();
		ui->searchEdit->setFocus();
		
	}
}

void SelGroupMember::onselmember()
{
	QStringList lst = m_mapPersonsR.keys();

	QStringList uidlstCache = m_mapPersonsCache.values();
	lst.append(uidlstCache);
	lst.append(m_mapExistMembers.keys());
	lst = lst.toSet().toList();


}

void SelGroupMember::onRightScrollBarValueChange(int value)
{
	QScrollBar* pbar = ui->listWidget->verticalScrollBar();
	if (pbar->maximum() - value < 10)
	{
		innerBuildResultList(cacheIndex, MAX_HC_STEP);
	}
}

void SelGroupMember::onMemberSelectChange(PersonItem_L* personL, bool selected)
{
	if (NULL == personL)
	{
		return;
	}


	m_mapPersonsCache.insert(personL->getDisplay(), personL->getJid());

	if (selected)
	{
		addNewPerson2Right(personL->getJid(), personL->getDisplay()); // + 圆圈选中

	}
	else
	{
		removePerson2Right(personL->getJid());
	}

	mergeHeadCount();

	AdjuestCreateButton();
}

void SelGroupMember::onRDeletePerson(const QString& jid)
{
	removePerson2Right(jid);

	if (m_mapPersonsL.contains(jid))
	{
		QTreeWidgetItem* item = m_mapPersonsL[jid];
		if (NULL != item)
		{
			PersonItem_L* pWidget = (PersonItem_L*)ui->jiagouTreeWidget->itemWidget(item, 0);
			if (NULL != pWidget)
			{
				pWidget->setSelectedBtnChecked(false);
			}
		}
	}

	if (m_mapSearchPersonsL.contains(jid))
	{
		QTreeWidgetItem* item = m_mapSearchPersonsL[jid];
		if (NULL != item)
		{
			PersonItem_L* pWidget = (PersonItem_L*)ui->searchTreeWidget->itemWidget(item, 0);
			if (NULL != pWidget)
			{
				pWidget->setSelectedBtnChecked(false);
			}
		}
	}

	m_mapPersonsCache.remove(m_mapPersonsCache.key(jid));
	mergeHeadCount();
	AdjuestCreateButton();
}

void SelGroupMember::mergeHeadCount()
{
	int count = m_mapPersonsCache.size();

	QStringList userids = m_mapPersonsCache.values();
	QStringList useridR = m_mapPersonsR.keys();
	foreach(QString userid, useridR)
	{
		if (!userids.contains(userid))
		{
			count++;
			userids.push_back(userid);
		}
	}

	QStringList useridex = m_mapExistMembers.keys();
	foreach(QString userid, useridex)
	{
		if (!userids.contains(userid))
		{
			count++;
			userids.push_back(userid);
		}
	}
	/*ui->headcount->setText(T_("CREATE_NEW_GROUP_TIP").arg(count));*/
}

void SelGroupMember::innerBuildResultList(int begin, int step)
{
	int i = 0; // 已经画了几个
	int j = 0; // 全队游标

	QMap<QString, QString>::iterator iter = m_mapPersonsCache.begin();
	for (; iter != m_mapPersonsCache.end(); iter++, j++)
	{
		if (i < step)
		{
			if (j >= begin)
			{
				addNewPerson2Right(iter.value(), iter.key()); // + 新建
				cacheIndex++;
				i++;
			}
		}
		else
		{
			break;
		}
	}

	AdjuestCreateButton();
}

void SelGroupMember::rebuildSearchList(const QMap<QString, QString>& membermap)
{
	// 清除所有节点
	ui->searchTreeWidget->setHeaderHidden(true);
	ui->searchTreeWidget->clear();
	mLstItems.clear();
	m_mapSearchPersonsL.clear(); // 用于 右向左 状态同步
	foreach(QString strone, membermap.keys())
	{
		// 将个人加在这
		QTreeWidgetItem* pPersonItem = new QTreeWidgetItem(ui->searchTreeWidget);
		pPersonItem->setSizeHint(0, MEMMBERSIZE);
		PersonItem_L* pGroupL = new PersonItem_L(NULL);
		pGroupL->setDisaplay(membermap.value(strone));
		pGroupL->setTreeWidgetItemHolder(pPersonItem);
		pGroupL->setJid(strone);
		QString filePath = Biz::PortraitHelper::getUserPortraitPath(strone);
		pGroupL->setHeader(filePath);
		connect(pGroupL, &PersonItem_L::sgSelectPerson, this, &SelGroupMember::onMemberSelectChange);
		ui->searchTreeWidget->addTopLevelItem(pPersonItem);
		ui->searchTreeWidget->setItemWidget(pPersonItem, 0, pGroupL);
		mLstItems.push_back(pPersonItem);
		m_mapSearchPersonsL.insert(strone, pPersonItem);
	}

	if (mLstItems.size() > 0)
	{
		ui->stackedWidget->setCurrentWidget(ui->searchpage);
		ui->searchTreeWidget->setCurrentItem(mLstItems[0]);
		PersonItem_L* pWidget = (PersonItem_L*)ui->searchTreeWidget->itemWidget(mLstItems[0], 0);
		pWidget->setActive(true);
	}
}
