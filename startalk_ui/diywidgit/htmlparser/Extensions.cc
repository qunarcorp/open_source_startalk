#include <cstring>
#include "Extensions.h"

using namespace std;
using namespace htmlcxx;

Extensions::Extensions(const string &exts)
{
	const char *begin = exts.c_str();
	while (*begin)
	{
		while (*begin == ' ') ++begin;
		if (*begin == 0) break;

		const char *end = begin + 1;
		while (*end && *end != ' ') ++end;

		insert(ci_string(begin, end));

		begin = end;
	}
}

bool Extensions::check(const string &url)
{
	const char *slash;
	const char *dot;
	const char *question;

	question = strchr(url.c_str(), '?');

	if (question) return false;
	
	slash = strrchr(url.c_str(), '/');
	dot = strrchr(url.c_str(), '.');

	if (slash >= dot) return false;
	
	ci_string ext(dot);
	
	return mExts.find(ext) != mExts.end();
}
