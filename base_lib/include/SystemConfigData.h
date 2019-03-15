#ifndef SYSTEMCONFIGDATA_H
#define SYSTEMCONFIGDATA_H

#include "../LocalManUtils/IXmlSerializeable.h"

namespace Biz
{
    class SystemConfigData : public IXmlSerializeable
    {
        Q_OBJECT

		PROPERTY(QString, XMPP_Host);
		PROPERTY(QString, XMPP_Domain);
        PROPERTY(QString,   XMPP_Resource);
		PROPERTY(int, XMPP_Port);
		PROPERTY(QString, HTTP_Host);
		PROPERTY(QString, HTTP_FILE_Host);
        PROPERTY(QString,   HTTP_NAV);
		PROPERTY(int, PB_Port);

		PROPERTY(QString, NAV_XMPP_Host);
		PROPERTY(QString, NAV_XMPP_Domain);
		PROPERTY(int, NAV_XMPP_Port);
		PROPERTY(QString, NAV_HTTP_Host);
		PROPERTY(QString, NAV_HTTP_FILE_Host);


        PROPERTY(QString,   RSA_Key_Path);
        PROPERTY(int,       RSA_Encode_Type);
        PROPERTY(QString,   Ops_App_Api);

        PROPERTY(bool, UpdateLimited);

		PROPERTY(QString, VidioAndAudio_Host);
		PROPERTY(QString, VidioGroupRoom_Host);

		PROPERTY(int,       NAV_RSA_Encode_Type);
		PROPERTY(QString,   NAV_Ops_App_Api);
		PROPERTY(QString,   NAV_VidioAndAudio_Host);
		PROPERTY(QString,   NAV_VideoGroupRoom_Host)
		PROPERTY(QString, NAV_RSA_Key_Path);
		PROPERTY(int,      NAV_PB_Port);
		PROPERTY(QString, NAV_GetPushStatus);
		PROPERTY(QString, NAV_SetPushStatus);
		PROPERTY(QString, NAV_CheckConfig);
		PROPERTY(QString, NAV_qcGrabOrder);
		PROPERTY(QString, NAV_qcOrderManager);
		PROPERTY(QString, NAV_qCloudHost);
		PROPERTY(QString, NAV_JavaUrl);
		PROPERTY(QString, NAV_QCHost);

		PROPERTY(QString, NAV_OpsHost);
		PROPERTY(QString, NAV_opsCheckversion);
		PROPERTY(QString, NAV_OpsConf);

		PROPERTY(QString, NAV_SECOND_navHosts);
		PROPERTY(QString, NAV_SearchUrl);
		PROPERTY(QString, NAV_MConfig);
		PROPERTY(QString, NAV_Simpleapiurl);
		PROPERTY(QString, NAV_HTTP_URL);
		PROPERTY(bool, NAV_ABILITI_ShowMsgStat);


    public:
        SystemConfigData();
        ~SystemConfigData();
        QString getXmppHost();
        QString getXmppDomain();
        int     getXmppPort();
        QString getHttpHost();
        QString getHttpFileHost();

		int getRSA_Encode_Type();
		QString getOps_App_Api();
		QString getVidioAndAudio_Host();
		QString getVideoGroupRoom_Host();
		QString getRSA_Key_Path();
		int getPbPort();
		QString getPushStatus();
		QString getSetPushStatus();
		QString getCheckConfig();
		QString getqcGrabOrder();
		QString getqcOrderManager();
		QString getqCloudHost();
		QString getjavaurl();
		QString gethttpUrl();
		QString getQCHost();
		QString getNavSearch();

		QString getSecondnavhost();
		QString getMConfig();
		QString getSimpleapiUrl();
		QString getOps_Host();
		
		
    private:

    };

}

#endif // SYSTEMCONFIGDATA_H
