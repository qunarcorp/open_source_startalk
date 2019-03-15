#ifndef __HTMLCXX__URI_H__
#define __HTMLCXX__URI_H__

#include <string>
#include <climits>
#include <stdexcept>

namespace htmlcxx
{
	class Uri
	{
		public:

			class Exception : public std::runtime_error
			{
				public:
					Exception(const std::string &arg)
						: std::runtime_error(arg) {}
			};
			
			Uri();
			Uri(const std::string &uri);
			~Uri();

			static std::string encode(const std::string &uri);
			static std::string decode(const std::string &uri);

			std::string unparse(int flags = 0) const;
			Uri absolute(const Uri &base) const;

			std::string canonicalHostname(unsigned int maxDepth = UINT_MAX) const;
			unsigned int hostnameDepth() const;

			static const unsigned int URI_FTP_DEFAULT_PORT =          21 ; /**< default FTP port */
			static const unsigned int URI_SSH_DEFAULT_PORT =          22 ; /**< default SSH port */
			static const unsigned int URI_TELNET_DEFAULT_PORT =       23 ; /**< default telnet port */
			static const unsigned int URI_GOPHER_DEFAULT_PORT =       70 ; /**< default Gopher port */
			static const unsigned int URI_HTTP_DEFAULT_PORT =         80 ; /**< default HTTP port */
			static const unsigned int URI_POP_DEFAULT_PORT =         110 ; /**< default POP port */
			static const unsigned int URI_NNTP_DEFAULT_PORT =        119 ; /**< default NNTP port */
			static const unsigned int URI_IMAP_DEFAULT_PORT =        143 ; /**< default IMAP port */
			static const unsigned int URI_PROSPERO_DEFAULT_PORT =    191 ; /**< default Prospero port */
			static const unsigned int URI_WAIS_DEFAULT_PORT =        210 ; /**< default WAIS port */
			static const unsigned int URI_LDAP_DEFAULT_PORT =        389 ; /**< default LDAP port */
			static const unsigned int URI_HTTPS_DEFAULT_PORT =       443 ; /**< default HTTPS port */
			static const unsigned int URI_RTSP_DEFAULT_PORT =        554 ; /**< default RTSP port */
			static const unsigned int URI_SNEWS_DEFAULT_PORT =       563 ; /**< default SNEWS port */
			static const unsigned int URI_ACAP_DEFAULT_PORT =        674 ; /**< default ACAP port */
			static const unsigned int URI_NFS_DEFAULT_PORT =        2049 ; /**< default NFS port */
			static const unsigned int URI_TIP_DEFAULT_PORT =        3372 ; /**< default TIP port */
			static const unsigned int URI_SIP_DEFAULT_PORT =        5060 ; /**< default SIP port */

			const static int REMOVE_WWW_PREFIX = 1;
			const static int REMOVE_TRAILING_BAR = 2;
			const static int REMOVE_SCHEME = 8;
			const static int REMOVE_QUERY_VALUES = 16;
			const static int REMOVE_QUERY = 32;
			const static int REMOVE_DEFAULT_FILENAMES = 64;
			const static int REMOVE_FRAGMENT = 128;

			std::string scheme() const;
			void scheme(std::string scheme);
			std::string user() const;
			void user(std::string user);
			std::string password() const;
			void password(std::string password);
			std::string hostname() const;
			void hostname(std::string hostname);
			std::string path() const;
			void path(std::string path);
			std::string query() const;
			void query(std::string query);
			std::string fragment() const;
			void fragment(std::string fragment);
			unsigned int port() const;
			void port(unsigned int port);
			bool existsFragment() const;
			void existsFragment(bool existsFragment);
			bool existsQuery() const;
			void existsQuery(bool existsQuery);
		protected:
			void init(const std::string &uri_str);
			
			std::string mScheme;
			std::string mUser;
			std::string mPassword;
			std::string mHostname;
			std::string mPath;
			std::string mQuery;
			std::string mFragment;
			std::string mPortStr;;
			bool mExistsQuery;
			bool mExistsFragment;
			unsigned int mPort;
	};
}

#endif
