#include "UiHelper.h"
#include <QMetaType>     
#include <QDir>
#include <QDesktopServices>
#include <QWidget>
#include <QApplication>
#include <QFileIconProvider>
#include "XmppMessage.h"
#include "../QXmpp/client/QXmppClient.h"
#include "RosterList.h"
#include "../QXmpp/custom/QXmppMucRoomListIq.h"
#include "../QXmpp/custom/QXmppMucRoomMemberIq.h"
#include "../QXmpp/custom/QXmppChatSelfInfoIq.h"

#include "QJsonObject"
#include "MessageListData.h"
#include "define.h"
#include "GroupMemberModule.h"
#include "AdvData.h"

#include "ConfigureHelper.h"

#include "colorset.h"
#include "LanguageHelper.h"

#include "Session.h"
#include "AccountData.h"
#include "accountmanager.h"
#include "SystemConfigData.h"
#include "loginmanager.h"
#include "SystemDefine.h"
#include "editablesettings.h"
#include "SettingData.h"

#include "jsonobject/conversationparam.h"

#ifdef _WINDOWS
#include <windows.h>
#include <windowsx.h>
#endif

namespace MainApp
{
    void registerMetaTypes()
    {
        qRegisterMetaType<QXmppPresence>("QXmppPresence");
        qRegisterMetaType<QXmppClient::Error>("QXmppClient::Error");
        qRegisterMetaType<QSharedPointer<Biz::XmppMessage>>("QSharedPointer<XmppMessage>");
        qRegisterMetaType<QXmppMucRoomListIq>("QXmppMucRoomListIq");     
        qRegisterMetaType<QXmppMucRoomMemberIq>("QXmppMucRoomMemberIq");   
		qRegisterMetaType<QXmppChatSelfInfoIq>("QXmppChatSelfInfoIq");   
        qRegisterMetaType<QList<Biz::ImSession>>("QList<Biz::ImSession>");        
        qRegisterMetaType<QMap<QString, QString>>("QMap<QString, QString>");        
        qRegisterMetaType<QSharedPointer<Biz::MessageListData>>("QSharedPointer<Biz::MessageListData>");  
        qRegisterMetaType<QXmppDataForm>("QXmppDataForm");
        qRegisterMetaType<QList<QSharedPointer<Biz::RoomVcard>>>("QList<QSharedPointer<Biz::RoomVcard>>");
		qRegisterMetaType<QList<QSharedPointer<Biz::ImSelfPerson>>>("QList<QSharedPointer<Biz::ImSelfPerson>>");
        qRegisterMetaType<QList<QSharedPointer<Biz::EmoticonPackageInfo>>>("QList<QSharedPointer<Biz::EmoticonPackageInfo>>");
        qRegisterMetaType<QSharedPointer<Biz::CheckVersionUpdate>>("QSharedPointer<Biz::CheckVersionUpdate>");
		qRegisterMetaType<Biz::GroupMemberModule>("Biz::GroupMemberModule");
        qRegisterMetaType<QList<QSharedPointer<Biz::GroupMemberModule>>>("QList<QSharedPointer<Biz::GroupMemberModule>>");
        qRegisterMetaType<QList<QSharedPointer<Biz::RobotVcard>>>("QList<QSharedPointer<Biz::RobotVcard>>");
		qRegisterMetaType<QList<QSharedPointer<Biz::AdvDataItem>>>("QList<QSharedPointer<Biz::AdvDataItem>>");
        qRegisterMetaType<QSharedPointer<Biz::AdvDataItem>>("QSharedPointer<Biz::AdvDataItem>");
		qRegisterMetaType<QList <QSharedPointer<Biz::CollectionBindUserInfo>>>("QList <QSharedPointer<Biz::CollectionBindUserInfo>>");
		qRegisterMetaType<QMap<QString,QPair<int,int>>>("QMap<QString,QPair<int,int>>");
		qRegisterMetaType<QSharedPointer<Biz::ConversationParam>>("QSharedPointer<Biz::ConversationParam>");
		qRegisterMetaType<QMap<QString,int>>("QMap<QString,int>");
    }

    int comparisonWeightsPresenceStatusType(QXmppPresence::AvailableStatusType statusType)
    {
        switch(statusType)
        {
        case QXmppPresence::Online:
        case QXmppPresence::Chat:
            return 0;
        case QXmppPresence::DND:
            return 1;
        case QXmppPresence::Away:
        case QXmppPresence::XA:
            return 2;
        case QXmppPresence::Invisible:
            return 3;
		case QXmppPresence::Normal:
			return 6;
        default:
            return 5;
        }
    }

    int comparisonWeightsPresenceType(QXmppPresence::Type type)
    {
        switch(type)
        {
        case QXmppPresence::Available:
            return 0;
        case QXmppPresence::Unavailable:
            return 1;
        case QXmppPresence::Error:
        case QXmppPresence::Subscribe:
        case QXmppPresence::Subscribed:
        case QXmppPresence::Unsubscribe:
        case QXmppPresence::Unsubscribed:
        case QXmppPresence::Probe:
            return 3;
        default:
            return 5;
        }
    }

    QString presenceToStatusText(const QXmppPresence& presence)
    {
        QString statusText = presence.statusText();
        if(statusText.isEmpty())
        {
            if(presence.type() == QXmppPresence::Available)
            {
                switch(presence.availableStatusType())
                {
                case QXmppPresence::Invisible:
                    statusText = "Offline";
                    break;
                case QXmppPresence::Online:
                case QXmppPresence::Chat:
                    statusText = "Available";
                    break;
                case QXmppPresence::Away:
                case QXmppPresence::XA:
                    statusText = "Idle";
                    break;
                case QXmppPresence::DND:
                    statusText = "Busy";
                    break;
                }
            }
            else
                statusText = "Offline";
        }

        return statusText;
    }

    QString getSettingsDir(const QString& bareJid)
    {
        return QStandardPaths::locate(QStandardPaths::DataLocation, bareJid);
        //QString dir = QStandardPaths::locate(QStandardPaths::DataLocation, bareJid);
        //if(bareJid.isEmpty())
        //    return dir + "/";
        //else
        //    return QString(dir + "/%1/").arg(bareJid);
    }

    QString getSha1HashAsHex(const QByteArray& image)
    {
        if(image.isEmpty())
            return "";
        else
            return QString(QCryptographicHash::hash(image,
            QCryptographicHash::Sha1).toHex());
    }

    QImage getImageFromByteArray(const QByteArray& image)
    {
        QBuffer buffer;
        buffer.setData(image);
        buffer.open(QIODevice::ReadOnly);
        QImageReader imageReader(&buffer);
        return imageReader.read();
    }

    QString getImageType1(const QByteArray& image)
    {
        QBuffer buffer;
        buffer.setData(image);
        buffer.open(QIODevice::ReadOnly);
        QString format = QImageReader::imageFormat(&buffer);

        if(format.toUpper() == "PNG")
            return "image/png";
        else if(format.toUpper() == "MNG")
            return "video/x-mng";
        else if(format.toUpper() == "GIF")
            return "image/gif";
        else if(format.toUpper() == "BMP")
            return "image/bmp";
        else if(format.toUpper() == "XPM")
            return "image/x-xpm";
        else if(format.toUpper() == "SVG")
            return "image/svg+xml";
        else if(format.toUpper() == "JPEG")
            return "image/jpeg";

        return "image/unknown";
    }

    bool isValidBareJid(const QString& bareJid)
    {
        QRegExp re("^[^@]+@[^@]+$");
        return re.exactMatch(bareJid);
    }

    QByteArray calculateXor(const QByteArray& data, const QByteArray& key)
    {
        if(key.isEmpty())
            return data;

        QByteArray result;
        for(int i = 0 , j = 0; i < data.length(); ++i , ++j)
        {
            if(j == key.length())
                j = 0;
            result.append(data.at(i) ^ key.at(j));
        }
        return result;
    }

   

    void setSheetsStyle(QWidget* widget, QString qss)
    {
        if (NULL == widget || qss.isEmpty())
        {
            return;
        }
        if (qss.at(0) == ':')
        {
            QFile qf(qss);
            if(qf.open(QFile::ReadOnly)){

                auto buf = QString::fromUtf8(qf.readAll());
                widget->setStyleSheet(buf);
            }
        } 
        else 
        {

            QString qsspath = GetDebugOrReleasePath(QCoreApplication::applicationDirPath())/*QCoreApplication::applicationDirPath()*/ + "/resources/" + qss;
            QFile qf(qsspath);
            if(qf.open(QFile::ReadOnly)){

                auto buf = QString::fromUtf8(qf.readAll());
                widget->setStyleSheet(buf);
            }
        }
    }
    void imageToGray(QImage& img)
    {
        int depth = img.depth();
        if(depth != 32){
            img = img.convertToFormat(QImage::Format_RGB32);
        }
        
        QSize colourImgSize = img.size();   
        int width = colourImgSize.rwidth();   
        int height = colourImgSize.rheight();  
        unsigned char *data = img.bits();   
        int bytePerLine=(width*24+31)/8;//图像每行字节对齐


        //unsigned char* graydata=new unsigned char[bytePerLine*height];//存储处理后的数据

        unsigned char r,g,b;
        for (int i=0;i<height;i++)
        {
            for (int j=0;j<width;j++)
            {
                r = *(data+2);
                g = *(data+1);
                b = *data;
                int gray = (r*30+g*59+b*11)/100;
                //graydata[i*bytePerLine+j*3]  =gray;
                //graydata[i*bytePerLine+j*3+1]=gray;
                //graydata[i*bytePerLine+j*3+2]=gray;
                *data = gray;
                *(data+1) = gray;
                *(data+2) = gray;

                data+=4;
            }
        }
    }

	QString GetDebugOrReleasePath(const QString& path)
	{
        QString strRtPath = path + "/commonresource";
        QDir dir(strRtPath);
        if (dir.exists(strRtPath))
        {
            return strRtPath;
        }
        else
        {
            QString strPath = path;
            int pos = strPath.lastIndexOf("/");
            strRtPath = strPath.left(pos) + "/commonresource";
            return strRtPath;
        }
        return strRtPath;
#ifdef _DEBUG
		QString strPath = path;
		int pos = strPath.lastIndexOf("/");
		strRtPath = strPath.left(pos) + "/commonresource";
#else
		strRtPath = path + "/commonresource";
#endif // DEBUG
		return strRtPath;
	}

    QColor intToQColor(int i)
    {
        int red     = (i&0xFF0000)>>16;
        int green   = (i&0xFF00)>>8;
        int blue    = (i&0xFF);
        return QColor(red,green,blue);
    }

    int QColorToInt(QColor color)
    {
        QRgb rgb = color.rgb();
        int i =0;
        i += (0xff0000& qRed(rgb)<<16);
        i += (0xff00& qGreen(rgb) <<8);
        i += (0xff& qBlue(rgb));
        return i;
    }

    void changeTheme(const QString& themeName)
    {
        appendQssFile(themeName,"default.qss",true);
        appendQssFile(themeName,"common.qss");
        appendQssFile(themeName,"titlebar.qss");
        appendQssFile(themeName,"MultiDialogContainer.qss");
        appendQssFile(themeName,"groupchatdialog.qss");
        appendQssFile(themeName,"newsdialog.qss");
        appendQssFile(themeName,"simplechatdialog.qss");
        appendQssFile(themeName,"mainwidget.qss");
        appendQssFile(themeName,"friendssearcher.qss");

#ifdef _LINUX
        appendQssFile(themeName,"linuxpatch.qss");
#endif // _LINUX

        // 加载颜色资源
        loadColorData(themeName);
    }

    void appendQssFile(const QString& themeName,const QString& fileName,bool bRetheme)
    {
        
        if (fileName.isEmpty())
            return;
        
        QString strTargetPath = QString(":/theme/qss/%1/%2").arg(themeName,fileName);
        if (QFile::exists(strTargetPath))
        {
            QFile qf(strTargetPath);
            if(qf.open(QFile::ReadOnly)){

                auto buf = QString::fromUtf8(qf.readAll());
                if (!bRetheme)
                {
                    QString strCurQss = qApp->styleSheet();
                    buf = strCurQss + buf;
                }
              
                qApp->setStyleSheet(buf);
                return;
            }
        }
       
        // 默认样式
        QString strDefaultPath = QString(":/theme/qss/%1").arg(fileName);
        if (QFile::exists(strDefaultPath))
        {
            QFile qf(strDefaultPath);
            if(qf.open(QFile::ReadOnly)){

                auto buf = QString::fromUtf8(qf.readAll());
                if (!bRetheme)
                {
                    QString strCurQss = qApp->styleSheet();
                    buf = strCurQss + buf;
                }
                qApp->setStyleSheet(buf);
                return;
            }
        }

     
    }

    void loadColorData(const QString& themeName)
    {
        QString strTargetPath = QString(":/theme/qss/%1/color.dat").arg(themeName);
        if (QFile::exists(strTargetPath))
        {
            QFile qf(strTargetPath);
            if(qf.open(QFile::ReadOnly)){

                auto buf = QString::fromUtf8(qf.readAll());
                ColorSetSingleton::resetInstance()->unserializeFromString(buf);
                ColorSet* pset = ColorSetSingleton::getInstance();
                return;
            }
        }

        // 默认样式
        QString strDefaultPath = QString(":/theme/qss/color.dat");
        if (QFile::exists(strDefaultPath))
        {
            QFile qf(strDefaultPath);
            if(qf.open(QFile::ReadOnly)){

                auto buf = QString::fromUtf8(qf.readAll());
                ColorSetSingleton::resetInstance()->unserializeFromString(buf);
                return;
            }
        }
    };
    
    QString translateXmppError(int nFirstError, int nSecendError)
    {
        switch(nFirstError)
        {
        case QXmppClient::SocketError:
        case QXmppClient::KeepAliveError:
            if (QXmppStanza::Error::Condition::NoCondition == nSecendError)
            {
				//把导航的信息清除一下
				Biz::Session::getLoginNavSetting ()->LastUpdataTime (0);
				Biz::Session::saveLoginNavSetting ();
				Biz::ConfigureHelper::deleteNavConfigureFile();
                return T_("Message_Error");
            }
        case QXmppClient::XmppStreamError:
            {
                switch (nSecendError)
                {
                case QXmppStanza::Error::NotAuthorized:
                    return T_("NotAuthorized_Error");
                case QXmppStanza::Error::Conflict:
                    return T_("Conflict_Error");
                case QXmppStanza::Error::Condition::FailureOutOfDate:
                    return T_("OutOfDate_Error"); //  = "token已过期":
                case QXmppStanza::Error::Condition::FailurePolicyViolation:
                    return QStringLiteral("账号在其他设备登陆，请重新登陆"); //  = "token已过期":
				case QXmppStanza::Error::FialureServerDisconnect:
					return QStringLiteral("invalid-from 服务器主动断开连接");
			
                default:
                    break;
                }
            }
            break;
        default:
            break;
        }
        
        //return T_("Unknown_Error") + QString::number((int)nSecendError, 10);
		 return QStringLiteral("服务器主动断开连接, 请重启客户端");;

    }

    void makeMutex()
    {


    }

    bool checkMutex()
    {
#ifdef _WINDOWS
#ifndef _DEBUG
#ifdef QCHAT
        QString mutexid = "QCHAT" + Biz::Session::getAccountManager()->accountData().UserID();
#else
        QString mutexid = "QTALK" + Biz::Session::getAccountManager()->accountData().LoginAccount()
			+ Biz::Session::getLoginManager()->getNavConfig();
#endif // QCHAT

        HANDLE signalton = OpenMutex(MUTEX_MODIFY_STATE , NULL,mutexid.toStdWString().c_str());
        if (0 != signalton && Util::checkOneProgress)
        {
            CloseHandle(signalton);
            return true;
        }
        return false;
#else  // DEBUG
		return false;
#endif // !DEBUG
#else
        return false;
#endif // _WINDOWS
    }

    void cancelMutex()
    {

    }

    QString getMaxLineCountLimitText(
        const QString& rawText,
        int maxWidth,
        int lineLimit,
        const QFont& font)
    {
        QFontMetrics fm(font);
        QString res = fm.elidedText ("test",Qt::ElideLeft,fm.width ("tes"));

        int floatWidth = 0;
        if (!res.isEmpty ())
            floatWidth = fm.width (res.at (0));

        QString retString;
        QString leftString = rawText;

        for (;;)
        {
            int leftWidth = fm.width (leftString);
            if (leftWidth<maxWidth)
            {
                retString += leftString;
                break;
            }

            lineLimit--;
            if (0 == lineLimit)
            {
                // 最后一行
                QString elidedText = fm.elidedText(leftString, Qt::ElideRight, maxWidth);
                retString += elidedText;
                break;
            }

            QString elidedText = fm.elidedText(leftString, Qt::ElideRight, maxWidth+floatWidth);
            retString += elidedText.left (elidedText.length ()-1);
            retString += "\r\n";
            leftString = leftString.right (leftString.length() - elidedText.length ()+1);
        }
        return retString;
    }

	int getMaxWidthbyfont( const QString& text, int maxWidth, const QFont&font )
	{
		 QFontMetrics fm(font);
		 int nwidth = fm.width(text);
		 return nwidth>=maxWidth ? maxWidth:nwidth;
	}

	QString makeDefaultSavePath()
    {
        QString saveAsPath = Biz::Session::getEditableSettings()->DefaultSaveAsPath();
        if (saveAsPath.isEmpty())
        {
            Biz::AllUserSettingData* settingconfig = Biz::Session::getSettingConfig();
            QString localDeskPath = settingconfig->UserSaveAsPath();//Biz::ConfigureHelper::getDeskWindowPath();
            if (localDeskPath.isEmpty())
            {
                localDeskPath = Biz::ConfigureHelper::getDeskWindowPath();
                settingconfig->UserSaveAsPath(localDeskPath);
                Biz::Session::saveSettingConfig();
            }
            if (localDeskPath.right(1) != "/")
            {
                localDeskPath += "/";
            }

            saveAsPath = localDeskPath;

        }
        return saveAsPath;
    }

    QPixmap getFileIcon(const QString& filepath, QSize size)
    {
		QFileIconProvider fileIconProvider;
		QIcon fileIcon;
        if (QFile::exists (filepath))
        {
			Log::e(QString("QIcon getFileIcon exists"));
            // 算本地文件的图标计算路径
            QFileInfo myfileInfo(filepath);
            fileIcon = fileIconProvider.icon(myfileInfo);
            
        }
        else
        {
			Log::e(QString("QIcon getFileIcon is not exists"));
            // 看卡本地缓存的文件有没有
            QString suffer = QFileInfo(filepath).suffix ();
            if (!suffer.isEmpty ())
            {
                QString fileIconSavePath = Biz::ConfigureHelper::SystemTempPath()+suffer+".ico";
                if (QFile::exists (fileIconSavePath))
                {
                    QIcon icon(fileIconSavePath);
					QPixmap iconPixmap = fileIcon.pixmap(size);
                    return iconPixmap;
                }
            }

			fileIcon = fileIconProvider.icon(QFileIconProvider::IconType::File);

        }
		QPixmap iconPixmap = fileIcon.pixmap(size);
		return iconPixmap;
    }


    void saveFileIcon(const QString& filepath)
    {
        if (QFile::exists (filepath))
        {
             QFileInfo myfileInfo(filepath);
            QString suffer = myfileInfo.suffix ();
            if (!suffer.isEmpty ())
            {
                QString fileIconSavePath = Biz::ConfigureHelper::SystemTempPath()+suffer+".ico";
                if (!QFile::exists (fileIconSavePath))
                {
                   // 
					QFileIconProvider fileIconprovider;

					QIcon fileIcon = fileIconprovider.icon(myfileInfo);

				
                    fileIcon.pixmap (40,40).save (fileIconSavePath);
                }
            }
        }
    }

	QString getEscapeCharacterconver( const QString& strOrigin )
	{
		return "";
	}

}
