#ifndef MILLISECONDSHELPER_H
#define MILLISECONDSHELPER_H

#include <chrono>


using milliseconds = long long;

inline milliseconds get_milliseconds()
{
	return std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now().time_since_epoch()).count();
}


#endif