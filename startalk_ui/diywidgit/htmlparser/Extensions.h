#ifndef __EXTENSIONS_H__
#define __EXTENSIONS_H__

#include <set>
#include <string>
#include "ci_string.h"

namespace htmlcxx
{
	class Extensions
	{
		public:
			Extensions() {}

			Extensions(const std::string &exts);

			~Extensions() {}

			bool check(const std::string &url);
			void insert(const ci_string &ext) { mExts.insert(ext); }

		private:
			std::set<ci_string> mExts;
	};
}

#endif
