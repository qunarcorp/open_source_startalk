#ifndef EMOTIONDIALOG_H
#define EMOTIONDIALOG_H

#include <QDialog>
#include <QList>
#include "ui_EmotionDialog.h"
#include <QScrollBar>
#include <QMovie>
#include <QLabel>
class EmotionTabDialog;

class EmotionDialog : public QWidget
{
    Q_OBJECT

public:
    EmotionDialog(QWidget *parent = 0);
    ~EmotionDialog();
	
    void initEmoticonPkgIcons(const QString& pkgid);

    void setitemInLine(int nLinecount);
	void setitemSize(int size);
	void setitempadding(int nsize);
	void setMinandMaxSize(int nwidth, int nheight);
	void deleteEmotionPkgIcons(const QString& pkgid);
	void settype(bool btype);
private:
    Ui::EmotionDialog ui;
    QMovie* m_pGifPlayer;
    void init();
	int m_itemInLine;
	int m_itemSize;
	int m_itempadding;
	bool m_type; //标识是那种类型的父窗口
	QWidget *mImagewidget; //预览图像的窗口
	QLabel *mEmotionlabel;
	QMovie* m_previewGifPlayer;
protected:
    virtual bool eventFilter(QObject *obj, QEvent *e);
	void EmotionPreView(const QString& filePath);
	virtual void showEvent( QShowEvent * );
signals:
    void sgSelectItem(const QString& pkgid, const QString &shortcut);
private slots:
    void onEmotionClicked();
    void onCustomEmotionLoaded(const QString& strLocalPath);
	void onCustomEmotionClicked();

	

};

#endif // EMOTIONDIALOG_H
