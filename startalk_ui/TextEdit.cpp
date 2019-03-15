#include "TextEdit.h"
#include <QKeyEvent>
#include <QTextDocument>
#include <QStack>
#include <QMovie>
#include <QTextDocument>
#include "ConfigureHelper.h"
#include "LanguageHelper.h"
#include "gloableeventobject.h"
#include "Session.h"
#include "SettingData.h"
#include "QTextBlock"

#include "EmotionManager.h"
#include "UtilHelper.h"
#include "ImageHelper.h"
#include "BaseChatDialog.h"
#include "accountmanager.h"
#include "SpellHelper.h"
#include "portraithelper.h"
#include "UIFrame.h"
#include "ConversationController.h"

int TextEdit::EmotionPath = 0x5012;
int TextEdit::EmotionShortText = 0x5013;
int TextEdit::EmotionUniqueKey = 0x5014;
int TextEdit::ImageType        = 0x5015;
int TextEdit::EmotionPkgid     = 0x0516;
int TextEdit::ImageUrl         = 0x5017;


#include "diywidgit/htmlparser/ParserDom.h"
#include "diywidgit/htmlparser/utils.h"
#include "diywidgit/htmlparser/Node.h"
using namespace htmlcxx;


static const QString ImageType_Image = "ImageType_Image";
static const QString ImageType_Emot = "ImageType_Emot";


TextEdit::TextEdit(QWidget *parent)
    : QTextEdit(parent)
{
    connect(GloableEventObject::getInstance(),&GloableEventObject::sgInputTextChange,this,&TextEdit::onInputTextSizeChange);
}

TextEdit::~TextEdit()
{
    disconnect(GloableEventObject::getInstance(),&GloableEventObject::sgInputTextChange,this,&TextEdit::onInputTextSizeChange);
}

void TextEdit::keyPressEvent( QKeyEvent * e )
{
    do 
    {
        if(e == QKeySequence::Paste){
            //拦截标准的粘贴
            emit sgPaste();
            return;
        }

        if(e->key() == Qt::Key_Enter || e->key() == Qt::Key_Return){
            if( (e->modifiers() & Qt::SHIFT)){
                //shift + 回车，换行
				if( emit sgShift_EnterPressed() ){
					return;
				}
                e->setModifiers( e->modifiers() & ~Qt::SHIFT);
                break;
            }
            else if( e->modifiers() & Qt::CTRL) {
                // ctrl + 回车
                if( emit sgCtrl_EnterPressed() ){
                    return;
                }
                e->setModifiers( e->modifiers() & ~Qt::CTRL);
                //去掉ctrl
                break;
            }
            else {
                if( emit sgEnter_Pressed() ){
                    return;
                }
            }
        }

        //alt +S
        if ((e->modifiers()&Qt::AltModifier) && e->key()==Qt::Key_S )
        {
            if( emit sgAltS_Pressed() )
                return;
        }
    } while (false);

    QTextEdit::keyPressEvent(e);
}

void TextEdit::insertImage(const QString& picFileName)
{
    Log::e(QString("TextEdit::insertImage picFileName=%1").arg(picFileName) );

    QImage image = Biz::ImageHelper::loadImageFromPath (picFileName);
    if (image.isNull ()){
        insertPlainText (QStringLiteral("[图片已损坏]"));
        return;
    }

    QUrl Uri = QUrl::fromLocalFile (picFileName);
    document()->addResource( QTextDocument::ImageResource, Uri, QVariant (image) );    
    int fixw = image.width();
    int fixh = image.height(); //  最宽150 最高100 算纵横比

    float scaleRate = qMax(fixh*1.0/100,fixw*1.0/150);
    if (scaleRate>1.0)
    {
        // 计算缩放
        fixw = image.width()/scaleRate;
        fixh = image.height()/scaleRate;
    }

    QTextImageFormat imageFormat;
    imageFormat.setWidth( fixw );
    imageFormat.setHeight( fixh );
    imageFormat.setName( Uri.toString() );

    QString emotionkey = QUuid::createUuid().toString().replace("{", "").replace("}", "").replace("-", "");

    imageFormat.setProperty(TextEdit::EmotionPath,Uri.toString());
    imageFormat.setProperty(TextEdit::EmotionUniqueKey,emotionkey);
    imageFormat.setProperty(TextEdit::ImageType,ImageType_Image);


    textCursor().insertImage(imageFormat);
}

void TextEdit::insertFile(const QString& fileName)
{

}

void TextEdit::insertMimeData(const QMimeData* pMime)
{
    
    
}

void TextEdit::addAnimation(const QString& pkgid, const QString& shortcut)
{
    QString emotionkey = QUuid::createUuid().toString().replace("{", "").replace("}", "").replace("-", "");

    QSharedPointer<Biz::EmotionItem> spItem = Biz::Session::getEmoticonManager()->findEmoticon(pkgid,shortcut);
    if (spItem.isNull())
    {
        return;
    }
    QString fileName = spItem->strPath;
    QMovie* movie = new QMovie(this);
    movie->setFileName(fileName);
    urls.insert(movie, emotionkey);
    connect(movie, SIGNAL(frameChanged(int)), this, SLOT(animate()));
    movie->start();

    QTextImageFormat imageFormat;
    //imageFormat.setName( emotionkey );
    imageFormat.setName( fileName );
    imageFormat.setProperty(TextEdit::EmotionPath,fileName);
    imageFormat.setProperty(TextEdit::EmotionShortText,spItem->shortcut);
    imageFormat.setProperty(TextEdit::EmotionUniqueKey,emotionkey);
    imageFormat.setProperty(TextEdit::EmotionPkgid,pkgid);
    imageFormat.setProperty(TextEdit::ImageType,ImageType_Emot);
    textCursor().insertImage(imageFormat);

}

void TextEdit::addUrledAnimation(const QString& pkgid, const QString& shortcut)
{
    QString emotionkey = QUuid::createUuid().toString().replace("{", "").replace("}", "").replace("-", "");

    QSharedPointer<Biz::EmotionItem> spItem = Biz::Session::getEmoticonManager()->findEmoticon(pkgid,shortcut);
    if (spItem.isNull())
    {
        return;
    }
    QString fileName = spItem->strPath;
    QMovie* movie = new QMovie(this);
    movie->setFileName(fileName);
    urls.insert(movie, emotionkey);
    connect(movie, SIGNAL(frameChanged(int)), this, SLOT(animate()));
    movie->start();

    QTextImageFormat imageFormat;
    //imageFormat.setName( emotionkey );
    imageFormat.setName( fileName );
    imageFormat.setProperty(TextEdit::EmotionPath,fileName);
    imageFormat.setProperty(TextEdit::EmotionShortText,spItem->shortcut);
    imageFormat.setProperty(TextEdit::EmotionUniqueKey,emotionkey);
    imageFormat.setProperty(TextEdit::EmotionPkgid,pkgid);
    imageFormat.setProperty(TextEdit::ImageType,ImageType_Image);
    imageFormat.setProperty(TextEdit::ImageUrl,spItem->strUrl);
    textCursor().insertImage(imageFormat);
}

void TextEdit::clearAnimation()
{
    QHash<QMovie*, QString>::iterator itr = urls.begin();
    for(; itr != urls.end(); ++itr)
    {

        if(itr.key() != NULL)
        {
            QMovie* movie = itr.key();
            QString filename = movie->fileName();
            QString strval = itr.value();
            disconnect(itr.key(), SIGNAL(frameChanged(int)), this, SLOT(animate()));
            delete itr.key();
        }
    }
    urls.clear();
    document()->clear();
}

void TextEdit::animate()
{
    if (QMovie* movie = qobject_cast<QMovie*>(sender()))
    {
        //QTextCursor cursor = ui->textEdit->textCursor();
        //QTextDocument *document = ui->textEdit->document();
        // 下面的addResource代码非常重要, 内存增加很少
        //cursor.movePosition(QTextCursor::End);
        // document->addResource(QTextDocument::ImageResource, QUrl("image"), image);

        document()->addResource(QTextDocument::ImageResource, QUrl(urls.value(movie)), movie->currentPixmap());


        setLineWrapColumnOrWidth(lineWrapColumnOrWidth()); // causes reload
    }
}

void TextEdit::wheelEvent(QWheelEvent *we)
{
    if (NULL!=we && we->modifiers() == (Qt::ControlModifier))
    {
        int  val = Biz::Session::getSettingConfig()->MInputFontSize();
        int offset = (we->angleDelta().y()>0 ? 1:-1);
        val = val+offset;
        val = val < 9? 9 : val;
        val = val > 50? 50 : val;
        Biz::Session::getSettingConfig()->MInputFontSize(val);
        emit GloableEventObject::getInstance()->sgInputTextChange(val);
        onInputTextSizeChange(val);
        return;
    }

    QTextEdit::wheelEvent(we);
}

void TextEdit::onInputTextSizeChange(qreal val)
{
    QTextCursor cursor = textCursor();
    selectAll();
    setFontPointSize(val);
    setTextCursor( cursor );
    setStyleSheet(QString("font: %1pt;").arg((int)val));
}


QString TextEdit::getText(QStack<QString>& urlstack, const QString&jid)
{
    QTextDocument *dt = NULL;
    //QTextDocument *dt =  document(); 
    dt = document();
    int blocksize = dt->blockCount();
    QTextBlock currentBlock = dt->begin();
    QTextBlock::iterator it;
    QString strResult;
    while( true)
    {
        for (it = currentBlock.begin(); !(it.atEnd());it++)
        {
            QTextFragment currentFragment = it.fragment();

            if( currentFragment.charFormat().isImageFormat())
            {
                QTextImageFormat newImageFormat = currentFragment.charFormat().toImageFormat();
                if (newImageFormat.isValid()) 
                {
                    QString imageType = newImageFormat.stringProperty(TextEdit::ImageType);
                    QString imagePath = newImageFormat.stringProperty(TextEdit::EmotionPath);

                    // 是表情
                    if (imageType == ImageType_Emot)
                    {
                        QString pkgid = newImageFormat.stringProperty(TextEdit::EmotionPkgid);
                        QString shortcut = newImageFormat.stringProperty(TextEdit::EmotionShortText);
                        strResult += QString("[obj type=\"emoticon\" value=\"%1\" width=%3 height=%3]").arg("["+shortcut+"]",pkgid);
                        continue;
                    }
                    // 是图片（进程内的）
                    if (imageType == ImageType_Image)
                    {
                        if (!QFile::exists(imagePath) && QUrl(imagePath).isLocalFile())
                        {
                            imagePath = QUrl(imagePath).toLocalFile();
                        }

                        QString imageurl = newImageFormat.stringProperty(TextEdit::ImageUrl);
                        if (imageurl.isEmpty())
                        {
                            int w = 200;
                            int h = 200;
                            QImage image(imagePath);
                            w = image.width()==0?w:image.width();
                            h = image.height()==0?h:image.height();

							///////////////////
							//这个时候把文件拷贝到temp文件夹下，然后以temp文件夹下的文件发送。
							QString strfileName = Biz::ConfigureHelper::GetFileMD5(imagePath) +QString(".") + QFileInfo(imagePath).suffix();
							QString newLocalfile = Biz::ConfigureHelper::UserTempPath(Biz::Session::getAccountManager()->accountData().UserID());
							QString  subDir = Biz::SpellHelper::MakeSpellCode(Biz::MessageUtil::makeSureGroupId(jid),( Biz::SpellHelper::SpellOptions)0).trimmed();
							newLocalfile += subDir;
							newLocalfile += "/";
							newLocalfile += strfileName;
							bool bret = Util::UtilHelper::copyFileToPath(imagePath, newLocalfile, false);
							if(bret)
							{
								imagePath = newLocalfile;
							}
							//////////////////////
                            strResult += QString("[obj type=\"image\" value=\"%3\" width=%2 height=%1]").arg(h).arg(w).arg(imagePath);
                            urlstack.push(imagePath);
                        }
                        else
                        {
                            int w = 200;
                            int h = 200;
                            QImage image(imagePath);
                            w = image.width()==0?w:image.width();
                            h = image.height()==0?h:image.height();
                            QString fullUrl = Biz::ConfigureHelper::makeFullUrl(imageurl);
                            strResult += QString("[obj type=\"image\" value=\"%3\" width=%2 height=%1]").arg(h).arg(w).arg(fullUrl);
                        }


                        continue;
                    }

                    // 外来图片
                    {
                        QString name = newImageFormat.name();
                        if (QFile::exists(name))
                        {
                            urlstack.push(name);
                            QImage image(name);
                            strResult += QString("[obj type=\"image\" value=\"%3\" width=%2 height=%1]").arg(image.height()).arg(image.width()).arg(name);
                        }
                        else
                        {
                            QUrl url(name);
                            if (url.isLocalFile())
                            {
                                QString localPath = url.toLocalFile();
                                urlstack.push(localPath);
                                QImage image(localPath);
                                strResult += QString("[obj type=\"image\" value=\"%3\" width=%2 height=%1]").arg(image.height()).arg(image.width()).arg(localPath);
                            }
                        }
                        continue;
                    }

                    Q_ASSERT(0);
                }
            }else if( currentFragment.charFormat().isCharFormat()) {
                if (currentFragment.isValid())
                {
					
                    //判断url
                    strResult += Util::UtilHelper::enocdeURL(currentFragment.text(), MainApp::UIFrame::getConversationController()->doGetZhongbaoparamByconversationId(jid));
                }
            }

        }

        currentBlock = currentBlock.next();
        strResult += '\n';
        if(!currentBlock.isValid())
            break;
    }
    //先替换全角的@
    strResult.replace(QStringLiteral("＠"), "@");
    //替换非法字符
    QRegExp regExp("[\\x00-\\x08\\x0b-\\x0c\\x0e-\\x1f]");    
    strResult.replace(regExp,"");

    if (strResult.right(1) == "\n")
    {
        strResult = strResult.left(strResult.length()-1);
    }
	
    return strResult;
}

void TextEdit::setMimeTypeMessage(const QSharedPointer<MimeTypeMessage>& mtmsg)
{
    if (!mtmsg.isNull())
    {
        clear();
        clearAnimation();

        for (MimeTypeMessage::MimeTypeInfo info:mtmsg->infos)
        {
            if (MimeTypeMessage::MimeTypeText == info.type)
            {
                this->insertPlainText(info.value1);
            }

            if (MimeTypeMessage::MimeTypeEMT == info.type)
            {
                this->addAnimation(info.value1,info.value2);
            }
            if (MimeTypeMessage::MimeTypeIMG == info.type)
            {
                this->insertImage(info.value1);
            }
            if (MimeTypeMessage::MimeTypeSpite == info.type )
            {
                this->insertPlainText(info.value1);
            }
        }
    }
}

QSharedPointer<MimeTypeMessage> TextEdit::getMimeTypeMessage()
{
    QSharedPointer<MimeTypeMessage> spMimeMessage(new MimeTypeMessage);

    QTextDocument *dt = NULL;
    dt = document();
    int blocksize = dt->blockCount();
    QTextBlock currentBlock = dt->begin();
    QTextBlock::iterator it;
    QString strResult;
    while( true)
    {
        for (it = currentBlock.begin(); !(it.atEnd());it++)
        {
            QTextFragment currentFragment = it.fragment();

            if( currentFragment.charFormat().isImageFormat())
            {
                QTextImageFormat newImageFormat = currentFragment.charFormat().toImageFormat();
                if (newImageFormat.isValid()) 
                {
                    QString imageType = newImageFormat.stringProperty(TextEdit::ImageType);
                    QString imagePath = newImageFormat.stringProperty(TextEdit::EmotionPath);

                    // 是表情
                    if (imageType == ImageType_Emot)
                    {
                        QString pkgid = newImageFormat.stringProperty(TextEdit::EmotionPkgid);
						QString shortcut =  newImageFormat.stringProperty(TextEdit::EmotionShortText) ;
						//判断shortcut是否有"[]",如果没有，要加上方括号
						shortcut = (shortcut.left(1) == QString("["))&& (shortcut.right(1)==QString("]"))?shortcut:"[" + shortcut + "]";
						

                        MimeTypeMessage::MimeTypeInfo info;
                        info.type = MimeTypeMessage::MimeTypeEMT;
                        info.value1 = pkgid;
                        info.value2 = shortcut;
                        spMimeMessage->infos.append(info);
                        continue;
                    }
                    // 是图片（进程内的）
                    if (imageType == ImageType_Image)
                    {
                        if (QFile::exists(imagePath))
                        {

                            MimeTypeMessage::MimeTypeInfo info;
                            info.type = MimeTypeMessage::MimeTypeIMG;
                            info.value1 = imagePath;
                            spMimeMessage->infos.append(info);
                        }
                        else
                        {
                            QUrl url(imagePath);
                            if (url.isLocalFile())
                            {
                                QString localPath = url.toLocalFile();
                                MimeTypeMessage::MimeTypeInfo info;
                                info.type = MimeTypeMessage::MimeTypeIMG;
                                info.value1 = localPath;
                                spMimeMessage->infos.append(info);
                            }
                        }
                        continue;
                    }

                    // 外来图片
                    {
                        QString name = newImageFormat.name();
                        if (QFile::exists(name))
                        {
                            MimeTypeMessage::MimeTypeInfo info;
                            info.type = MimeTypeMessage::MimeTypeIMG;
                            info.value1 = name;
                            spMimeMessage->infos.append(info);
                        }
                        else
                        {
                            QUrl url(name);
                            if (url.isLocalFile())
                            {
                                QString localPath = url.toLocalFile();
                                MimeTypeMessage::MimeTypeInfo info;
                                info.type = MimeTypeMessage::MimeTypeIMG;
                                info.value1 = localPath;
                                spMimeMessage->infos.append(info);
                            }
                        }
                        continue;
                    }

                    Q_ASSERT(0);
                }
            }else if( currentFragment.charFormat().isCharFormat()) {
                if (currentFragment.isValid())
                {
                    QString text = currentFragment.text();
                    MimeTypeMessage::MimeTypeInfo info;
                    info.type = MimeTypeMessage::MimeTypeText;
                    info.value1 = text;
                    spMimeMessage->infos.append(info);
                }
            }

        }

        currentBlock = currentBlock.next();

        MimeTypeMessage::MimeTypeInfo info;
        info.type = MimeTypeMessage::MimeTypeSpite;
        info.value1 = "\n";
        spMimeMessage->infos.append(info);

        if(!currentBlock.isValid())
            break;
    }

    if (MimeTypeMessage::MimeTypeSpite == spMimeMessage->infos.last().type)
    {
        spMimeMessage->infos.removeLast();
    }

    return spMimeMessage;
}
