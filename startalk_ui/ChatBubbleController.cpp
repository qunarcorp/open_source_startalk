#include "ChatBubbleController.h"
#include <QColor>
#include <QPainter>
#include "Session.h"
#include "accountmanager.h"
#include "ConfigureHelper.h"
#include "PersonCfgManager.h"
#include "SettingData.h"
#include "RunnableExecutor.h"
#include "ChatDisplayOptionWidget.h"
#include "UiHelper.h"

namespace MainApp {
    const int DefaultColorValue = -1;
    const QString ChatBubbleController::kChatColorInfo = "kChatColorInfo";
    const QString ChatBubbleController::kCurrentFontInfo = "kCurrentFontInfo";

    class ChatBubbleConfigItem {
    public:
        ChatBubbleConfigItem() : mType(0), mColorValue(DefaultColorValue) {};

        ~ChatBubbleConfigItem() {};
    public:
        int mType;
        int mColorValue;
        QString mBubbleFilePath;
    };

    ChatBubbleController::ChatBubbleController()
            : ControllerBase(NULL) {
        mVersion = 0;
    }

    ChatBubbleController::~ChatBubbleController() {

    }

    void ChatBubbleController::initController() {
        Biz::PersonCfgManager *pPersonCfgManager = Biz::Session::getPersonCfgManager();
        pPersonCfgManager->registerPersonCfgKey(kChatColorInfo); // �ö���������
        pPersonCfgManager->registerPersonCfgKey(kCurrentFontInfo); // �ö���������

        connect(pPersonCfgManager, &Biz::PersonCfgManager::sgPersonCfgChange, this,
                &ChatBubbleController::onPersonCfgChange);
    }

    void ChatBubbleController::unInitController() {
    }

    void ChatBubbleController::updateBubble(const QString &jid, int color) {
        auto addNewItem = [this, jid, color] {
            QPixmap picture = drawBubble(color, 1);
            QString configpath = Biz::ConfigureHelper::bubbleConfigPath(
                    Biz::Session::getAccountManager()->accountData().UserID());
            QString bubblePath = QFileInfo(QFileInfo(configpath).absoluteDir(),
                                           QString::number(color) + "L.png").absoluteFilePath();

            auto callback = createCallback([this, color, bubblePath, jid, configpath] {
                ChatBubbleConfigItem item;
                item.mColorValue = color;
                item.mBubbleFilePath = bubblePath;
                mBubbleConfigs.insert(jid, item);
                Biz::Session::getServiceManager()->getLogicThread()->QueueAction([this, configpath] {
                    saveBubbleConfig();
                });

            }, [] {});

            if (!QFile::exists(bubblePath)) {
                Biz::Session::getServiceManager()->getLogicThread()->QueueAction([this, picture, bubblePath, callback] {
                    QDir().mkpath(QFileInfo(bubblePath).absolutePath());
                    picture.save(bubblePath);
                    callback->doCompleted();
                });
            } else {
                callback->doCompleted();
            }


        };

        if (mBubbleConfigs.contains(jid)) {
            ChatBubbleConfigItem item = mBubbleConfigs.value(jid);
            QString filePath = Biz::ConfigureHelper::bubbleConfigPath(
                    Biz::Session::getAccountManager()->accountData().UserID());
            if (DefaultColorValue != item.mColorValue && !QFile::exists(filePath)
                && item.mColorValue != color) {
                addNewItem();
            }

        } else {
            ChatBubbleConfigItem item;
            item.mColorValue = color;
            mBubbleConfigs.insert(jid, item);

            addNewItem();
        }
    }

    void ChatBubbleController::updateOtherDefault(int color, qreal alpha) {
        QPixmap picture = drawBubble(color, alpha);
        QString configpath = Biz::ConfigureHelper::bubbleConfigPath(
                Biz::Session::getAccountManager()->accountData().UserID());
        QColor tempColor = MainApp::intToQColor(color);
        tempColor.setAlphaF(alpha);
        QString colorName = tempColor.name(QColor::HexArgb);
        QString bubblePath = QFileInfo(QFileInfo(configpath).absoluteDir(), colorName + "L.png").absoluteFilePath();

        auto callback = createCallback([this, color, bubblePath, configpath] {

            Biz::Session::getServiceManager()->getLogicThread()->QueueAction([this, configpath] {
                saveBubbleConfig();
            });

        }, [] {});

        if (!QFile::exists(bubblePath)) {
            Biz::Session::getServiceManager()->getLogicThread()->QueueAction([this, picture, bubblePath, callback] {
                QDir().mkpath(QFileInfo(bubblePath).absolutePath());
                picture.save(bubblePath);
                callback->doCompleted();
            });
        } else {
            callback->doCompleted();
        }
    }

    void ChatBubbleController::updateSelfDefault(int color, qreal alpha) {
        QPixmap picture = drawSelfBubble(color, alpha);
        QString configpath = Biz::ConfigureHelper::bubbleConfigPath(
                Biz::Session::getAccountManager()->accountData().UserID());
        QColor tmpColor = MainApp::intToQColor(color);
        tmpColor.setAlphaF(alpha);
        QString colorName = tmpColor.name(QColor::HexArgb);
        QString bubblePath = QFileInfo(QFileInfo(configpath).absoluteDir(), colorName + "R.png").absoluteFilePath();

        auto callback = createCallback([this, color, bubblePath, configpath] {

            Biz::Session::getServiceManager()->getLogicThread()->QueueAction([this, configpath] {
                saveBubbleConfig();
            });

        }, [] {});

        if (!QFile::exists(bubblePath)) {
            Biz::Session::getServiceManager()->getLogicThread()->QueueAction([this, picture, bubblePath, callback] {
                QDir().mkpath(QFileInfo(bubblePath).absolutePath());
                picture.save(bubblePath);
                callback->doCompleted();
            });
        } else {
            callback->doCompleted();
        }
    }

    void ChatBubbleController::saveBubbleConfig() {
        QString configpath = Biz::ConfigureHelper::bubbleConfigPath(
                Biz::Session::getAccountManager()->accountData().UserID());

        QDir dir = QFileInfo(configpath).absoluteDir();
        dir.mkpath(dir.path());
        Biz::AllUserSettingData *pSettingData = Biz::Session::getSettingConfig();

        QJsonObject rootObj;
        rootObj.insert("version", ++mVersion);
        rootObj.insert("selfcolor", pSettingData->SelfBubbleColor2());
        rootObj.insert("othercolor", pSettingData->OtherBubbleColor2());

        for (QString jid:mBubbleConfigs.keys()) {
            QJsonObject itemJson;
            ChatBubbleConfigItem item = mBubbleConfigs.value(jid);
            itemJson.insert("type", item.mType);
            itemJson.insert("color", item.mColorValue);
            itemJson.insert("path", item.mBubbleFilePath);
            rootObj.insert(jid, itemJson);
        }
        QJsonDocument doc(rootObj);

        QFile::remove(configpath);
        QFile f(configpath);
        f.open(QIODevice::WriteOnly);
        f.write(doc.toJson(QJsonDocument::Compact));
        f.close();

        // ����css

        QString cssContent;
        QString bubblePath;
        QString cssItem;

        if (pSettingData->SelfBubbleColor2() != -1) {
            QColor color = MainApp::intToQColor(pSettingData->SelfBubbleColor2());
            color.setAlphaF(pSettingData->SelfBubbleColorAlpha());
            QString colorName = color.name(QColor::HexArgb);
            bubblePath = QFileInfo(QFileInfo(configpath).absoluteDir(), colorName + "R.png").absoluteFilePath();
            cssItem = QString(".bubble9.mc-local-sender {-webkit-border-image: url(%2) 30 29 30 29 !important;}\r\n")
                    .arg(QUrl::fromLocalFile(bubblePath).toString());
            cssContent += cssItem;
        }

        if (pSettingData->OtherBubbleColor2() != -1) {
            QColor color = MainApp::intToQColor(pSettingData->OtherBubbleColor2());
            color.setAlphaF(pSettingData->OtherBubbleColorAlpha());
            QString colorName = color.name(QColor::HexArgb);

            bubblePath = QFileInfo(QFileInfo(configpath).absoluteDir(), colorName + "L.png").absoluteFilePath();
            cssItem = QString(".bubble9.mc-remote-sender {-webkit-border-image: url(%2) 30 29 30 29 !important;}\r\n")
                    .arg(QUrl::fromLocalFile(bubblePath).toString());
            cssContent += cssItem;
        }


        for (QString jid:mBubbleConfigs.keys()) {
            ChatBubbleConfigItem item = mBubbleConfigs.value(jid);
            QString cssItem = QString(
                    ".bubble9.mc-remote-sender.%1 {-webkit-border-image: url(%2) 30 29 30 29 !important;}\r\n")
                    .arg(Biz::MessageUtil::makeSureUserId(jid).replace(".", ""),
                         QUrl::fromLocalFile(item.mBubbleFilePath).toString());
            cssContent += cssItem;
        }


        dir.setFilter(QDir::Files);
        QFileInfoList list = dir.entryInfoList();
        for (QFileInfo fileInfo : list) {
            QString fileNam = fileInfo.fileName();
            if (fileInfo.fileName().endsWith(".css")) {
                QFile::remove(fileInfo.absoluteFilePath());
            }
        }

        QString cssPath = QFileInfo(QFileInfo(configpath).absoluteDir(),
                                    QString::number(mVersion) + ".css").absoluteFilePath();
        QFile::remove(cssPath);
        QFile fcss(cssPath);
        fcss.open(QIODevice::WriteOnly);
        fcss.write(cssContent.toUtf8());
        fcss.close();
        emit sgChatBubbleQssChanged(cssPath);
    }

    QPixmap ChatBubbleController::drawBubble(int color, qreal alpha) {
        int maxWidth = 60;
        int maxHeight = 62;
        int radius = 7;
        int paddingleft = 12;
        int pointheight = 12;
        int offset = 1;

        QPixmap retPixMap(maxWidth, maxHeight);
        retPixMap.fill(Qt::transparent);
        QPainter painter(&retPixMap);
        painter.setRenderHint(QPainter::Antialiasing, true);
        QString colorName = "#";

        painter.setPen(Qt::transparent);

        // ͷ�� ��ͼ 2����Բ�� 50*50
        QRect rectangle(paddingleft, 0, maxWidth - paddingleft, maxHeight);

        QColor background = MainApp::intToQColor(color);
        background.setAlphaF(alpha);
        painter.setBrush(QBrush(background));
        painter.drawRoundedRect(rectangle, 10.0, 10.0); // 4%

        static const QPoint triangle[3] = {QPoint(0, radius + offset), QPoint(paddingleft, radius + offset),
                                           QPoint(paddingleft, pointheight + radius + offset)};//1
        painter.drawPolygon(triangle, 3);
        return retPixMap;
    }

    QPixmap ChatBubbleController::drawSelfBubble(int color, qreal alpha) {
        int maxWidth = 60;
        int maxHeight = 62;
        int radius = 7;
        int paddingright = 12;
        int pointheight = 12;
        int offset = 1;

        QPixmap retPixMap(maxWidth, maxHeight);
        retPixMap.fill(Qt::transparent);
        QPainter painter(&retPixMap);
        painter.setRenderHint(QPainter::Antialiasing, true);
        painter.setPen(Qt::transparent);

        // ͷ�� ��ͼ 2����Բ�� 50*50
        QRect rectangle(0, 0, maxWidth - paddingright, maxHeight);

        QColor background = MainApp::intToQColor(color);
        background.setAlphaF(alpha);
        painter.setBrush(QBrush(background));
        painter.drawRoundedRect(rectangle, 10.0, 10.0); // 4%

        static const QPoint triangle[3] = {
                QPoint(maxHeight - paddingright - 2, radius + offset),
                QPoint(maxHeight - 2, radius + offset),
                QPoint(maxHeight - paddingright - 2, pointheight + radius + offset)};//1
        painter.drawPolygon(triangle, 3);
        return retPixMap;
    }

    void ChatBubbleController::onPersonCfgChange(const QStringList &changedKeys) {
        if (changedKeys.contains(kChatColorInfo)) {
            auto loadConfig = [this] {
                QSharedPointer<Biz::PersonConfInfo> spPersonCfg =
                        Biz::Session::getPersonCfgManager()->getPersonCfgInfo(kChatColorInfo);
                if (spPersonCfg.isNull()) {
                    return;
                }
                QString jsonString = spPersonCfg->infoValue();
                QString jsonData = spPersonCfg->infoValue();
                QVariantMap jsonMaps
                        = QJsonDocument::fromJson(jsonData.toUtf8()).toVariant().toMap();

                Biz::AllUserSettingData *pSettingData = Biz::Session::getSettingConfig();

                int fontcolor = pSettingData->TextColorRGB();
                int otherFontColor = pSettingData->TextColorRGBOther();
                int selfColor = pSettingData->SelfBubbleColor2();
                int otherColor = pSettingData->OtherBubbleColor2();

                qreal otherFontAlpha = pSettingData->OtherTextColorAlpha();
                qreal selfFontAlpha = pSettingData->SelfTextColorAlpha();
                qreal selfColorAlpha = pSettingData->SelfBubbleColorAlpha();
                qreal otherColorAlpha = pSettingData->OtherBubbleColorAlpha();

                if (jsonMaps.contains("kOtherFontColor")) {
                    otherFontColor = jsonMaps.value("kOtherFontColor").toMap().value("colorHex").toInt();
                    otherFontAlpha = jsonMaps.value("kOtherFontColor").toMap().value("alpha", 1.0).toDouble();
                }

                if (jsonMaps.contains("kMyFontColor")) {
                    fontcolor = jsonMaps.value("kMyFontColor").toMap().value("colorHex").toInt();
                    selfFontAlpha = jsonMaps.value("kMyFontColor").toMap().value("alpha", 1.0).toDouble();
                }

                if (jsonMaps.contains("kMyBubbleColor")) {
                    selfColor = jsonMaps.value("kMyBubbleColor").toMap().value("colorHex").toInt();
                    selfColorAlpha = jsonMaps.value("kMyBubbleColor").toMap().value("alpha", 1.0).toDouble();
                }

                if (jsonMaps.contains("kOtherBubbleColor")) {
                    otherColor = jsonMaps.value("kOtherBubbleColor").toMap().value("colorHex").toInt();
                    otherColorAlpha = jsonMaps.value("kOtherBubbleColor").toMap().value("alpha", 1.0).toDouble();
                }

                Util::Executor::runPost(Biz::Session::getServiceManager()->getMainThread(),
                                        [this, fontcolor, selfColor, otherColor, selfFontAlpha, selfColorAlpha, otherColorAlpha, otherFontColor, otherFontAlpha] {

                                            if (otherFontColor !=
                                                Biz::Session::getSettingConfig()->TextColorRGBOther()) {
                                                Biz::Session::getSettingConfig()->TextColorRGBOther(otherFontColor);
                                                Biz::Session::getSettingConfig()->OtherTextColorAlpha(otherFontAlpha);
                                                emit ChatDisplayOptionWidgetSingleton::getInstance()->sgOtherFontChange();
                                                Biz::Session::saveSettingConfig();
                                            }

                                            if (fontcolor != Biz::Session::getSettingConfig()->TextColorRGB()) {
                                                Biz::Session::getSettingConfig()->TextColorRGB(fontcolor);
                                                Biz::Session::getSettingConfig()->SelfTextColorAlpha(selfFontAlpha);
                                                emit ChatDisplayOptionWidgetSingleton::getInstance()->sgSelfFontChange();
                                                Biz::Session::saveSettingConfig();
                                            }

                                            if (selfColor != Biz::Session::getSettingConfig()->SelfBubbleColor2() ||
                                                selfColorAlpha !=
                                                Biz::Session::getSettingConfig()->SelfBubbleColorAlpha()) {
                                                Biz::Session::getSettingConfig()->SelfBubbleColor2(selfColor);
                                                Biz::Session::getSettingConfig()->SelfBubbleColorAlpha(selfColorAlpha);
                                                Biz::Session::saveSettingConfig();
                                                this->updateSelfDefault(selfColor, selfColorAlpha);
                                            }

                                            if (otherColor != Biz::Session::getSettingConfig()->OtherBubbleColor2() ||
                                                otherColorAlpha !=
                                                Biz::Session::getSettingConfig()->OtherBubbleColorAlpha()) {
                                                Biz::Session::getSettingConfig()->OtherBubbleColor2(otherColor);
                                                Biz::Session::getSettingConfig()->OtherBubbleColorAlpha(
                                                        otherColorAlpha);
                                                Biz::Session::saveSettingConfig();
                                                this->updateOtherDefault(otherColor, otherColorAlpha);
                                            }
                                        });

            };
            if (Biz::Session::getServiceManager()->getLogicThread() != QThread::currentThread()) {
                Biz::Session::getServiceManager()->getLogicThread()->QueueAction(loadConfig);
            } else
                loadConfig();
        }

        if (changedKeys.contains(kCurrentFontInfo)) {
            auto currentFontInfoFun = [this] {
                QSharedPointer<Biz::PersonConfInfo> spPersonCfg =
                        Biz::Session::getPersonCfgManager()->getPersonCfgInfo(kCurrentFontInfo);
                if (spPersonCfg.isNull()) {
                    return;
                }
                QString jsonData = spPersonCfg->infoValue();
                QVariantMap jsonMaps
                        = QJsonDocument::fromJson(jsonData.toUtf8()).toVariant().toMap();

                int fontsize = Biz::Session::getSettingConfig()->MFontSize();
                QString fontfamily = Biz::Session::getSettingConfig()->MFontFamily();

                if (jsonMaps.contains("kBubbleFontSize"))
                    fontsize = jsonMaps.value("kBubbleFontSize").toInt();
                if (jsonMaps.contains("kBubbleFontFamily"))
                    fontfamily = jsonMaps.value("kBubbleFontFamily").toString();

                Util::Executor::runPost(Biz::Session::getServiceManager()->getMainThread(),
                                        [this, fontsize, fontfamily] {
                                            if (fontsize != Biz::Session::getSettingConfig()->MFontSize()) {
                                                Biz::Session::getSettingConfig()->MFontSize(fontsize);
                                                Biz::Session::saveSettingConfig();
                                                emit ChatDisplayOptionWidgetSingleton::getInstance()->sgSelfFontChange();
                                                emit ChatDisplayOptionWidgetSingleton::getInstance()->sgOtherFontChange();
                                            }

                                            if (fontfamily != Biz::Session::getSettingConfig()->MFontFamily()) {
                                                Biz::Session::getSettingConfig()->MFontFamily(fontfamily);
                                                Biz::Session::saveSettingConfig();
                                                emit ChatDisplayOptionWidgetSingleton::getInstance()->sgSelfFontChange();
                                                emit ChatDisplayOptionWidgetSingleton::getInstance()->sgOtherFontChange();
                                            }
                                        });
            };
            if (Biz::Session::getServiceManager()->getLogicThread() != QThread::currentThread()) {
                Biz::Session::getServiceManager()->getLogicThread()->QueueAction(currentFontInfoFun);
            } else
                currentFontInfoFun();
        }
    }

    void ChatBubbleController::saveConfigeToRemote() {
        auto saveConfig = [this] {

            Biz::AllUserSettingData *pSettingData = Biz::Session::getSettingConfig();
            int fontcolor = pSettingData->TextColorRGB();
            int otherFont = pSettingData->TextColorRGBOther();
            int selfColor = pSettingData->SelfBubbleColor2();
            int otherColor = pSettingData->OtherBubbleColor2();

            qreal otherFontAlpha = pSettingData->OtherTextColorAlpha();
            qreal selfFontAlpha = pSettingData->SelfTextColorAlpha();
            qreal selfColorAlpha = pSettingData->SelfBubbleColorAlpha();
            qreal otherColorAlpha = pSettingData->OtherBubbleColorAlpha();

            QJsonObject objOtherFont;
            objOtherFont.insert("colorHex", otherFont);
            objOtherFont.insert("alpha", otherFontAlpha);

            QJsonObject objFontcolor;
            objFontcolor.insert("colorHex", fontcolor);
            objFontcolor.insert("alpha", selfFontAlpha);

            QJsonObject objSelf;
            objSelf.insert("colorHex", selfColor);
            objSelf.insert("alpha", selfColorAlpha);

            QJsonObject objothercolor;
            objothercolor.insert("colorHex", otherColor);
            objothercolor.insert("alpha", otherColorAlpha);

            QSharedPointer<Biz::PersonConfInfo> spPersonCfg =
                    Biz::Session::getPersonCfgManager()->getPersonCfgInfo(kChatColorInfo);
            QJsonObject jsonValue;
            if (!spPersonCfg.isNull()) {
                QString txtCurrentValue = spPersonCfg->infoValue();
                jsonValue = QJsonObject::fromVariantMap(
                        QJsonDocument::fromJson(txtCurrentValue.toUtf8()).toVariant().toMap());
            }

            jsonValue.insert("kOtherFontColor", objOtherFont);
            jsonValue.insert("kMyFontColor", objFontcolor);
            jsonValue.insert("kMyBubbleColor", objSelf);
            jsonValue.insert("kOtherBubbleColor", objothercolor);

            QString value = QJsonDocument(jsonValue).toJson(QJsonDocument::Compact);
            Log::e("ChatBubbleController::saveConfigeToRemote 111---Biz::Session::getPersonCfgManager()->savePersonCfgInfo");
            Biz::Session::getPersonCfgManager()->savePersonCfgInfo(kChatColorInfo, value);

            spPersonCfg = Biz::Session::getPersonCfgManager()->getPersonCfgInfo(kCurrentFontInfo);
            QJsonObject fontValue;
            if (!spPersonCfg.isNull()) {
                QString txtCurrentValue = spPersonCfg->infoValue();
                fontValue = QJsonObject::fromVariantMap(
                        QJsonDocument::fromJson(txtCurrentValue.toUtf8()).toVariant().toMap());
            }

            fontValue.insert("kBubbleFontSize", Biz::Session::getSettingConfig()->MFontSize());
            fontValue.insert("kBubbleFontFamily", Biz::Session::getSettingConfig()->MFontFamily());
            value = QJsonDocument(fontValue).toJson(QJsonDocument::Compact);
            Log::e("ChatBubbleController::saveConfigeToRemote 222---Biz::Session::getPersonCfgManager()->savePersonCfgInfo");
            Biz::Session::getPersonCfgManager()->savePersonCfgInfo(kCurrentFontInfo, "Windows", value);
        };
        if (Biz::Session::getServiceManager()->getLogicThread() != QThread::currentThread())
            Biz::Session::getServiceManager()->getLogicThread()->QueueAction(saveConfig);

        else
            saveConfig();
    }

}
