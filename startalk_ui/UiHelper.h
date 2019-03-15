#ifndef UIHELPER_H
#define UIHELPER_H

#include "CoreObject.h"
#include "QXmppPresence.h"

#include <QCryptographicHash>
#include <QBuffer>
#include <QImageReader>
#include <QIcon>
#include <QMap>

namespace MainApp
{
// 	QMap <QString, QString> mEscpeCharInvalmap;
// 	mEscpeCharInvalmap.insert("&nbsp;", " ");
// 	mEscpeCharInvalmap.insert("&gt;", ">");
// 	mEscpeCharInvalmap.insert("&lt;", "<");
// 	mEscpeCharInvalmap.insert("&amp;", "&");
// 	mEscpeCharInvalmap.insert("&quot;", "\"");
// 
// 	mEscpeCharInvalmap.insert("&#34;", "\"");
// 	mEscpeCharInvalmap.insert("&#38;", "&");

	
    void registerMetaTypes();

    int comparisonWeightsPresenceStatusType(QXmppPresence::AvailableStatusType);
    int comparisonWeightsPresenceType(QXmppPresence::Type);

    QString presenceToStatusText(const QXmppPresence& presence);

    QString getSettingsDir(const QString& bareJid = "");

    QString getSha1HashAsHex(const QByteArray& image);
    QImage getImageFromByteArray(const QByteArray& image);
    QString getImageType1(const QByteArray& image);

    bool isValidBareJid(const QString& bareJid);

    QByteArray calculateXor(const QByteArray& data, const QByteArray& key);


    void imageToGray(QImage& img);

    void setSheetsStyle(QWidget* widget, QString qss);

	QString GetDebugOrReleasePath(const QString& path);

    QColor  intToQColor(int);
    int     QColorToInt(QColor);

    void    changeTheme(const QString& themeName);
    void    appendQssFile(const QString& themeName,const QString& fileName,bool bRetheme = false);
    void    loadColorData(const QString& themeName);
   
    QString translateXmppError(int nFirstError, int nSecendError);

    void    makeMutex();
    bool    checkMutex();
    void    cancelMutex();

    QString getMaxLineCountLimitText(const QString& rawText,int maxWidth,int lineLimit,const QFont& font);
	//根据文本和字体，获取文本的最大宽度
	int getMaxWidthbyfont(const QString& text, int maxWidth, const QFont&font);

    QString makeDefaultSavePath();

    QPixmap getFileIcon(const QString& filepath, QSize size);
    void    saveFileIcon(const QString& filePath);

	QString getEscapeCharacterconver(const QString& strOrigin);
}

#endif // UIHELPER_H
