#pragma once


namespace Biz
{
    enum ImSessionConfigration
    {
        SESSION_CFG_SILENCE = 0x1,
        SESSION_CFG_TOPMOST = 0x2
    };

    enum MailSplitChar{
        MSC_SEMICOLON,
        MSC_COMMA
    };

    enum QuitOnCloseOption
    {
        QOC_NOTSET,
        QOC_QUIT,
        QOC_IGNORE
    };

    enum RSAENCODETYPE
    {
        RSAENCODETYPE_RSAPUBLIC = 0,
        RSAENCODETYPE_PUBLIC    = 1
    };

	enum MESSAGESTATE {
		MESSAGESTATE_REMOTE_NONE = 0,
		MESSAGESTATE_REMOTE_RECIVED = 0x01,
		MESSAGESTATE_REMOTE_READED  = 0x02,

		MESSAGESTATE_LOCAL_SENDING   = 0x01,
		MESSAGESTATE_LOCAL_SENDSUCCESS = 0x02,
		MESSAGESTATE_LOCAL_VOICEPLAYED = 0x04
	};
};