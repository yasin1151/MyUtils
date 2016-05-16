/*
	author : yasin
	time   : 2016/3/23
	version: 1.0
	ext    : myself utils lib
	e-mail : yasin1151@outlook.com
 */

#ifndef _YASIN_UTILS_H_
#define _YASIN_UTILS_H_

#include <string>
#include <sstream>
#include <iostream>
#include <ctime>
using namespace std;


class yUtils
{
public:
	/**@brief : convert int or double to string
	 * @param : _value int or double
	 *          length default is zero if _value is double , you can set it
	 */
	template <typename T>
	static std::string toStr(T _value, int length = 0);

	static int getRandom(int _begin, int _end);
};





template <typename T>
std::string Utils::toStr(T _value, int length)
{
	//assert
	if (digit < 0)
	{
		return "";
	}

	stringstream strStream;
	strStream << _value;
	string returnBuf;

	if (digit > 0)
	{
		//if double , digit ++;
		if (strStream.str().find('.', 0) >= 0)
		{
			digit++;
		}

		returnBuf = strStream.str().substr(0, digit);
	}
	else
	{
		returnBuf = strStream.str();
	}

	return returnBuf;
}


#endif	// end _YASIN_UTILS_H_