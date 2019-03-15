#ifndef SNIPSCREENTOOL_H
#define SNIPSCREENTOOL_H

#include <QObject>
#include <QToolBar>
#include <QMenu>

#include "FullScreenWidget.h"
#include "QPushButton"
#include <stack>
#include "snipscreemtoolbar.h"
// 功能说明
//     1 带有抓图功能
//     2 带有工具条
//     3 带有目录
class SnipScreemToolBar;
class ActionCommand;
class floatTextEdit;
class SnipScreenTool : public FullScreenWidget
{
    Q_OBJECT
public:
    ~SnipScreenTool();
    SnipScreenTool& Init();
    static SnipScreenTool* getInstance();
 
	inline void setConversionId(const QString& id) { mConversionId = id; }
    floatTextEdit* getTextEdit() {return pEdit;};
    void onSaveContext();
private :
    SnipScreenTool(QObject *parent);
    static SnipScreenTool* pInstance;
	QString mConversionId;
protected:
    virtual void showPictureEditContextMenu(const QPoint& pos);
    virtual void showPictureEditBar(const QRect& rec);
    virtual void mousePressEvent(QMouseEvent *);
    virtual void mouseReleaseEvent(QMouseEvent *);
    virtual void mouseDoubleClickEvent(QMouseEvent *);
    virtual void mouseMoveEvent(QMouseEvent *);
    virtual void paintEvent(QPaintEvent *);
    virtual void drawSelectedPixmap(void);
    virtual void keyPressEvent(QKeyEvent *);
    void onForcus(QFocusEvent *);
    virtual void JietuFinshed();
	virtual void JietuCancel();

protected slots:
    void onPenSizeChanged(int size);
    void onPenColorChanged(const QString& color);
    void onToolBarTypeChanged(SnipScreemToolBar::TOOLTYPE type);

    void onUndo();
signals:
    void sgFinish(const QString&id);
    void sgCancel(const QString&id);    

    

private:
private:
    int m_currentType;
    QMenu    m_menu;
    SnipScreemToolBar* m_toolbar;
    floatTextEdit* pEdit;
    ActionCommand* m_Actioning; // 当绘制结束的时候命令行压栈
     std::stack<ActionCommand*> m_actionStatck;
     bool _beEdit;
     int _fontSize;
     QColor _brushColor;
     int _burshSize;
};

#endif // SNIPSCREENTOOL_H
