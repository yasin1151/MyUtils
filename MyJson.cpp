#include "MyJson.h"

MyJson * MyJson::create(const char * jsonData)
{
	MyJson* ret = new MyJson();
	if (ret && ret->init(jsonData))
	{
		ret->autorelease();
	}
	else
	{
		CC_SAFE_DELETE(ret);
	}
	return ret;
}

bool MyJson::init(const char * data)
{
	doc.Parse<0>(data);
	if (doc.HasParseError())
	{
		return false;
	}
	return true;
}

const char * MyJson::getCStrData(const char * key)
{
	if (!doc.HasMember(key) || !doc[key].IsString())
	{
		return nullptr;
	}

	return doc[key].GetString();
}

int MyJson::getIntData(const char * key)
{
	if (!doc.HasMember(key) || !doc[key].IsString())
	{
		return 0;
	}
	return doc[key].GetInt();
}

bool MyJson::isHasKey(const char * key)
{
	if (doc.HasMember(key))
	{
		return true;
	}
	return false;
}
