#ifndef EMOTIONTABDIALOG_H
#define EMOTIONTABDIALOG_H

#include <QWidget>
#include "ui_EmotionTabDialog.h"
#include "EmotionDialog.h"
#include <QPushButton>
#include <QMenu>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include "UtilHelper.h"

namespace Biz
{
    class EmoticonPackageInfo;
}

class EmotionMultiInfor
{
public:
	EmotionMultiInfor():emotiondlg(NULL),mEmotionPBtn(NULL),strEmotionFilePath(""),strTitle("")
	{

	}
public:
	EmotionDialog *emotiondlg;
	QPushButton *mEmotionPBtn;
	QString strEmotionFilePath;
	QString strTitle;
};
class EmotionTabDialog : public QWidget
{
	Q_OBJECT

public:
	EmotionTabDialog(QWidget *parent=0);
	~EmotionTabDialog();
public:
	void autoshow();
	inline void setConversionId(const QString& conversionId) { mconversionId = conversionId; };
	void addOneEmotionPackage(const QString& pkgid);

signals:
private slots:
	void onTabBtnClicked(bool b);

private:
	bool parseToolBarContianBtn(const QString&id);
	QPushButton*getEmotionButtonById(const QString&id);
	void onImportEmotion();
	void onExportEmotion();
	void onCustomEmotion();
	Ui::EmotionTabDialog ui;
	void init();
	void InitEmotion();
	void OnSettingMenu();
	void InitMenu();
	QMenu* settingMenu;
	QStringList getAllPackageIds();
	
private:

    QMap<QString,EmotionDialog*> mapEmoticonDialogs;

private:
	QString mconversionId;

signals:
    void sgSelectItem(const QString& wid,const QString& pkgid, const QString &shortcut);
	void sgSendImage(const QString& wid,const QString& imagePath);
    void sgSendUrlImage(const QString& wid,const QString& pkgid, const QString &shortcut);
        public slots:
            void onEmoticonSelected(const QString& pkgid,const QString& shortcut);
            void onCheckEmotionBtnClicked(bool bcheck);
            void onEmotionInfoListRecvied( const QList<QSharedPointer<Biz::EmoticonPackageInfo>>& list );
			void onReloadEmojiconPackage(const QString& pkgid);
			void OnSettingBtnClicked();
			void onDeleteCustormerEmotion(const QString&pkg);
			void OnDownloadFinishEmotionPackage(const QString&pkg);
	
};

typedef Util::SingletonTemplete<EmotionTabDialog> EmotionTabDialogSingleton;

class EmoticonDownloadInfoWidget : public QWidget
{
	Q_OBJECT
public:
    QHBoxLayout* horizontalLayout_5;
    QVBoxLayout* verticalLayout_3;
    QVBoxLayout* verticalLayout_4;
    QVBoxLayout* verticalLayout_5;
    QLabel* label;
    QLabel* name;
    QLabel* desc;
    QWidget* widget_5;// 文字区域
    QWidget* widget_6;// 名字区域
    QWidget* widget_8;// 描述区域
    QSpacerItem* verticalSpacer;
    QSpacerItem* verticalSpacer_2;

    QPushButton* download;

    QSharedPointer<Biz::EmoticonPackageInfo> spEpinfo;
	EmotionTabDialog* pTabDialog ;

public:
    ~EmoticonDownloadInfoWidget();;
    EmoticonDownloadInfoWidget(QWidget* parent);
	public slots:
		void onUpdateDescription(const QString& pkgid, const QString& descinfo);
		void onDownloadPackageResult(const QString& pkgid,bool bResult);
		void onDeleteEmotionPackage(const QString& pkgid);
};
#endif // EMOTIONTABDIALOG_H
