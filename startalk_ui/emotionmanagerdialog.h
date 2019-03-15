#ifndef EMOTIONMANAGERDIALOG_H
#define EMOTIONMANAGERDIALOG_H

#include "LocalManDialog.h"
#include "EmotionDialog.h"
#include "Player.h"
class QListWidgetItem;
class QListWidget;
namespace Ui{
	class EmotionManagerDialog;
}
class EmotionManagerDialog : public LocalManDialog
{
	Q_OBJECT

public:
	static EmotionManagerDialog* getInstance();
	void onShowEmotionManagerDialog();
	void initUi();
private:
	static EmotionManagerDialog* instance;
	EmotionManagerDialog(QWidget *parent);
	~EmotionManagerDialog();
	void InitLocalData();
	void InitServerData();
	void addOneEmotionPackage(const QString& pkgid, QListWidget*listwidget);
	void setEmotionPackageInfo(const QString& pkgid, const QString& downloadurl);
private slots:
	void onCloseclicked();
	void onTabBarClicked(int index);
	void onAddSaveEmotionBtnClicked();
	void onDeleteSaveEmotionBtnClicked();
	void onDownloadBtnClicked();
	void onCurrentItemChange(QListWidgetItem * item, QListWidgetItem*preitem);
	void onCurrentItemClicked(QListWidgetItem * item );
	void onCustomEmotionSelected();
	void onReloadEmojiconPackage(const QString&pkgi);
	void onCurrentItemServerChange(QListWidgetItem*item, QListWidgetItem*preitem);
	void onManagerEmotionInfoListRecvied(const QList<QSharedPointer<Biz::EmoticonPackageInfo>>& list);
	//下载的信息显示
	void onUpdateDescription(const QString& pkgid, const QString& descinfo);
	void onDownloadPackageResult(const QString& pkgid,bool bResult);
private:
	Ui::EmotionManagerDialog *ui;
	QStringList m_locallistwidget;
	QStringList m_Serverlistwidget;
	QMap<QString,EmotionDialog*> mapEmoticonManagerDialogs;
	QList<QSharedPointer<Biz::EmoticonPackageInfo>> m_emotionpackageInfolist;
	QSharedPointer<Biz::EmoticonPackageInfo> spDownloadinfo;
	QString m_CurrentId;
};

#endif // EMOTIONMANAGERDIALOG_H
