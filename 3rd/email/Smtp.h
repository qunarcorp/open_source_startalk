#ifndef __SMTP_H__ //避免重复包含
#define __SMTP_H__

#include <iostream>
#include <list>
#ifdef _WINDOWS
#include <WinSock2.h>




using namespace std;

const int MAXLEN = 1024;
const int MAX_FILE_LEN = 6000;

static const char base64Char[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

struct FILEINFO /*用来记录文件的一些信息*/
{
	char fileName[128]; /*文件名称*/
	char filePath[256]; /*文件绝对路径*/
};

class CSmtp
{
public:
	CSmtp(void);
	CSmtp(
		int port,
		string srvDomain,	//smtp服务器域名
		string userName,	//用户名
		string password,	//密码
		string targetEmail, //目的邮件地址
		string emailTitle,  //主题
		string content       //内容
	);
public:
	~CSmtp(void);
public:
	int port;
public:
	string domain;
	string user;
	string pass;
	string targetAddr;
	string title;
	string content;
	/*为了方便添加文件，删除文件神马的，使用list容器最为方便，相信大家在数据结构里面都学过*/
	list <FILEINFO *> listFile;

public:
	char buff[MAXLEN + 1];
	int buffLen;

	SOCKET sockClient;	//客户端的套接字


	
public:
	bool CreateConn(); /*创建连接*/

	bool Send(string &message);
	bool Recv();

	void FormatEmailHead(string &email);//格式化要发送的邮件头部
	int Login();
	bool SendEmailHead();		//发送邮件头部信息
	bool SendTextBody();	    //发送文本信息
								//bool SendAttachment();	    //发送附件
	int SendAttachment_Ex();
	bool SendEnd();
public:
	void AddAttachment(string &filePath); //添加附件
	void DeleteAttachment(string &filePath); //删除附件
	void DeleteAllAttachment(); //删除所有的附件

	void SetSrvDomain(string &domain);
	void SetUserName(string &user);
	void SetPass(string &pass);
	void SetTargetEmail(string &targetAddr);
	void SetEmailTitle(string &title);
	void SetContent(string &content);
	void SetPort(int port);
	int SendEmail_Ex();
	/*关于错误码的说明:1.网络错误导致的错误2.用户名错误3.密码错误4.文件不存在0.成功*/
	char* base64Encode(char const* origSigned, unsigned origLength);
};
#endif // _WINDOWS
#endif // !__SMTP_H__
