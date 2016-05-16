#ifndef __YASIN_JSON_H__
#define __YASIN_JSON_H__
#include "cocos2d.h"
#include "cocos2d\external\json\rapidjson.h"
#include "cocos2d\external\json\document.h"

USING_NS_CC;
using namespace rapidjson;

class MyJson : public Ref
{
public:
	/**@brief create the MyJson with the json data
	*/
	static MyJson* create(const char* jsonData);

	/**@brief init the Document
	*/
	bool init(const char* data);

	/**@brief get a c type string from json
	*@param key The json data key
	*/
	const char* getCStrData(const char* key);

	/**@brief get a int from json
	*@param key The json data key
	*/
	int getIntData(const char* key);

	/**@brief judge the json data is have the key
	*@param key The json data key
	*/
	bool isHasKey(const char* key);

	/**@brief get the Document reference
	*@note to user get array or object...
	*/
	Document& getRoot() { return doc; }
private:
	Document doc;			
};

#endif // !__YASIN_JSON_H__


