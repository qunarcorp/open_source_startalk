#pragma once
#include "QString"
namespace Util
{
	class CryptoHelper
	{
	public:
	    CryptoHelper(void);
	    ~CryptoHelper(void);
	
	    static bool Encode(const QString& in, QString& out);
	    static bool Decode(const QString& in, QString& out);
	};
	
}
