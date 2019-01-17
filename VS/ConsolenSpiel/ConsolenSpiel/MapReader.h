#ifndef MAPREADER_H
#define MAPREADER_H
#include <fstream>
#include <string.h>
#include <sstream>

char * GetMapFromFile(short mapNumber)
{
	std::stringstream ss;

	ss << "map" << mapNumber << ".txt";

	std::ifstream in(ss.str());
	std::string contents((std::istreambuf_iterator<char>(in)),
		std::istreambuf_iterator<char>());

	char * map = new char[contents.length()];
	strcpy(map, contents.c_str());

	if (in.is_open())
		in.close();

	return map;
}

short GetMapCount()
{
	return 3;
}

#endif
