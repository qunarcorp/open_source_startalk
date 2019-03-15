#ifndef __CI_STRING__
#define __CI_STRING__

#include <cctype>
#include <string>

struct ci_char_traits : public std::char_traits<char>

// just inherit all the other functions
//  that we don't need to override
{
	static bool eq( char c1, char c2 ) {
		return tolower(c1) == tolower(c2);
	}

	static bool ne( char c1, char c2 ) {
		return tolower(c1) != tolower(c2);
	}

	static bool lt( char c1, char c2 ) {
		return tolower(c1) < tolower(c2);
	}

	static int compare( const char* s1,
			const char* s2,
			size_t n ) {
		#ifdef WIN32
		return _strnicmp(s1, s2, n);
		#else
		return strncasecmp( s1, s2, n );
		#endif
		// if available on your compiler,
		//  otherwise you can roll your own
	}

	static const char*
		find( const char* s, int n, char a ) {
			while( n-- > 0 && tolower(*s) != tolower(a) ) {
				++s;
			}
			return s;
		}
};

typedef std::basic_string<char, ci_char_traits> ci_string;

#endif
