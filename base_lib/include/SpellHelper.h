#pragma once
#include "CoreObject.h"
namespace Biz{
    class SpellHelper
    {
    public:
	    enum SpellOptions
	    {
		    /// <summary>
		    ///只转换拼音首字母，默认转换全部 
		    /// </summary>
		    FirstLetterOnly = 1,
		    /// <summary>
		    /// 转换未知汉字为问号，默认不转换
		    /// </summary>
		    TranslateUnknowWordToInterrogation = 1 << 1,
		    /// <summary>
		    /// 保留非字母、非数字字符，默认不保留
		    /// </summary>
		    EnableUnicodeLetter = 1 << 2,
	    };

    public:
	    static QString MakeSpellCode( const QString &strInput, SpellOptions options );

    private:
	    SpellHelper();
    };
}