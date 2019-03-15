#include "searchatresultdialog.h"
#include "Session.h"
#include "portraithelper.h"
#include "UserVcardManager.h"


const int ItemWidth = 130;
const int ItemHeight = 30;
const QSize ItemImage = QSize(26, 26);

SearchAtResultDialog::SearchAtResultDialog(QWidget *parent)
	: QWidget(parent)
	, ui(new Ui::SearchAtResultDialog)
{
	ui->setupUi(this);

	using namespace Qt;
	auto remove = WindowTitleHint;
	auto add = Qt::Tool | FramelessWindowHint | Qt::Popup;
	overrideWindowFlags((Qt::WindowFlags)((windowFlags() & ~remove) | add));

	connect(ui->listWidget, &QListWidget::itemClicked, this, &SearchAtResultDialog::onItemClicked);
	ui->listWidget->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	ui->listWidget->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	ui->listWidget->setSpacing(0);
	

}

SearchAtResultDialog::~SearchAtResultDialog()
{

}

void SearchAtResultDialog::setList(const QMap<QString, QString>& resultmap)
{
	ui->listWidget->clear();
	for (QString oneuserid: resultmap.keys())
	{

		QPixmap pixmap = Biz::PortraitHelper::getUserPortrait(oneuserid);
		QString strDisplayname = resultmap.value(oneuserid);
		QListWidgetItem* pItem = new QListWidgetItem(QIcon(pixmap.scaled(ItemImage)), strDisplayname);
		pItem->setData( Qt::UserRole+1,oneuserid);
		pItem->setSizeHint(QSize(ItemWidth, ItemHeight));
		ui->listWidget->addItem(pItem);
		
	}
	int nRow = ui->listWidget->count();
	ui->listWidget->setCurrentRow(nRow - 1);
}

void SearchAtResultDialog::setMoveDown()
{
	int curPos = ui->listWidget->currentRow();
	
	if (curPos != -1)
	{
		int nextRow = curPos + 1 >= ui->listWidget->count() ? -1 : curPos + 1;
		ui->listWidget->setCurrentRow(nextRow);
		if (nextRow < 0)
		{
			ui->listWidget->setCurrentRow(0);	
		}
	}
}

void SearchAtResultDialog::setMoveUp()
{
	int curPos = ui->listWidget->currentRow();
	
	if (curPos != -1)
	{
		int nextRow = curPos - 1;
		ui->listWidget->setCurrentRow(nextRow);
		if (nextRow < 0)
		{

			ui->listWidget->setCurrentRow(ui->listWidget->count() - 1);
		}
	}
}

void SearchAtResultDialog::selectItem()
{
	if (ui->listWidget->isVisible() && ui->listWidget->currentRow() != -1)
	{
		QListWidgetItem* pitem = ui->listWidget->selectedItems().at(0);
		QString selectUser = pitem->data(Qt::UserRole+1).toString();
		emit sgatItemSelected(selectUser);
		
		this->hide();
	}
}

void SearchAtResultDialog::onItemClicked(QListWidgetItem *item)
{
	QString selectUser = item->data(Qt::UserRole+1).toString();
	emit sgatItemSelected(selectUser);
	this->hide();
}

void SearchAtResultDialog::enterEvent(QEvent *event)
{
	
	ui->listWidget->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
}
	

void SearchAtResultDialog::leaveEvent(QEvent *)
{
	ui->listWidget->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
}
