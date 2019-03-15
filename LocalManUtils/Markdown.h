#ifndef _MARKDOWN_H_
#define _MARKDOWN_H_
#include <iostream>
#include <fstream>
#include <cstdlib>
#include "QString"
#include "QStringList"

class Markdown
{
public:
	Markdown(void);
	~Markdown(void);
public:
	QString CovertMarkdown();
	void setConverInfor(const QString&str);
	QString getLine();
	int getLineSize();
private:
	//判断空行 
	bool _Blank_line(std::string &line, QString& out);
	//分割线 
	bool _Dividing_line(std::string &Line, QString& out);
	//无序序列 
	bool _Unordered_sequence(std::string &Line,QString&out);
	// 引用 
	bool _Quotes(std::string &Line, QString&out);
	//代码块 
	bool _Code_block(std::string &Line, QString&out);
	//# 的个数
	bool _Count_Headline(std::string &Line, QString&out);
	void Bold(std::string &Line); //加粗
	void Italic(std::string &Line); //斜体
	bool code(std::string &Line); //代码 
	void Img(std::string &Line); //插入图片 
	void Links(std::string &Line); //链接 
	std::string getstring (const int n); //整形转换为字符串类型 
private:
	QStringList mlistLine;
};
#endif //_MARKDOWN_H_
