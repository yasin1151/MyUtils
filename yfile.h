/*
	name      : yfile.h
	copyright : myself
	author    : yasin
	time      : 2016/3/26
	des		  : to open a file ,
				get '=' before and after info,
				and you can use [] or at() to get value.
*/


#ifndef _Y_FILE_H_
#define _Y_FILE_H_
				
#include <fstream>
#include <string>
#include <map>


class yFile
{
public:
	yFile(std::string fileName);
	std::string operator[](std::string paramName);
	std::string at(std::string paramName);
private:
	std::string m_fileName;
	std::map<std::string, std::string> m_data;
private:
	void GetDataByFile();
};


#endif