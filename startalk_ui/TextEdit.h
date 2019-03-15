#ifndef TEXTEDIT_H
#define TEXTEDIT_H
#include <QTextEdit>
#include <QMenu>
#include <QDomElement>
#include <QDomDocument>
#include <QStack>
#include "gloableeventobject.h"

class MimeTypeMessage;

class TextEdit : public QTextEdit
{
    Q_OBJECT
public:
    static int EmotionPath;
    static int EmotionShortText;
    static int EmotionPkgid;
    static int EmotionUniqueKey;
    static int ImageType;
    static int ImageUrl;
public:
    TextEdit(QWidget *parent);
    ~TextEdit();

    virtual void keyPressEvent( QKeyEvent * );
public:
    QString getText(QStack<QString>& urlstack, const QString&jid); 
    void addAnimation(const QString& pkgid, const QString& shortcut);
    void addUrledAnimation(const QString& pkgid, const QString& shortcut);
    void clearAnimation();
    void insertImage(const QString& picFileName);
    void insertFile(const QString& fileName);

    void insertMimeData(const QMimeData* pMime);


    void setMimeTypeMessage(const QSharedPointer<MimeTypeMessage>& mtmsg);
    QSharedPointer<MimeTypeMessage> getMimeTypeMessage();

protected:
    virtual void wheelEvent(QWheelEvent *e);
    
private:
    QHash<QMovie*, QString> urls;
    QMenu *Menu;
    QString lastElement;
    QAction *qcpy;
    QAction *qpast;

signals:
    bool sgAltS_Pressed();
    bool sgCtrl_EnterPressed();
    bool sgEnter_Pressed();
	bool sgShift_EnterPressed();
    void sgScreenShotFile(QString&);
    void sgPaste();

    public slots:
        void onInputTextSizeChange(qreal val);
        private slots:
            void animate();
};

#endif // TEXTEDIT_H
