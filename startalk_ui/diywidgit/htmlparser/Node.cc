#include <iostream>
#include <cctype>
#include <algorithm>
#include "wincstring.h"
#include "Node.h"

//#define DEBUG
#include "debug.h"

using namespace std;
using namespace htmlcxx;
using namespace HTML;

void Node::parseAttributes() 
{
	if (!(this->isTag())) return;

	const char *end;
	const char *ptr = mText.c_str();
	if ((ptr = strchr(ptr, '<')) == 0) return;
	++ptr;

	// Skip initial blankspace
	while (isspace(*ptr)) ++ptr;

	// Skip tagname
	if (!isalpha(*ptr)) return;
	while (!isspace(*ptr) && *ptr != '>') ++ptr;

	// Skip blankspace after tagname
	while (isspace(*ptr)) ++ptr;

	while (*ptr && *ptr != '>') 
	{
		string key, val;

		// skip unrecognized
		while (*ptr && !isalnum(*ptr) && !isspace(*ptr)) ++ptr;

		// skip blankspace
		while (isspace(*ptr)) ++ptr;

		end = ptr;
		while (isalnum(*end) || *end == '-') ++end;
		key.assign(end - ptr, '\0');
		transform(ptr, end, key.begin(), ::tolower);
		ptr = end;

		// skip blankspace
		while (isspace(*ptr)) ++ptr;

		if (*ptr == '=') 
		{
			++ptr;
			while (isspace(*ptr)) ++ptr;
			if (*ptr == '"' || *ptr == '\'') 
			{
				char quote = *ptr;
//				fprintf(stderr, "Trying to find quote: %c\n", quote);
				const char *end = strchr(ptr + 1, quote);
				if (end == 0)
				{
					//b = mText.find_first_of(" >", a+1);
					const char *end1, *end2;
					end1 = strchr(ptr + 1, ' ');
					end2 = strchr(ptr + 1, '>');
					if (end1 && end1 < end2) end = end1;
					else end = end2;
					if (end == 0) return;
				}
				const char *begin = ptr + 1;
				while (isspace(*begin) && begin < end) ++begin;
				const char *trimmed_end = end - 1;
				while (isspace(*trimmed_end) && trimmed_end >= begin) --trimmed_end;
				val.assign(begin, trimmed_end + 1);
				ptr = end + 1;
			}
			else 
			{
				end = ptr;
				while (*end && !isspace(*end) && *end != '>') end++;
				val.assign(ptr, end);
				ptr = end;
			}

//			fprintf(stderr, "%s = %s\n", key.c_str(), val.c_str());
			mAttributes.insert(make_pair(key, val));
		}
		else
		{
//			fprintf(stderr, "D: %s\n", key.c_str());
			if (!key.empty())
			{
				mAttributes.insert(make_pair(key, string()));
			}
		}
	}
}

bool Node::operator==(const Node &n) const 
{
	if (!isTag() || !n.isTag()) return false;
	return !(strcasecmp(tagName().c_str(), n.tagName().c_str()));
}

Node::operator string() const {
	if (isTag()) return this->tagName();
	return this->text();
}

ostream &Node::operator<<(ostream &stream) const {
	stream << (string)(*this);
	return stream;
}
