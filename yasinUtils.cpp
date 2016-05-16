#include "yasinUtils.h"

int Utils::getRandom(int _begin, int _end)
{
	if (_begin == _end)
	{
		return _begin;
	}

	srand(time(0));
	int range = _end - _begin + 1;

	return rand() % range + _begin;
}
