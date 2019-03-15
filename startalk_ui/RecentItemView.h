#ifndef RECENTITEMVIEW_H
#define RECENTITEMVIEW_H

#include <QTextEdit>
#include <QListWidgetItem>
#include <QPushButton>

namespace Ui {
    class recentitem;
}
class LocalManDialog;


class RecentItemViewBase : public QWidget
{
    Q_OBJECT
public:
    RecentItemViewBase(QWidget* parent);
    ~RecentItemViewBase();

};


class RecentItemView : public RecentItemViewBase
{
    Q_OBJECT
 public:
    RecentItemView(QWidget *parent);
    ~RecentItemView();
public:
	void setunReadFlag(bool flag);
    void setChecked(bool bChecked) {this->mbChecked = bChecked;};
    bool isChecked() const {return this->mbChecked;}  ;
    void setDisplayName(const QString& string);
    QString getDisplayName();
    void setDescription(const QString& string);
    QString description() const;
    void setUnReadCount(int count);
    int unreadCount() const;
    void setAtCount(int count, int type, const QString&senduser="");
    int atCount() const;
    int atType() const;
    void setAtFlag(bool b);
    void setTopFlag(bool top);
    bool isTop() const;
    void clearUnreadCount();
    void setHeaderIcon(const QPixmap& pixmap);
    void setHeaderVersion(quint64 version);
    quint64 headerVersion() const;
	void setStatusIcon(const QPixmap& pixmap);
	void setStatusHide();
	void setVirtualPixmap(const QPixmap&pix);

    inline void setID(const QString& id) {this->id = id;};
    inline QString Id() {return id;};



    virtual void mousePressEvent(QMouseEvent *);
    virtual void enterEvent(QEvent *);
    virtual void leaveEvent(QEvent *);

	void setUnReadPositionImage();
	void clearUnReadPositionImage();
	void InitFontSize();

    void disableCloseBtn();
    void enableBtnMark();
protected:
    virtual void resizeEvent(QResizeEvent *);

private:
	
	void setFontSize(int nsize);
    void updateTitle();

	void updateQChatDesption(const QString& shopname);
	
private:
    Ui::recentitem* ui;
private:
    bool mIsTop;
    bool mbChecked;
    int mAtCount;
    int mAtType;
    QString id;

    QString displayRawName;
    QString descStr;
    quint64 headerversion;
    static const int sMinTitleWidth;
	static const int sMinDescWidth;
private slots:
	void onFontSizeChange(int nsize);
    void onMainThemeChanged();

};

#endif // RECENTITEMVIEW_H
