#include "CryptoHelper.h"
#include "CrcHelper.h"

namespace Util
{
	
	CryptoHelper::CryptoHelper(void)
	{
	}
	
	
	CryptoHelper::~CryptoHelper(void)
	{
	}
	
	bool CryptoHelper::Encode(const QString& in, QString& out)
	{
        char* encodedVal = NULL;
        int encodedLength = 0;
        Util::CrcHelper::Encode(in.toStdString().c_str(),in.toStdString().length(),encodedVal,encodedLength);
        
        QByteArray arr(encodedVal,encodedLength);
        out = arr.toBase64();
	    return true;
	}
	
	bool CryptoHelper::Decode(const QString& in, QString& out)
	{
        QByteArray arr = QByteArray::fromBase64(in.toUtf8());
        int decodedLength = 0;
        char* decodeVal = NULL;
        Util::CrcHelper::Decode(arr.data(),arr.length(),decodeVal,decodedLength);
        out = QString(decodeVal);
	    return true;
	}
}
