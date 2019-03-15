#pragma once
#include "CoreObject.h"
namespace Util
{
	class CrcHelper
	{
	public:
		CrcHelper(void);
		~CrcHelper(void);
		static QString Encrypt(QString str);

        static bool Encode(const char* input, int inLen, char*& out, int& outLen);
        static bool Decode(const char* input, int inLen, char*& out, int& outLen);
	private:
        static unsigned long Crc32_ComputeBuf( unsigned long inCrc32, const void *buf, size_t bufLen );
        static void ed(unsigned const char* src,unsigned char** dst,const char* key, int length);

        static const char* SECRETKEY;
	};
}


