#include "Markdown.h"
#include <string>
#include <cstdlib>
#include <sstream>

using namespace std;

Markdown::Markdown(void)
{
}


Markdown::~Markdown(void)
{
}

QString Markdown::CovertMarkdown()
{
	bool judge = false;
	QString strtmpHtml;
	QString strHtml;
	QString line;
	while (getLineSize() >0)
	{
		
		if ((line = getLine()).isEmpty())
		{
			continue;
		}

		std::string Line = line.toStdString();

		//无序序列 *

		judge = _Unordered_sequence(Line,strtmpHtml);
		if (judge == true) {
			strHtml += strtmpHtml;
			continue;
		}

		//引用 >
		if (judge == false) {
			strtmpHtml.clear();
			judge = _Quotes(Line, strtmpHtml);
			if (judge == true) {
				strHtml += strtmpHtml;
				continue;
			}
		}

		//代码块 ```
		if (judge == false) {
			strtmpHtml.clear();
			judge = _Code_block(Line, strtmpHtml);
			if (judge == true) {
				//std::getline(in,Line);
				strHtml += strtmpHtml;
				continue;
			}
		}

		//判断空行
		strtmpHtml.clear();
		judge = _Blank_line(Line, strtmpHtml);
		if (judge == true) {
			//std::getline(in,Line);
			strHtml += strtmpHtml;
			continue;
		}

		//分割线 ---
		strtmpHtml.clear();
		judge = _Dividing_line(Line, strtmpHtml);
		if (judge == true) {
			//std::getline(in,Line);
			strHtml += strtmpHtml;
			continue;
		}

		//标记  `~~~~~~` 
		strtmpHtml.clear();
		judge = code(Line); 
		if (judge == true) {
			//out << "\n<p>" << Line << "</p>" <<"\n";
			strHtml += QString("\n<p>") + Line.c_str() + QString("<p>") + QString("\n");
			//std::getline(in,Line);
			continue;
		}

		//加粗 **~~~~** 
		Bold(Line);
		

		//斜体 *~~~~~* 
		Italic(Line);	

		//图片 
		Img(Line); 	

		//连接 
		Links(Line);

		//判断 # 大标题 
		strtmpHtml.clear();
		judge = _Count_Headline(Line, strtmpHtml);
		if (judge == true) {
			//std::getline(in,Line);
			strHtml += strtmpHtml;
			continue;
		}	

		strHtml += QString("\n<p>") + Line.c_str() + QString("</p>") + QString("\n");
	}

	return strHtml;
}

void Markdown::setConverInfor( const QString&str )
{
	QStringList list = str.split("\n");

	mlistLine = list;
}

QString Markdown::getLine()
{
	QString retStr;
	if (mlistLine.size() > 0)
	{
		retStr = mlistLine.at(0);
		mlistLine.removeAt(0);
	}

	return retStr;
}

int Markdown::getLineSize()
{
	return mlistLine.size();
}

bool Markdown::_Blank_line( std::string &Line, QString& out )
{
	if (Line == "\r" || Line.empty()) {
		//out << "\n<br>\n"; 
		out += QString("\n<br>\n");
		return true; 
	}
	return false;
}

bool Markdown::_Dividing_line( std::string &Line, QString& out )
{
	int count = 0;

	while (Line[count++] == '-' && count < (int)Line.size());

	if (count == Line.size() && (count - 1) >= 3) {
		//out << "\n<hr>\n";
		out += QString("\n<hr>\n");
		return true;
	}

	return false;
}

bool Markdown::_Unordered_sequence( std::string &Line,QString&out )
{
	int count = 0;
	bool judge = false;
	if ((Line[0] == '*' && Line[1] == ' ') || (Line[0] == '-' && Line[1] == ' ') || (Line[0] == '+' && Line[1] == ' ')) {
		judge = true;
		while(1)
		{
			if ((Line[0] == '*' && Line[1] == ' ') || (Line[0] == '-' && Line[1] == ' ') || (Line[0] == '+' && Line[1] == ' ')) {
				Line.replace(0,1,"<li>");
				code(Line); 
				Bold(Line);
				Italic(Line);	
				Img(Line); 	
				Links(Line);
				if(count == 0) {
					out  += QString("\n<ul>\n") + Line.c_str() + QString("</li>\n") ;
					//out << "\n<ul>\n" << Line << "</li>\n";
					count++;
				} else {
					//out << Line << "</li>\n";
					out += Line.c_str() + QString("</li>\n");
					count++;
				}
			} else {
				//out << "</ul>\n";
				out += QString("</ul>\n");
				break;
			} 	
			Line = getLine().toStdString();
		} 
	}
	return judge;
}

bool Markdown::_Quotes( std::string &Line, QString&out )
{
	int count = 0;
	bool judge = false;
	if (Line[0] == '>') {
		judge = true;
		while (1)
		{
			if(Line[0] == '>') {
				Line.replace(0,2,"");
				code(Line); 
				Bold(Line);
				Italic(Line);	
				Img(Line); 	
				Links(Line);
				if(count == 0) {
					//out << "\n<blockquote>\n" << "<p>" << Line << "</p>\n";
					out += QString("\n<blockquote>\n") + QString("<p>") + Line.c_str() + QString("</p>\n");
					count++;
				} else {
					//out << "<p>" << Line << "</p>\n";
					out +=  QString("<p>") + Line.c_str() + QString("</p>\n");
					count++;
				}
			} else {
				//out << "</blockquote>\n";
				out += QString("</blockquote>\n");
				break;
			} 	
			//std::getline(in,Line);
			Line = getLine().toStdString();
		} 
	}
	return judge;
}

bool Markdown::_Code_block( std::string &Line, QString&out )
{
	int count = 3; 
	bool judge = false;
	while(Line[count++] == ' ' && count < (int)Line.size());
	if (Line[0] == '`' && Line[1] == '`' && Line[2] == '`' && count == (int)Line.size()) {
		Line.replace(0,Line.size(),"\n<blockquote>\n<font color=9900FF>\n");
		//out << Line;
		out += Line.c_str();
		count = 3;
		while(1)
		{
			Line = getLine().toStdString();//std::getline(in,Line);
			while(Line[0] == '`' && Line[1] == '`' && Line[2] == '`' && Line[count++] == ' ' && count < (int)Line.size());
			if (count == (int)Line.size()) {
				judge = true;
				Line.replace(0,Line.size(),"\n</font>\n</blockquote>\n");
				//out << Line;
				out += Line.c_str();
				break;
			}
			//out << "<p>" << Line << "</p>";
			out += QString("<p>") + Line.c_str() + QString("</p>");
		} 
	}
	return judge;
}

bool Markdown::_Count_Headline( std::string &Line, QString&out )
{
	int count = 0; 

	while(Line[count++] == '#' && count < (int)Line.size());

	if (count == 1) {
		return false; 
	} else {

		code(Line);
		count = count - 1;
		string string_count = getstring(count);

		if (count >= 1 && count <= 6) {
			//字符串的替换
			Line.replace(0,count,"\n<h"+string_count+">");  
			//out << Line << "</h" << string_count << ">\n";
			out += Line.c_str() + QString("</h") + string_count.c_str() + QString(">\n");
		} else {
			//# 号大于6时 按 6 处理 
			Line.replace(0,6,"\n<h"+getstring(6)+">\n");      
			//out << Line << "</h" << "6" << ">\n";
			out += Line.c_str() + QString("</h") + QString("6" ) + QString(">\n");
		}

	}

	return true;
}

void Markdown::Bold( std::string &Line )
{
	int count = 0;

	for (int i = 0;i < Line.size()-1;i++)//找到所有的 **  
	{
		if (Line[i] == '*' && Line[i+1] == '*') {
			count++;
		}
	}

	if (count % 2 != 0){count--;}

	for (int i = 0;count > 0;i++) {
		if ( Line[i] == '*' && Line[i+1] == '*') {
			if(count % 2 == 0)
				Line.replace(i,2,"<strong>");
			else
				Line.replace(i,2,"</strong>");
			count--;
		}
	}
}

void Markdown::Italic( std::string &Line )
{
	int count = 0;

	for (int i = 0;i < Line.size()-1;i++)//找到所有的 *
	{
		if (Line[i] == '*') {
			count++;
		}
	}

	if (count % 2 != 0){count--;}

	for (int i = 0;count > 0;i++) {

		if (Line[i] == '*') {
			if (count % 2 == 0)
				Line.replace(i,1,"<i>");
			else
				Line.replace(i,1,"</i>");
			count--;
		}
	}
}

bool Markdown::code( std::string &Line )
{
	int count = 0;

	for (int i = 0;i < Line.size()-1;i++)//找到所有的 `
	{
		if (Line[i] == '`') {
			count++;
		}
	}

	if (count == 0 || count == 1){
		return false;
	}

	if (count % 2 != 0){count--;}

	for (int i = 0;count > 0;i++) {

		if (Line[i] == '`') {
			if(count % 2 == 0) {
				Line.replace(i,1,"<font color=33CC00>");
			}
			else {
				Line.replace(i,1,"</font>");
			}
			count--;
		}
	}
	return true;
}

void Markdown::Img( std::string &Line )
{
	int j = 0,k = 0;
	char quotes = '"';
	string word,link,html;
	bool Front = false;
	bool Behind = false;
	for (int i = 0;Line[i] != '\0';i++) {
		if (Line[i] == ']' && Line[i+1] == '(') {

			for (j = i;j > 0;j--) {
				if (Line[j] == '[' && Line[j-1] == '!') {
					Front = true;
					break;
				}
			}

			for (k = i;Line[k] != '\0';k++) {
				if (Line[k] == ')') {
					Behind = true;
					break;
				}
			}

			if (Front == true && Behind == true) {
				word = Line.substr(j+1,i-j-1);
				link = Line.substr(i+2,k-i-2);
				html = "<img  src= "+link+" alt="+word+">";
				Line.replace(j-1,k-j+2,html);
			}
			i = k;
		}
	}
}

void Markdown::Links( std::string &Line )
{
	int j = 0,k = 0;
	char quotes = '"';
	string word,link,html;
	bool Front = false;
	bool Behind = false;
	for (int i = 0;Line[i] != '\0';i++) {
		if (Line[i] == ']' && Line[i+1] == '(') {

			for (j = i;j >= 0;j--) {
				if (Line[j] == '[') {
					Front = true;
					break;
				}
			}

			for (k = i;Line[k] != '\0';k++) {
				if(Line[k] == ')') {
					Behind = true;
					break;
				}
			}

			if (Front == true && Behind == true) {
				word = Line.substr(j+1,i-j-1);
				link = Line.substr(i+2,k-i-2);
				html = "<a href = "+link+">"+word+"</a>";
				Line.replace(j,k-j+1,html);
			}
			i = k;
		}
	}
}

std::string Markdown::getstring( const int n )
{
	std::stringstream newstr;
	newstr << n;
	return newstr.str();
}
